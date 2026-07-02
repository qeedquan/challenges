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

int width, height;

SDL_FPoint control[4];

Uint64 start;

int pause;

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

float
lerp(float t, float a, float b)
{
	return a + t * (b - a);
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
}

void
initsdl(void)
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 800;
	h = 600;
	if (!SDL_CreateWindowAndRenderer("Sierpinski Triangle", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	resize(w, h);
}

void
reset(void)
{
	SDL_FPoint *cp;
	int i;

	control[0] = (SDL_FPoint){ width / 2.0, 0 };
	control[1] = (SDL_FPoint){ 0, height };
	control[2] = (SDL_FPoint){ width, height };
	control[3] = (SDL_FPoint){ SDL_rand(width), SDL_rand(height) };

	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);
	cairo_set_source_rgb(cr, 1, 1, 1);
	for (i = 0; i < 3; i++) {
		cp = &control[i];
		cairo_arc(cr, cp->x, cp->y, 8, 0, 2 * SDL_PI_F);
		cairo_fill(cr);
	}

	start = SDL_GetTicks();
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
				pause = !pause;
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
step(int iterations)
{
	static const float cols[3][3] = {
		{ 1, 0, 1 },
		{ 0, 1, 1 },
		{ 1, 1, 0 },
	};

	SDL_FPoint *cp, *cc;
	const float *col;
	int i, n;

	cc = &control[3];
	for (i = 0; i < iterations; i++) {
		n = SDL_rand(3);
		cp = &control[n];
		col = cols[n];

		cairo_set_source_rgb(cr, col[0], col[1], col[2]);
		cairo_arc(cr, cc->x, cc->y, 2, 0, 2 * SDL_PI_F);
		cairo_fill(cr);

		cc->x = lerp(0.5, cc->x, cp->x);
		cc->y = lerp(0.5, cc->y, cp->y);
	}
}

void
update(void)
{
	Uint64 ticks;
	int dt;

	ticks = SDL_GetTicks();
	dt = ticks - start;
	if (dt < 16)
		return;

	if (!pause)
		step(100);

	start = ticks;
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
	SDL_srand(time(NULL));
	initsdl();
	reset();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
