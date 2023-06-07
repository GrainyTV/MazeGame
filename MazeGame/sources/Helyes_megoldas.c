#include <stdio.h>
#include <stdbool.h>

#include "Helyes_megoldas.h"
#include "Hol_van.h"
#include "Randomszam.h"
#include "Atalakitas.h"

void Helyes_megoldas(int meret, bool **palya, int *szomszedos_cellak)
{
	for(int i = 0; i < meret; ++i)
	{
		for(int j = 0; j < meret; ++j)
		{
			if(i == 0 || i == meret-1)
			{
				*(szomszedos_cellak + i*meret + j) = 2;
			}
			else if(j == 0 || j == meret-1)
			{
				*(szomszedos_cellak + i*meret + j) = 2;
			}
		}
	}

	int szomszedos_cellakdb = 0;
	int x = 1;
	int y = meret-2;
	*(szomszedos_cellak + y*meret + x) = 1;

	do
	{
		szomszedos_cellakdb = 0;
		Hol_van(x,y,meret,szomszedos_cellak,palya);

		for(int i = 1; i < meret-1; ++i)
		{
			for(int j = 1; j < meret-1; ++j)
			{
				if(*(szomszedos_cellak + i*meret + j) == 1)
				{
					++szomszedos_cellakdb;
				}
			}
		}

		int random;
		if(szomszedos_cellakdb > 0)
		{
			random = Randomszam(1,szomszedos_cellakdb);
		}
		int n = 0;

		for(int i = 1; i < meret-1; ++i)
		{
			for(int j = 1; j < meret-1; ++j)
			{
				if(*(szomszedos_cellak + i*meret + j) == 1)
				{
					++n;
					if(n == random)
					{
						y = i;
						x = j;
						Atalakitas(x,y,meret,szomszedos_cellak, palya);
						break;
					}
				}
			}
		}

		if(szomszedos_cellakdb == 0)
		{
			palya[meret-2][0] = true;
			palya[1][meret-1] = true;
		}

	}while(szomszedos_cellakdb > 0);
}
