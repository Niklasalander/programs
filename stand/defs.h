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
	int hPressed, mPressed;
	time_t pressed;
	tm *cPressed;
} Timer;

typedef struct
{
	SDL_Rect boxes;
	SDL_Rect volume;
	SDL_Rect stop;
	SDL_Rect flap;
	SDL_Rect mini;
	SDL_Rect newFlap;
	SDL_Rect song;
	bool boxesH;
	bool volumeH;
	bool stopH;
	bool flapH;
	bool miniH; // click mini to change flap
	bool newFlapH;
	bool songH;
} Boxes;

typedef struct
{
	Boxes boxes[10];
	Boxes volume[3];
	Boxes stop[2];
	Boxes flap[2];
	Boxes mini[10];
	Boxes song[6];
	Boxes boxesH[6];
	Boxes volumeH[2];
	Boxes stopH[2];
	Boxes flapH[2];
	Boxes miniH[10]; // click mini to change flap
	Boxes songH[6];

	int shadeB;


	int typing;
	int asdeerqqwec;
	int length;
	char *text;
	char *genText;
} Prog;

typedef struct
{
	SDL_Texture *timeText;
	SDL_Texture *numText;
	SDL_Texture *shade;
} Text;

typedef struct
{
	SDL_Texture *volText;
	SDL_Texture *stop;
	SDL_Texture *exit;
} newText; // put this in Draw;

typedef struct
{
	
	Text tText[10];
	Text numText[10];
	Text shade[8];
	SDL_Texture *background;
	SDL_Texture *miniTimer;
	SDL_Texture *miniTimerT;
	SDL_Texture *chooseSound;
	SDL_Texture *chooseSoundT;
	TTF_Font *arial;
} Draw;

typedef struct
{
	Mix_Music *backgroundSound;
	int volume;
} Sound;

typedef struct
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} Wind;

typedef struct
{
	int flapF;
	int flapL;
	int newFlap;
} Extf;

typedef struct
{
    Timer timer;
    Prog prog;
    newText newText;
    Draw draw;
    Sound sound;
    int max;
	int asdqwe;
} Main;