#ifndef BILLENTYUZETIRANY_INCLUDED
#define BILLENTYUZETIRANY_INCLUDED
#include "SDL.h"
#include "SDL_mixer.h"
#include "Egerpoz.h"

void billentyuzet_irany(arrow_key current_key, game_state *current_screen, game_variables *variable, SDL_Renderer *renderer, bool **palya, int *valto, Mix_Chunk *drippy);

#endif // BILLENTYUZETIRANY_INCLUDED
