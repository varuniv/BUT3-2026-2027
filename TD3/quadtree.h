#include <stdio.h>
#include <stdbool.h>
#include "sprite.c"

struct quadtree {
    int x;
    int y;
    int width;
    int height;
    int nbsprite;
    struct sprite *sprites;
    struct quadtree *enfents[4];
};