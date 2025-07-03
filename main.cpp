// Tocomp windows:
// g++ -Wall -IC:\Users\Alex\Documents\Estudios\Proyectos\Automatas\include\ C:\Users\Alex\Documents\Estudios\Proyectos\Automatas\src\afd.cpp main.cpp -o .\build\nanno

#include <iostream>
#include <locale>
#include <vector>
#include <stdlib.h>
#include <limits>

#include "automatas.h"
#include "colores.h"

int main(int argc, char* argv[])
{ setlocale(LC_ALL, "es_MX.UTF-8");
    int op;

    while (1) {
        system("cls");
        
        std::cout << LBLUE << "Seleccione una opción: \n" << RESET
                  << GREEN << "1. AFD\n" << RESET
                  << RED << "2. AFND\n" << RESET
                  << ORANGE << "3. Salir\n\n" << RESET
                  << WHITE << ">>> " << RESET;
        std::cin >> op;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (op)
        {
            case 1:
                system("cls");
                afd();
                break;
            case 2:
                std::cout << ORANGE << "\nEn construcción." << RESET;
                getchar();
                break;
            case 3:
                std::cout << YELLOW << "\nBye :D" << RESET;
                getchar();
                return 0;
            default:
                std::cout << RED << "\nError." << RESET;
                getchar();
                break;
        }
    }
    
    return 0;
}
