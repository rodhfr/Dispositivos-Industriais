#ifndef CONTROLADOR_MOTOR_H
#define CONTROLADOR_MOTOR_H

#include <string>
#include "dispositivo_industrial.h"
#include <iostream>
#include <string>

using namespace std;

class controlador_motor : dispositivo_industrial {
private:
    int potencia;
    int rpm;
    double horas_de_uso;
    string relatorio;
    string warning;
public:
    controlador_motor(int p, int r);
    void ajustar_velocidade(int nova_rpm);
    double calcular_eficiencia();
    bool verificar_seguranca() override;
    void iniciar() override;
    void parar() override;
    string gerar_relatorio() override;

};

#endif // CONTROLADOR_MOTOR_H
