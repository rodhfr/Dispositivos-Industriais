#ifndef DISPOSITIVO_INDUSTRIAL_H
#define DISPOSITIVO_INDUSTRIAL_H

#include <string>
#include <iostream>

using namespace std;

class dispositivo_industrial {
private:
    string id;
    bool status;
    double temperatura;
public:
    // Método virtual de verificar segurança
    virtual bool verificar_seguranca() { 
        return true; // Retorna booleano verificando se está operando em condições seguras
    }; 

    virtual void iniciar() = 0;  // Coloca o dispositivo em funcionamento
    virtual void parar() = 0;    // Interrompe o funcionamento do dispositivo
    virtual string gerar_relatorio() = 0; // Retorna string com informações sobre o estado atual do dispositivo

    virtual ~dispositivo_industrial();  // Destrutor virtual

    // Getters
    string getId() const;
    bool getStatus() const;
    double getTemperatura() const;

    // Setters
    void setId(string i);
    void setStatus(bool s);
    void setTemperatura(double t);
};

#endif // DISPOSITIVO_INDUSTRIAL_H
