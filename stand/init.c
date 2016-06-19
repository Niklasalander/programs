#include "defs.h"
/***** loading backgroud, sound *****/

/***** creates a window and loads background image *****/
void loadBackground(Draw *windowF)
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
void loadTimeText(Draw *timeText, newText *newText, Prog *prog, Sound *sound)
{
	//timeText->tText = (char*)malloc(100);

	timeText->arial = TTF_OpenFont("arialbd.ttf", 48);
	//TTF_Font *arial = TTF_OpenFont("arialbd.ttf", 48);
	SDL_Color black = {0, 0, 0};

	SDL_Surface *surfaceMessage;
	surfaceMessage = TTF_RenderText_Blended(timeText->arial, "15 minutes", black);
	timeText->tText[0].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(timeText->arial, "20 minutes", black);
	timeText->tText[1].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(timeText->arial, "30 minutes", black);
	timeText->tText[2].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(timeText->arial, "60 minutes", black);
	timeText->tText[3].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(timeText->arial, "set time", black);
	timeText->tText[4].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(timeText->arial, "40 minutes", black);
	timeText->tText[5].timeText = SDL_CreateTextureFromSurface(timeText->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);




   // SDL_FreeSurface(surfaceMessage);
}

/***** loads all sounds *****/
void loadSounds(Sound *sound)
{
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_VolumeMusic(16);
    sound->backgroundSound = Mix_LoadMUS("yeeeha.MP3");
}

/***** initiates variables *****/
void initVariables(Timer *timer, Prog *prog, Sound *sound)
{
    timer->ticks = 0;
    timer->timer = 0;
    timer->total = 0;
    prog->typing = 0;
    timer->firstTime = 9999999;
    timer->firstCount = 9999999;
    timer->minCount = 0;
    timer->secCount = 0;
    timer->destroyTexture = 0;
    sound->volume = 16;
}

/***** makes a test string clean *****/
void initTextString(Prog *prog)
{
    prog->text = (char*)malloc(100);
    while(strlen(prog->text)!=0)
    {
        prog->length = strlen(prog->text);
        prog->text[prog->length-1] = '\0';
    }
}

void initGenString(Prog *prog)
{
    prog->genText = (char*)malloc(100);
    while(strlen(prog->genText)!=0)
    {
        prog->length = strlen(prog->genText);
        prog->genText[prog->length-1] = '\0';
    }
}

/***** creates SDL_Rects for the boxes *****/
void initBoxes(Prog *prog)
{
    /***** first 10 boxes *****/
    int x = 100, y = 84;
    int w = 208, h = 90;
    int i;

    for (i = 0; i < 10; i++)
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
            y += 132;
        else if (i == 3)
            x -= 308;
        else if (i == 4)
            x -= 308;
        else if (i == 5)
        {
            y += 132;
            x += 75;
        }
        else if (i == 6)
            x += 150;
        else if (i == 7)
            y += 128;
        else if (i == 8)
            x -= 150;
    }

    /***** volume box *****/
    for (i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            x = 460, y = 584;
            w = 102, h = 102;            
        }
        else if (i == 1)
        {
            x = 484, y = 535;
            w = 54, h = 44;   
        }
        else 
            y = 692;
        prog->volume[i].volume.x = x;
        prog->volume[i].volume.y = y;
        prog->volume[i].volume.w = w;
        prog->volume[i].volume.h = h;
    }

    /***** stop and quit boxes *****/



    prog->genText = (char*)malloc(100);
}

void generateText(Draw *genText, Prog *prog, Timer *timer, int *firstT, int *lastT, Sound *sound, newText *newText)
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
        if (timer->destroyTexture == 1)
            SDL_DestroyTexture(genText->tText[6].timeText);
        genText->tText[6].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

    	/***** time when pressed *****/
    	sprintf(prog->genText, "time started %.2d:%.2d", timer->cPressed->tm_hour, timer->cPressed->tm_min);
    	surfaceMessage = TTF_RenderText_Solid(genText->arial, prog->genText, black);
        //  if (timer->destroyTexture == 1)
        SDL_DestroyTexture(genText->tText[7].timeText);
    	genText->tText[7].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);


    	/***** time left *****/
    	sprintf(prog->genText, "time left %.2d:%.2d", timer->minCount, timer->secCount);
    	surfaceMessage = TTF_RenderText_Solid(genText->arial, prog->genText, black);
        if (timer->destroyTexture == 1)
            SDL_DestroyTexture(genText->tText[8].timeText);
    	genText->tText[8].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

    	/***** show how long the session is *****/
    	sprintf(prog->genText, "%.2d minute session", timer->minutes);
    	surfaceMessage = TTF_RenderText_Solid(genText->arial, prog->genText, black);
        //if (timer->destroyTexture == 1)
        SDL_DestroyTexture(genText->tText[9].timeText);
    	genText->tText[9].timeText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);
    	

        /***** text for volume *****/
        sprintf(prog->genText, "%.2d", sound->volume);
        surfaceMessage = TTF_RenderText_Blended(genText->arial, prog->genText, black);
        newText->volText = SDL_CreateTextureFromSurface(genText->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);





        if (timer->destroyTexture == 0)
            timer->destroyTexture = 1;
       }
}

/***** shuts down SDL *****/
void shutDown(Draw *draw, Prog *prog)
{
	free(prog->text);
	free(prog->genText);
    TTF_CloseFont(draw->arial);
    Mix_CloseAudio();
    SDL_DestroyWindow(draw->window);
    SDL_DestroyRenderer(draw->renderer);
    SDL_Quit();
}
