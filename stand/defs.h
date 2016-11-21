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
	SDL_Rect stop;
	SDL_Rect volume;
	SDL_Rect flap;
	SDL_Rect mini;
	SDL_Rect newFlap;
	SDL_Rect song;
	SDL_Rect songlist;
	bool boxesH;
	bool stopH;
	bool volumeH;
	bool flapH;
	bool miniH;
	bool newFlapH;
	bool songH;
} Boxes;

typedef struct
{
	Boxes boxes[10];
	Boxes stop[2];
	Boxes volume[3];
	Boxes flap[2];
	Boxes mini[11];
	Boxes newFlap;
	Boxes song[6];
	Boxes boxesH[6];
	Boxes stopH[2];
	Boxes volumeH[2];
	Boxes flapH[2];
	Boxes miniH[11];
	Boxes newFlapH;
	Boxes songH[6];
	Boxes songlist;

	int shadeB;
	int shadeQ;
	int shadeV;
	int shadeF;
	int shadeS;
	int shadeN;
	int shadeM;
	int test;

	int typing;
	int length;
	char *text;
	char *genText;
} Prog;

typedef struct
{
	SDL_Texture *timeText;
	SDL_Texture *numText;
	SDL_Texture *shade;
	SDL_Texture *dBoxes;
	SDL_Texture *sBoxes;
	SDL_Texture *miniTimerS;
	SDL_Texture *songlist;
} Text;

typedef struct
{
	SDL_Texture *volText;
	SDL_Texture *stop;
	SDL_Texture *exit;
	SDL_Texture *newFlap;
} newText;

typedef struct
{
	Text tText[10];
	Text numText[10];
	Text shade[8];
	Text dBoxes[9];
	Text sBoxes[9];
	Text miniTimerS[9];
	Text songlist[4];
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
	int volume, currSound;
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
	int deltaTimeMs;
	int deltaTimeS;
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