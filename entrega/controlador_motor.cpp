#include "controlador_motor.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>



using namespace std;

void controlador_motor::ajustar_velocidade(int nova_rpm) {
    if (nova_rpm > 0) {
        rpm = nova_rpm;
        warning = "Maquina comeca a trabalhar com nova rpm: " + to_string(nova_rpm) + "\n";
        relatorio += nova_rpm;
    }
    else {
        warning = "rpm precisa ser maior que 0 \n";
        relatorio += warning;
        cout << warning << endl;
    }
}
double controlador_motor::calcular_eficiencia() {
    warning = "Calculando eficiencia da maquina \n";
    
    // Exemplo: eficiência = (potência / (rpm * constante))
    double constante = 1000; 
    
    // eficiência como uma função do RPM e da potência
    double eficiencia = (potencia / (rpm * constante)) * 100;
    warning += "Eficiencia da maquina: " + to_string(eficiencia) + "\n";
    relatorio += warning;

    return eficiencia;
}
bool controlador_motor::verificar_seguranca() {
    if (potencia > 10000 || rpm > 8000) {
        warning = "controlador_motor::verificar_seguranca(): Comportamento anômalo, taxas fora do normal, desligando máquina \n\n";
        cout << warning << endl;
        relatorio += warning;
        return false;
    }
    else {
        warning = "controlador_motor::verificar_seguranca(): Funciona normalmente \n\n";
        cout << warning << endl;
        relatorio += warning;
        return true;
    }
}

void controlador_motor::iniciar() {

    setStatus(true);
    while (getStatus()) {
        cout << getId() << endl;
        cout << "controlador_motor::getStatus(): " << getStatus() << endl;
        cout << "RPM:" << rpm << endl;
        if (!verificar_seguranca()) {
            parar();
            break;
        }
        cout << endl << "Motor em execução. Status: ativo.\n" << endl;
        calcular_eficiencia();
        horas_de_uso += 1;
        cout << "Loop 1s... controlador_motor::iniciar()" << endl;
        cout << "---------------------------------------" << endl;
        sleep(1); // utils.h sleep 
    }
}
void controlador_motor::parar() {
    warning = "controlador_motor::parar() \n";
    setStatus(false);
    warning += "Maquina parada com sucesso \n";
    cout << warning << endl;
    relatorio += warning;
    gerar_relatorio();
}
string controlador_motor::gerar_relatorio() {
    cout << endl << "### Relatorio gerado: ###" << endl;
    relatorio += "\n###############################\n";
    relatorio += "ID do dispositivo: " + getId() + "\n";
    relatorio += "Tempo de utilizacao da maquina (segundos): " + to_string(horas_de_uso) + "\n";
    relatorio += "###############################\n";
    //cout << relatorio; // fica muito verboso
    escreverLog(relatorio, "controlador_motor");
    return relatorio;
}

