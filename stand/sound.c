#include "defs.h"

void volumeChanger(Main *main)
{
	Mix_VolumeMusic(main->sound.volume);
}

void changeVolume(Main *main, int level)
{
	if (level == 1 && main->sound.volume <128)
	{
		main->sound.volume += 2;
		volumeChanger(&*main);
		//Mix_VolumeMusic(main->sound.volume);
	}
	else if (level == 2 && main->sound.volume > 0)
	{
		main->sound.volume -= 2;
		volumeChanger(&*main);
		//Mix_VolumeMusic(main->sound.volume);			
	}
}

void changeSound(int num, Main *main)
{
	if (num == 0)
		main->sound.backgroundSound = Mix_LoadWAV("yeeeha.WAV");
	else if (num == 1)
		main->sound.backgroundSound = Mix_LoadWAV("adiosamigos.WAV");
	else if (num == 2)
		main->sound.backgroundSound = Mix_LoadWAV("yeeeha.WAV");
	else if (num == 3)
		main->sound.backgroundSound = Mix_LoadWAV("yeeeha.WAV");
	else if (num == 4)
		main->sound.backgroundSound = Mix_LoadWAV("America.WAV");
}