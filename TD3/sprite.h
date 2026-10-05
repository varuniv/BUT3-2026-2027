#include <stdio.h>
#include <stdbool.h>

struct point {
    int x;
    int y;
};

struct sprite {
    struct point position;
    int width;
    int height;
};

bool colision(struct sprite *s1, struct sprite *s2);

int colisionTotal(struct sprite tableau[], int taille);