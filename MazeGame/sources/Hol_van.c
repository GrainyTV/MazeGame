#include <stdio.h>
#include <stdbool.h>
#include "Hol_van.h"

void Hol_van(int x, int y, int meret, int *szomszedos_cellak, bool **palya)
{
	if(y > 1)
	{
		switch(*(szomszedos_cellak + (y-2)*meret + x))
		{
		case 0:
			*(szomszedos_cellak + (y-2)*meret + x) = 1;
			break;
		default:
			break;
		}
	}

	if(y < meret-2)
	{
		switch(*(szomszedos_cellak + (y+2)*meret + x))
		{
		case 0:
			*(szomszedos_cellak + (y+2)*meret + x) = 1;
			break;
		default:
			break;
		}
	}

	if(x > 1)
	{
		switch(*(szomszedos_cellak + y*meret + (x-2)))
		{
		case 0:
			*(szomszedos_cellak + y*meret + (x-2)) = 1;
			break;
		default:
			break;
		}
	}

	if(x < meret-2)
	{
		switch(*(szomszedos_cellak + y*meret + (x+2)))
		{
		case 0:
			*(szomszedos_cellak + y*meret + (x+2)) = 1;
			break;
		default:
			break;
		}
	}

	*(szomszedos_cellak + y*meret + x) = 3;
	palya[y][x] = true;
}
