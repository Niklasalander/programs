#include "defs.h"

void changeVolume(Sound *sound, int level)
{
	if (level == 1 && sound->volume <30)
		sound->volume += 2;
	else if (level == 2 && sound->volume > 0)
		sound->volume -= 2;
}