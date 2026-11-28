#include "display.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
uint32_t *color_buffer = NULL;
SDL_Texture *color_buffer_texture = NULL;
int window_width = 800;
int window_height = 600;

bool
initialize_window(void)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "Error initializing SDL.\n");
		return false;
	}

	// Set width and height of the SDL window with the max screen resolution
	SDL_DisplayID id;
	const SDL_DisplayMode *dm;
	id = SDL_GetPrimaryDisplay();
	dm = SDL_GetCurrentDisplayMode(id);
	if (!dm) {
		fprintf(stderr, "Failed to get current display: %s\n", SDL_GetError());
		return false;
	}

	window_width = dm->w;
	window_height = dm->h;

	// Create a SDL Window
	window = SDL_CreateWindow(
	    "Fixed Timestep",
	    window_width,
	    window_height,
	    SDL_WINDOW_BORDERLESS);
	if (!window) {
		fprintf(stderr, "Error creating SDL window.\n");
		return false;
	}

	// Create a SDL renderer
	renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer) {
		fprintf(stderr, "Error creating SDL renderer.\n");
		return false;
	}

	return true;
}

void
draw_grid(void)
{
	for (int y = 0; y < window_height; y += 10) {
		for (int x = 0; x < window_width; x += 10) {
			color_buffer[(window_width * y) + x] = 0xFF444444;
		}
	}
}

void
draw_pixel(int x, int y, uint32_t color)
{
	if (x >= 0 && x < window_width && y >= 0 && y < window_height) {
		color_buffer[(window_width * y) + x] = color;
	}
}

void
draw_rect(int x, int y, int width, int height, uint32_t color)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int current_x = x + i;
			int current_y = y + j;
			draw_pixel(current_x, current_y, color);
		}
	}
}

void
render_color_buffer(void)
{
	SDL_UpdateTexture(
	    color_buffer_texture,
	    NULL,
	    color_buffer,
	    (int)(window_width * sizeof(uint32_t)));
	SDL_RenderTexture(renderer, color_buffer_texture, NULL, NULL);
}

void
clear_color_buffer(uint32_t color)
{
	for (int y = 0; y < window_height; y++) {
		for (int x = 0; x < window_width; x++) {
			color_buffer[(window_width * y) + x] = color;
		}
	}
}

void
destroy_window(void)
{
	free(color_buffer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
