#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <chrono>
#include <thread>
#include <sstream>
#include <stdlib.h>
#include "colores.h"

int afd()
{
    for (int i = 0; i < 3; i++) {
        std::cout << "Hola, iniciando AFD.";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        system("cls");
        std::cout << "Hola, iniciando AFD..";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
   
        system("cls");
        std::cout << "Hola, iniciando AFD...";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("cls");
    }
    
    // Estados generados automaticamente -----------------------------------------------
    int numEstados = 0;
    std::string estado;
    std::vector<std::string> Q;
    
    std::cout << "Número de estados\n>>> ";
    std::cin >> numEstados;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    for (int i = 0; i < numEstados; i++) {
        estado = "q" + std::to_string(i);
        Q.push_back(estado);
    }
    
    // Alfabeto, por ahora, solo es: Σ = {0, 1} ----------------------------------------
    char c;
    std::string alf;
    std::vector<char> E;

    std::cout << "\nEspecifica el alfabeto (carácteres separados por espacios)\n>>> ";
    std::getline(std::cin, alf);

    std::istringstream stream(alf);
    while (stream >> c) { E.push_back(c); }

    // Creando tabla de transiciones ---------------------------------------------------
    std::string line;
    std::vector<std::string> row;
    std::vector<std::vector<std::string>> AFD;
  
    std::cout << "\nDefine la tabla de transiciones (solo #'s por fila y termina con 'x')\n";
    while (1) {
        std::cout << ">>> ";
        
        std::getline(std::cin, line);

        if (line == "x") { break; }
        
        std::istringstream stream(line);

        while (stream >> estado) {
            row.push_back(Q[std::stoi(estado)]);
        }
        
        AFD.push_back(row);
        row.clear();     
    }
    
    // Estado Inicial -------------------------------------------------------------------
    int n;
    std::string Qi;

    std::cout << "\nEstado inicial (solo #)\n>>> ";
    std::cin >> n; Qi = Q[n];
    
    // Estados Finales ------------------------------------------------------------------
    std::string final;
    std::vector<std::string> F;

    std::cout << "\nSelecciona los estados finales (solo #'s y termina con 'x')\n[ ";
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

    for (const char &c : E) std::cout << c << ' ';
 
    // Comprobando palabras --------------------------------------------
    bool flag = true;
    std::string Qa;
    std::string word;
 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << '\n';

    while (1) {
        Qa = Qi;

        std::cout << "\nIntroduce la palabra a probar ('q' para terminar)\n>>> ";
        std::getline(std::cin, word);

        if (word == "q") { std::cout << "Bye :D"; getchar(); break; }

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
            std::cout << GREEN << "SI" << RESET << '\n';
        } else {
            std::cout << RED << "NO" << RESET << '\n';
        }
    }
 
    return 0;
}