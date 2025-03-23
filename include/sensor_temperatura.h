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
    sensor_temperatura(double temp_min, double temp_max);
    bool alerta_temperatura();
    void iniciar() override;
    void parar() override;
    string gerar_relatorio() override;
};

#endif // SENSOR_TEMPERATURA_H
