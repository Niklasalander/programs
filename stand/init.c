#include "defs.h"
/***** loading backgroud, sound *****/

/***** creates a window and loads background image *****/
void loadBackground(draw *windowF)
{
    windowF->window = SDL_CreateWindow("Stand",                            // window title
                                      SDL_WINDOWPOS_UNDEFINED,           // initial x position
                                      SDL_WINDOWPOS_UNDEFINED,           // initial y position
                                      1024,                              // width, in pixels
                                      768,                               // height, in pixels
                                      0                                  // flags
                                     );
    windowF->renderer = SDL_CreateRenderer(windowF->window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface *background;
    background = IMG_Load("background768.PNG");
    SDL_Texture *bgtexture;
    windowF->background = SDL_CreateTextureFromSurface(windowF->renderer,background);
    SDL_FreeSurface(background);

}

/***** loads the hardcoded text for the boxes *****/
void loadTimeText(draw *timeText)
{
	//timeText->tText = (char*)malloc(100);

	timeText->arial = TTF_OpenFont("arialbd.ttf", 48);
	//TTF_Font *arial = TTF_OpenFont("arialbd.ttf", 48);
	SDL_Color black = {0, 0, 0};

	SDL_Surface *surfaceMessage;
	surfaceMessage = TTF_RenderText_Blended(timeText->arial, "15 minutes", black);
	timeText->tText[0].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Blended(timeText->arial, "20 minutes", black);
	timeText->tText[1].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Blended(timeText->arial, "30 minutes", black);
	timeText->tText[2].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Blended(timeText->arial, "60 minutes", black);
	timeText->tText[3].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Blended(timeText->arial, "set time", black);
	timeText->tText[4].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	surfaceMessage = TTF_RenderText_Blended(timeText->arial, "40 minutes", black);
	timeText->tText[5].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);

	/***** saves numbers in text *****/
	// removed

	SDL_FreeSurface(surfaceMessage);
}

/***** loads all sounds *****/
void loadSounds(sound *sound)
{
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_VolumeMusic(16);
    sound->backgroundSound = Mix_LoadMUS("yeeeha.MP3");
}

/***** initiates variables *****/
void initVariables(timer *timer, prog *prog)
{
    timer->ticks = 0;
    timer->timer = 0;
    timer->total = 0;
    prog->typing = 0;
    timer->firstTime = 9999999;
    timer->firstCount = 9999999;
    timer->minCount = 0;
    timer->secCount = 0;
    timer->destTexas = 0;
    timer->destTexas2 = 0;
}

/***** makes a test string clean *****/
void initTextString(prog *prog)
{
    prog->text = (char*)malloc(100);
    while(strlen(prog->text)!=0)
    {
        prog->length = strlen(prog->text);
        prog->text[prog->length-1] = '\0';
    }
}

void initGenString(prog *prog)
{
    prog->genText = (char*)malloc(100);
    while(strlen(prog->genText)!=0)
    {
        prog->length = strlen(prog->genText);
        prog->genText[prog->length-1] = '\0';
    }
}

/***** creates SDL_Rects for the boxes *****/
void initBoxes(prog *prog)
{
    /** 720p 
    int x = 128, y = 80;
    int w = 256, h = 80;

    for (int i = 0; i < 10; i++)
    {
    	prog->boxes[i].boxes.x = x;
    	prog->boxes[i].boxes.y = y;
    	prog->boxes[i].boxes.w = w;
    	prog->boxes[i].boxes.h = h;
    	if (i == 0)
    		x += 384;
    	else if (i == 1)
    		x += 384;
    	else if (i == 2)
    		y += 160;
    	else if (i == 3)
    		x -= 384;
    	else if (i == 4)
    		x -= 384;
    	else if (i == 5)
    		y += 240;
    	else if (i >= 6)
    		x += 277;
    }
    **/
    int x = 100, y = 84;
    int w = 208, h = 90;

    for (int i = 0; i < 10; i++)
    {
        prog->boxes[i].boxes.x = x;
        prog->boxes[i].boxes.y = y;
        prog->boxes[i].boxes.w = w;
        prog->boxes[i].boxes.h = h;
        if (i == 0)
            x += 308;
        else if (i == 1)
            x += 308;
        else if (i == 2)
            y += 172;
        else if (i == 3)
            x -= 308;
        else if (i == 4)
            x -= 308;
        else if (i == 5)
        {
            y += 172;
            x += 75;
        }
        else if (i == 6)
            x += 150;
        else if (i == 7)
            y += 128;
        else if (i == 8)
            x -= 150;
    }

    prog->genText = (char*)malloc(100);
}

void generateText(draw *genText, prog *prog, timer *timer, int *firstT, int *lastT)
{
    SDL_Color black = {0, 0, 0};
    SDL_Surface *surfaceMessage;

    time_t now;
    time(&now);
    tm *myT = localtime(&now);

    *lastT = SDL_GetTicks();
    if (*lastT > *firstT + 10)
    {
        *firstT = SDL_GetTicks();
        initGenString(&*prog);

        //time_t now = time(0);


        /***** current time *****/
        sprintf(prog->genText, "current time %.2d:%.2d", myT->tm_hour, myT->tm_min);
        surfaceMessage = TTF_RenderText_Solid(genText->arial, prog->genText, black);
        if (timer->destTexas == 1)
            SDL_DestroyTexture(genText->tText[6].timeText);
        genText->tText[6].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

    	/***** time when pressed *****/
    	sprintf(prog->genText, "time started %.2d:%.2d", timer->cPressed->tm_hour, timer->cPressed->tm_min);
    	surfaceMessage = TTF_RenderText_Solid(genText->arial, prog->genText, black);
        //  if (timer->destTexas == 1)
        SDL_DestroyTexture(genText->tText[7].timeText);
    	genText->tText[7].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);


    	/***** time left *****/
    	sprintf(prog->genText, "time left %.2d:%.2d", timer->minCount, timer->secCount);
    	surfaceMessage = TTF_RenderText_Solid(genText->arial, prog->genText, black);
        if (timer->destTexas == 1)
            SDL_DestroyTexture(genText->tText[8].timeText);
    	genText->tText[8].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

    	/***** show how long the session is *****/
    	sprintf(prog->genText, "%.2d minute session", timer->minutes);
    	surfaceMessage = TTF_RenderText_Solid(genText->arial, prog->genText, black);
        //if (timer->destTexas == 1)
        SDL_DestroyTexture(genText->tText[9].timeText);
    	genText->tText[9].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);
    	

        if (timer->destTexas == 0)
            timer->destTexas = 1;
       }
}

/***** shuts down SDL *****/
void shutDown(draw *draw, prog *prog)
{
	free(prog->text);
	free(prog->genText);
    TTF_CloseFont(draw->arial);
    Mix_CloseAudio();
    SDL_DestroyWindow(draw->window);
    SDL_DestroyRenderer(draw->renderer);
    SDL_Quit();
}
