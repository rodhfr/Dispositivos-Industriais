#ifndef ROBO_MANIPULADOR_H
#define ROBO_MANIPULADOR_H

#include "dispositivo_industrial.h"
#include <string>

using std::string;

class robo_manipulador : public dispositivo_industrial {
private:
    double posicao_x = 0.0;
    double posicao_y = 0.0;
    double posicao_z = 0.0;
    double carga_atual;
    double carga_maxima;
    string warning;
    string relatorio;

public:
    robo_manipulador(const string& i, double temp_celsius, double carga_max) : dispositivo_industrial(i, temp_celsius), carga_maxima(carga_max) { }
    
    // Métodos específicos
    void mover_para(double x, double y, double z);
    void agarrar_objeto(double peso);

    void soltar_objeto();

    // Implementações dos métodos virtuais puros
    void iniciar() override;
    void parar() override;
    string gerar_relatorio() override;

    // Sobrescrita do método verificar_seguranca
    bool verificar_seguranca() override;
};

#endif // ROBO_MANIPULADOR_H
