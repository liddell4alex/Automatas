#define AUTOMATAS
#include "automatas.h"

#include <string>
#include <vector>

std::string nombreDeEstado(int n)
{
    std::string str = "q";
    str = str + std::to_string(n);

    return str;
}
