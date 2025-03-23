#include "../include/utils.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <thread> 
#include <iostream>
#include <fstream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::string;
using std::cerr;
using std::cout;
using std::endl;

// copiei da internet essa funcao e pra pegar o tempo do sistema
std::string obterHoraAtual() {
    // Obtém o tempo atual
    auto now = std::chrono::system_clock::now();

    // Converte para time_t para usar com std::ctime
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Converte time_t para string
    std::stringstream ss;
    ss << std::ctime(&now_time);
    
    // Retorna a string com a hora atual
    return ss.str();
}

// copiei função sleep que recebe o número de segundos para esperar
void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}



void escreverLog(const string& mensagem, const string& filename) {
    string filenametxt = filename + ".txt";
    ofstream arquivo(filenametxt);
    if (arquivo.is_open()) {
        arquivo << mensagem;
        arquivo.close();
        cout << "Arquivo de texto escrito com sucesso em " << filenametxt << endl;
    }
    else { 
        cerr << "Erro ao escrever o arquivo de texto " << filenametxt << endl;
    }
}

void lerLog(const string& filename) { 
    string filenametxt = filename + ".txt";
    ifstream arquivo(filenametxt);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filenametxt << endl;
        return;
    }
    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
    arquivo.close();
}