#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <time.h>

void printTime();


typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} program;

typedef struct
{
    Mix_Music *backgroundSound;
} Sound;

typedef struct tm tm;

int main(int argc, char **argv)
{
    int tm_min;
    program program;
    Sound Sound;
    int ticks = 0;
    int timer = 0;
    int total = 0;
    int millisec = 60000;
    int running = 1;
    int firstTime = 9999999;
    int lastTime;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;

    program.window = SDL_CreateWindow("Stand",                           // window title
                                      SDL_WINDOWPOS_UNDEFINED,           // initial x position
                                      SDL_WINDOWPOS_UNDEFINED,           // initial y position
                                      640,                               // width, in pixels
                                      480,                               // height, in pixels
                                      0                                  // flags
                                     );
    program.renderer = SDL_CreateRenderer(program.window, -1, SDL_RENDERER_ACCELERATED);

    printf("%d\n", tm_min);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_VolumeMusic(16);
    Sound.backgroundSound = Mix_LoadMUS("yeeeha.MP3");
    while(running)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_1:
                    firstTime = SDL_GetTicks();
                    timer = 15 * millisec;
                    printf("\n%d minute sessions\n", timer/millisec);
                    printTime();
                    break;
                case SDLK_2:
                    firstTime = SDL_GetTicks();
                    timer = 20 * millisec;
                    printf("\n%d minute sessions\n", timer/millisec);
                    printTime();
                    break;
                case SDLK_3:
                    firstTime = SDL_GetTicks();
                    timer = 30 * millisec;
                    printf("\n%d minute sessions\n", timer/millisec);
                    printTime();
                    break;
                case SDLK_4:
                    firstTime = SDL_GetTicks();
                    timer = 40 * millisec;
                    printf("\n%d minute sessions\n", timer/millisec);
                    printTime();
                    break;
                case SDLK_5:
                    firstTime = SDL_GetTicks();
                    timer = 60 * millisec;
                    printf("\n%d minute sessions\n", timer/millisec);
                    printTime();
                    break;

                case SDLK_SPACE:
                    printf("\nTotal time: %d\n", total);
                    printf("Total tick: %d\n", ticks);
                    running = 0;
                    break;
                case SDLK_RETURN:
                    printf("\nTotal time: %d\n", total);
                    printf("Total tick: %d\n", ticks);
                    running = 0;
                    break;
                default:
                    break;
                }
            }
        }
        lastTime = SDL_GetTicks();
        if (lastTime > firstTime + timer)
        {
            total += timer/millisec;
            printf("Total time so far: %d\n", total);
            Mix_VolumeMusic(22);
            Mix_PlayMusic(Sound.backgroundSound, -1);
            SDL_Delay(1800);
            Mix_VolumeMusic(0);
            firstTime = SDL_GetTicks();
            ticks++;
        }
        SDL_Delay(10);
    }

    Mix_CloseAudio();
    SDL_DestroyWindow(program.window);
    SDL_DestroyRenderer(program.renderer);
    SDL_Quit();

    return 0;
}

void printTime()
{
    time_t tNow;
    time(&tNow);
    tm *myTime = localtime(&tNow);
    if (myTime->tm_hour > 9 && myTime->tm_min > 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) %d:%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min > 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) 0%d:%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour > 9 && myTime->tm_min <= 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) %d:0%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min <= 9 && myTime->tm_sec > 9)
        printf("Time when pressed (h/m/s) 0%d:0%d:%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour > 9 && myTime->tm_min > 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) %d:%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min > 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) 0%d:%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour > 9 && myTime->tm_min <= 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) %d:0%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
    else if (myTime->tm_hour <= 9 && myTime->tm_min <= 9 && myTime->tm_sec <= 9)
        printf("Time when pressed (h/m/s) 0%d:0%d:0%d\n", myTime->tm_hour, myTime->tm_min, myTime->tm_sec);
}


