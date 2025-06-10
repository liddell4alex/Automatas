#include <iostream>
#include <array>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    // Alfabeto
    std::array<int, 2> E = {0,1};

    // Estados
    std::array<std::string, 2> Q = {"q0", "q1"};

    // Estado Inicial
    std::string Qi = "q0";

    // Estados Finales
    std::array<std::string, 1> F = {"q0"};

    // Tabla de transiciones
    std::array<std::array<std::string, 2>, 2> AFD = {{
        {{"q1", "q1"}},
        {{"q0", "q0"}}
    }};

    std::string palabra = "0101";

    // Seguimos luego





    return 0;
}