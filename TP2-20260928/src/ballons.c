/*
	Code fourni dans le cadre de la ressource R5.04 Qualité algo

	Auteurs: Noël Gillet, d'après le code de José Martins

	## Dépendance
	
	Sur votre machine personnelle, il faut installer la SDL2

	Sous ubuntu/debian: sudo apt-get install libsdl2-dev libsdl2-image-dev

	## Compilation

	make 

	ou

	gcc -Wall ballons.c utils.c defs.h -o ballons $(sdl2-config --cflags --libs) -lSDL2 -lSDL2-image -lm

	## Affichage

	Le programme est sensé afficher des ballons qui rebondissent sur les bords de la fenêtre
*/

#include <SDL2/SDL_main.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

#include "defs.h"
#include "utils.h"

#define X 0
#define Y 1
#define Z 2

int indiceTexture(int z,int nbTextures, int zMax){
	return z/(ceil((float)zMax/(float)nbTextures));
}


int main(int argc, char *argv[]) 
{
	int nbBallons = 8; // valeur par défaut
	if (argc >1){
		int arg = atoi(argv[1]);
		if (arg>0) {
			nbBallons = arg;
		}
	}

	SDL_Window * mafenetre; 		// Fenetre du programme
	SDL_Event event; 					// Structure pour gerer les evenements clavier, souris, joystick
	SDL_Renderer * canevas;		// Canvas
		
	init(&mafenetre,&canevas,tailleFenetreW,tailleFenetreH);

	/* Initialisation des ballons */

	// Import des textures
	int nbTextures = 4;
	SDL_Texture * texturesBallons[nbTextures];
	
	for(int i=0;i<nbTextures;i++){
		char *cheminVersImage = construireChemin(i);
		texturesBallons[i] = getTextureFromImage(cheminVersImage, canevas);
		free(cheminVersImage);
	}

	// Placement des ballons
	int zMax = 1023;
	struct ballon tabBalls[nbBallons];
	for (int i = 0; i < nbBallons; i++)
	{
		int z = (rand() % zMax);
		tabBalls[i].positionZ = z;
		tabBalls[i].texture = texturesBallons[indiceTexture(z, nbTextures, zMax)];
		tabBalls[i].position.w = 64;	
		tabBalls[i].position.h = 64;
		tabBalls[i].position.x = (rand() % tailleFenetreW);
		tabBalls[i].position.y = (rand() % tailleFenetreH) ;
	}

	// les vecteurs vitesse associés à chaque ballon
	int vecteurs[nbBallons][2];
	for(int i=0;i<nbBallons;i++){
		for (int d=0;d<2;d++){
			vecteurs[i][d] = ((rand() % 2) == 0) ? -1: 1 ;
		}
	}

	/* Boucle principale */

	int fin = 0;
	while (!fin) 
	{
		effacerCanvas(canevas);
		
		fin = gestionEvenements(&event);	

		/* Déplacements des ballons */
		for (int sommet = 0; sommet < nbBallons; sommet ++)
		{	
			// déplacement en x
			int xx = tabBalls[sommet].position.x + vecteurs[sommet][X];
			// si x est croissant, on doit prendre en compte la largeur de l'objet à afficher
			// afin de détecter la collision avec le bord "droit" (ayant pour abscisse tailleFenetreW)
			if(vecteurs[sommet][X] == 1){ 
				xx += tabBalls[sommet].position.w;
			}
			// on teste s'il y a collision avec un bord
			if(xx > tailleFenetreW || xx < 0){
				// si c'est le cas on change de direction
				vecteurs[sommet][X] *= -1;
			}
			tabBalls[sommet].position.x += vecteurs[sommet][X];

			// déplacement en y
			int yy = tabBalls[sommet].position.y + vecteurs[sommet][Y];
			// si y est croissant, on doit prendre en compte la hauteur de l'objet à afficher
			// afin de détecter la collision avec le bord "bas" (ayant pour ordonnée tailleFenetreH)
			if(vecteurs[sommet][Y] == 1){
				yy += tabBalls[sommet].position.h ;
			}
			// on teste s'il y a collision avec un bord
			if (yy < 0 || yy > tailleFenetreH ){
				// si c'est le cas on change de direction
				vecteurs[sommet][Y] *= -1;
			}
			tabBalls[sommet].position.y += vecteurs[sommet][Y];
		}
		
		
		/*
			Affichage des ballons
		*/
		for (int sommet = 0; sommet < nbBallons; sommet++)
		{
			SDL_RenderCopy(canevas, tabBalls[sommet].texture,NULL,&tabBalls[sommet].position);			
		}

		SDL_RenderPresent(canevas);
		SDL_Delay(5);
	}
	
	SDL_DestroyRenderer(canevas);
	SDL_DestroyWindow(mafenetre);
	SDL_Quit();
	exit(0);
}