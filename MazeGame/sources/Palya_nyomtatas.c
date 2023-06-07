#include <stdio.h>
#include <stdbool.h>

#include "Palya_nyomtatas.h"
#include "SDL.h"
#include "debugmalloc.h"

void Palya_nyomtatas(int meret, bool **palya, SDL_Renderer *renderer, int falvastagsag)
{
	int magassag = 0;

	for(int i = 0; i < meret; ++i)
	{
		int szelesseg = 0;

		for(int j = 0; j < meret; ++j)
		{
			SDL_Rect fal;
			fal.x = j+szelesseg;
			fal.y = i+magassag;
			fal.w = falvastagsag;
			fal.h = falvastagsag;

			if(palya[i][j] == false)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderFillRect(renderer, &fal);
				szelesseg += falvastagsag-1;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderFillRect(renderer, &fal);
				szelesseg += falvastagsag-1;
			}
		}
		
		magassag += falvastagsag-1;
	}
}
