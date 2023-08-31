#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif
#define SDL_MAIN_HANDLED
#include <SDL.h>
#undef main

#include "utils.c"
#include "logger.c"
#include "material_defs.c"
#include "reaction.c"
#include "pixel.c"
#include "sim.c"
#include "render.c"
#include "input.c"

int main()
{
#ifndef _WIN32
	time_handle = &time_spec;
#endif
	srand(((long int)cur_time) % (1 << 31));
	// logger("init");
	SDL_GetError();
	init_sim();
	init_render();
	printf("Init Done.\n");
	// long long z = 10;
	// for (int i = 0; i < 100; i++)
	// {
	// 	printf("%f\n", t_rand(&z));
	// }
	// return;
	for (unsigned long loop_count = 1; 1; loop_count++)
	{
		unsigned long start = cur_time();
		int quit = handle_input();
		if (quit)
		{
			printf("Quitting!\n");
			break;
		}
		// logger("tick");
		tick();
		display();
		logger("garbage");
		unsigned long end = cur_time();
		if (end > start)
		{ // stop sleeping for billion years if code is too fast
		  // SDL_Delay(10-min(end-start,10));
		}
		// SDL_Delay(1000);
		if (loop_count % 10 == 0)
		{
			show_logs(loop_count);
			show_logs(loop_count);
			// printf("%fFPS total\n", ((float)loop_count) / ((float)(cur_time() - ran) / 1000.0f));
		}
	}

	return 0;
}
