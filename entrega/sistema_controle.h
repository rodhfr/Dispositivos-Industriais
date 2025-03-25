#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include "dispositivo_industrial.h" 

class sistema_controle {
private:
    std::vector<dispositivo_industrial*> dispositivos;
    std::vector<std::thread> threads;

public:
  
    void adicionar_dispositivo(dispositivo_industrial* dispositivo) {
        dispositivos.push_back(dispositivo);
    }

 
    void remover_dispositivo(const std::string& id) {
        for (auto it = dispositivos.begin(); it != dispositivos.end(); ++it) {
            if ((*it)->getId() == id) { 
                delete *it; 
                dispositivos.erase(it); 
                std::cout << "Dispositivo com ID " << id << " removido.\n";
                return;
            }
        }
        std::cout << "Dispositivo com ID " << id << " não encontrado.\n";
    }

   
    void iniciar_todos() {
        for (auto dispositivo : dispositivos) {
            threads.push_back(std::thread(&dispositivo_industrial::iniciar, dispositivo));
        }
    }


    void parar_todos() {
        for (auto dispositivo : dispositivos) {
            dispositivo->parar(); 
        }
    }


    void verificar_seguranca_geral() {
        for (auto dispositivo : dispositivos) {
            dispositivo->verificar_seguranca(); 
        }
    }

 
    void gerar_relatorio_completo() const {
        std::cout << "Relatório Completo dos Dispositivos:\n";
        for (const auto dispositivo : dispositivos) {
            dispositivo->gerar_relatorio(); 
        }
    }

    ~sistema_controle() {
        // vou colocar o finalizador das threads aqui no destrutor tambem pra ver se rola
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();  
            }
        }

        for (auto dispositivo : dispositivos) {
            delete dispositivo;
        }
        dispositivos.clear();
        std::cout << "Todos os dispositivos foram removidos e a memória foi liberada.\n";
    }
};
