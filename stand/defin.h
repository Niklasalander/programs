#ifndef defs.h
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#endif

typedef struct tm tm;

typedef struct 
{
	int firstTime, lastTime;
	int firstCount, lastCount;
	int timer, ticks, total, minutes, typeText, destTexas, destTexas2;
	int minCount, secCount;
	time_t pressed;
	tm *cPressed;
} timer;

typedef struct
{
	SDL_Rect boxes;
} boxes;

typedef struct
{
	boxes boxes[10];
	int typing;
	int length;
	char *text;
	char *genText;
} prog;

typedef struct 
{
	SDL_Texture *timeText;
	SDL_Texture *numText;
} tText;

typedef struct
{
	tText tText[10];
	tText numText[10];
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *background;
    TTF_Font *arial;
} draw;



typedef struct
{

} background;

typedef struct
{
    Mix_Music *backgroundSound;
} sound;
