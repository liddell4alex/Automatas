// Tocomp windows:
// g++ -Wall -IC:\Users\Alex\Documents\Estudios\Proyectos\Automatas\include\ C:\Users\Alex\Documents\Estudios\Proyectos\Automatas\src\afd.cpp main.cpp -o .\build\nanno

#include <iostream>
#include <locale>
#include <vector>
#include <stdlib.h>
#include <automatas.h>
#include <limits>

int main(int argc, char* argv[])
{ setlocale(LC_ALL, "es_MX.UTF-8");
    int op;

    while (1) {
        system("cls");
        
        std::cout << "Seleccione una opción: \n"
                  << "1. AFD\n"
                  << "2. AFND\n"
                  << "3. Salir\n"
                  << ">>> ";
        std::cin >> op;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (op)
        {
            case 1:
                system("cls");
                afd();
                break;
            case 2:
                std::cout << "En construcción.";
                getchar();
                break;
            case 3:
                std::cout << "Bye :D";
                return 0;
            default:
                std::cout << "Error.";
                getchar();
                break;
        }
    }
    
    return 0;
}
