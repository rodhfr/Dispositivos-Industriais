#include <iostream>
#include "controlador_motor.h"
#include "sensor_temperatura.h"
#include "robo_manipulador.h"
#include "sistema_controle.h"
#include "utils.h"
#include <chrono>
#include <thread>


using namespace std;

int main() {
    // Criando o sistema de controle
    sistema_controle sistema;

    // Criando dispositivos industriais
    controlador_motor* motor1 = new controlador_motor("MOTOR-001", 28, 500, 1500);
    sensor_temperatura* sensor1 = new sensor_temperatura("SENSOR-001", 28, 30.0, 80.0);
    robo_manipulador* robo1 = new robo_manipulador("ROBO-001", 28, 50.0);

    sistema.adicionar_dispositivo(motor1);
    sistema.adicionar_dispositivo(sensor1);
    sistema.adicionar_dispositivo(robo1);


    thread motor_thread(&controlador_motor::iniciar, motor1);
    motor1->ajustar_velocidade(1500); 
    cout << "############# Ajustando velocidade para 1500..." << endl;
    sleep(1);

    motor1->ajustar_velocidade(2000); 
    cout << "############# Ajustando velocidade para 2000..." << endl;
    sleep(1);

    motor1->ajustar_velocidade(3000);  
    cout << "############# Ajustando velocidade para 3000..." << endl;
    sleep(1);

    motor1->ajustar_velocidade(5000);  
    cout << "############# Ajustando velocidade para 5000..." << endl;
    sleep(1); 

    cout << "############# Ajustando velocidade para 10000..." << endl;
    motor1->ajustar_velocidade(10000);  // velocidade acima do permitido. parar() invocado e gera relatorio.

    motor_thread.join();


    thread sensor_thread(&sensor_temperatura::iniciar, sensor1);
    // abaixo do limite
    cout << "############# temperatura elevada para 25C" << endl;
    sensor1->setTemperatura(25.0);
    sleep(1);

    // dentro do intervalo seguro
    cout << "############# temperatura elevada para 50C" << endl;
    sensor1->setTemperatura(50.0);
    sleep(1);

    // acima do limite
    cout << "############# temperatura elevada para 85C" << endl;
    sensor1->setTemperatura(85.0);

    // abaixo do limite
    cout << "############# temperatura elevada para 25C" << endl;
    sensor1->setTemperatura(25.0);
    sleep(1);
    
    sensor1->parar();
    sensor_thread.join();

    thread robo_thread(&robo_manipulador::iniciar, robo1);

    // movendo diferentes posicoes
    cout << "############# Movendo robô para a posição (10, 20, 30)..." << endl;
    robo1->mover_para(10.0, 20.0, 30.0);
    sleep(1);

    cout << "############# Movendo robô para a posição (15, 25, 35)..." << endl;
    robo1->mover_para(15.0, 25.0, 35.0);
    sleep(1);

    // peso valido
    try {
        cout << "############# Tentando agarrar objeto de 25kg..." << endl;
        robo1->agarrar_objeto(25.0);
        sleep(1);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    // peso acima do permitido
    try {
        cout << "############# Tentando agarrar objeto de 100kg..." << endl;
        robo1->agarrar_objeto(100.0); 
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << "############# Soltando o objeto..." << endl;
    robo1->soltar_objeto();
    sleep(1);

    robo1->gerar_relatorio();

    cout << "############# Parando o robô..." << endl;
    robo1->parar();

    robo_thread.join();

    // sisetema iniciar todos deixei no fim porque esta terrivel a saida do console e nao vai dar mais tempo de consertar essa parte
    // falta experiencia pra mexer com threads melhor ta tudo uma por cima da outra se rodar todos ao mesmo tempo
    sistema.iniciar_todos();
    sistema.gerar_relatorio_completo();
    sistema.parar_todos();



    return 0;
}
