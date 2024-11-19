#define AUTOMATAS
#include "automatas.h"

#include <vector>

struct Transitions
{
    std::string digit;      // Para los digitos del alfabeto
    std::string states;     // Estado al que me lleva el digito
};

struct States
{
    std::string state;              // Estado en el que estoy
    std::vector<Transitions> trns;   // Transiciones que hay con los digitos del alfabeto
};
