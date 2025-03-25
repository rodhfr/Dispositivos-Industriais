#include <iostream>
#include "../include/sistema_controle.h"
#include "../include/dispositivo_industrial.h"
#include "../include/controlador_motor.h"
#include "../include/robo_manipulador.h"
#include "../include/sensor_temperatura.h"
#include "../include/utils.h"  // Para o sleep e os logs
#include <string>

using namespace std;

int main() {
    // Criando dispositivos
    controlador_motor* motor = new controlador_motor("motor_01", 1500, 3000);
    robo_manipulador* robo = new robo_manipulador("robo_01", 100.0);
    sensor_temperatura* sensor = new sensor_temperatura("sensor_01", 20.0, 80.0);

    // Criando o sistema de controle e adicionando dispositivos
    sistema_controle sistema;
    sistema.adicionar_dispositivo(motor);
    sistema.adicionar_dispositivo(robo);
    sistema.adicionar_dispositivo(sensor);

    // Iniciando todos os dispositivos
    sistema.iniciar_todos();

    // Verificando segurança
    sistema.verificar_seguranca_geral();

    // Gerando relatório completo do sistema
    string relatorio_completo = sistema.gerar_relatorio_completo();
    std::cout << "Relatório Completo do Sistema:\n" << relatorio_completo << std::endl;

    // Parando todos os dispositivos
    sistema.parar_todos();

    // Removendo dispositivos
    sistema.remover_dispositivo("motor_01");
    sistema.remover_dispositivo("robo_01");
    sistema.remover_dispositivo("sensor_01");

    // Liberação de memória
    delete motor;
    delete robo;
    delete sensor;

    return 0;
}




