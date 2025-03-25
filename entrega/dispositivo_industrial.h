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
    dispositivo_industrial(const string& i, double temp_celsius) : id(i), status(false) {}
    ~dispositivo_industrial() {
        cout << "LOG: Destrutor virtual de ~dispositivo_industrial chamado" << endl;
    }

    //getters
    string getId() const { return id; }
    bool getStatus() const { return status; }
    double getTemperatura() const { return temperatura; }

    //setters
    void setId(string i) { id = i; }
    void setStatus(bool s) { status = s; }
    void setTemperatura(double t) { temperatura = t; }

    // Método virtuais
    virtual void iniciar() = 0;  // Coloca o dispositivo em funcionamento
    virtual void parar() = 0;    // Interrompe o funcionamento do dispositivo
    virtual string gerar_relatorio() = 0; // Retorna string com informações sobre o estado atual do dispositivo
    virtual bool verificar_seguranca() { 
        return true; // Retorna booleano verificando se está operando em condições seguras
    }; 


};

#endif // DISPOSITIVO_INDUSTRIAL_H
