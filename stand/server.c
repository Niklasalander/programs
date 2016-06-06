
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>


struct Program
{
    SDL_Window *window;
    SDL_Renderer *renderer;
};


int main(int argc, char **argv)
{
    int x,y,type,id,next=0,offset,max,hitid;

    SDL_Event event;


    SDL_Init(SDL_INIT_EVERYTHING);

    int i,k, j,len,size;
    int killed,died,scoreUpdate = 0;
    int running = 1;

    SDL_Init(SDL_INIT_VIDEO);

    struct Program program;
    program.window = SDL_CreateWindow("Game Window",                     // window title
                                      SDL_WINDOWPOS_UNDEFINED,           // initial x position
                                      SDL_WINDOWPOS_UNDEFINED,           // initial y position
                                      640,                               // width, in pixels
                                      480,                               // height, in pixels
                                      0                                  // flags
                                     );
    program.renderer = SDL_CreateRenderer(program.window, -1, SDL_RENDERER_ACCELERATED);

    while(running)
    {

        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_1:
                    running = 0;
                default:
                    break;
                }
            }
        }



        SDL_Delay(20);
        if(running == 0)
        {
            for(i=5; i>0; i--)
            {
                printf("Shutting down in %d seconds.\n",i);
                SDL_Delay(1000);
            }
        }
    }

    /* shutdown SDL */
    SDL_Quit();

    return(0);
}
