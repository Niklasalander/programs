#include "defs.h"

void printTime();

int main(int argc, char **argv)
{
    int tm_min;
    //window window;
    sound sound;
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

        SDL_Window *window = SDL_CreateWindow("Stand",                            // window title
                                      SDL_WINDOWPOS_UNDEFINED,           // initial x position
                                      SDL_WINDOWPOS_UNDEFINED,           // initial y position
                                      1280,                              // width, in pixels
                                      720,                               // height, in pixels
                                      0                                  // flags
                                     );
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface *background;
    background = IMG_Load("background.PNG");
    SDL_Texture *bgtexture;
    bgtexture = SDL_CreateTextureFromSurface(renderer,background);
    SDL_FreeSurface(background);

    printf("%d\n", tm_min);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_VolumeMusic(16);
    sound.backgroundSound = Mix_LoadMUS("yeeeha.MP3");
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
            Mix_PlayMusic(sound.backgroundSound, -1);
            SDL_Delay(1800);
            Mix_VolumeMusic(0);
            firstTime = SDL_GetTicks();
            ticks++;
        }
        SDL_Delay(10);

        // draws everything
		//SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_Rect bg = {0,0,1280,720};

		SDL_RenderCopy(renderer,bgtexture,NULL,&bg);

		SDL_RenderPresent(renderer);
    }

    Mix_CloseAudio();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}


