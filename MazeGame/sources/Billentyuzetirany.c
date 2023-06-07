#include <stdio.h>
#include <stdbool.h>

#include "Billentyuzetirany.h"
#include "SDL.h"

void billentyuzet_irany(arrow_key current_key, game_state *current_screen, game_variables *variable, SDL_Renderer *renderer, bool **palya, int *valto, Mix_Chunk *drippy, Mix_Chunk *applause)
{
	switch(current_key)
	{
	case up:
		if(*current_screen == jatek && variable->pause_menu != true)
		{
			if(palya[variable->kezdopoz_y-1][variable->kezdopoz_x] == true)
			{
				Mix_PlayChannel(-1,drippy,0);
				variable->mozgathato.y -= variable->meret;
				variable->kezdopoz_y -= 1;
			}
		}
		break;
	case left:
		if(*current_screen == jatek && variable->pause_menu != true && variable->kezdopoz_x != 0)
		{
			if(palya[variable->kezdopoz_y][variable->kezdopoz_x-1] == true)
			{
				Mix_PlayChannel(-1,drippy,0);
				variable->mozgathato.x -= variable->meret;
				variable->kezdopoz_x -= 1;
			}
		}
		break;
	case down:
		if(*current_screen == jatek && variable->pause_menu != true)
		{
			if(palya[variable->kezdopoz_y+1][variable->kezdopoz_x] == true)
			{
				Mix_PlayChannel(-1,drippy,0);
				variable->mozgathato.y += variable->meret;
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
				variable->finish_time = SDL_GetTicks() - variable->start_time;
				variable->hossz_prev = variable->hossz;
				eredmenykezelo(variable->finish_time,variable->bekert);
				Mix_PlayChannel(-1,applause,0);	
			}
			else if(palya[variable->kezdopoz_y][variable->kezdopoz_x+1] == true)
			{
				Mix_PlayChannel(-1,drippy,0);
				variable->mozgathato.x += variable->meret;
				variable->kezdopoz_x += 1;
			}
		}
		break;
	}
}
