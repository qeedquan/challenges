/*

https://en.wikipedia.org/wiki/Monte_Carlo_method

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
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

double radius;
double circle;
double total;

double bestdiff;
double bestpi;

int paused;

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
	radius = SDL_min(width, height) / 2;
	circle = 0;
	total = 0;
	bestdiff = FLT_MAX;
	bestpi = 0;
	
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);

	cairo_set_line_width(cr, 4);
	cairo_identity_matrix(cr);
	cairo_translate(cr, width / 2.0, height / 2.0);
	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_arc(cr, 0, 0, radius, 0, 2 * SDL_PI_D);
	cairo_stroke(cr);

	printf("\n");
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

	width = w;
	height = h;
	reset();
}

void
initsdl(void)
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 800;
	h = 800;
	if (!SDL_CreateWindowAndRenderer("Monte Carlo Approximation of PI", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	resize(w, h);
}

void
event(void)
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
				paused = !paused;
				break;
			case SDLK_RETURN:
				reset();
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
update(void)
{
	double d, x, y;
	double diff, pi;
	int i;

	if (paused)
		return;

	cairo_set_line_width(cr, 1);
	for (i = 0; i < 250; i++) {
		x = (SDL_randf() * 2 * radius) - radius;
		y = (SDL_randf() * 2 * radius) - radius;
		d = (x * x) + (y * y);

		total += 1;
		if (d < radius * radius) {
			circle += 1;
			cairo_set_source_rgb(cr, 0.94, 0.39, 0.64);
		} else {
			cairo_set_source_rgb(cr, 0.18, 0.77, 0.96);
		}
		cairo_rectangle(cr, x, y, 1, 1);
		cairo_stroke(cr);
	}

	pi = (4 * circle / total);
	diff = fabs(SDL_PI_D - pi);
	if (diff < bestdiff) {
		bestdiff = diff;
		bestpi = pi;
		printf("PI: %f\n", pi);
	}
}

void
upload(void)
{
	void *pixels, *data;
	int pitch;

	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	data = cairo_image_surface_get_data(canvas);
	memcpy(pixels, data, pitch * height);
	SDL_UnlockTexture(texture);
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	upload();

	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
