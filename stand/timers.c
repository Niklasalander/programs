#include "defs.h"

/***** checks if a timer is done *****/
void checkTimers(Main *main)
{
	int millisec = 60000;

    main->timer.lastCount = SDL_GetTicks();
    if (main->timer.lastCount > main->timer.firstCount + 1000)
    {
        if (main->timer.minCount || main->timer.secCount > 0)
        {
            if (main->timer.secCount == 0)
            {
                main->timer.secCount = 59;
                main->timer.minCount -= 1;
            }
            else
                main->timer.secCount -= 1;

            if (main->timer.minCount == 0 && main->timer.secCount == 0)  
                Mix_PlayChannel(-1, main->sound.backgroundSound, 0);
        }
        else 
        {
            main->timer.minCount = main->timer.minutes -1;
            main->timer.secCount = 59;
        }
        main->timer.firstCount = SDL_GetTicks();
    }
}

/***** creates the timer *****/
void setTimer(Main *main, int minutes)
{
	int millisec = 60000;
    main->timer.minutes = minutes;
    main->timer.firstTime = SDL_GetTicks();
    main->timer.timer = minutes * millisec;

    time(&main->timer.pressed);
    main->timer.cPressed = localtime(&main->timer.pressed);
    main->timer.hPressed = main->timer.cPressed->tm_hour;
    main->timer.mPressed = main->timer.cPressed->tm_min;

    main->timer.firstCount = SDL_GetTicks();
    main->timer.minCount = minutes;
    main->timer.secCount = 0;
}