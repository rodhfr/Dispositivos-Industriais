#include "../include/controlador_motor.h"
#include "../include/sensor_temperatura.h"  
#include "../include/dispositivo_industrial.h"
#include "../include/utils.h" // sleep fn
#include <iostream>
#include <thread>
#include <string>

using namespace std;

int main() {
    // TESTANDO SENSOR DE TEMPERATURA
    /*try {*/
    /*    // iniciar com 10 como temp minima e 30 max*/
    /*    sensor_temperatura sensor(10.0, 30.0);*/
    /**/
    /**/
    /*    // Inicia o sensor*/
    /*    cout << "Iniciando sensor de temperatura..." << endl;*/
    /*    thread sensorThread([&sensor]() {*/
    /*        sensor.iniciar();*/
    /*    });*/
    /**/
    /*    cout << "Colocando 20 graus de temperatura (Dentro da faixa)..." << endl;*/
    /*    sensor.setTemperatura(20.0);*/
    /*    sleep(2);*/
    /**/
    /*    cout << "Colocando 26 graus de temperatura (Dentro da faixa)..." << endl;*/
    /*    sensor.setTemperatura(26.0);*/
    /*    sleep(2);*/
    /**/
    /*    cout << "Colocando 32 graus de temperatura (Fora da faixa)..." << endl;*/
    /*    sensor.setTemperatura(32.0);*/
    /*    sleep(2);*/
    /*    //this_thread::sleep_for(std::chrono::seconds(2));*/
    /**/
    /*    cout << "Colocando 5 graus de temperatura (Fora da faixa)..." << endl;*/
    /*    sensor.setTemperatura(5.0);*/
    /*    sleep(2);*/
    /**/
    /**/
    /**/
    /*    // Parar sensor*/
    /*    cout << "Parando o sensor de temperatura..." << endl;*/
    /*    sensor.parar();*/
    /*    sensorThread.join();*/
    /**/
    /*    // Relatório final*/
    /*    string relatorio = sensor.gerar_relatorio();*/
    /**/
    /*} catch (const exception& e) {*/
    /*    cout << "Erro: " << e.what() << endl;*/
    /*}*/

    // TESTANDO CONTROLADOR DE MOTOR
    try {
        // Iniciar com 10 como temperatura mínima e 30 como máxima
        controlador_motor motor(5000, 3000); // Inicializando o motor com potência 5000 e 3000 RPM

        // Inicia o motor
        cout << "Iniciando o motor..." << endl;
        thread motorThread([&motor]() {
            motor.iniciar();
        });

        cout << "Ajustando para 4000 RPM..." << endl;
        motor.ajustar_velocidade(4000);
        sleep(2);

        cout << "Ajustando para 2000 RPM (Dentro da faixa)..." << endl;
        motor.ajustar_velocidade(2000);
        sleep(2);

        cout << "Tentando ajustar para -500 RPM ..." << endl;
        motor.ajustar_velocidade(-500);
        sleep(2);

        cout << "Tentando ajustar para 9000 RPM (Fora da faixa)..." << endl;
        motor.ajustar_velocidade(9000);
        sleep(2);

        cout << "Parando o motor..." << endl;
        motor.parar();
        motorThread.join();

        string relatorio = motor.gerar_relatorio();
        cout << relatorio << endl;

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }

    return 0;
}

