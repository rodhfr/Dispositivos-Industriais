#include "sensor_temperatura.h"
#include "dispositivo_industrial.h" // classe base de sensor_temperatura
#include "utils.h" // write-read logs, time e um sleep os agnostic
#include <iostream>

using namespace std;

bool sensor_temperatura::alerta_temperatura() {
    string mensagem, hr_atual = obterHoraAtual();
    if (temp_atual > temperatura_minima && temp_atual < temperatura_maxima) {
        mensagem = "Temperatura normal...";
        cout << temp_atual << "C - " << mensagem << " " << hr_atual << endl;
        relatorio += "\n=======================================\n";
        relatorio += to_string(temp_atual) + "C " + hr_atual + " " + mensagem + "\n";
        relatorio += "=======================================\n";
        return false;
    }
    else if (temp_atual > temperatura_maxima) { 
        mensagem = "PERIGO: ALTA TEMPERATURA!";
        cout << temp_atual << " " << mensagem << " " << hr_atual << endl;
        relatorio += "======================================= \n";
        relatorio += to_string(temp_atual) + "C " + hr_atual + " " + mensagem + "\n";
        relatorio += "======================================= \n";
        return true;
    }
    else {
        mensagem = "Temperatura ABAIXO da requerida para funcionamento";
        cout << temp_atual << " " << mensagem << " " << hr_atual << endl;
        relatorio += "======================================= \n";
        relatorio += to_string(temp_atual) + "C " + hr_atual + " " + mensagem + "\n";
        relatorio += "======================================= \n";
        return true;
    }
}



void sensor_temperatura::iniciar() {
    setStatus(true);
    while (getStatus()) {
        cout << "ID: " << getId() << endl;
        cout << "sensor_temperatura.h::iniciar()" << endl;
        cout << "cout: temp_atual = getTemperatura()" << getTemperatura();
        temp_atual = getTemperatura();
        cout << endl << "Sensor de temperatura em execução. Status: ativo." << endl;
        alerta_temperatura();
        cout << "Loop sleep 1s..." << endl;
        sleep(1); // utils.h sleep 
    }
}

void sensor_temperatura::parar() {
    cout << "sensor_temperatura::parar()" << endl;
    setStatus(false);
    gerar_relatorio();
}

string sensor_temperatura::gerar_relatorio() {
    relatorio += "ID: " + getId() + "\n";
    relatorio += "\n________ Limites de Temperatura ________\n";
    relatorio += "Temperatura máxima permitida: " + to_string(temperatura_maxima) + "C|\n";
    relatorio += "Temperatura mínima permitida: " + to_string(temperatura_minima) + "C|\n";
    relatorio += "________________________________________|\n";
    cout << endl << "### Relatorio de temperatura gerado: ###" << endl;
    cout << relatorio;
    escreverLog(relatorio, "temperatura_status");
    return relatorio;
}

