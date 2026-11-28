/*

https://en.wikipedia.org/wiki/Bitwise_operation

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <SDL3/SDL.h>
#include <cairo.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

cairo_surface_t *canvas;
cairo_t *cr;

double width, height;

Uint8 byte;
double radius;

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
reset()
{
	byte = SDL_rand(256);
}

void
resize(int w, int h)
{
	if (texture)
		SDL_DestroyTexture(texture);

	if (canvas) {
		cairo_surface_destroy(canvas);
		cairo_destroy(cr);
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	canvas = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w, h);
	cr = cairo_create(canvas);
	cairo_select_font_face(cr, "Purisa", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(cr, 25);

	width = w;
	height = h;
	radius = 25;
	reset();
}

void
initsdl()
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 640;
	h = 480;
	if (!SDL_CreateWindowAndRenderer("Bit Shifting", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_srand(time(NULL));

	resize(w, h);
}

void
event()
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_EVENT_QUIT:
			exit(0);

		case SDL_EVENT_KEY_DOWN:
			switch (ev.key.key) {
			case SDLK_ESCAPE:
				exit(0);
			case SDLK_SPACE:
				reset();
				break;
			case SDLK_LEFT:
				byte <<= 1;
				break;
			case SDLK_RIGHT:
				byte >>= 1;
				break;
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			break;
		}
	}
}

void
upload()
{
	void *pixels, *data;
	int pitch;

	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	data = cairo_image_surface_get_data(canvas);
	memcpy(pixels, data, pitch * height);
	SDL_UnlockTexture(texture);
}

void
drawbyte()
{
	char str[16];
	double x, y, space;
	int i;

	cairo_set_source_rgb(cr, 0.2, 0.2, 0.2);
	cairo_paint(cr);

	cairo_set_line_width(cr, 2);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_new_path(cr);
	space = radius * 2;
	x = (width / 2) - (3.5 * (radius + space));
	y = height / 2;
	for (i = 0; i < 8; i++) {
		cairo_arc(cr, x, y, radius, 0, 2 * SDL_PI_F);
		if (byte & (1 << (7 - i)))
			cairo_fill(cr);
		else
			cairo_stroke(cr);
		x += radius + space;
	}
	cairo_close_path(cr);

	snprintf(str, sizeof(str), "% 3d", byte);
	x = (width / 2) - (radius * 2);
	y = (height / 2) + (radius * 3);
	cairo_new_path(cr);
	cairo_move_to(cr, x, y);
	cairo_show_text(cr, str);
	cairo_close_path(cr);
}

void
draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	drawbyte();
	upload();

	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main()
{
	initsdl();
	for (;;) {
		event();
		draw();
	}
	return 0;
}
