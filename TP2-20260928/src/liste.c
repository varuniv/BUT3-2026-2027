#include "liste.h"

void ajoutEnTete(liste * liste, ballon * b) {
    // on crée le nouveau maillon
    struct maillon * nouveauMaillon = (maillon * ) malloc(sizeof(struct maillon));
    nouveauMaillon->ballon = b;
    nouveauMaillon->suivant = (*liste)->premier;
    (*liste)->premier = nouveauMaillon;
    (*liste)->taille++;
}