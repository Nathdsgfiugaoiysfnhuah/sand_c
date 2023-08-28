SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
unsigned char screen[WORLD_HEIGHT][WORLD_WIDTH][4]; // consider that the struct probably alligns this correctly anyway

void init_render()
{
	SDL_Init(0);
	window = SDL_CreateWindow("Sand Sim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0); // 0 is def wrong flags, but i dont know which ones are right
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WORLD_WIDTH, WORLD_HEIGHT);
}

void display()
{
	for (int x = 0; x < WORLD_WIDTH; x++)
	{
		for (int y = 0; y < WORLD_HEIGHT; y++)
		{
			struct colour cur_col = world[x][y].col;
			screen[WORLD_HEIGHT - y - 1][x][0] = (unsigned char)(cur_col.red * 255.9);
			screen[WORLD_HEIGHT - y - 1][x][1] = (unsigned char)(cur_col.green * 255.9);
			screen[WORLD_HEIGHT - y - 1][x][2] = (unsigned char)(cur_col.blue * 255.9);
			screen[WORLD_HEIGHT - y - 1][x][3] = (unsigned char)(cur_col.alpha * 255.9);
		}
	}
	SDL_UpdateTexture(texture, NULL, screen, 4 * WORLD_WIDTH);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
