#include "liste.h"
#include <stdio.h>
#include <time.h>
#include "main.h"

//valgrind --tools-callgrind ./programe

void main() {

    Mesure1();
    
}
void Mesure1()
{
    clock_t debut = clock();
    // instructions du programme
    clock_t fin = clock();
    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("Temps d'exécution : %f secondes\n", temps);
}