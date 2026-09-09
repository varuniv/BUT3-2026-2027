/**

	Ce code est fourni dans le cadre de la ressource R5.04 Qualité Algorithmique du BUT3 informatique à l'IUT d'Orléans.

	Auteur: José Martins
	Contributeur: Noël Gillet

	## Dépendance
	
	Il faut installer la SDL2

	Sous ubuntu/debian: sudo apt-get install libsdl2-dev

	## Compilation

	gcc -Wall droites.c utils.c defs.h -o droites $(sdl2-config --cflags --libs) -lSDL2 -lm

	## Affichage

	Le programme est sensé afficher un carré en rotation autour de son centre

*/

#include <SDL2/SDL_render.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "utils.h"
#include "defs.h"


int main() 
{
	SDL_Window * mafenetre; 		// Fenêtre du programme
	SDL_Event event; 			    // Structure pour gérer les évènements clavier, souris, joystick
	SDL_Renderer * canvas;		// Canvas
		
	if(init(&mafenetre, tailleFenetreW,tailleFenetreH,&canvas)){
		printf("Problème d'initialisation %s\n", SDL_GetError());
        exit(1);
	}

	if(!mafenetre ){
    printf("Impossible d'initialiser la fenêtre: %s\n", SDL_GetError());
        exit(1);
	}

	// canvas = SDL_CreateRenderer(mafenetre, -1, 0);

	if(!canvas){
    printf("Impossible d'initialiser le canvas: %s\n", SDL_GetError());
        exit(1);
	}

	int fin = 0;

	// Calcule des coordonnées du centre de la fenêtre, qui sera également le centre du carré
	int centreX = (tailleFenetreW / 2);
	int centreY = (tailleFenetreH / 2);

	printf("centre: (%d,%d)",centreX,centreY);

	// Définitions des variables utilisées pour le calcul de la position du carré
	float inc = (3.14 * 2) / 360; // on ferra pivoter le carré d'un degré à chaque rafraîchissement.
	float a = 0;                  // angle actuel

	// Début de la boucle principale
	while (!fin) 
	{
		// Initialisation du compteur de FPS
		Uint64 start = SDL_GetPerformanceCounter();
		
		// Effacement du canvas
		effacerCanvas(canvas);

		// Gestion des événements
		fin = gestionEvenements(&event);
		
		// Changement de la couleur de dessin
		SDL_SetRenderDrawColor(canvas,120,
			120,
			120,
			SDL_ALPHA_OPAQUE);
		
		// Re-calcul des nouvelles positions des côtés du carré
		// On dessine un carré de taille 150 pixels
		for (int i = 0; i < 4; i++)
		{
			float x1 = centreX + 150 * sin(a + (inc * 90 * i));
			float y1 = centreY + 150 * cos(a + (inc * 90 * i));
			float x2 = centreX + 150 * sin(a + (inc * 90 * (i+1)));
			float y2 = centreY + 150 * cos(a + (inc * 90 * (i+1)));

			SDL_RenderDrawLine(canvas,x1,y1,x2,y2);	
			
			/** VOTRE CODE ICI **/

			
		}

		a += inc;
		if (a > 3.14 * 2) a = 0;

		// Mise à jour de l'affichage
		// majCanvas(renderer);
		SDL_RenderPresent(canvas);

		
		// Mise à jour du compteur de FPS
		// Vertical sync => Attente 60 fps
		Uint64 end= SDL_GetPerformanceCounter() ;
		float elapseTime = (end - start) / 1000000000.f;		
		while(1.0f / elapseTime > 60)
		{
			end= SDL_GetPerformanceCounter() ;
			elapseTime = (end - start) / 1000000000.f;				
		}
	}

	SDL_DestroyRenderer(canvas);
	SDL_DestroyWindow(mafenetre);
	SDL_Quit();
	exit(0);
}
