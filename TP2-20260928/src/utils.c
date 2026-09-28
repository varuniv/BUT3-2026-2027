#include "utils.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

int init(SDL_Window ** mafenetre, 
    SDL_Renderer ** canvas,  
    int tailleFenetreW, 
    int tailleFenetreH)
{
	int res=0;
	// On commence par initialiser l'application en changeant les modules qui nous serons nécessaires
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Impossible d'initialiser la SDL: %s\n", SDL_GetError());
        exit(1);
    }

	// on crée la fenêtre et le canvas (le renderer)
	// SDL_CreateWindowAndRenderer(tailleFenetreW,
	// 	tailleFenetreH, 
	// 	SDL_WINDOW_SHOWN,
	// 	&mafenetre,
	// 	&canvas);



	*mafenetre = SDL_CreateWindow("Carré", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		tailleFenetreW, 
		tailleFenetreH, 
		0);

	if(!*mafenetre ){
    printf("Impossible d'initialiser la fenêtre: %s\n", SDL_GetError());
        exit(1);
	}

	*canvas = SDL_CreateRenderer(*mafenetre, -1, 0);

	if(!*canvas){
    printf("Impossible d'initialiser le canvas: %s\n", SDL_GetError());
        exit(1);
	}

	effacerCanvas(*canvas);
	return res;
}


void effacerCanvas(SDL_Renderer * canvas){
    SDL_SetRenderDrawColor(canvas,0,0,0,255);
    SDL_RenderClear(canvas);
}

int gestionEvenements(SDL_Event * event){
    int fin = 0;
    if (SDL_PollEvent(event)) 
		{ 												// Scrute sans cesse les evenements et renvoie 1
			switch (event->type) 
			{
				case SDL_QUIT: 			// Evenement fermeture de la fenetre
				fin=1;
				break;
				
				case SDL_KEYDOWN:
                if(event->key.keysym.sym == SDLK_ESCAPE) fin = 1;					
				break;
			}
		}
    return fin;
}

void majCanvas(SDL_Renderer *canvas){
    SDL_RenderPresent(canvas);
}

SDL_Texture * getTextureFromImage(const char * nomPic, SDL_Renderer * renderer)
{
	SDL_Surface * image = IMG_Load(nomPic);
	if(!image)
	{
		printf("Erreur de chargement de l'image : %s",SDL_GetError());
		return NULL;
	}
	
	SDL_Texture * texSprite=SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	return texSprite;
}

/** renvoie une chaine de caractère indiquant le chemin vers l'image appropriée */
char * construireChemin(int numeroImage){
	int l = strlen("img/ball_")+1+strlen(".png");
	char *chemin = malloc(sizeof(char)*l);
	strcpy(chemin, "img/ball_");
	char num[2];
	num[0] = '1'+numeroImage;
	num[1] = '\0';
	strcat(chemin,num);
	strcat(chemin,".png");
	return chemin;
}