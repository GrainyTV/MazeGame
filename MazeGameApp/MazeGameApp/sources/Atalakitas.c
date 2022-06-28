#include <stdio.h>
#include <stdbool.h>
#include "Atalakitas.h"

void Atalakitas(int x, int y, int meret, int *szomszedos_cellak, bool **palya)
{
    int n = 0;

    if(y != 1 && n == 0)
    {
        switch(*(szomszedos_cellak + (y-2)*meret + x))
        {
        case 3:
            palya[(y-2+y)/2][x] = true;
            //*(palya + ((y-2+y)/2)*meret + x) = true;
            ++n;
            break;
        default:
            break;
        }
    }

    if(y != meret-2 && n == 0)
    {
        switch(*(szomszedos_cellak + (y+2)*meret + x))
        {
        case 3:
            palya[(y+2+y)/2][x] = true;
           // *(palya + ((y+2+y)/2)*meret + x) = true;
            ++n;
            break;
        default:
            break;
        }
    }

    if(x != 1 && n == 0)
    {
       switch(*(szomszedos_cellak + y*meret + (x-2)))
       {
       case 3:
           palya[y][(x-2+x)/2] = true;
           // *(palya + y*meret + ((x-2+x)/2)) = true;
            ++n;
            break;
       default:
            break;

       }
    }

    if(x != meret-2 && n == 0)
    {
        switch(*(szomszedos_cellak + y*meret + (x+2)))
        {
        case 3:
            palya[y][(x+2+x)/2] = true;
            //*(palya + y*meret + ((x+2+x)/2)) = true;
            ++n;
            break;
        default:
            break;
        }
    }
}
