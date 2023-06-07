#include <stdio.h>
#include <stdlib.h>

#include "Egergomb.h"
#include "Palya_nyomtatas.h"

void egergomb_megnyomas(game_state *current_screen, game_variables *variable, int x, int y, int *valto, bool *running, SDL_Renderer *renderer, bool **palya)
{
	if(*current_screen == main_menu)
	{
		if(x >= 375 && x <= 375+250 && y >= 400 && y <= 400+90)
		{
			*current_screen = diff_choosing;
			*valto = 0;
		}
		else if(x >= 150 && x <= 150+690 && y >= 495 && y <= 495+85)
		{
			*current_screen = inst;
			*valto = 0;
		}
		else if(x >= 385 && x <= 385+225 && y >= 590 && y <= 590+85)
		{
			*running = false;
		}
	}
	else if(*current_screen == inst)
	{
		if(x >= 360 && x <= 360+270 && y >= 700 && y <= 700+85)
		{
			*current_screen = main_menu;
			*valto = 0;
		}
	}
	else if(*current_screen == diff_choosing)
	{
		if(x >= 365 && x <= 365+255 && y >= 355 && y <= 355+85)
		{
			*valto = 0;
			variable->bekert = 1;
			variable->meret = 30;
			variable->hossz = 33;
			*current_screen = jatek;
		}
		else if(x >= 305 && x <= 305+385 && y >= 445 && y <= 445+85)
		{
			*valto = 0;
			variable->bekert = 2;
			variable->meret = 10;
			variable->hossz = 99;
			*current_screen = jatek;
		}
		else if(x >= 365 && x <= 365+270 && y >= 540 && y <= 540+85)
		{
			*valto = 0;
			variable->bekert = 3;
			variable->meret = 6;
			variable->hossz = 165;
			*current_screen = jatek;
		}
		else if(x >= 365 && x <= 365+270 && y >= 705 && y <= 705+85)
		{
			*valto = 0;
			*current_screen = main_menu;
		}
	}
	else if(*current_screen == jatek)
	{
		if(x >= 305 && x <= 305+380 && y >= 500 && y <= 500+66 && variable->pause_menu)
		{
			variable->hossz_prev = variable->hossz;
			*current_screen = main_menu;
			*valto = 0;
			variable->pause_menu = false;
		}
		else if(x >= 415 && x <= 415+166 && y >= 570 && y <= 570+62 && variable->pause_menu)
		{
			*running = false;
		}
		else if(x >= 400 && x <= 400+190 && y >= 635 && y <= 635+64 && variable->pause_menu)
		{
			*valto = 5;
			variable->pause_menu = false;
			variable->finish_pause = SDL_GetTicks()-variable->start_pause;
			variable->start_time += variable->finish_pause;
		}
	}
	else if(*current_screen == victory_screen)
	{
		*current_screen = main_menu;
	}
}
