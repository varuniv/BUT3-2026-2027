#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

struct ballon
{
	SDL_Texture *  texture;
	SDL_Rect position;
	float positionZ;
};

typedef struct ballon ballon ;

/**
Initialisation de la fenêtre et du canvas
*/
int init(SDL_Window ** mafenetre, SDL_Renderer ** canevas, int w, int h);


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

/**
Création d'une texture à partir d'une image
*/
SDL_Texture * getTextureFromImage(const char * nomPic, SDL_Renderer * renderer);

/** 
Renvoie une chaine de caractère indiquant le chemin vers l'image appropriée 
*/
char * construireChemin(int numeroImage);