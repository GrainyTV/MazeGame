#include <stdio.h>
#include <stdbool.h>

#include "Generalas.h"
#include "Helyes_megoldas.h"
#include "Palya_nyomtatas.h"
#include "SDL.h"
#include "debugmalloc.h"

void Generalas(int nehezseg, SDL_Renderer *renderer, int falvastagsag, int meret, bool** palya)
{
	int *szomszedos_cellak = (int*)calloc(meret*meret, sizeof(int));
	Helyes_megoldas(meret, palya, szomszedos_cellak);
	Palya_nyomtatas(meret, palya, renderer, falvastagsag);
	free(szomszedos_cellak);
}
