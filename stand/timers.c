#include "defs.h"

/***** checks if a timer is done *****/
void checkTimers(Timer *timer, Sound *sound)
{
	int millisec = 60000;
    /*timer->lastTime = SDL_GetTicks();
    if (timer->lastTime > timer->firstTime + timer->timer)
    {
        timer->total += timer->timer/millisec;
        printf("Total time so far: %d\n", timer->total);
        Mix_VolumeMusic(22);
        Mix_PlayMusic(sound->backgroundSound, 0);
        printf("normal done: ");
        printTime();
        timer->firstTime = SDL_GetTicks();
        timer->ticks++;
    }*/

    timer->lastCount = SDL_GetTicks();
    if (timer->lastCount > timer->firstCount + 1000)
    {
        if (timer->minCount || timer->secCount > 0)
        {
            if (timer->secCount == 0)
            {
                timer->secCount = 59;
                timer->minCount -= 1;
            }
            else
                timer->secCount -= 1;

            if (timer->minCount == 0 && timer->secCount == 0)  
            {
                printf("counter done: ");
                printTime();
                //timer->minCount = timer->minutes;
                Mix_VolumeMusic(12);
                Mix_PlayMusic(sound->backgroundSound, 0);
            }
        }
        else 
        {
            //printf("counter done: ");
            //printTime();
            timer->minCount = timer->minutes -1;
            //Mix_VolumeMusic(12);
            //Mix_PlayMusic(sound->backgroundSound, 0);
            timer->secCount = 59;
        }
        timer->firstCount = SDL_GetTicks();
    }
}

/***** creates the timer *****/
void setTimer(Timer *timer, int minutes)
{
	int millisec = 60000;
    timer->minutes = minutes;
    timer->firstTime = SDL_GetTicks();
    timer->timer = minutes * millisec;
    printf("\n%d minute sessions\n", timer->timer/millisec);

    time(&timer->pressed);
    timer->cPressed = localtime(&timer->pressed);

    timer->firstCount = SDL_GetTicks();
    timer->minCount = minutes;
    timer->secCount = 0;


    printTime();
}