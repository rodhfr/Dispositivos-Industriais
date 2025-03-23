#include "../include/dispositivo_industrial.h"

//destrutor virtual
dispositivo_industrial::~dispositivo_industrial() {
    cout << "LOG: Destrutor virtual de ~dispositivo_industrial chamado" << endl;
}

//getters
string dispositivo_industrial::getId() const { return id; }
bool dispositivo_industrial::getStatus() const { return status; }
double dispositivo_industrial::getTemperatura() const { return temperatura; }

//setters
void dispositivo_industrial::setId(string i) { id = i; }
void dispositivo_industrial::setStatus(bool s) { status = s; }
void dispositivo_industrial::setTemperatura(double t) { temperatura = t; }
