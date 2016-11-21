#include "defs.h"

bool clicked(SDL_Rect test, int mouseX, int mouseY, SDL_Event event);
bool hover(SDL_Rect rect, int mouseX, int mouseY);
bool clickedMini(SDL_Rect rect, int mouseX, int mouseY, SDL_Event event, int *flap, int *max, Main *main);
bool hoverMini(SDL_Rect rect, int mouseX, int mouseY, SDL_Event event, int *flap, int *max, Main *main);
bool cancelType(SDL_Rect rect, int mouseX, int mouseY, SDL_Event event);
void changeFlap(int box, Main *main, int *flap, int *max);
void addFlap(Main *main, Wind *wind, int *flap, int *max, int *newFlapF, int *newFlapL);

void processEvents(Main *main, Extf *extf, int *flap, int *running, int *max)
{
	int millisec = 60000;
	int mouseX, mouseY, i, ted;
	
	SDL_Event event;
	SDL_StartTextInput();
    while(SDL_PollEvent(&event) != 0)
    {
        /***** get coordinates for mouse *****/
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

        /***** lets the user pick a sound *****/
        for (i = 1; i < 5; i++)
        {
            if (clicked(main->prog.song[i].song, mouseX, mouseY, event))
            {
                changeSound(i - 1, &*main);
                main->prog.shadeS = 11;
                main->prog.songH[0].songH = 0;
            }
        }

        /***** lets the user add a new flap *****/
        if (clicked(main->prog.newFlap.newFlap, mouseX, mouseY, event))
            checkFlap(&*extf);

        /***** lets the user change flap by pressing the mini boxes *****/
        if (clickedMini(main->prog.mini[1].mini, mouseX, mouseY, event, &*flap, &*max, &*main))
            ted = 0;


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

        /***** lets the user stop or quit the program *****/
        if (hover(main->prog.stop[0].stop, mouseX, mouseY))
            main->prog.shadeQ = 0;
        else if (hover(main->prog.stop[1].stop, mouseX, mouseY))
            main->prog.shadeQ = 1;
        else
            main->prog.shadeQ = 11;


        /***** lets the user change volume *****/
        if (hover(main->prog.volume[1].volume, mouseX, mouseY))
            main->prog.shadeV = 1;
        else if (hover(main->prog.volume[2].volume, mouseX, mouseY))
            main->prog.shadeV = 2;
        else
            main->prog.shadeV = 11;


        /***** lets the user change flaps *****/
        if (hover(main->prog.flap[0].flap, mouseX, mouseY))
            main->prog.shadeF = 0;
        else if (hover(main->prog.flap[1].flap, mouseX, mouseY))
            main->prog.shadeF = 1;
        else 
            main->prog.shadeF = 11;

        /***** lets the user pick a sound *****/
        if (hover(main->prog.song[0].song, mouseX, mouseY))
            main->prog.songH[0].songH = 1;

        /***** lets the user pick a sound *****/
        for (i = 1; i < 5; i++)
        {
            if (hover(main->prog.song[i].song, mouseX, mouseY) && main->prog.songH[0].songH)
                main->prog.shadeS = i;
            else if (hover(main->prog.song[i].song, mouseX, mouseY) && main->prog.songH[0].songH)
                main->prog.shadeS = i;
            else if (hover(main->prog.song[i].song, mouseX, mouseY) && main->prog.songH[0].songH)
                main->prog.shadeS = i;
            else if (hover(main->prog.song[i].song, mouseX, mouseY) && main->prog.songH[0].songH)
                main->prog.shadeS = i;
            else if (!hover(main->prog.songlist.songlist, mouseX, mouseY) || hover(main->prog.song[0].song, mouseX, mouseY))
                main->prog.shadeS = 11;
        }

        /***** keeps the songlist showing *****/
        if (!hover(main->prog.songlist.songlist, mouseX, mouseY))
            main->prog.songH[0].songH = 0;

        /***** lets the user add a new flap *****/
        if (hover(main->prog.newFlap.newFlap, mouseX, mouseY))
            main->prog.shadeN = 1;
        else 
            main->prog.shadeN = 11;

        /***** lets the user change flap with mini boxes *****/
        if (hoverMini(main->prog.mini[1].mini, mouseX, mouseY, event, &*flap, &*max, &*main))
            ted = 0;
        else 
            main->prog.shadeM = 11;


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
                checkFlap(&*extf);
                break;

            case SDLK_LEFT:
                changeFlap(0, &*main, &*flap, &*max);
                break;
            case SDLK_RIGHT:
                changeFlap(1, &*main, &*flap, &*max);
                break;

            case SDLK_a:
                changeFlap(0, &*main, &*flap, &*max);
                break;
            case SDLK_d:
                changeFlap(1, &*main, &*flap, &*max);
                break;                

            case SDLK_q:
                Mix_PlayChannel(-1, main->sound.backgroundSound, 0);
                break;
            case SDLK_SPACE:
                *running = 0;
                break;
            case SDLK_ESCAPE:
                *running = 0;
                break;
            case SDLK_LCTRL:
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
                    /***** exit function and save values *****/ 
                    main->prog.typing = 0;

                    setTimer(&*main, atoi(main->prog.text));
                    initTextString(&*main);
                }
                else if (event.type == SDL_TEXTINPUT && main->prog.length < 5)
                {
                    strcat(main->prog.text, event.text.text);
                }
                else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE || cancelType(main->prog.boxes[4].boxes, mouseX, mouseY, event))
                {
                    /***** exit function and discard values *****/
                    main->prog.typing = 0;
                    initTextString(&*main);
                }
            }
        }
    }
    
    SDL_StopTextInput();
}

/***** checks if userver clicked on a box *****/
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

/***** check if user is hovering over a clickable box  *****/
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

/***** checks if user is clicking a miniBox *****/
bool clickedMini(SDL_Rect rect, int mouseX, int mouseY, SDL_Event event, int *flap, int *max, Main *main)
{
    /***** creates and compares 2 boxes *****/
    if (*max == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            int x, y, w, h;
            x = main->prog.mini[0].mini.x - 50;
            y = main->prog.mini[0].mini.y;
            w = main->prog.mini[0].mini.w;
            h = main->prog.mini[0].mini.h;
            if (i == 1)
                x += 90;
            SDL_Rect rect = {x, y, w, h};

            if (clicked(rect, mouseX, mouseY, event))
            {
                *flap = i;
                return true;
            }
        }
    }
    /***** creates and compares 3 boxes *****/
    else if (*max == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            int x, y, w, h;
            x = main->prog.mini[0].mini.x - 100;
            y = main->prog.mini[0].mini.y;
            w = main->prog.mini[0].mini.w;
            h = main->prog.mini[0].mini.h;
            if (i == 1)
                x += 90;
            if (i == 2)
                x += 180;
            SDL_Rect rect = {x, y, w, h};

            if (clicked(rect, mouseX, mouseY, event))
            {
                *flap = i;
                return true;
            }
        }
    }
    /***** creates and compares 4 boxes *****/
    else if (*max == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            int x, y, w, h;
            x = main->prog.mini[0].mini.x - 150;
            y = main->prog.mini[0].mini.y;
            w = main->prog.mini[0].mini.w;
            h = main->prog.mini[0].mini.h;
            if (i == 1)
                x += 90;
            if (i == 2)
                x += 180;
            if (i == 3)
                x += 270;
            SDL_Rect rect = {x, y, w, h};

            if (clicked(rect, mouseX, mouseY, event))
            {
                *flap = i;
                return true;
            }
        }
    }
    else 
        return false;
}

/***** checks if user is hovering on a miniBox *****/
bool hoverMini(SDL_Rect rect, int mouseX, int mouseY, SDL_Event event, int *flap, int *max, Main *main)
{
    /***** creates and compares 2 boxes *****/
    if (*max == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            int x, y, w, h;
            x = main->prog.mini[0].mini.x - 50;
            y = main->prog.mini[0].mini.y;
            w = main->prog.mini[0].mini.w;
            h = main->prog.mini[0].mini.h;
            if (i == 1)
                x += 90;
            SDL_Rect rect = {x, y, w, h};

            if (hover(rect, mouseX, mouseY))
            {
                main->prog.shadeM = i;
                return true;
            }
            else 
                main->prog.shadeM = 11;
        }
    }
    /***** creates and compares 3 boxes *****/
    else if (*max == 3)
    {
        for (int i = 2; i < 5; i++)
        {
            int x, y, w, h;
            x = main->prog.mini[0].mini.x - 100;
            y = main->prog.mini[0].mini.y;
            w = main->prog.mini[0].mini.w;
            h = main->prog.mini[0].mini.h;
            if (i == 3)
                x += 90;
            if (i == 4)
                x += 180;
            SDL_Rect rect = {x, y, w, h};

            if (hover(rect, mouseX, mouseY))
            {
                main->prog.shadeM = i;
                return true;
            }
            else 
                main->prog.shadeM = 11;
        }
    }
    /***** creates and compares 4 boxes *****/
    else if (*max == 4)
    {
        for (int i = 5; i < 9; i++)
        {
            int x, y, w, h;
            x = main->prog.mini[0].mini.x - 150;
            y = main->prog.mini[0].mini.y;
            w = main->prog.mini[0].mini.w;
            h = main->prog.mini[0].mini.h;
            if (i == 6)
                x += 90;
            if (i == 7)
                x += 180;
            if (i == 8)
                x += 270;
            SDL_Rect rect = {x, y, w, h};

            if (hover(rect, mouseX, mouseY))
            {
                main->prog.shadeM = i;
                return true;
            }
            else 
                main->prog.shadeM = 11;
        }
    }
    else
        return false;
}

/***** if the user clicks outside a box *****/
bool cancelType(SDL_Rect rect, int mouseX, int mouseY, SDL_Event event)
{
    if(mouseX < rect.x && mouseY < rect.y &&
        mouseX > rect.x + rect.w && 
        mouseY > rect.y + rect.h &&
        event.type == SDL_MOUSEBUTTONDOWN)
    {
        return true;
    }
    else 
        return false;
}

/***** changes flap and loops around *****/
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

/***** small delay to open one flap at a time *****/
void checkFlap(Extf *extf)
{
    extf->flapL = SDL_GetTicks();
    if (extf->flapL > extf->flapF + 1000)
    {
        extf->newFlap = 1;
        extf->flapF = extf->flapL;
    }
}

/***** draws everything on screen *****/
void render(Main *main, Wind *wind, int *flap, int *max)
{
    SDL_RenderClear(wind->renderer);

    SDL_SetRenderDrawColor(wind->renderer, 0, 0, 255, 255);

    int i, x, y, w, h;

    SDL_Rect bg = {0,0,1024,768};

    SDL_RenderCopy(wind->renderer,main[*flap].draw.background,NULL,&bg);


    /***** draw first 10 boxes on screen *****/
    for (i = 0; i < 6; i++)
    {
        x = main[*flap].prog.boxes[i].boxes.x;
        y = main[*flap].prog.boxes[i].boxes.y;
        w = main[*flap].prog.boxes[i].boxes.w;
        h = main[*flap].prog.boxes[i].boxes.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[0].dBoxes, NULL, &rect);
    }

    for (i = 6; i < 10; i++)
    {
        x = main[*flap].prog.boxes[i].boxes.x;
        y = main[*flap].prog.boxes[i].boxes.y;
        w = main[*flap].prog.boxes[i].boxes.w;
        h = main[*flap].prog.boxes[i].boxes.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[1].dBoxes, NULL, &rect);
    }


    /***** draw stop and exit boxes *****/
    for (i = 0; i < 2; i++)
    {
        x = main[*flap].prog.stop[i].stop.x;
        y = main[*flap].prog.stop[i].stop.y;
        w = main[*flap].prog.stop[i].stop.w;
        h = main[*flap].prog.stop[i].stop.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[2].dBoxes, NULL, &rect);
    }


    /***** draw volume boxes *****/
    for (i = 0; i < 3; i++)
    {
        x = main[*flap].prog.volume[i].volume.x;
        y = main[*flap].prog.volume[i].volume.y;
        w = main[*flap].prog.volume[i].volume.w;
        h = main[*flap].prog.volume[i].volume.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[3 + i].dBoxes, NULL, &rect);
    }


    /***** draw change flap boxes *****/
    for (i = 0; i < 2; i++)
    {
        x = main[*flap].prog.flap[i].flap.x;
        y = main[*flap].prog.flap[i].flap.y;
        w = main[*flap].prog.flap[i].flap.w;
        h = main[*flap].prog.flap[i].flap.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[6 + i].dBoxes, NULL, &rect);
    }


    /***** draw change song box *****/
    for (i = 0; i < 1; i++)
    {
        x = main[*flap].prog.song[i].song.x;
        y = main[*flap].prog.song[i].song.y;
        w = main[*flap].prog.song[i].song.w;
        h = main[*flap].prog.song[i].song.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[8].dBoxes, NULL, &rect);
    }


    /***** draw pick sound images *****/
    if (main[*flap].prog.songH[0].songH)
    {
        for (i = 1; i < 5; i++)
        {      
            x = main[*flap].prog.song[i].song.x;
            y = main[*flap].prog.song[i].song.y;
            w = main[*flap].prog.song[i].song.w;
            h = main[*flap].prog.song[i].song.h;
            SDL_Rect rect = {x, y, w, h};
            SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[8].dBoxes, NULL, &rect);
        }
    }


    /***** draw new flap box *****/
    x = main[*flap].prog.newFlap.newFlap.x;
    y = main[*flap].prog.newFlap.newFlap.y;
    w = main[*flap].prog.newFlap.newFlap.w;
    h = main[*flap].prog.newFlap.newFlap.h;
    SDL_Rect newRect = {x, y, w, h};
    SDL_RenderCopy(wind->renderer, main[*flap].draw.dBoxes[8].dBoxes, NULL, &newRect);

    
    /***** Draws all shade boxes *****/
    /***** draws shade for first 6 boxes *****/
    if (main[*flap].prog.shadeB < 11)
    {
        x = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.x;
        y = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.y;
        w = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.w;
        h = main[*flap].prog.boxes[main[*flap].prog.shadeB].boxes.h;
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.sBoxes[0].sBoxes, NULL, &rect);
    }


    /***** draw stop and quit boxes *****/
    if (main[*flap].prog.shadeQ < 11)
    {
        x = main[*flap].prog.stop[main[*flap].prog.shadeQ].stop.x;
        y = main[*flap].prog.stop[main[*flap].prog.shadeQ].stop.y;
        w = main[*flap].prog.stop[main[*flap].prog.shadeQ].stop.w;
        h = main[*flap].prog.stop[main[*flap].prog.shadeQ].stop.h;

        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.sBoxes[2].sBoxes, NULL, &rect);
    }   


    /***** draw volume boxes *****/
    if (main[*flap].prog.shadeV < 11)
    {
        x = main[*flap].prog.volume[main[*flap].prog.shadeV].volume.x;
        y = main[*flap].prog.volume[main[*flap].prog.shadeV].volume.y;
        w = main[*flap].prog.volume[main[*flap].prog.shadeV].volume.w;
        h = main[*flap].prog.volume[main[*flap].prog.shadeV].volume.h;

        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.sBoxes[main[*flap].prog.shadeV * 2 + 1].sBoxes, NULL, &rect);
    }    


    /***** draw change flap boxes *****/
    if (main[*flap].prog.shadeF < 11)
    {
        x = main[*flap].prog.flap[main[*flap].prog.shadeF].flap.x;
        y = main[*flap].prog.flap[main[*flap].prog.shadeF].flap.y;
        w = main[*flap].prog.flap[main[*flap].prog.shadeF].flap.w;
        h = main[*flap].prog.flap[main[*flap].prog.shadeF].flap.h;

        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.sBoxes[6 + main[*flap].prog.shadeF].sBoxes, NULL, &rect);
    }    


    /***** draw songlist boxes *****/
    if (main[*flap].prog.shadeS < 11)
    {
        x = main[*flap].prog.song[main[*flap].prog.shadeS].song.x;
        y = main[*flap].prog.song[main[*flap].prog.shadeS].song.y;
        w = main[*flap].prog.song[main[*flap].prog.shadeS].song.w;
        h = main[*flap].prog.song[main[*flap].prog.shadeS].song.h;

        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.sBoxes[8].sBoxes, NULL, &rect);
    }


    /***** draw new flap box *****/
    if (main[*flap].prog.shadeN < 11)
    {
        x = main[*flap].prog.newFlap.newFlap.x;
        y = main[*flap].prog.newFlap.newFlap.y;
        w = main[*flap].prog.newFlap.newFlap.w;
        h = main[*flap].prog.newFlap.newFlap.h;

        SDL_Rect rect = {x, y, w, h};
        SDL_RenderCopy(wind->renderer, main[*flap].draw.sBoxes[8].sBoxes, NULL, &rect);
    }


    /***** draws what the user is typing in realtime *****/
    SDL_Surface *surfaceMessage;
    SDL_Texture *tmpText;
    SDL_Color black = {0, 0, 0};
    surfaceMessage = TTF_RenderText_Blended(main[*flap].draw.arial,main[*flap].prog.text,black);
    tmpText = SDL_CreateTextureFromSurface(wind->renderer, surfaceMessage);
    main[*flap].prog.length = strlen(main[*flap].prog.text);
    SDL_Rect rect = {main[*flap].prog.boxes[4].boxes.x + 54, main[*flap].prog.boxes[4].boxes.y + 14, 160, 60};
    rect.w = 20*main[*flap].prog.length;
    SDL_FreeSurface(surfaceMessage);
    SDL_RenderCopy(wind->renderer,tmpText,NULL,&rect);
    SDL_DestroyTexture(tmpText);


    /***** draws the text for middle 10 boxes *****/
    x = 128, y = 98;
    w = 160, h = 60;
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
    SDL_Rect exit = {x, y, w, h};
    SDL_RenderCopy(wind->renderer, main[*flap].newText.exit, NULL, &exit);

    /***** draw current sound text *****/
    x = main[*flap].prog.song[0].song.x + 20;
    y = main[*flap].prog.song[0].song.y + 6;
    w = 137, h = 32;
    SDL_Rect songlist = {x, y, w, h};
    SDL_RenderCopy(wind->renderer, main[*flap].draw.songlist[main[*flap].sound.currSound].songlist, NULL, &songlist);

    /***** draw songlist text *****/
    if (main[*flap].prog.songH[0].songH)
    {
        for (i = 1; i < 5; i++)
        {
            x = main[*flap].prog.song[i].song.x + 22;
            y = main[*flap].prog.song[i].song.y + 8;
            w = 133, h = 28;
            SDL_Rect songlist = {x, y, w, h};
            SDL_RenderCopy(wind->renderer, main[*flap].draw.songlist[i - 1].songlist, NULL, &songlist);
        }
    }

    /***** draw newflap text *****/
    x = main[*flap].prog.newFlap.newFlap.x + 20;
    y = main[*flap].prog.newFlap.newFlap.y + 6;
    w = 137, h = 32;
    SDL_Rect newFlap = {x, y, w, h};
    SDL_RenderCopy(wind->renderer, main[*flap].newText.newFlap, NULL, &newFlap);


    /***** draw miniTimers *****/
    x = main[*flap].prog.mini[0].mini.x;
    y = main[*flap].prog.mini[0].mini.y;
    w = main[*flap].prog.mini[0].mini.w;
    h = main[*flap].prog.mini[0].mini.h;

    x -= (*max - 1) * 50;

    for (i = 0; i < *max; i++)
    {
        SDL_Rect mini = {x, y, w, h};

        SDL_RenderCopy(wind->renderer, main[i].draw.miniTimer, NULL, &mini);

        x += 90;
    }

    /***** draw shade for miniTimers *****/
    if (main[*flap].prog.shadeM < 11)
    {
        int xS = main[*flap].prog.mini[main[*flap].prog.shadeM + 1].mini.x;
        int yS = main[*flap].prog.mini[main[*flap].prog.shadeM + 1].mini.y;
        int wS = main[*flap].prog.mini[main[*flap].prog.shadeM + 1].mini.w;
        int hS = main[*flap].prog.mini[main[*flap].prog.shadeM + 1].mini.h;

        SDL_Rect miniS = {xS, yS, wS, hS};

        SDL_RenderCopy(wind->renderer, main[*flap].draw.miniTimerS[main[*flap].prog.shadeM].miniTimerS, NULL, &miniS);
    }


    /***** draw miniTimers text *****/
    x = main[*flap].prog.mini[0].mini.x;
    y = main[*flap].prog.mini[0].mini.y;
    w = main[*flap].prog.mini[0].mini.w;
    h = main[*flap].prog.mini[0].mini.h;

    x -= (*max - 1) * 50;

    for (i = 0; i < *max; i++)
    {
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
