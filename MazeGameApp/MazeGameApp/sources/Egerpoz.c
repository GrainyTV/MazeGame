#include <stdio.h>
#include <stdbool.h>

#include "Egerpoz.h"
#include "SDL_mixer.h"

void eger_pozicio(game_state current_screen, int *valto, int x, int y, bool pause_menu, Mix_Chunk *bassdrum)
{
    switch(current_screen)
    {
    case main_menu:
        if(x >= 375 && x <= 375+250 && y >= 400 && y <= 400+90)
        {
            if(*valto != 1)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 1;
        }
        else if(x >= 150 && x <= 150+690 && y >= 495 && y <= 495+85)
        {
            if(*valto != 2)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 2;
        }
        else if(x >= 385 && x <= 385+225 && y >= 590 && y <= 590+85)
        {
            if(*valto != 3)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 3;
        }
        else
        {
            *valto = 0;
        }
        break;
    case inst:
        if(x >= 360 && x <= 360+270 && y >= 700 && y <= 700+85)
        {
            if(*valto != 1)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 1;
        }
        else
        {
            *valto = 0;
        }
        break;
    case diff_choosing:
        if(x >= 365 && x <= 365+255 && y >= 355 && y <= 355+85)
        {
            if(*valto != 1)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 1;
        }
        else if(x >= 305 && x <= 305+385 && y >= 445 && y <= 445+85)
        {
            if(*valto != 2)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 2;
        }
        else if(x >= 365 && x <= 365+270 && y >= 540 && y <= 540+85)
        {
            if(*valto != 3)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 3;
        }
        else if(x >= 365 && x <= 365+270 && y >= 705 && y <= 705+85)
        {
            if(*valto != 4)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 4;
        }
        else
        {
            *valto = 0;
        }
        break;
    case jatek:
        if(x >= 305 && x <= 305+380 && y >= 500 && y <= 500+66 && pause_menu)
        {
            if(*valto != 2)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 2;
        }
        else if(x >= 415 && x <= 415+166 && y >= 570 && y <= 570+62 && pause_menu)
        {
            if(*valto != 3)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 3;
        }
        else if(x >= 400 && x <= 400+190 && y >= 635 && y <= 635+64 && pause_menu)
        {
            if(*valto != 4)
            {
                Mix_PlayChannel(-1,bassdrum,0);
            }
            *valto = 4;
        }
        else if(pause_menu)
        {
            *valto = 1;
        }
        break;
    case victory_screen:
    default:
        break;
    }
}
