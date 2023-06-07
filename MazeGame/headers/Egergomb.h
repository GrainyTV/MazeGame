#ifndef EGERGOMB_INCLUDED
#define EGERGOMB_INCLUDED
#include <stdbool.h>
#include "SDL.h"
#include "Egerpoz.h"

void egergomb_megnyomas(game_state *current_screen, game_variables *variable, int x, int y, int *valto, bool *running, SDL_Renderer *renderer, bool **palya);

#endif // EGERGOMB_INCLUDED
