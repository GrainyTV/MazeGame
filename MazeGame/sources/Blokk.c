#include <stdio.h>

#include "SDL.h"
#include "Blokk.h"

void blokk(SDL_Rect *rectangle, int kezdopoz_x, int kezdopoz_y, int width, int height)
{
    rectangle->x = kezdopoz_x;
    rectangle->y = kezdopoz_y;
    rectangle->w = width;
    rectangle->h = height;
}
