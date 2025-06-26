#include <iostream>
#include <array>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
    // Alfabeto
    std::array<int, 2> E = {0,1};
    E = {0, 1};

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

    // Comprobando palabras --------------------------------------------
    std::string Qa = Qi;
    std::string word = "1010";

    if (!(word.length() < 1)) {
        for (const char c : word) {
            int row = (int)Qa[1] - '0';
            int col = (int)c - '0';
            
            if (AFD[row][col] != "V") {
                Qa = AFD[row][col];
            } else {
                Qa = "V";
                break;
            }
        }
        
        bool find = std::binary_search(F.begin(), F.end(), Qa);
        
        if (find) {
            std::cout << "SI" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    } else {
        std::cout << "NO" << '\n';
    }

    std::getchar();

    return 0;
}