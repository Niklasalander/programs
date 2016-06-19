#include "defs.h"

bool clickedChoose(int box, Prog *prog, int mouseX, int mouseY, SDL_Event event);
bool clickedVolume(int box, Prog *prog, int mouseX, int mouseY, SDL_Event event);

void processEvents(Prog *prog, Timer *timer, int *running, Sound *sound)
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
		if (clickedChoose(0, &*prog, mouseX, mouseY, event))
			setTimer(*&timer, 1);

		else if (clickedChoose(1, &*prog, mouseX, mouseY, event))
			setTimer(*&timer, 20);

		else if (clickedChoose(2, &*prog, mouseX, mouseY, event))
			setTimer(*&timer, 30);

		else if (clickedChoose(3, &*prog, mouseX, mouseY, event))
			setTimer(*&timer, 60);

		else if (clickedChoose(5, &*prog, mouseX, mouseY, event))
			setTimer(*&timer, 40);

        /***** lets the user change volume *****/
        if (clickedVolume(1, &*prog, mouseX, mouseY, event))
            changeVolume(*&sound, 1);
        else if (clickedVolume(2, &*prog, mouseX, mouseY, event))
            changeVolume(*&sound, 2);

        /***** lets the user choose timer with keybinds *****/
        if (event.type == SDL_KEYDOWN && prog->typing == 0)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_1:
                setTimer(*&timer, 15);
                break;
            case SDLK_2:
            	setTimer(*&timer, 20);
                break;
            case SDLK_3:
                setTimer(*&timer, 30);
                break;
            case SDLK_4:
                setTimer(*&timer, 40);
                break;
            case SDLK_5:
                setTimer(*&timer, 60);
                break;

            case SDLK_SPACE:
                printf("\nTotal time: %d\n", timer->total);
                printf("Total tick: %d\n", timer->ticks);
                *running = 0;
                break;
            case SDLK_ESCAPE:
                printf("\nTotal time: %d\n", timer->total);
                printf("Total tick: %d\n", timer->ticks);
                *running = 0;
                break;
            case SDLK_LCTRL:
                printf("\nTotal time: %d\n", timer->total);
                printf("Total tick: %d\n", timer->ticks);
                *running = 0;
                break;
            default:
                break;
            }
        }

        /***** lets the user type a desired time *****/
        if (clickedChoose(4, &*prog, mouseX, mouseY, event))
        {
            initTextString(&*prog);
            prog->typing = 1;
        }
        // text blink function call
        if (prog->typing)
        {
            if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
            {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    prog->length = strlen(prog->text);
                    prog->text[prog->length-1] = '\0';
                }
                else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
                {
                    // exit function and save values 
                    prog->typing = 0;

                    setTimer(*&timer, atoi(prog->text));
                    initTextString(&*prog);
                    //free(prog->text);

                }
                else if (event.type == SDL_TEXTINPUT && prog->length < 5)
                {
                    strcat(prog->text, event.text.text);
                    printf("%s\n", prog->text);
                    printf("%d\n", prog->length);
                }
                else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                {
                    // exit function and discard values
                    prog->typing = 0;
                    initTextString(&*prog);
                    //free(prog->text);
                }
            }
        }



    }
    
    SDL_StopTextInput();
}

bool clickedChoose(int box, Prog *prog, int mouseX, int mouseY, SDL_Event event)
{
    if(mouseX > prog->boxes[box].boxes.x && mouseY > prog->boxes[box].boxes.y &&
        mouseX < prog->boxes[box].boxes.x + prog->boxes[box].boxes.w && 
        mouseY < prog->boxes[box].boxes.y + prog->boxes[box].boxes.h &&
        event.type == SDL_MOUSEBUTTONDOWN)
    {
        return true;
    }
    else 
        return false;
}
bool clickedVolume(int box, Prog *prog, int mouseX, int mouseY, SDL_Event event)
{
    if(mouseX > prog->volume[box].volume.x && mouseY > prog->volume[box].volume.y &&
        mouseX < prog->volume[box].volume.x + prog->volume[box].volume.w && 
        mouseY < prog->volume[box].volume.y + prog->volume[box].volume.h &&
        event.type == SDL_MOUSEBUTTONDOWN)
    {
        return true;
    }
    else 
        return false;
}

void render(Draw *windowF, Prog *prog, newText *newText)
{
    //SDL_SetRenderDrawColor(windowF->renderer, 123, 12, 123, 31);

    SDL_RenderClear(windowF->renderer);

    SDL_SetRenderDrawColor(windowF->renderer, 0, 0, 255, 255);

    SDL_Rect bg = {0,0,1024,768};

    SDL_RenderCopy(windowF->renderer,windowF->background,NULL,&bg);



    /***** places '15 minutes' '20 minutes' etc *****/

    SDL_Surface *surfaceMessage;
    SDL_Texture *ipAddressText;
    SDL_Color black = {0, 0, 0};
    surfaceMessage = TTF_RenderText_Blended(windowF->arial,prog->text,black);
    ipAddressText = SDL_CreateTextureFromSurface(windowF->renderer, surfaceMessage);
    prog->length = strlen(prog->text);
    //SDL_Rect rect = {560, 250, 200, 60};
    SDL_Rect rect = {prog->boxes[4].boxes.x + 54, prog->boxes[4].boxes.y + 14, 160, 60};
    rect.w = 20*prog->length;
    SDL_FreeSurface(surfaceMessage);
    SDL_RenderCopy(windowF->renderer,ipAddressText,NULL,&rect);
    SDL_DestroyTexture(ipAddressText);
    
    


    /** for 720p
    int x = 156;
    int y = 90; 
    for (int i = 0; i < 10; i++)
    {
    	int drawText = 1;
	    	SDL_Rect text = {x, y, 200, 60};
	    	if (i == 4  && prog->typing == 1)
    			drawText = 0;
    		if (drawText)
    			SDL_RenderCopy(windowF->renderer, windowF->tText[i].timeText, NULL, &text);
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
    int x = 128;
    int y = 98;
    int w = 160;
    int h = 60;
    for (int i = 0; i < 6; i++)
    {
        int drawText = 1;
            SDL_Rect text = {x, y, w, h};
            if (i == 4  && prog->typing == 1)
                drawText = 0;
            if (drawText)
                SDL_RenderCopy(windowF->renderer, windowF->tText[i].timeText, NULL, &text);
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
            x += 75;
            w += 60;
        }
        if (i == 7)
            x += 412;
        if (i == 8)
            y += 128;
       if (i == 9)
            x -= 412;
        SDL_Rect text = {x, y, w, h};
        SDL_RenderCopy(windowF->renderer, windowF->tText[i].timeText, NULL, &text);
    }

    /***** draw volume *****/
    x = prog->volume[0].volume.x + 10;
    y = prog->volume[0].volume.y + 25;
    w = 80, h = 50;
    SDL_Rect volText = {x, y, w, h};
    SDL_RenderCopy(windowF->renderer, newText->volText, NULL, &volText);


    //for (int i = 6; i < 10; i++)
      //  SDL_DestroyTexture(windowF->tText[i].timeText);


    SDL_RenderPresent(windowF->renderer);
}
