#include "../include/dispositivo_industrial.h" // classe base de sensor_temperatura
#include "../include/utils.h" // write-read logs, time e um sleep os agnostic
#include "../include/robo_manipulador.h"
#include <iostream>
#include <string>

using namespace std;
using std::cout;
using std::to_string;
using std::endl;

// Métodos específicos
void robo_manipulador::mover_para(double x, double y, double z) {
    posicao_x = x;
    posicao_y = y;
    posicao_z = z;
    warning += "Robo movido para a posicao" + to_string(posicao_x) + "," + to_string(posicao_y) + "," + to_string(posicao_z) + "\n";
    cout << warning << endl;
    relatorio += warning;
}
void robo_manipulador::agarrar_objeto(double peso) {
    if (peso > carga_maxima) {
        warning = "Peso excede a capacidade maxima do robo \n";
        relatorio += warning; 
        cout << warning;
        throw invalid_argument(warning);
    }
    carga_atual = peso;
    warning = "Objeto de " + to_string(peso) + "kg agarrado. Carga atual: " + to_string(carga_atual) + "kg\n";
    cout << warning << endl;
    relatorio += warning; 
}

void robo_manipulador::soltar_objeto() {
    warning = "Soltando objeto de " + to_string(carga_atual) + "kgs... \n";
    carga_atual = 0;
    warning += "Carga atual " + to_string(carga_atual);
    cout << warning << endl;
    relatorio += warning;
}

// Implementações dos métodos virtuais puros
void robo_manipulador::iniciar() {
    setStatus(true);
    while (getStatus()) {
        verificar_seguranca();
        cout << "Robô manipulador iniciado. Posição inicial: (" 
        << posicao_x << ", " << posicao_y << ", " << posicao_z << ")" << endl;
        cout << "LOG: dentro do while loop esperando 1s robo_manipulador::iniciar()" << endl;
        sleep(1); // utils.h sleep 
    }
}
void robo_manipulador::parar() {
    setStatus(false);
    cout << "Robô manipulador parado na posição atual: (" 
         << posicao_x << ", " << posicao_y << ", " << posicao_z << ")" << endl;
}

string robo_manipulador::gerar_relatorio() {
    string relatorio;
    relatorio += "\n_______ Relatório do Robô Manipulador _______\n";
    relatorio += "ID: " + getId() + "\n";
    relatorio += "Posição atual: (" + to_string(posicao_x) + ", " 
                 + to_string(posicao_y) + ", " + to_string(posicao_z) + ")\n";
    relatorio += "Carga atual: " + to_string(carga_atual) + "kg\n";
    relatorio += "Carga máxima: " + to_string(carga_maxima) + "kg\n";
    relatorio += "_____________________________________________\n";
    cout << relatorio;
    escreverLog(relatorio, "robo_status");
    return relatorio;
}

// Sobrescrita do método verificar_seguranca
bool robo_manipulador::verificar_seguranca() {
    if (carga_atual > carga_maxima) {
        warning = "ALERTA: Carga atual excede a capacidade maxima! \n";
        cout << warning << endl;
        relatorio += warning; 
        parar();
        return false;
    }
    else {    
        warning = "Robo operando dentro das condicoes de seguranca \n";
        relatorio += warning;
        cout << warning << endl;
        return true;
    }

}