#ifndef VERIFICA_H
#define VERIFICA_H

#include <iostream>
#include <vector>

#include "../pila/pila.h"

bool accept_str(std::string, std::string);
bool verifica_ap(std::string cadena, std::vector<std::vector<std::string>>);
bool eval(std::vector<std::string> v, char c, Pila &pila, int &i);
void ex(Pila &, std::string str);

#endif