#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

/**
Initialisation de la fenêtre et du canvas
*/
int init(SDL_Window ** mafenetre, 
    int tailleFenetreW,
    int tailleFenetreH,
    SDL_Renderer ** canvas);

/**
Effacer le canvas
*/
void effacerCanvas(SDL_Renderer * canvas);

/**
Gestion des évènements
*/
int gestionEvenements(SDL_Event * event);

/**
Mise à jour du canvas
*/
void majCanvas(SDL_Renderer *canvas);