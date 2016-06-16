#include "defs.h"

int main(int argc, char **argv)
{
    draw draw;
    sound sound;
    prog prog;
    timer timer;
    int running = 1; //lägg in i struct

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // initiate program
    initVariables(&timer, &prog);
    loadBackground(&draw);
    loadTimeText(&draw);
    loadSounds(&sound);
    initTextString(&prog);
    initBoxes(&prog);

    int firstT = -1000000;
    int lastT = 0;

    while(running)
    {
        //printf("1\n");
    	// check for user action
		processEvents(&prog, &timer, &running);
       // printf("2\n");
		// check if any timer is done
		checkTimers(&timer, &sound);
     //   printf("3\n");
        // update timers
        generateText(&draw, &prog, &timer, &firstT, &lastT);
      //  printf("4\n");
        // draws everything
        render(&draw, &prog);
     //   printf("5\n");
        // don't burn cpu
        SDL_Delay(10);
      //  printf("6\n");
    }

    // shuts everything down safetly
    shutDown(&draw, &prog);

    return 0;
}


