#ifndef EGERPOZ_INCLUDED
#define EGERPOZ_INCLUDED
#include "SDL.h"
#include "SDL_mixer.h"

typedef enum
{
    main_menu,
    inst,
    diff_choosing,
    jatek,
    victory_screen
}game_state;

typedef enum
{
    up,
    left,
    down,
    right
}arrow_key;

typedef struct
{
    int kezdopoz_x, kezdopoz_y;
    int start_time, finish_time;
    int start_pause, finish_pause;
    int bekert;
    int meret;
    int hossz;
    int hossz_prev;
    bool pause_menu;
    SDL_Rect mozgathato;
    SDL_Rect endpoint;
}game_variables;

void eger_pozicio(game_state current_screen, int *valto, int x, int y, bool pause_menu, Mix_Chunk *bassdrum);

#endif // EGERPOZ_INCLUDED
