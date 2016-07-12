#include "defs.h"

bool clicked(SDL_Rect test, int mouseX, int mouseY, SDL_Event event);
bool hover(SDL_Rect rect, int mouseX, int mouseY);
void changeFlap(int box, Main *main, int *flap, int *max);
void addFlap(Main *main, Wind *wind, int *flap, int *max, int *newFlapF, int *newFlapL);

void processEvents(Main *main, Extf *extf, int *flap, int *running, int *max)
{
	int millisec = 60000;
	int mouseX, mouseY;
	//int len = 0;
	//int length = 1;
	//int rectlen = 20;
	
	SDL_Event event;
	SDL_StartTextInput();
    while(SDL_PollEvent(&event) != 0)
    {
        // get coordinates for mouse
        SDL_GetMouseState(&mouseX, &mouseY);

        /***** lets the user press the boxes for the timer *****/
        if (clicked(main->prog.boxes[0].boxes, mouseX, mouseY, event))
            setTimer(&*main, 15);
        else if (clicked(main->prog.boxes[1].boxes, mouseX, mouseY, event))
            setTimer(&*main, 20);
        else if (clicked(main->prog.boxes[2].boxes, mouseX, mouseY, event))
            setTimer(&*main, 30);
        else if (clicked(main->prog.boxes[3].boxes, mouseX, mouseY, event))
            setTimer(&*main, 60);
        else if (clicked(main->prog.boxes[5].boxes, mouseX, mouseY, event))
            setTimer(&*main, 40);

        /***** lets the user change volume *****/
        if (clicked(main->prog.volume[1].volume, mouseX, mouseY, event))
            changeVolume(&*main, 1);
        else if (clicked(main->prog.volume[2].volume, mouseX, mouseY, event))
            changeVolume(&*main, 2);

        /***** lets the user stop or quit the program *****/
        if (clicked(main->prog.stop[0].stop, mouseX, mouseY, event))
            initVariables(&*main);
        else if (clicked(main->prog.stop[1].stop, mouseX, mouseY, event))
            *running = 0;

        /***** lets the user change flaps *****/
        if (clicked(main->prog.flap[0].flap, mouseX, mouseY, event))
            changeFlap(0, &*main, &*flap, &*max);
        else if (clicked(main->prog.flap[1].flap, mouseX, mouseY, event))
            changeFlap(1, &*main, &*flap, &*max);

        /***** show which box the user hovers over *****/
        if (hover(main->prog.boxes[0].boxes, mouseX, mouseY))
            main->prog.shadeB = 0;
        else if (hover(main->prog.boxes[1].boxes, mouseX, mouseY))
            main->prog.shadeB = 1;
        else if (hover(main->prog.boxes[2].boxes, mouseX, mouseY))
            main->prog.shadeB = 2;
        else if (hover(main->prog.boxes[3].boxes, mouseX, mouseY))
            main->prog.shadeB = 3;
        else if (hover(main->prog.boxes[4].boxes, mouseX, mouseY))
            main->prog.shadeB = 4;
        else if (hover(main->prog.boxes[5].boxes, mouseX, mouseY))
            main->prog.shadeB = 5;
        else 
            main->prog.shadeB = 11;

        /***** lets the user change volume *****/
        if (hover(main->prog.volume[1].volume, mouseX, mouseY))
            changeVolume(&*main, 1);
        else if (hover(main->prog.volume[2].volume, mouseX, mouseY))
            changeVolume(&*main, 2);

        /***** lets the user stop or quit the program *****/
        if (hover(main->prog.stop[0].stop, mouseX, mouseY))
            initVariables(&*main);
        else if (hover(main->prog.stop[1].stop, mouseX, mouseY))
            *running = 0;

        /***** lets the user change flaps *****/
        if (hover(main->prog.flap[0].flap, mouseX, mouseY))
            changeFlap(0, &*main, &*flap, &*max);
        else if (hover(main->prog.flap[1].flap, mouseX, mouseY))
            changeFlap(1, &*main, &*flap, &*max);

        /***** lets the user pick a sound *****/
        if (hover(main->prog.song[0].song, mouseX, mouseY))
            main->prog.songH[0].songH = 1;
        else         
            main->prog.songH[0].songH = 0;
       


        /***** lets the user choose timer with keybinds *****/
        if (event.type == SDL_KEYDOWN && main->prog.typing == 0)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_1:
                setTimer(&*main, 15);
                break;
            case SDLK_2:
            	setTimer(&*main, 20);
                break;
            case SDLK_3:
                setTimer(&*main, 30);
                break;
            case SDLK_4:
                setTimer(&*main, 40);
                break;
            case SDLK_5:
                setTimer(&*main, 60);
                break;

            case SDLK_e:
                extf->flapL = SDL_GetTicks();
                if (extf->flapL > extf->flapF + 1000)
                {
                    extf->newFlap = 1;
                    extf->flapF = extf->flapL;
                }
                break;

            case SDLK_a:
                changeSound(0, &*main);
                break;
            case SDLK_s:
                changeSound(1, &*main);
                break;
            case SDLK_d:
                changeSound(2, &*main);
                break;
            case SDLK_f:
                changeSound(3, &*main);
                break;
            case SDLK_g:
                changeSound(4, &*main);
                break;

            case SDLK_LEFT:
                changeFlap(0, &*main, &*flap, &*max);
                break;
            case SDLK_RIGHT:
                changeFlap(1, &*main, &*flap, &*max);
                break;

            case SDLK_q:
                Mix_PlayChannel(-1, main->sound.backgroundSound, 0);
                break;
            case SDLK_SPACE:
                printf("\nTotal time: %d\n", main->timer.total);
                printf("Total tick: %d\n", main->timer.ticks);
                *running = 0;
                break;
            case SDLK_ESCAPE:
                printf("\nTotal time: %d\n", main->timer.total);
                printf("Total tick: %d\n", main->timer.ticks);
                *running = 0;
                break;
            case SDLK_LCTRL:
                printf("\nTotal time: %d\n", main->timer.total);
                printf("Total tick: %d\n", main->timer.ticks);
                *running = 0;
                break;
            default:
                break;
            }
        }

        /***** lets the user type a desired time *****/
        if (clicked(main->prog.boxes[4].boxes, mouseX, mouseY, event))
        {
            initTextString(&*main);
            main->prog.typing = 1;
        }
        // text blink function call
        if (main->prog.typing)
        {
            if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
            {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    main->prog.length = strlen(main->prog.text);
                    main->prog.text[main->prog.length-1] = '\0';
                }
                else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
                {
                    // exit function and save values 
                    main->prog.typing = 0;

                    setTimer(&*main, atoi(main->prog.text));
                    initTextString(&*main);
                    //free(main->prog.text);

                }
                else if (event.type == SDL_TEXTINPUT && main->prog.length < 5)
                {
                    strcat(main->prog.text, event.text.text);
                    printf("%s\n", main->prog.text);
                    printf("%d\n", main->prog.length);
                }
                else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                {
                    // exit function and discard values
                    main->prog.typing = 0;
                    initTextString(&*main);
                    //free(main->prog.text);
                }
            }
        }

    }
    
    SDL_StopTextInput();
}

bool clicked(SDL_Rect rect, int mouseX, int mouseY, SDL_Event event)
{
    if(mouseX > rect.x && mouseY > rect.y &&
        mouseX < rect.x + rect.w && 
        mouseY < rect.y + rect.h &&
        event.type == SDL_MOUSEBUTTONDOWN)
    {
        return true;
    }
    else 
        return false;
}

bool hover(SDL_Rect rect, int mouseX, int mouseY)
{
    if(mouseX > rect.x && mouseY > rect.y &&
        mouseX < rect.x + rect.w && 
        mouseY < rect.y + rect.h)
    {
        return true;
    }
    else 
        return false;
}

void changeFlap(int box, Main *main, int *flap, int *max)
{
    if (box == 0)
    {
        if (*flap == 0)
            *flap = *max - 1;
        else if (*flap > 0)
            *flap -= 1;
    }
    else 
    {
        if (*flap == *max - 1)
            *flap = 0;
        else if (*flap < *max - 1)
            *flap += 1;
    }
}

void render(Main *main, Wind *wind, int *flap, int *max)
{
    //SDL_SetRenderDrawColor(wind->renderer, 123, 12, 123, 31);

    SDL_RenderClear(wind->renderer);

    SDL_SetRenderDrawColor(wind->renderer, 0, 0, 255, 255);

    int i, x, y, w, h;

    SDL_Rect bg = {0,0,1024,768};

    SDL_RenderCopy(wind->renderer,main[*flap].draw.background,NULL,&bg);



    /***** places '15 minutes' '20 minutes' etc *****/

    SDL_Surface *surfaceMessage;
    SDL_Texture *ipAddressText;
    SDL_Color black = {0, 0, 0};
    surfaceMessage = TTF_RenderText_Blended(main[*flap].draw.arial,main[*flap].prog.text,black);
    ipAddressText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    main[*flap].prog.length = strlen(main[*flap].prog.text);
    //SDL_Rect rect = {560, 250, 200, 60};
    SDL_Rect rect = {main[*flap].prog.boxes[4].boxes.x + 54, main[*flap].prog.boxes[4].boxes.y + 14, 160, 60};
    rect.w = 20*main[*flap].prog.length;
    SDL_FreeSurface(surfaceMessage);
    SDL_RenderCopy(wind->renderer,ipAddressText,NULL,&rect);
    SDL_DestroyTexture(ipAddressText);
    
    /***** draws shade for first 6 boxes *****/
    if (main[*flap].prog.shadeB < 11)
    {
        x = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.x - 1;
        y = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.y - 2;
        w = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.w + 3;
        h = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.h + 2;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.shade[0].shade, NULL, &rect);
    }

    /***** draw pick sound image *****/
    if (main[*flap].prog.songH[0].songH)
    {
        x = main[*flap].prog.song[1].song.x;
        y = main[*flap].prog.song[1].song.y;
        w = main[*flap].prog.song[1].song.w;
        h = main[*flap].prog.song[1].song.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.chooseSound, NULL, &rect);
    }


    /** for 720p
    int x = 156;
    int y = 90; 
    for (int i = 0; i < 10; i++)
    {
    	int drawText = 1;
	    	SDL_Rect text = {x, y, 200, 60};
	    	if (i == 4  && main[*flap].prog.typing == 1)
    			drawText = 0;
    		if (drawText)
    			SDL_RenderCopy(wind->renderer, main[*flap].draw.tText[i].timeText, NULL, &text);
	    	if (i == 0)
	    		x += 384;
	    	if (i == 1)
	    		x += 384;
	    	if (i == 2)
	    		y += 160;
	    	if (i == 3)
	    		x -= 384;
	    	if (i == 4)
	    		x -= 384;
            if (i == 5)
                y += 240;
            if (i >= 6)
                x += 277;
    }
    **/

    // for 768p
    x = 128;
    y = 98;
    w = 160;
    h = 60;
    for (int i = 0; i < 6; i++)
    {
        int drawText = 1;
            SDL_Rect text = {x, y, w, h};
            if (i == 4  && main[*flap].prog.typing == 1)
                drawText = 0;
            if (drawText)
                SDL_RenderCopy(wind->renderer, main[*flap].draw.tText[i].timeText, NULL, &text);
            if (i == 0)
                x += 308;
            if (i == 1)
                x += 308;
            if (i == 2)
                y += 132;
            if (i == 3)
                x -= 308;
            if (i == 4)
                x -= 308;
    }

    for (int i = 6; i < 10; i++)
    {
        if (i == 6)
        {
            y += 132;
            x += 125;
            w += 60;
        }
        if (i == 7)
            x += 312;
        if (i == 8)
        {
            y += 128;
            x += 50;
        }
       if (i == 9)
            x -= 412;
        SDL_Rect text = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.tText[i].timeText, NULL, &text);
    }

    /***** draw volume *****/
    x = main[*flap].prog.volume[0].volume.x + 10;
    y = main[*flap].prog.volume[0].volume.y + 25;
    w = 80, h = 50;
    SDL_Rect volText = {x, y, w, h};
    SDL_RenderCopy(wind->renderer, main[*flap].newText.volText, NULL, &volText);

    /***** draw stop and exit *****/
    x = main[*flap].prog.stop[0].stop.x + 16;
    y = main[*flap].prog.stop[0].stop.y + 10;
    w = 132, h = 40;
    SDL_Rect stop = {x, y, w, h};
    SDL_RenderCopy(wind->renderer, main[*flap].newText.stop, NULL, &stop);
    x = main[*flap].prog.stop[1].stop.x + 16;
    //x += 200;
    SDL_Rect exit = {x, y, w, h};
    SDL_RenderCopy(wind->renderer, main[*flap].newText.exit, NULL, &exit);

    /***** draw miniTimers *****/
    x = main->prog.mini[0].mini.x;
    y = main->prog.mini[0].mini.y;
    w = main->prog.mini[0].mini.w;
    h = main->prog.mini[0].mini.h;

    x -= (*max - 1) * 50;

    for (i = 0; i < *max; i++)
    {
        SDL_Rect mini = {x, y, w, h};

        SDL_RenderCopy(wind->renderer, main[i].draw.miniTimer, NULL, &mini);

        x += 10;
        y += 5;
        w -= 20;
        h -= 10;

        SDL_Rect texta = {x, y, w, h};

        SDL_RenderCopy(wind->renderer, main[i].draw.miniTimerT, NULL, &texta);
        
        x -= 10;
        y -= 5;
        w += 20;
        h += 10;

        x += 90;
    }



    SDL_RenderPresent(wind->renderer);
}

void renderMini(Main *main, Wind *wind)
{
    int x, y, w, h;

    x = main->prog.mini[0].mini.x;
    y = main->prog.mini[0].mini.y;
    w = main->prog.mini[0].mini.w;
    h = main->prog.mini[0].mini.h;

    SDL_Rect mini = {x, y, w, h};

    SDL_RenderCopy(wind->renderer, main->draw.miniTimer, NULL, &mini);

    x += 10;
    y += 5;
    w -= 20;
    h -= 10;

    SDL_Rect texta = {x, y, w, h};

    SDL_RenderCopy(wind->renderer, main->draw.miniTimerT, NULL, &texta);
    
    SDL_RenderPresent(wind->renderer);
}