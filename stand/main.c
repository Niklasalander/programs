#include "defs.h"

int main(int argc, char **argv)
{
    
    
    Timer timer;
    Prog prog;
    newText newText;
    Draw draw;
    Sound sound;
    int running = 1; //lägg in i struct

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // initiate program
    initVariables(&timer, &prog, &sound);
    loadBackground(&draw);
    loadTimeText(&draw, &newText, &prog, &sound);
    loadSounds(&sound);
    initTextString(&prog);
    initBoxes(&prog);

    int firstT = -1000000;
    int lastT = 0;

    while(running)
    {
    	// check for user action
		processEvents(&prog, &timer, &running, &sound);

		// check if any timer is done
		checkTimers(&timer, &sound);

        // update timers
        generateText(&draw, &prog, &timer, &firstT, &lastT, &sound, &newText);

        // draws everything
        render(&draw, &prog, &newText);

        // don't burn cpu
        SDL_Delay(10);
    }

    // shuts everything down safetly
    shutDown(&draw, &prog);

    return 0;
}


