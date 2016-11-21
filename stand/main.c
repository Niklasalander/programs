#include "defs.h"

int main(int argc, char **argv)
{
    Wind wind;
    Extf extf;
    Main main[10];

    int running = 1;
    int flap = -1;
    int max = 0;
    int i;
    int test = 0;

    SDL_Init(SDL_INIT_EVERYTHING); 
    TTF_Init();


    /***** initiate program *****/
    initAll(&main, &wind, &max);

    initFlap(&main, &wind, &extf, &flap, &max);

    initGenString(&main);

    flap = 0;

    initExtf(&extf);

    int firstT = -1000000;
    int lastT = 0;
    int firstMT = -1000;
    int lastMT = 0;

    int firstFPS = -32;
    int lastFPS = 0;

    int newFlapF = 0;
    int newFlapL;

    while(running)
    {

        /***** checks if timers are done *****/
        for (i = 0; i < max; i++)
		  checkTimers(&main[i]);

        /***** creates text for current time *****/
        generateText(&main[flap], &wind, &firstT, &lastT, &test);
        
        /***** draws everything at 32 fps *****/
        lastFPS = SDL_GetTicks();
        if (lastFPS > firstFPS + 32)
        {
            render(&main, &wind, &flap, &max);
            firstFPS = lastFPS;
            lastMT = SDL_GetTicks();
            if (lastMT > firstMT + 32)
            {
                for (i = 0; i < max; i++)
                    generateMiniText(&main[i], &wind, &flap);
                firstMT = lastMT;
            }

        }
        
        /***** check for user action *****/
        processEvents(&main[flap], &extf, &flap, &running, &max);

        /***** creates a new flap *****/
        if (extf.newFlap)
            initFlap(&main, &wind, &extf, &flap, &max);

        SDL_Delay(4);
    }

    /***** shuts everything down safetly *****/
    for (int i = 0; i < max; i++)
        destTexture(&main[i]);
    SDL_Delay(80);
    shutAll(&main, &wind, &max);

    return 0;
}


