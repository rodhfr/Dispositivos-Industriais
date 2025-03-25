#include "../include/dispositivo_industrial.h"
#include "../include/sistema_controle.h"
#include <iostream>


bool sistema_controle::adicionar_dispositivo(dispositivo_industrial* dispositivo) {
    if (total_dispositivos >= MAX_DISPOSITIVOS) {
        std::cerr << "Erro: Limite máximo de dispositivos atingido.\n";
        return false;
    }

    dispositivos[total_dispositivos++] = dispositivo;
    return true;
}

bool sistema_controle::remover_dispositivo(const std::string& id) {
    for (int i = 0; i < total_dispositivos; ++i) {
        if (dispositivos[i] != nullptr && dispositivos[i]->getId() == id) {
            delete dispositivos[i];
            dispositivos[i] = dispositivos[total_dispositivos - 1];
            dispositivos[total_dispositivos - 1] = nullptr;
            --total_dispositivos;
            return true;
        }
    }

    std::cerr << "Dispositivo com ID " << id << " não encontrado.\n";
    return false;
}

void sistema_controle::iniciar_todos() {
    for (int i = 0; i < total_dispositivos; ++i) {
        if (dispositivos[i] != nullptr) {
            dispositivos[i]->iniciar();
        }
    }
}

void sistema_controle::parar_todos() {
    for (int i = 0; i < total_dispositivos; ++i) {
        if (dispositivos[i] != nullptr) {
            dispositivos[i]->parar();
        }
    }
}

void sistema_controle::verificar_seguranca_geral() {
    for (int i = 0; i < total_dispositivos; ++i) {
        if (dispositivos[i] != nullptr && !dispositivos[i]->verificar_seguranca()) {
            std::cerr << "Alerta: Dispositivo " << dispositivos[i]->getId() << " não está operando de forma segura.\n";
        }
    }
}

std::string sistema_controle::gerar_relatorio_completo() {
    std::string relatorio;
    for (int i = 0; i < total_dispositivos; ++i) {
        if (dispositivos[i] != nullptr) {
            relatorio += dispositivos[i]->gerar_relatorio() + "\n";
        }
    }
    return relatorio;
}

sistema_controle::~sistema_controle() {
    for (int i = 0; i < total_dispositivos; ++i) {
        delete dispositivos[i];
        dispositivos[i] = nullptr;
    }
}
