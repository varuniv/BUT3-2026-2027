/**
This code has been found on stackoverflow at this URL

https://stackoverflow.com/a/3536261

As mention on the website, it is released under CC BY SA 4.0 licence

Author: casablanca <https://stackoverflow.com/users/381345/casablanca>

The current version of the code has been slightly modified by Noël Gillet (IUT d'Orléans) 
and is distributed during the labs of course "R5.04 Qualité algorithmique" to the third year students
of the Bachelor Universitaire Technologique (BUT) in computer science
*/

#include "dyn_array.h"

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(ballon *));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, ballon * element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(ballon*));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
    // free the balloons
    for(int i=0;i<a->used;i++){

    }
    // free the array
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}