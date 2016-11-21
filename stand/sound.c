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
	}
	else if (level == 2 && main->sound.volume > 0)
	{
		main->sound.volume -= 2;
		volumeChanger(&*main);		
	}
}

void changeSound(int num, Main *main)
{
	main->sound.currSound = num;
	if (num == 0)
	{
		main->sound.backgroundSound = Mix_LoadWAV("sounds/yeeeha.WAV");
		main->sound.currSound = 0;
	}
	else if (num == 1)
	{
		main->sound.backgroundSound = Mix_LoadWAV("sounds/adiosamigos.WAV");
		main->sound.currSound = 1;
	}
	else if (num == 2)
	{
		main->sound.backgroundSound = Mix_LoadWAV("sounds/quacker.WAV");
		main->sound.currSound = 2;
	}
	else if (num == 3)
	{
		main->sound.backgroundSound = Mix_LoadWAV("sounds/rooster.WAV");
		main->sound.currSound = 3;
	}
}