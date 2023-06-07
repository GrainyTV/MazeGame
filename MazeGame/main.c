#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "debugmalloc.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Generalas.h"
#include "Palya_nyomtatas.h"
#include "Eredmenykezelo.h"
#include "Egergomb.h"
#include "Egerpoz.h"
#include "Billentyuzetirany.h"
#include "Blokk.h"

int main(int argc, char **argv)
{
	//Random Ido Beallitasa
	srand(time(NULL));

	//SDL Inicializalasa
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(IMG_INIT_PNG);
	SDL_Init(SDL_INIT_AUDIO);

	//SDL Ablak Merete
	static const int width = 990;
	static const int height = 990;

	//SDL Valos Ideju Renderer Beallitasa
	SDL_Window *window = SDL_CreateWindow("A_MAZE_ING GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

	//Texturak betoltese
	SDL_Texture *mainmenu1 = IMG_LoadTexture(renderer,"textures/mainmenu_v1.png");
	SDL_Texture *mainmenu2 = IMG_LoadTexture(renderer,"textures/mainmenu_v2.png");
	SDL_Texture *mainmenu3 = IMG_LoadTexture(renderer,"textures/mainmenu_v3.png");
	SDL_Texture *mainmenu4 = IMG_LoadTexture(renderer,"textures/mainmenu_v4.png");
	SDL_Texture *diff1 = IMG_LoadTexture(renderer,"textures/diff_v1.png");
	SDL_Texture *diff2 = IMG_LoadTexture(renderer,"textures/diff_v2.png");
	SDL_Texture *diff3 = IMG_LoadTexture(renderer,"textures/diff_v3.png");
	SDL_Texture *diff4 = IMG_LoadTexture(renderer,"textures/diff_v4.png");
	SDL_Texture *diff5 = IMG_LoadTexture(renderer,"textures/diff_v5.png");
	SDL_Texture *inst1 = IMG_LoadTexture(renderer,"textures/instructions_v1.png");
	SDL_Texture *inst2 = IMG_LoadTexture(renderer,"textures/instructions_v2.png");
	SDL_Texture *victory = IMG_LoadTexture(renderer,"textures/victory_screen.png");
	SDL_Texture *pause1 = IMG_LoadTexture(renderer,"textures/pause_v1.png");
	SDL_Texture *pause2 = IMG_LoadTexture(renderer,"textures/pause_v2.png");
	SDL_Texture *pause3 = IMG_LoadTexture(renderer,"textures/pause_v3.png");
	SDL_Texture *pause4 = IMG_LoadTexture(renderer,"textures/pause_v4.png");

	//Audio betoltese
	Mix_Chunk *applause = Mix_LoadWAV("sounds/applause.wav");
	Mix_Chunk *bassdrum = Mix_LoadWAV("sounds/bassdrum.wav");
	Mix_Chunk *drippy = Mix_LoadWAV("sounds/drippy.wav");

	//Nehany egyeb valtozo a jatekhoz
	SDL_Rect dest;
	blokk(&dest,0,0,width,height);
	game_state current_screen = main_menu;
	arrow_key current_key;
	game_variables variable;
	variable.pause_menu = false;
	int x, y;
	int valto = 0;
	bool running = true;
	bool **palya = NULL;
	SDL_Event event;
	
	SDL_Event invalidate;
	invalidate.type = SDL_RegisterEvents(1);
	SDL_PushEvent(&invalidate);

	while(running)
	{
		//Jelen idoben torteno Eventek kezelese
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&x, &y);
				int valtoAtTheBeginning = valto;
				eger_pozicio(current_screen,&valto,x,y,variable.pause_menu,bassdrum);
				if(valtoAtTheBeginning != valto)
				{
					SDL_PushEvent(&invalidate);
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
				case SDL_BUTTON_LEFT:
					int currentScreenAtTheBeginning = current_screen;
					int valtoAtTheBeginning = valto;
					egergomb_megnyomas(&current_screen,&variable,x,y,&valto,&running,renderer, palya);
					if(currentScreenAtTheBeginning != current_screen || valtoAtTheBeginning != valto)
					{
						SDL_PushEvent(&invalidate);
					}
					break;
				default:
					break;
				}
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					if(current_screen == jatek && variable.pause_menu == false)
					{
						variable.pause_menu = true;
						valto = 1;
						variable.start_pause = SDL_GetTicks();
					}
					break;
				case SDLK_UP:
				case SDLK_w:
					current_key = up;
					billentyuzet_irany(current_key,&current_screen,&variable,renderer,palya,&valto,drippy,applause);
					break;
				case SDLK_LEFT:
				case SDLK_a:
					current_key = left;
					billentyuzet_irany(current_key,&current_screen,&variable,renderer,palya,&valto,drippy,applause);
					break;
				case SDLK_DOWN:
				case SDLK_s:
					current_key = down;
					billentyuzet_irany(current_key,&current_screen,&variable,renderer,palya,&valto,drippy,applause);
					break;
				case SDLK_RIGHT:
				case SDLK_d:
					current_key = right;
					billentyuzet_irany(current_key,&current_screen,&variable,renderer,palya,&valto,drippy,applause);
					break;
				default:
					if(current_screen == victory_screen)
					{
						current_screen = main_menu;
						Mix_HaltChannel(-1);
					}
					break;
				}
				SDL_PushEvent(&invalidate);
				break;
			case SDL_USEREVENT:
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderClear(renderer);

				if(current_screen == main_menu)
				{
					switch(valto)
					{
					case 0:
						SDL_RenderCopy(renderer,mainmenu1,NULL,&dest);
						break;
					case 1:
						SDL_RenderCopy(renderer,mainmenu2,NULL,&dest);
						break;
					case 2:
						SDL_RenderCopy(renderer,mainmenu3,NULL,&dest);
						break;
					case 3:
						SDL_RenderCopy(renderer,mainmenu4,NULL,&dest);
						break;
					}
				}
				else if(current_screen == inst)
				{
					switch(valto)
					{
					case 0:
						SDL_RenderCopy(renderer,inst1,NULL,&dest);
						break;
					case 1:
						SDL_RenderCopy(renderer,inst2,NULL,&dest);
						break;
					}
				}
				else if(current_screen == diff_choosing)
				{
					switch(valto)
					{
					case 0:
						SDL_RenderCopy(renderer,diff1,NULL,&dest);
						break;
					case 1:
						SDL_RenderCopy(renderer,diff2,NULL,&dest);
						break;
					case 2:
						SDL_RenderCopy(renderer,diff3,NULL,&dest);
						break;
					case 3:
						SDL_RenderCopy(renderer,diff4,NULL,&dest);
						break;
					case 4:
						SDL_RenderCopy(renderer,diff5,NULL,&dest);
						break;
					}
				}
				else if(current_screen == jatek)
				{
					switch(valto)
					{
					case 0:
						if(palya != NULL)
						{
							for(int i = 0; i < variable.hossz_prev; ++i)
							{
								free(palya[i]);
							}

							free(palya);
						}

						palya = (bool**)malloc(variable.hossz * sizeof(bool*));

						for(int i = 0; i < variable.hossz; ++i)
						{
							palya[i] = (bool*)malloc(variable.hossz * sizeof(bool));

							for(int j = 0; j < variable.hossz; ++j)
							{
								palya[i][j] = false;
							}
						}
						Generalas(variable.bekert,renderer,variable.meret,variable.hossz,palya);
						blokk(&variable.mozgathato,0,(variable.hossz*variable.meret)-(2*variable.meret),variable.meret,variable.meret);
						SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
						SDL_RenderFillRect(renderer,&variable.mozgathato);
						blokk(&variable.endpoint,(variable.hossz*variable.meret)-(1*variable.meret),variable.meret,variable.meret,variable.meret);
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						SDL_RenderFillRect(renderer,&variable.endpoint);
						variable.kezdopoz_x = 0;
						variable.kezdopoz_y = variable.mozgathato.y/variable.meret;
						variable.start_time = SDL_GetTicks();
						valto = 5;
						break;
					case 1:
						SDL_SetRenderDrawColor(renderer,165,165,200,204);
						SDL_RenderFillRect(renderer,&dest);
						SDL_RenderCopy(renderer,pause1,NULL,&dest);
						break;
					case 2:
						SDL_SetRenderDrawColor(renderer,165,165,200,204);
						SDL_RenderFillRect(renderer,&dest);
						SDL_RenderCopy(renderer,pause2,NULL,&dest);
						break;
					case 3:
						SDL_SetRenderDrawColor(renderer,165,165,200,204);
						SDL_RenderFillRect(renderer,&dest);
						SDL_RenderCopy(renderer,pause3,NULL,&dest);
						break;
					case 4:
						SDL_SetRenderDrawColor(renderer,165,165,200,204);
						SDL_RenderFillRect(renderer,&dest);
						SDL_RenderCopy(renderer,pause4,NULL,&dest);
						break;
					default:
						Palya_nyomtatas(variable.hossz, palya, renderer, variable.meret);
						SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
						SDL_RenderFillRect(renderer,&variable.mozgathato);
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						SDL_RenderFillRect(renderer,&variable.endpoint);
						break;
					}
				}
				else if(current_screen == victory_screen)
				{
					SDL_RenderCopy(renderer,victory,NULL,&dest);
				}
				
				SDL_RenderPresent(renderer);
				
				break;
			}
		}
	}

	//Texturak & Tomb felszabaditasa
	if(palya != NULL)
	{
		for(int i = 0; i < variable.hossz; ++i)
		{
			free(palya[i]);
		}
		free(palya);
	}
	Mix_FreeChunk(applause);
	Mix_FreeChunk(bassdrum);
	Mix_FreeChunk(drippy);
	SDL_DestroyTexture(mainmenu1);
	SDL_DestroyTexture(mainmenu2);
	SDL_DestroyTexture(mainmenu3);
	SDL_DestroyTexture(mainmenu4);
	SDL_DestroyTexture(diff1);
	SDL_DestroyTexture(diff2);
	SDL_DestroyTexture(diff3);
	SDL_DestroyTexture(diff4);
	SDL_DestroyTexture(inst1);
	SDL_DestroyTexture(inst2);
	SDL_DestroyTexture(pause1);
	SDL_DestroyTexture(pause2);
	SDL_DestroyTexture(pause3);
	SDL_DestroyTexture(pause4);
	SDL_DestroyTexture(victory);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
