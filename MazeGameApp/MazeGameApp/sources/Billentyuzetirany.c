#include <stdio.h>
#include <stdbool.h>

#include "Billentyuzetirany.h"
#include "SDL.h"

void billentyuzet_irany(arrow_key current_key, game_state *current_screen, game_variables *variable, SDL_Renderer *renderer, bool **palya, int *valto, Mix_Chunk *drippy)
{
    switch(current_key)
    {
    case up:
        if(*current_screen == jatek && variable->pause_menu != true)
        {
            if(palya[variable->kezdopoz_y-1][variable->kezdopoz_x] == true)//*(palya + (variable->kezdopoz_y-1)*variable->hossz + variable->kezdopoz_x) == true)
            {
                Mix_PlayChannel(-1,drippy,0);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->mozgathato.y -= variable->meret;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->kezdopoz_y -= 1;
            }
        }
        break;
    case left:
        if(*current_screen == jatek && variable->pause_menu != true && variable->kezdopoz_x != 0)
        {
            if(palya[variable->kezdopoz_y][variable->kezdopoz_x-1] == true)//*(palya + variable->kezdopoz_y*variable->hossz + variable->kezdopoz_x-1) == true)
            {
                Mix_PlayChannel(-1,drippy,0);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->mozgathato.x -= variable->meret;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->kezdopoz_x -= 1;
            }
        }
        break;
    case down:
        if(*current_screen == jatek && variable->pause_menu != true)
        {
            if(palya[variable->kezdopoz_y+1][variable->kezdopoz_x] == true)//*(palya + (variable->kezdopoz_y+1)*variable->hossz + variable->kezdopoz_x) == true)
            {
                Mix_PlayChannel(-1,drippy,0);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->mozgathato.y += variable->meret;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->kezdopoz_y += 1;
            }
        }
        break;
    case right:
        if(*current_screen == jatek && variable->pause_menu != true)
        {
            if(variable->kezdopoz_y == 1 && variable->kezdopoz_x == variable->hossz-2)
            {
                *valto = 0;
                *current_screen = victory_screen;
            }
            else if(palya[variable->kezdopoz_y][variable->kezdopoz_x+1] == true)//*(palya + variable->kezdopoz_y*variable->hossz + variable->kezdopoz_x+1) == true)
            {
                Mix_PlayChannel(-1,drippy,0);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->mozgathato.x += variable->meret;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer,&variable->mozgathato);
                variable->kezdopoz_x += 1;

            }
        }
        break;
    }
}
