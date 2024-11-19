#include <iostream>
#include <vector>

#define AUTOMATAS
#include "automatas.h"

/* Como argumento se puede especificar que es un AFN o un AFD en cualquier
caso se indicará el número total de estados como argumento*/
int main(int argc, char* argv[])
{
    int numQ;
    if(argc > 1) {
        numQ = std::stoi(argv[1]);
    }
    else {
        std::cout << "Es necesario indicar la cantidad de estados totales: ";
	std::cin >> numQ;
    }

    std::vector<char> E;            // Almaceno los digitos del alfabeto
    std::vector<std::string> Q;     // Almaceno los estados
    std::string Qi;                 // Almaceno el estado inicial
    std::vector<std::string> F;     // Almaceno los estados finales

    // Almacenando digitos del alfabeto
    std::cout << "Digitos del alfabeto separados por un espacio (';' para terminar las entradas)\n>>> ";
    char d;
    while(std::cin >> d && d != ';') {
        E.push_back(d);
    }

    // Creando estados usando la cantidad de estados proporcionada
    for(int i = 0; i < numQ; i++) {
        Q.push_back(nombreDeEstado(i));
    }

    // Almacenando el estado inicial
    int i;
    std::cout << "Estado inicial (solo número de estado)\n>>> ";
    std::cin >> i; std::cin.ignore();
    Qi = Q[i];

    // Almacenando estados finales
    std::cout << "Estados finales separados por espacio (solo numero de estado, termina con ';')\n>>> ";
    int s;
    while(std::cin >> s) {
        F.push_back(Q[s]);
    }

    // Imprimiendo datos del AFN -----------
    std::cout << std::endl << "Datos del AFN" << std::endl << std::endl;

    std::cout << "Alfabeto: ";
    for(long unsigned int i = 0; i < E.size(); i++) {
        std::cout << E[i] << ' ';
    } std::cout << std::endl;

    std::cout << "Estados totales: ";
    for(long unsigned int i = 0; i < Q.size(); i++) {
        std::cout << Q[i] << ' ';
    } std::cout << std::endl;

    std::cout << "Estado inicial: ";
    std::cout << Qi << std::endl;

    std::cout << "Estados finales: ";
    for(long unsigned int i = 0; i < F.size(); i++) {
        std::cout << F[i] << ' ';
    } std::cout << std::endl;

    return 0;
}
