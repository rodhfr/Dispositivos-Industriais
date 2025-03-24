#include "../include/controlador_motor.h"
#include "../include/utils.h"
#include <iostream>

using namespace std;

controlador_motor::controlador_motor(int p, int r) : potencia(p), rpm(r), horas_de_uso(0) { }

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
    cout << warning << endl;

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
        if (!verificar_seguranca()) {
            parar();
            break;
        }

        cout << endl << "Motor em execução. Status: ativo." << endl;
        calcular_eficiencia();
        horas_de_uso += 1;
        cout << "LOG: dentro do while loop esperando 1s... controlador_motor::iniciar()" << endl;
        sleep(1); // utils.h sleep 
    }
}
void controlador_motor::parar() {
    warning = "LOG: Parando controlador de motor... controlador_motor::parar() \n";
    setStatus(false);
    warning += "Maquina parada com sucesso \n";
    cout << warning << endl;
    relatorio += warning;
}
string controlador_motor::gerar_relatorio() {
    cout << endl << "### Relatorio gerado: ###" << endl;
    relatorio += "\n###############################\n";
    relatorio += "Tempo de utilizacao da maquina (segundos): " + to_string(horas_de_uso) + "\n";
    relatorio += "###############################\n";
    cout << relatorio;
    escreverLog(relatorio, "controlador_motor");
    return relatorio;
}

