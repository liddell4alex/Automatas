#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

int main(int argc, char *argv[])
{
    // Alfabeto, por ahora, solo es: Σ = {0, 1}
    std::vector<char> E = {'0', '1'}; 

    // Estados generados automaticamente
    int numEstados = 0;
    std::vector<std::string> Q;

    std::cout << "Número de estados\n>>> ";
    std::cin >> numEstados;

    std::string estado;

    for (int i = 0; i < numEstados; i++) {
        estado = "q" + std::to_string(i);
        Q.push_back(estado);
    }

    // Estado Inicial
    int n;
    std::string Qi;

    std::cout << "Estado inicial (solo #)\n>>> ";
    std::cin >> n; Qi = Q[n];
    
    // Estados Finales
    std::string final;
    std::vector<std::string> F;

    std::cout << "Selecciona los estados finales (solo #'s y termina con x)\n[ ";
    for (const std::string &e : Q) {
        std::cout << e << ' ';
    }
    std::cout << "]\n>>> ";

    while (std::cin >> final) {
        if (final != "x") {
            int index = std::stoi(final);
            F.push_back(Q[index]);
        } else {
            break;
        }
        
        std::cout << ">>> ";
    }

    // Pruebas --------------------------------------------------------
    std::cout << '\n';

    std::cout << "Estados: ";
    for (const std::string &e : Q) {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    std::cout << "Estado inicial: " << Qi << '\n';
    
    std::cout << "Estados finales: ";
    for (const std::string &e : F) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';
    // Pruebas --------------------------------------------------------
    
    
    // Tabla de transiciones
    std::vector<std::vector<std::string>> AFD = {
        {"q2", "q0"},
        {"q1", "q1"},
        {"q2", "q1"}
    };


    // Comprobando palabras --------------------------------------------
    bool flag = true;
    std::string Qa;
    std::string word;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (1) {
        Qa = Qi;

        std::cout << "Introduce la palabra a probar\n>>> ";
        std::getline(std::cin, word);

        if (!(word.length() < 1)) {
            for (const char &c : word) {
                flag = std::binary_search(E.begin(), E.end(), c);
                if (flag) {
                    int row = (int)Qa[1] - '0';
                    int col = (int)c - '0';
                    
                    if (AFD[row][col] != "V") {
                        Qa = AFD[row][col];
                    } else {
                        Qa = "V";
                        break;
                    }
                } else {
                    Qa = "V";
                }
            }
            
            flag = std::binary_search(F.begin(), F.end(), Qa);
            
            if (flag) {
                std::cout << "SI" << '\n';
            } else {
                std::cout << "NO" << '\n';
            }
        } else {
            std::cout << "NO" << '\n';
        }
        
        std::cout << '\n';
    }
    
    return 0;
}