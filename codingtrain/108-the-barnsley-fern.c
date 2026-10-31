/*

https://en.wikipedia.org/wiki/Barnsley_fern

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>

typedef struct {
	float x, y;
} Fern;

SDL_Window *window;
SDL_Renderer *renderer;
Fern fern;

float
lerp(float t, float a, float b)
{
	return a + t * (b - a);
}

float
unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float
linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(unlerp(x, a, b), c, d);
}

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
ferninit(Fern *f)
{
	f->x = f->y = 0;
}

void
fernnext(Fern *f)
{
	float nx, ny;
	float x, y;
	float r;

	x = f->x;
	y = f->y;
	r = SDL_randf();
	if (r < 0.01) {
		nx = 0;
		ny = 0.16 * y;
	} else if (r < 0.86) {
		nx = 0.85 * x + 0.04 * y;
		ny = -0.04 * x + 0.85 * y + 1.6;
	} else if (r < 0.93) {
		nx = 0.2 * x + -0.26 * y;
		ny = 0.23 * x + 0.22 * y + 1.6;
	} else {
		nx = -0.15 * x + 0.28 * y;
		ny = 0.26 * x + 0.24 * y + 0.44;
	}

	f->x = nx;
	f->y = ny;
}

void
ferndraw(Fern *f)
{
	int width;
	int height;
	SDL_FRect r;

	SDL_GetRenderOutputSize(renderer, &width, &height);
	r.x = linear_remap(f->x, -2.182, 2.6558, 0, width);
	r.y = linear_remap(f->y, 0, 9.9983, height, 0);
	r.w = 2;
	r.h = 2;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderRect(renderer, &r);
}

void
reset()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	ferninit(&fern);
}

void
initsdl()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	if (!SDL_CreateWindowAndRenderer("Barnsley Fern", 640, 360, 0, &window, &renderer))
		fatal("Failed to create SDL window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_srand(time(NULL));

	reset();
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
			}
			break;
		}
	}
}

void
draw()
{
	int i;

	for (i = 0; i < 100; i++) {
		ferndraw(&fern);
		fernnext(&fern);
	}
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
