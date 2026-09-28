#include <SDL2/SDL_render.h>
#include "utils.h"


struct maillon {
    ballon * ballon;
    struct maillon * suivant;
};

struct liste {
    struct maillon * premier;
    int taille;
};

typedef struct maillon * maillon;
typedef struct liste * liste;

/** Ajoute un maillon en tête de liste */
struct maillon ajoutEnTete(liste * liste, ballon * b);

/** Supprime le maillon en tête de liste */
maillon supprimerEnTete(liste * liste);

/** Recherche un ballon dans la liste */
int recherche(liste * liste, ballon * b);