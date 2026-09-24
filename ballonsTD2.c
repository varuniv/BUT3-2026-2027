#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

struct ballon { 
    SDL_Texture * texture;
    SDL_Rect position;
    float positionZ;
};

struct fabriqueBallon (SDL_Texture tabTexture[] , SDL_Rect tabPositions, int nbBallons )
{
    struct ballon tab[nbBallons];
    for(int i=0, i< nbBallons;i++){
        tab[i].texture = tabTexture[i%4];
        tab[i].position = tabPositions[i%4];
        tab[i].positionZ = 0.0;
    }
    return tab;
    

}