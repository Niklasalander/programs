#include "defs.h"
/***** loading backgroud, sound *****/

/***** calls all init functions *****/
void initAll(Main *main, Wind *wind, int *max)
{
    loadWindow(&*wind);
}

/***** init a new flap *****/
void initFlap(Main *main, Wind *wind, Extf *extf, int *flap, int *max)
{
    *max += 1;
    *flap = *max - 1;
    extf->newFlap = 0;
    printf("0 ");
    loadBackground(&main[*max - 1], &*wind, &*flap);
    printf("1 ");
    initVariables(&main[*max - 1]);
    printf("2 ");
    loadTimeText(&main[*max - 1], &*wind);
    printf("3 ");
    loadSounds(&main[*max - 1]);
    printf("4 ");
    initTextString(&main[*max - 1]);
    printf("5 ");
    initBoxes(&main[*max - 1]);
    printf("6 ");
    initMiniTimer(&main[*max - 1], &*wind, &*flap);
    printf("7 ");
    loadShade(&main[*max - 1], &*wind, &*flap);
    printf("8 ");
    loadChooseSound(&main[*max - 1], &*wind, &*flap);
    printf("9 ");
}

/***** creates a window and loads background image *****/
void loadWindow(Wind *wind)
{
    wind->window = SDL_CreateWindow("Stand",                            // window title
                                      SDL_WINDOWPOS_UNDEFINED,           // initial x position
                                      SDL_WINDOWPOS_UNDEFINED,           // initial y position
                                      1024,                              // width, in pixels
                                      768,                               // height, in pixels
                                      0                                  // flags
                                     );
    wind->renderer = SDL_CreateRenderer(wind->window, -1, SDL_RENDERER_ACCELERATED);
}

void loadBackground(Main *main, Wind *wind, int *flap)
{
    //printf("b1\n");
    // maybe only one renderer
    //wind->renderer = SDL_CreateRenderer(wind->window, -1, SDL_RENDERER_ACCELERATED);
    //printf("b1\n");
    SDL_Surface *background;
    printf("b1\n");
    if (*flap == 0)
    {
        printf("f1\n");
        background = IMG_Load("background768-0test.PNG");
    }
    printf("b2\n");
    if (*flap == 1)
    {
        printf("f2\n");
        background = IMG_Load("background768-1.PNG");
    }
    printf("b3\n");
    if (*flap == 2)
    {
        printf("f2\n");
        background = IMG_Load("background768-2.PNG");
    }

    //SDL_Texture *bgtexture;
    printf("b3\n");
    main->draw.background = SDL_CreateTextureFromSurface(wind->renderer, background);
    SDL_FreeSurface(background);
    printf("b4\n");
}

/***** loads miniTimer images *****/
void initMiniTimer(Main *main, Wind *wind, int *flap)
{
    SDL_Surface *miniTimer;
    if (*flap == 0)
    {
        miniTimer = IMG_Load("small-0.PNG");
    }
    if (*flap == 1)
    {
        miniTimer = IMG_Load("small-1.PNG");
    }
    if (*flap == 2)
    {
        miniTimer = IMG_Load("small-2.PNG");
    }
    main->draw.miniTimer = SDL_CreateTextureFromSurface(wind->renderer, miniTimer);
    SDL_FreeSurface(miniTimer);
}

/***** loads shade images *****/
void loadShade(Main *main, Wind *wind, int *flap)
{
    SDL_Surface *shade;
    if (*flap == 0)
    {
        for (int i = 0; i < 1; i++)
        {
            shade = IMG_Load("shade-0-0.PNG");
            main->draw.shade[0].shade = SDL_CreateTextureFromSurface(wind->renderer, shade);
            SDL_FreeSurface(shade);
        }
    }
}

void loadChooseSound(Main *main, Wind *wind, int *flap)
{
    SDL_Surface *chooseSound;
    if (*flap == 0)
    {
        chooseSound = IMG_Load("chooseSound-0.PNG");
    }
    if (*flap == 1)
    {
        chooseSound = IMG_Load("chooseSound-1.PNG");
    }
    if (*flap == 2)
    {
        chooseSound = IMG_Load("chooseSound-2.PNG");
    }
    main->draw.chooseSound = SDL_CreateTextureFromSurface(wind->renderer, chooseSound);
    SDL_FreeSurface(chooseSound);
}

/***** loads the hardcoded text for the boxes *****/
void loadTimeText(Main *main, Wind *wind)
{
	//timeText->tText = (char*)malloc(100);

	main->draw.arial = TTF_OpenFont("arialbd.ttf", 48);

	SDL_Color black = {0, 0, 0};

	SDL_Surface *surfaceMessage;
	surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "15 minutes", black);
	main->draw.tText[0].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "20 minutes", black);
	main->draw.tText[1].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "30 minutes", black);
	main->draw.tText[2].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "60 minutes", black);
	main->draw.tText[3].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "set time", black);
	main->draw.tText[4].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "40 minutes", black);
	main->draw.tText[5].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "stop", black);
	main->newText.stop = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "exit", black);
	main->newText.exit = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

   // SDL_FreeSurface(surfaceMessage);
}

/***** loads all sounds *****/
void loadSounds(Main *main)
{
    /* GÖR SÅ FLERA LJUD KAN SPELAS */
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_VolumeMusic(64);
    main->sound.backgroundSound = Mix_LoadWAV("yeeeha.WAV");
}



/***** initiates variables *****/
void initVariables(Main *main)
{
    main->timer.ticks = 0;
    main->timer.timer = 0;
    main->timer.total = 0;
    main->prog.typing = 0;
    main->timer.firstTime = 9999999;
    main->timer.firstCount = 9999999;
    main->timer.minutes = 0;
    main->timer.minCount = 0;
    main->timer.secCount = 0;
    main->timer.hPressed = 0;
    main->timer.mPressed = 0;
    main->timer.destroyTexture = 0;
    main->sound.volume = 64;
    main->prog.shadeB = 11;
}

void initExtf(Extf *extf)
{
    extf->flapF = -1000;
    extf->newFlap = 0;
}

/***** makes a test string clean *****/
void initTextString(Main *main)
{
    main->prog.text = (char*)malloc(100);
    while(strlen(main->prog.text)!=0)
    {
        main->prog.length = strlen(main->prog.text);
        main->prog.text[main->prog.length-1] = '\0';
    }
}

void initGenString(Main *main)
{
    main->prog.genText = (char*)malloc(100);
    while(strlen(main->prog.genText)!=0)
    {
        main->prog.length = strlen(main->prog.genText);
        main->prog.genText[main->prog.length-1] = '\0';
    }
}

/***** creates SDL_Rects for the boxes *****/
void initBoxes(Main *main)
{
    /***** first 10 boxes *****/
    int x = 100, y = 84;
    int w = 208, h = 90;
    int i;

    for (i = 0; i < 10; i++)
    {
        main->prog.boxes[i].boxes.x = x;
        main->prog.boxes[i].boxes.y = y;
        main->prog.boxes[i].boxes.w = w;
        main->prog.boxes[i].boxes.h = h;
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
            x += 125;
        }
        else if (i == 6)
            x += 50;
        else if (i == 7)
        {
            y += 128;
            x += 50;
        }
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
        main->prog.volume[i].volume.x = x;
        main->prog.volume[i].volume.y = y;
        main->prog.volume[i].volume.w = w;
        main->prog.volume[i].volume.h = h;
    }

    /***** stop and quit boxes *****/
    for (i = 0; i < 2; i++)
    {
    	if (i == 0)
    	{
    		x = 223, y = 604;
    		w = 164, h = 60;
    	}
    	else if (i == 1)
    		x = 636;
        main->prog.stop[i].stop.x = x;
        main->prog.stop[i].stop.y = y;
        main->prog.stop[i].stop.w = w;
        main->prog.stop[i].stop.h = h;
    }

    /***** flap switch boxes *****/
    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            x = 50, y = 619;
            w = 123, h = 100;
        }
        else if (i == 1)
            x = 849;
        main->prog.flap[i].flap.x = x;
        main->prog.flap[i].flap.y = y;
        main->prog.flap[i].flap.w = w;
        main->prog.flap[i].flap.h = h;
    }

    /***** miniTimer boxes *****/
    for (i = 0; i < 1; i++)
    {
        if (i == 0)
        {
            x = 472, y = 20;
            w = 80, h = 40;
        }
        main->prog.mini[i].mini.x = x;
        main->prog.mini[i].mini.y = y;
        main->prog.mini[i].mini.w = w;
        main->prog.mini[i].mini.h = h;
    }

    /***** choose song boxes *****/
    for (i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            x = 25, y = 368;
            w = 175, h = 40;
        }
        else if (i == 1)
        {
            y += 42;
            h = 231;
        }

        main->prog.song[i].song.x = x;
        main->prog.song[i].song.y = y;
        main->prog.song[i].song.w = w;
        main->prog.song[i].song.h = h;
    }


    main->prog.genText = (char*)malloc(100);
}

void generateText(Main *main, Wind *wind, int *firstT, int *lastT, int *test)
{
    *lastT = SDL_GetTicks();
    if (*lastT > *firstT + 10)
    {
        SDL_Color black = {0, 0, 0};
        SDL_Surface *surfaceMessage;

        time_t now;
        time(&now);
        tm *myT = localtime(&now);

        *firstT = *lastT;
        

        //time_t now = time(0);

        /***** current time *****/
        sprintf(main->prog.genText, "current time %.2d:%.2d", myT->tm_hour, myT->tm_min);
        surfaceMessage = TTF_RenderText_Solid(main->draw.arial, main->prog.genText, black);
        if (main->timer.destroyTexture == 1)
            SDL_DestroyTexture(main->draw.tText[6].timeText);
        main->draw.tText[6].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

    	/***** time when pressed *****/
    	sprintf(main->prog.genText, "time started %.2d:%.2d", main->timer.hPressed, main->timer.mPressed);
    	surfaceMessage = TTF_RenderText_Solid(main->draw.arial, main->prog.genText, black);
        if (main->timer.destroyTexture == 1)
            SDL_DestroyTexture(main->draw.tText[7].timeText);
    	main->draw.tText[7].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);


    	/***** time left *****/
    	sprintf(main->prog.genText, "time left %.2d:%.2d", main->timer.minCount, main->timer.secCount);
    	surfaceMessage = TTF_RenderText_Solid(main->draw.arial, main->prog.genText, black);
        if (main->timer.destroyTexture == 1)
            SDL_DestroyTexture(main->draw.tText[8].timeText);
    	main->draw.tText[8].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

    	/***** show how long the session is *****/
    	sprintf(main->prog.genText, "%.2d minute session", main->timer.minutes);
    	surfaceMessage = TTF_RenderText_Solid(main->draw.arial, main->prog.genText, black);
        if (main->timer.destroyTexture == 1)
            SDL_DestroyTexture(main->draw.tText[9].timeText);
    	main->draw.tText[9].timeText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);
    	

        /***** text for volume *****/
        sprintf(main->prog.genText, "%.2d", main->sound.volume);
        surfaceMessage = TTF_RenderText_Blended(main->draw.arial, main->prog.genText, black);
        if (main->timer.destroyTexture == 1)
            SDL_DestroyTexture(main->newText.volText);
        main->newText.volText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);


        if (main->timer.destroyTexture == 0)
            main->timer.destroyTexture = 1;
       }
}

void generateMiniText(Main *main, Wind *wind)
{
    SDL_Color black = {0, 0, 0};
    SDL_Surface *surfaceMessage;

    /***** miniTime left *****/
    sprintf(main->prog.genText, "%.2d:%.2d", main->timer.minCount, main->timer.secCount);
    surfaceMessage = TTF_RenderText_Solid(main->draw.arial, main->prog.genText, black);
    if (main->timer.destroyTexture == 1)
        SDL_DestroyTexture(main->draw.miniTimerT);
    main->draw.miniTimerT = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
}

void destTexture(Main *main)
{
    for (int i = 0; i < 10; i++)
        SDL_DestroyTexture(main->draw.tText[i].timeText);

    SDL_DestroyTexture(main->newText.volText);
    SDL_DestroyTexture(main->newText.stop);
    SDL_DestroyTexture(main->newText.exit);
    SDL_DestroyTexture(main->draw.miniTimerT);
}

void shutAll(Main *main, Wind *wind, int *max)
{
    printf("s1 ");
    SDL_DestroyWindow(wind->window);
    SDL_DestroyRenderer(wind->renderer);
    TTF_CloseFont(main[0].draw.arial);
    for (int i = 0; i < *max; i++)
    {
        printf("\nhorse: %d\n", i);
        shutDown(&main[i]);
    }
}

/***** shuts down SDL *****/
void shutDown(Main *main)
{
	free(main->prog.text);
    
	free(main->prog.genText);
    printf("s2 ");
    
    printf("s3 ");
    TTF_Quit();
    printf("s4 ");
    Mix_CloseAudio();
    printf("s5 ");
    Mix_FreeMusic(main->sound.backgroundSound);
    
    printf("s6 ");
    SDL_Quit();
    printf("s7 ");
}
