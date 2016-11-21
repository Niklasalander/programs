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
    
    loadBackground(&main[*max - 1], &*wind, &*flap);
    
    initVariables(&main[*max - 1]);
    
    loadTimeText(&main[*max - 1], &*wind);
    
    loadSounds(&main[*max - 1], &*flap);
    
    initTextString(&main[*max - 1]);

    initBoxes(&main[*max - 1]);

    initMiniTimer(&main[*max - 1], &*wind, &*flap);

    loadShade(&main[*max - 1], &*wind, &*flap);

    loadChooseSound(&main[*max - 1], &*wind, &*flap);

    loadBoxPics(&main[*max - 1], &*wind, &*flap);

    loadShadePics(&main[*max - 1], &*wind, &*flap);

    initMiniTimerS(&main[*max - 1], &*wind, &*flap);
}

/***** creates a window and loads background image *****/
void loadWindow(Wind *wind)
{
    wind->window = SDL_CreateWindow("Stand",                             // window title
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
    SDL_Surface *background;
    if (*flap == 0)
        background = IMG_Load("images/background768-0.PNG");
    
    if (*flap == 1)
        background = IMG_Load("images/background768-1.PNG");
    
    if (*flap == 2)
        background = IMG_Load("images/background768-2.PNG");
    
    if (*flap == 3)
        background = IMG_Load("images/background768-3.PNG");

    main->draw.background = SDL_CreateTextureFromSurface(wind->renderer, background);
    SDL_FreeSurface(background);
}

/***** loads miniTimer images *****/
void initMiniTimer(Main *main, Wind *wind, int *flap)
{
    SDL_Surface *miniTimer;
    if (*flap == 0)
        miniTimer = IMG_Load("images/boxSmall-0.PNG");
    
    if (*flap == 1)
        miniTimer = IMG_Load("images/boxSmall-1.PNG");
    
    if (*flap == 2)
        miniTimer = IMG_Load("images/boxSmall-2.PNG");
    
    if (*flap == 3)
        miniTimer = IMG_Load("images/boxSmall-3.PNG");
    
    main->draw.miniTimer = SDL_CreateTextureFromSurface(wind->renderer, miniTimer);
    SDL_FreeSurface(miniTimer);
}

void initMiniTimerS(Main *main, Wind *wind, int *flap)
{
    SDL_Surface *miniTimerS;
    for (int i = 0; i < 9; i++)
    {
        if (i == 0)
            miniTimerS = IMG_Load("images/boxSmallS-0.PNG");
        else if (i == 1)
            miniTimerS = IMG_Load("images/boxSmallS-1.PNG");
        else if (i == 2)
            miniTimerS = IMG_Load("images/boxSmallS-0.PNG");
        else if (i == 3)
            miniTimerS = IMG_Load("images/boxSmallS-1.PNG");
        else if (i == 4)
            miniTimerS = IMG_Load("images/boxSmallS-2.PNG");
        else if (i == 5)
            miniTimerS = IMG_Load("images/boxSmallS-0.PNG");
        else if (i == 6)
            miniTimerS = IMG_Load("images/boxSmallS-1.PNG");
        else if (i == 7)
            miniTimerS = IMG_Load("images/boxSmallS-2.PNG");
        else if (i == 8)
            miniTimerS = IMG_Load("images/boxSmallS-3.PNG");

        main->draw.miniTimerS[i].miniTimerS = SDL_CreateTextureFromSurface(wind->renderer, miniTimerS);
        SDL_FreeSurface(miniTimerS);
    }
}

/***** loads shade images *****/
void loadShade(Main *main, Wind *wind, int *flap)
{
    SDL_Surface *shade;
    if (*flap == 0)
    {
        for (int i = 0; i < 1; i++)
        {
            shade = IMG_Load("images/shade-0-0.PNG");
            main->draw.shade[0].shade = SDL_CreateTextureFromSurface(wind->renderer, shade);
            SDL_FreeSurface(shade);
        }
    }
}

/***** loads all box pictures *****/
void loadBoxPics(Main *main, Wind *wind, int *flap)
{
    int i;
    SDL_Surface *boxPic0;
    SDL_Surface *boxPic1;
    SDL_Surface *boxPic2;
    SDL_Surface *boxPic3;
    SDL_Surface *boxPic4;
    SDL_Surface *boxPic5;
    SDL_Surface *boxPic6;
    SDL_Surface *boxPic7;
    SDL_Surface *boxPic8;
    if (*flap == 0)
    {
        boxPic0 = IMG_Load("images/box-0-0.PNG");
        boxPic1 = IMG_Load("images/box-0-1.PNG");
        boxPic2 = IMG_Load("images/box-0-2.PNG");
        boxPic3 = IMG_Load("images/box-0-3.PNG");
        boxPic4 = IMG_Load("images/box-0-4.PNG");
        boxPic5 = IMG_Load("images/box-0-5.PNG");
        boxPic6 = IMG_Load("images/box-0-6.PNG");
        boxPic7 = IMG_Load("images/box-0-7.PNG");
        boxPic8 = IMG_Load("images/box-0-8.PNG");
    }
    else if (*flap == 1)
    {
        boxPic0 = IMG_Load("images/box-1-0.PNG");
        boxPic1 = IMG_Load("images/box-1-1.PNG");
        boxPic2 = IMG_Load("images/box-1-2.PNG");
        boxPic3 = IMG_Load("images/box-1-3.PNG");
        boxPic4 = IMG_Load("images/box-1-4.PNG");
        boxPic5 = IMG_Load("images/box-1-5.PNG");
        boxPic6 = IMG_Load("images/box-1-6.PNG");
        boxPic7 = IMG_Load("images/box-1-7.PNG");
        boxPic8 = IMG_Load("images/box-1-8.PNG");
    }
    else if (*flap == 2)
    {
        boxPic0 = IMG_Load("images/box-2-0.PNG");
        boxPic1 = IMG_Load("images/box-2-1.PNG");
        boxPic2 = IMG_Load("images/box-2-2.PNG");
        boxPic3 = IMG_Load("images/box-2-3.PNG");
        boxPic4 = IMG_Load("images/box-2-4.PNG");
        boxPic5 = IMG_Load("images/box-2-5.PNG");
        boxPic6 = IMG_Load("images/box-2-6.PNG");
        boxPic7 = IMG_Load("images/box-2-7.PNG");
        boxPic8 = IMG_Load("images/box-2-8.PNG");
    }
    else if (*flap == 3)
    {
        boxPic0 = IMG_Load("images/box-3-0.PNG");
        boxPic1 = IMG_Load("images/box-3-1.PNG");
        boxPic2 = IMG_Load("images/box-3-2.PNG");
        boxPic3 = IMG_Load("images/box-3-3.PNG");
        boxPic4 = IMG_Load("images/box-3-4.PNG");
        boxPic5 = IMG_Load("images/box-3-5.PNG");
        boxPic6 = IMG_Load("images/box-3-6.PNG");
        boxPic7 = IMG_Load("images/box-3-7.PNG");
        boxPic8 = IMG_Load("images/box-3-8.PNG");
    }

    main->draw.dBoxes[0].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic0);
    main->draw.dBoxes[1].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic1);
    main->draw.dBoxes[2].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic2);
    main->draw.dBoxes[3].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic3);
    main->draw.dBoxes[4].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic4);
    main->draw.dBoxes[5].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic5);
    main->draw.dBoxes[6].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic6);
    main->draw.dBoxes[7].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic7);
    main->draw.dBoxes[8].dBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic8);

    SDL_FreeSurface(boxPic0);
    SDL_FreeSurface(boxPic1);
    SDL_FreeSurface(boxPic2);
    SDL_FreeSurface(boxPic3);
    SDL_FreeSurface(boxPic4);
    SDL_FreeSurface(boxPic5);
    SDL_FreeSurface(boxPic6);
    SDL_FreeSurface(boxPic7);
    SDL_FreeSurface(boxPic8);
}

/***** loads all box shades *****/
void loadShadePics(Main *main, Wind *wind, int *flap)
{
    int i;
    SDL_Surface *boxPic0;
    SDL_Surface *boxPic1;
    SDL_Surface *boxPic2;
    SDL_Surface *boxPic3;
    SDL_Surface *boxPic4;
    SDL_Surface *boxPic5;
    SDL_Surface *boxPic6;
    SDL_Surface *boxPic7;
    SDL_Surface *boxPic8;
    if (*flap == 0)
    {
        boxPic0 = IMG_Load("images/boxS-0-0.PNG");
        boxPic1 = IMG_Load("images/boxS-0-1.PNG");
        boxPic2 = IMG_Load("images/boxS-0-2.PNG");
        boxPic3 = IMG_Load("images/boxS-0-3.PNG");
        boxPic4 = IMG_Load("images/boxS-0-4.PNG");
        boxPic5 = IMG_Load("images/boxS-0-5.PNG");
        boxPic6 = IMG_Load("images/boxS-0-6.PNG");
        boxPic7 = IMG_Load("images/boxS-0-7.PNG");
        boxPic8 = IMG_Load("images/boxS-0-8.PNG");
    }
    else if (*flap == 1)
    {
        boxPic0 = IMG_Load("images/boxS-1-0.PNG");
        boxPic1 = IMG_Load("images/boxS-1-1.PNG");
        boxPic2 = IMG_Load("images/boxS-1-2.PNG");
        boxPic3 = IMG_Load("images/boxS-1-3.PNG");
        boxPic4 = IMG_Load("images/boxS-1-4.PNG");
        boxPic5 = IMG_Load("images/boxS-1-5.PNG");
        boxPic6 = IMG_Load("images/boxS-1-6.PNG");
        boxPic7 = IMG_Load("images/boxS-1-7.PNG");
        boxPic8 = IMG_Load("images/boxS-1-8.PNG");
    }
    else if (*flap == 2)
    {
        boxPic0 = IMG_Load("images/boxS-2-0.PNG");
        boxPic1 = IMG_Load("images/boxS-2-1.PNG");
        boxPic2 = IMG_Load("images/boxS-2-2.PNG");
        boxPic3 = IMG_Load("images/boxS-2-3.PNG");
        boxPic4 = IMG_Load("images/boxS-2-4.PNG");
        boxPic5 = IMG_Load("images/boxS-2-5.PNG");
        boxPic6 = IMG_Load("images/boxS-2-6.PNG");
        boxPic7 = IMG_Load("images/boxS-2-7.PNG");
        boxPic8 = IMG_Load("images/boxS-2-8.PNG");
    }
    else if (*flap == 3)
    {
        boxPic0 = IMG_Load("images/boxS-3-0.PNG");
        boxPic1 = IMG_Load("images/boxS-3-1.PNG");
        boxPic2 = IMG_Load("images/boxS-3-2.PNG");
        boxPic3 = IMG_Load("images/boxS-3-3.PNG");
        boxPic4 = IMG_Load("images/boxS-3-4.PNG");
        boxPic5 = IMG_Load("images/boxS-3-5.PNG");
        boxPic6 = IMG_Load("images/boxS-3-6.PNG");
        boxPic7 = IMG_Load("images/boxS-3-7.PNG");
        boxPic8 = IMG_Load("images/boxS-3-8.PNG");
    }

    main->draw.sBoxes[0].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic0);
    main->draw.sBoxes[1].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic1);
    main->draw.sBoxes[2].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic2);
    main->draw.sBoxes[3].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic3);
    main->draw.sBoxes[4].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic4);
    main->draw.sBoxes[5].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic5);
    main->draw.sBoxes[6].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic6);
    main->draw.sBoxes[7].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic7);
    main->draw.sBoxes[8].sBoxes = SDL_CreateTextureFromSurface(wind->renderer, boxPic8);

    SDL_FreeSurface(boxPic0);
    SDL_FreeSurface(boxPic1);
    SDL_FreeSurface(boxPic2);
    SDL_FreeSurface(boxPic3);
    SDL_FreeSurface(boxPic4);
    SDL_FreeSurface(boxPic5);
    SDL_FreeSurface(boxPic6);
    SDL_FreeSurface(boxPic7);
    SDL_FreeSurface(boxPic8);
}

void loadChooseSound(Main *main, Wind *wind, int *flap)
{
    SDL_Surface *chooseSound;
    if (*flap == 0)
        chooseSound = IMG_Load("images/chooseSound-0.PNG");
    
    if (*flap == 1)
        chooseSound = IMG_Load("images/chooseSound-1.PNG");
    
    if (*flap == 2)
        chooseSound = IMG_Load("images/chooseSound-2.PNG");
    
    if (*flap == 3)
        chooseSound = IMG_Load("images/chooseSound-2.PNG");
    
    main->draw.chooseSound = SDL_CreateTextureFromSurface(wind->renderer, chooseSound);
    SDL_FreeSurface(chooseSound);
}

/***** loads the hardcoded text for the boxes *****/
void loadTimeText(Main *main, Wind *wind)
{
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

    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "yeeeeehaa", black);
    main->draw.songlist[0].songlist = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "adiosamigo", black);
    main->draw.songlist[1].songlist = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "quackers", black);
    main->draw.songlist[2].songlist = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "roosters", black);
    main->draw.songlist[3].songlist = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    surfaceMessage = TTF_RenderText_Blended(main->draw.arial, "new flap", black);
    main->newText.newFlap = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
}

/***** loads all sounds *****/
void loadSounds(Main *main, int *flap)
{
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_VolumeMusic(64);

    int num = *flap;
    changeSound(num, &*main);
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
    main->prog.shadeQ = 11;
    main->prog.shadeV = 11;
    main->prog.shadeF = 11;
    main->prog.shadeS = 11;
    main->prog.shadeN = 11;
    main->prog.shadeM = 11;
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
            x = 225, y = 346;
            w = 265, h = 87;
        }
        else if (i == 6)
            x = 536;
        else if (i == 7)
            x = 586, y = 474;
        else if (i == 8)
            x = 175;
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
    for (i = 0; i < 11; i++)
    {
        if (i == 0)
        {
            x = 472, y = 20;
            w = 80, h = 40;
        }
        if (i == 1)
            x -= 50;
        if (i == 2)
            x += 90;
        if (i == 3)
            x = 372;
        if (i == 4)
            x += 90;
        if (i == 5)
            x += 90;
        if (i == 6)
            x = 322;
        if (i == 7)
            x += 90;
        if (i == 8)
            x += 90;
        if (i == 9)
            x += 90;

        if (i == 10)
        {
            x = 322;
            w = 350;
        }
        main->prog.mini[i].mini.x = x;
        main->prog.mini[i].mini.y = y;
        main->prog.mini[i].mini.w = w;
        main->prog.mini[i].mini.h = h;
    }

    /***** choose song boxes *****/
    for (i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            x = 25, y = 368;
            w = 177, h = 44;
        }
        else
        {
            y += 50;
        }

        main->prog.song[i].song.x = x;
        main->prog.song[i].song.y = y;
        main->prog.song[i].song.w = w;
        main->prog.song[i].song.h = h;
    }

    /***** songlist box *****/
    x = 25, y = 368;
    w = 177, h = 250;
    main->prog.songlist.songlist.x = x;
    main->prog.songlist.songlist.y = y;
    main->prog.songlist.songlist.w = w;
    main->prog.songlist.songlist.h = h;


    /***** choose song boxes ****
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
    }*/

    /***** new flap box *****/
    x = 821, y = 368;
    w = 175, h = 40;
   // w = 125, h = 20;
    main->prog.newFlap.newFlap.x = x;
    main->prog.newFlap.newFlap.y = y;
    main->prog.newFlap.newFlap.w = w;
    main->prog.newFlap.newFlap.h = h;


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

void generateMiniText(Main *main, Wind *wind, int *flap)
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
    for (int i = 0; i < 9; i++)
        SDL_DestroyTexture(main->draw.miniTimerS[i].miniTimerS);

    SDL_DestroyTexture(main->newText.volText);
    SDL_DestroyTexture(main->newText.stop);
    SDL_DestroyTexture(main->newText.exit);
    SDL_DestroyTexture(main->draw.miniTimerT);
}

void shutAll(Main *main, Wind *wind, int *max)
{
    SDL_DestroyWindow(wind->window);
    SDL_DestroyRenderer(wind->renderer);
    TTF_CloseFont(main[0].draw.arial);
    for (int i = 0; i < *max; i++)
        shutDown(&main[i]);
}

/***** shuts down SDL *****/
void shutDown(Main *main)
{
	free(main->prog.text);
    
	free(main->prog.genText);

    TTF_Quit();

    Mix_CloseAudio();

    Mix_FreeMusic(main->sound.backgroundSound);
    
    SDL_Quit();
}
