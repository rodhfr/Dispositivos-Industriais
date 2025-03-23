#ifndef UTILS_H
#define UTILS_H

#include <string>
using std::string;

void escreverLog(const string& mensagem, const string& filename);
void lerLog(const string& filename);
string obterHoraAtual();
void sleep(int seconds);

#endif // ! UTILS_H
