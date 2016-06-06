#include "definition.h"

int main(int argc, char *argv[])
{


    srand(time(NULL));


    loadSounds(&player);
    initMenu(&menu,&player);

    /**** MAIN MENU ****/
    while(!exit)
    {

            Mix_PlayMusic(player.sounds.backgroundSound, -1);

        /**** SKRIV IN IP ****/
        while(enterIPmenu)
        {
            pickCharacter = enterIP(&player);
            SDL_StopTextInput();
            if(pickCharacter)
            {
                if(!(networkInit(&client,&player,tmp)))
                {
                    ingame = 0;
                    pickCharacter = 0;
                    enterIPmenu = 0;
                }
                else
                {
                    player.connected = 1;
                    player.disconnected = 0;
                }
            }
            else
                enterIPmenu = 0;

            /**** PICK CHARACTER ****/
            while(pickCharacter)
            {
                displayMenu(pick);
                ingame = handlePick(&pickCharacter,&player);
                if(ingame==1)
                {
                    player.gameStarted = 1;
                    initPlayer(&player);
                    clearCartridge(ammo);
                    send_data(&player,&client,2);
                    player.deltaTimeMs = 0;
                    player.alive = 0;
                    send_data(&player,&client,12);
                }
                recv_data(&player,&client,&done,ammo);

                /**** INGAME ****/
                while(ingame==1)
                {
                    if(player.deltaTimeMs < 1)
                    {
                        frameStart = SDL_GetTicks();
                        SDL_Delay(1);
                        frameEnd = SDL_GetTicks();
                        player.deltaTimeMs = frameEnd-frameStart;
                    }

                    direct = 0;
                    done = 0;

                    // hanterar spelarens handlingar
                    done = processEvents(&player,ammo,&moved,&type,&direct,&client);

                    updateEnemyBullet(&player);
                    updateLogic(&player,ammo);
                    if(player.alive)
                        collisionDetect(&player, &direct);
                    bulletGone(ammo,&player,&client);

                    // skickar data till servern
                    if(moved && player.alive)
                    {
                        send_data(&player,&client,type);
                        moved = 0;
                    }

                    // tar emot data från servern
                    if (done != 1)
                        recv_data(&player,&client,&done,ammo);

                    // ritar allting på spelplanen
                    doRender(&player,ammo);

                    detectHit(&player,ammo,&client);

                    /** RESPAWNING IN 4 SECONDS **/
                    if(!player.alive)
                    {
                        currentTime = SDL_GetTicks();
                        currentTime = currentTime/1000;
                        if(currentTime>lastTime)
                        {
                            spawnTimer--;
                        }
                        lastTime = currentTime;
                        if(spawnTimer<= 0)
                        {
                            respawn(&player);
                            player.alive = 1;
                            send_data(&player,&client,2);
                            spawnTimer = 4;
                        }
                    }

                    if(player.gameStarted)
                    {
                        player.currentRTime = SDL_GetTicks();
                        timeDiff = player.currentRTime - player.lastRTime;
                        player.roundTime = player.roundTime - timeDiff;
                        player.lastRTime = player.currentRTime;
                        if(player.roundTime <= (lastPrint-1000))
                        {
                            printf("Time left: %d\n",player.roundTime/1000);
                            lastPrint = player.roundTime;
                        }
                    }

                    if(done || player.disconnected)
                    {
                        ingame = 0;
                        if(LINUX)
                            Mix_PlayMusic(player.sounds.backgroundLinux, -1);
                        else
                            Mix_PlayMusic(player.sounds.backgroundSound, -1);
                    }
                    frameEnd = SDL_GetTicks();
                    player.deltaTimeMs = frameEnd - frameStart;
                }

            }
        }
    }
    TTF_Quit();
    if(LINUX)
    {
        Mix_FreeMusic(player.sounds.backgroundLinux);
    }
    else
    {
        Mix_FreeMusic(player.sounds.backgroundSound);
    }
    Mix_CloseAudio();
    free(tmp);
    SDLNet_Quit();
    Quit();



    return 0;
}

