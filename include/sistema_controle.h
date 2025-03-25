#ifndef SISTEMA_CONTROLE_H
#define SISTEMA_CONTROLE_H

#include <string>
#include "dispositivo_industrial.h"

using std::string;

class sistema_controle {
private:
    static const int MAX_DISPOSITIVOS = 100;
    dispositivo_industrial* dispositivos[MAX_DISPOSITIVOS];
    int total_dispositivos;
public:
    sistema_controle() : total_dispositivos(0) {
        for (int i = 0; i < MAX_DISPOSITIVOS; ++i) {
            dispositivos[i] = nullptr;
        }
    }
    bool adicionar_dispositivo(dispositivo_industrial* dispositivo);
    bool remover_dispositivo(const std::string& id);
    void iniciar_todos();
    void parar_todos();
    void verificar_seguranca_geral();
    string gerar_relatorio_completo();
    ~sistema_controle();
};

#endif // SISTEMA_CONTROLE_H