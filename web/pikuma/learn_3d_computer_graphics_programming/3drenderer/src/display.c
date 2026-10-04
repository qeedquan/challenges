#include "display.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static uint32_t *colorbuffer = NULL;
static float *zbuffer = NULL;

static SDL_Texture *colorbuffer_texture = NULL;
static int window_width = 320;
static int window_height = 240;

static int render_method = 0;
static int cull_method = 0;

int
get_window_width(void)
{
	return window_width;
}

int
get_window_height(void)
{
	return window_height;
}

bool
init_window(void)
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
		fprintf(stderr, "Error initializing SDL.\n");
		return false;
	}

	// Create a SDL Window
	window = SDL_CreateWindow(
	    "3D Renderer",
	    window_width * 4,
	    window_height * 4,
	    0);
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

	// Allocate the required memory in bytes to hold the color buffer and the z-buffer
	colorbuffer = (uint32_t *)malloc(sizeof(uint32_t) * window_width * window_height);
	zbuffer = (float *)malloc(sizeof(float) * window_width * window_height);

	// Creating a SDL texture that is used to display the color buffer
	colorbuffer_texture = SDL_CreateTexture(
	    renderer,
	    SDL_PIXELFORMAT_RGBA32,
	    SDL_TEXTUREACCESS_STREAMING,
	    window_width,
	    window_height);

	// Lock the mouse and hide the cursor
	SDL_SetWindowRelativeMouseMode(window, 1);

	return true;
}

void
set_render_method(int method)
{
	render_method = method;
}

void
set_cull_method(int method)
{
	cull_method = method;
}

bool
should_render_wire(void)
{
	return render_method == RENDER_WIRE ||
	       render_method == RENDER_WIRE_VERTEX ||
	       render_method == RENDER_FILL_TRIANGLE_WIRE ||
	       render_method == RENDER_TEXTURED_WIRE;
}

bool
should_render_wire_vertex(void)
{
	return render_method == RENDER_WIRE_VERTEX;
}

bool
should_render_filled_triangle(void)
{
	return render_method == RENDER_FILL_TRIANGLE ||
	       render_method == RENDER_FILL_TRIANGLE_WIRE;
}

bool
should_render_textured_triangle(void)
{
	return render_method == RENDER_TEXTURED ||
	       render_method == RENDER_TEXTURED_WIRE;
}

bool
should_cull_backface(void)
{
	return cull_method == CULL_BACKFACE;
}

void
draw_grid(void)
{
	for (int y = 0; y < window_height; y += 10) {
		for (int x = 0; x < window_width; x += 10) {
			colorbuffer[(window_width * y) + x] = 0xFF444444;
		}
	}
}

void
draw_pixel(int x, int y, uint32_t color)
{
	if (x < 0 || x >= window_width || y < 0 || y >= window_height) {
		return;
	}
	colorbuffer[(window_width * y) + x] = color;
}

void
draw_line(float x0, float y0, float x1, float y1, uint32_t color)
{
	float delta_x = (x1 - x0);
	float delta_y = (y1 - y0);

	float longest_side_length = (fabs(delta_x) >= fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);

	float x_inc = delta_x / longest_side_length;
	float y_inc = delta_y / longest_side_length;

	float current_x = x0;
	float current_y = y0;

	for (int i = 0; i <= longest_side_length; i++) {
		draw_pixel(round(current_x), round(current_y), color);
		current_x += x_inc;
		current_y += y_inc;
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
	    colorbuffer_texture,
	    NULL,
	    colorbuffer,
	    (int)(window_width * sizeof(uint32_t)));
	SDL_RenderTexture(renderer, colorbuffer_texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void
clear_color_buffer(uint32_t color)
{
	for (int i = 0; i < window_width * window_height; i++) {
		colorbuffer[i] = color;
	}
}

void
clear_z_buffer(void)
{
	for (int i = 0; i < window_width * window_height; i++) {
		zbuffer[i] = 1.0;
	}
}

float
get_zbuffer_at(int x, int y)
{
	if (x < 0 || x >= window_width || y < 0 || y >= window_height) {
		return 1.0;
	}
	return zbuffer[(window_width * y) + x];
}

void
update_zbuffer_at(int x, int y, float value)
{
	if (x < 0 || x >= window_width || y < 0 || y >= window_height) {
		return;
	}
	zbuffer[(window_width * y) + x] = value;
}

void
destroy_window(void)
{
	free(colorbuffer);
	free(zbuffer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
