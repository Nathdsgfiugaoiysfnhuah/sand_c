#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "utils.c"
#include "material_defs.c"
#include "sim.c"
#include "render.c"

void init_world()
{
	for (int x = 0; x < WORLD_WIDTH; x++)
	{
		for (int y = 0; y < WORLD_HEIGHT; y++)
		{
			if (abs(x - WORLD_WIDTH / 2) < 2 || randf() < 0.1)
			{
				world[x][y] = get_particle(3);
			}
			else
			{
				world[x][y] = get_particle(0);
			}
		}
	}
}

int main(int argc, char **argv)
{
	time_handle = &time;
	srand((unsigned)gettimeofday(time_handle, NULL));

	init_world();
	return 0;
}
