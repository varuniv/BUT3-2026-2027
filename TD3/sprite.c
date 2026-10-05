#include "sprite.h"

bool colision(struct sprite *s1, struct sprite *s2) {
    // On véerifie si spirte un et sprite deux entre ne colison
    int x1 = s1->position.x;
    int y1 = s1->position.y;
    int width1 = s1->width;
    int height1 = s1->height;
    int x2 = s2->position.x;
    int y2 = s2->position.y;
    int width2 = s2->width;
    int height2 = s2->height;

    return (x1 < x2 + width2) && (x1 + width1 > x2) &&
           (y1 < y2 + height2) && (y1 + height1 > y2);

}

int colisionTotal(struct sprite tableau[], int taille){
    int cmp = 0;
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            if(i != j && colision(&tableau[i], &tableau[j])){
                cmp++;
            }
        }
    }
    return cmp;
}