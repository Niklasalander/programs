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
	int timer, ticks, total, minutes, typeText, destroyTexture;
	int minCount, secCount;
	time_t pressed;
	tm *cPressed;
} Timer;

typedef struct
{
	SDL_Rect boxes;
	SDL_Rect volume;
	SDL_Rect stop;
	SDL_Rect next;
} Boxes;

typedef struct
{
	Boxes boxes[10];
	Boxes volume[3];
	Boxes stop[2];
	Boxes next[2];
	int typing;
	int length;
	char *text;
	char *genText;
} Prog;

typedef struct
{
	SDL_Texture *timeText;
	SDL_Texture *numText;
} Text;

typedef struct
{
	SDL_Texture *volText;
} newText;

typedef struct
{
	Text tText[10];
	Text numText[10];
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *background;
	TTF_Font *arial;
} Draw;

typedef struct
{
	Mix_Music *backgroundSound;
	int volume;
} Sound;
