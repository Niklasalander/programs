#include "defs.h"

int main(int argc, char **argv)
{
    Wind wind;
    Extf extf;
    Main main[10];

    int running = 1; //lägg in i struct edit: nope
    int flap = -1;
    int max = 0;
    int i;
    int test = 0;

    SDL_Init(SDL_INIT_EVERYTHING); 
   // SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();


    // initiate program
    initAll(&main, &wind, &max);

    initFlap(&main, &wind, &extf, &flap, &max);

    initGenString(&main);

    flap = 0;

    initExtf(&extf);

    int firstT = -1000000;
    int lastT = 0;
    int firstMT = -1000;
    int lastMT = 0;
    int newFlapF = 0;
    int newFlapL;

    while(running) // FREE SURFACES IN ALL FUNCTIONS
    {
       // printf("R2\n");
		// check if any timer is done
        for (i = 0; i < max; i++)
		  checkTimers(&main[i]);

        lastMT = SDL_GetTicks();
        if (lastMT > firstMT + 1000)
        {
            for (i = 0; i < max; i++)
                generateMiniText(&main[i], &wind);
            firstMT = lastMT;
        }
       // printf("R3\n");
        // update timers
        generateText(&main[flap], &wind, &firstT, &lastT, &test);
        //printf("R4\n");
        
        // draws everything
        render(&main, &wind, &flap, &max);

        // draws miniTimers
       // for (i = 0; i < 1; i++)
       //     renderMini(&main[i], &wind);
       // printf("R5\n");
        
        // check for user action
        processEvents(&main[flap], &extf, &flap, &running, &max);

        // creates a new flap
        if (extf.newFlap)
            initFlap(&main, &wind, &extf, &flap, &max);
        //addFlap(&main, &extf, &wind, &flap, &max);

        // check for new flap
        
        // don't burn cpu
        SDL_Delay(1);
    }

    // shuts everything down safetly
    printf("5\n");
    for (int i = 0; i < max; i++)
        destTexture(&main[i]);
    printf("6 ");
    shutAll(&main, &wind, &max);

    printf("\n7 ");
    SDL_Delay(10);
   // SDL_Quit();
    printf("8\n");

    return 0;
}


