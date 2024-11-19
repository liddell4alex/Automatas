#ifdef AUTOMATAS
#define AUTOMATAS

#include <string>

/* Estructuras para armar la tabla de transiciones */
typedef struct Transitions Transitions;
typedef struct States States;

/* Funcion simple para ponerle nombre a los estados en
formato q# dependiendo de la cantidad de estados dada */
std::string nombreDeEstado(int);

#endif // AUTOMATAS
