#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include <string>
#include "dispositivo_industrial.h"

using namespace std;

class sensor_temperatura : public dispositivo_industrial {
private:
    double temperatura_maxima;
    double temperatura_minima;
    double temp_atual;
    string relatorio;

public:
    sensor_temperatura(const string& i, double temp_celsius, double temp_min, double temp_max) : dispositivo_industrial(i, temp_celsius), temperatura_minima(temp_min), temperatura_maxima(temp_max) {
        if (temp_min >= temp_max) {
            throw invalid_argument("temperatura_minima deve ser menor que temperatura_maxima");
        }
    }
    bool alerta_temperatura();
    void iniciar() override;
    void parar() override;
    string gerar_relatorio() override;
};

#endif // SENSOR_TEMPERATURA_H
