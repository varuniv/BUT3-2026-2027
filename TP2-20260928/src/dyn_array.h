#include <stdlib.h>
#include "utils.h"

typedef struct {
  ballon **array;
  size_t used;
  size_t size;
} Array;

/** 
Initialization of a dynamic array of size initialSize
*/
void initArray(Array *a, size_t initialSize);

/**
Insert an element in the array
*/
void insertArray(Array *a, ballon * element);


/**
Free the elements of the array
*/
void freeArray(Array *a);