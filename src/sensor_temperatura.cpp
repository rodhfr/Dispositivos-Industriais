#include "../include/sensor_temperatura.h"
#include "../include/dispositivo_industrial.h" // classe base de sensor_temperatura
#include "../include/utils.h" // write-read logs, time e um sleep os agnostic
#include <iostream>

using namespace std;

sensor_temperatura::sensor_temperatura(double temp_min, double temp_max) : temperatura_minima(temp_min), temperatura_maxima(temp_max) {
    if (temp_min >= temp_max) {
        throw invalid_argument("temperatura_minima deve ser menor que temperatura_maxima");
    }
}

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
        temp_atual = getTemperatura();
        cout << endl << "Sensor de temperatura em execução. Status: ativo." << endl;
        alerta_temperatura();
        cout << "LOG: dentro do while loop esperando 1s... sensor_temperatura.h::iniciar()" << endl;
        sleep(1); // utils.h sleep 
    }
}

void sensor_temperatura::parar() {
    cout << "LOG: Parando o sensor de temperatura... sensor_temperatura::parar()" << endl;
    setStatus(false);
}

string sensor_temperatura::gerar_relatorio() {
    relatorio += "\n________ Limites de Temperatura ________\n";
    relatorio += "Temperatura máxima permitida: " + to_string(temperatura_maxima) + "C|\n";
    relatorio += "Temperatura mínima permitida: " + to_string(temperatura_minima) + "C|\n";
    relatorio += "________________________________________|\n";
    cout << endl << "### Relatorio de temperatura gerado: ###" << endl;
    cout << relatorio;
    escreverLog(relatorio, "temperatura_status");
    return relatorio;
}

