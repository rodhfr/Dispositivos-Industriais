#include "../include/sensor_temperatura.h"  
#include "../include/dispositivo_industrial.h"
#include "../include/utils.h" // sleep fn
#include <iostream>
#include <thread>
#include <string>

using namespace std;

int main() {
    try {
        // iniciar com 10 como temp minima e 30 max
        sensor_temperatura sensor(10.0, 30.0);


        // Inicia o sensor
        cout << "Iniciando sensor de temperatura..." << endl;
        thread sensorThread([&sensor]() {
            sensor.iniciar();
        });

        cout << "Colocando 20 graus de temperatura (Dentro da faixa)..." << endl;
        sensor.setTemperatura(20.0);
        sleep(2);

        cout << "Colocando 26 graus de temperatura (Dentro da faixa)..." << endl;
        sensor.setTemperatura(26.0);
        sleep(2);

        cout << "Colocando 32 graus de temperatura (Fora da faixa)..." << endl;
        sensor.setTemperatura(32.0);
        sleep(2);
        //this_thread::sleep_for(std::chrono::seconds(2));

        cout << "Colocando 5 graus de temperatura (Fora da faixa)..." << endl;
        sensor.setTemperatura(5.0);
        sleep(2);



        // Parar sensor
        cout << "Parando o sensor de temperatura..." << endl;
        sensor.parar();
        sensorThread.join();

        // Relatório final
        string relatorio = sensor.gerar_relatorio();

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
    return 0;
}

