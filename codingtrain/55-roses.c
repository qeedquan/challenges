/*

https://en.wikipedia.org/wiki/Rose_(mathematics)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

float radius;
float petals;
float degrees;

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
initsdl(void)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", strerror(errno));

	if (!SDL_CreateWindowAndRenderer("Roses", 800, 800, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create SDL window: %s", strerror(errno));
}

void
reset(void)
{
	radius = 200;
	petals = 5;
	degrees = 8;
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
				reset();
				break;
			case SDLK_UP:
				petals += 1;
				break;
			case SDLK_DOWN:
				petals -= 1;
				break;
			case SDLK_LEFT:
				degrees -= 1;
				break;
			case SDLK_RIGHT:
				degrees += 1;
				break;
			}
			break;
		}
	}

	petals = SDL_clamp(petals, 0, petals);
	degrees = SDL_clamp(degrees, 0, degrees);
}

void
rose(float n, float d, float R)
{
	float px, py;
	float x, y;
	float k, a, r;
	int w, h;

	SDL_GetCurrentRenderOutputSize(renderer, &w, &h);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	k = n / d;
	for (a = 0; a < 2 * SDL_PI_F * d; a += 0.02) {
		r = R * cos(k * a);
		x = (r * cos(a)) + (w / 2);
		y = (r * sin(a)) + (h / 2);

		if (a > 0)
			SDL_RenderLine(renderer, px, py, x, y);

		px = x;
		py = y;
	}
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);
	rose(petals, degrees, radius);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	reset();
	for (;;) {
		event();
		draw();
	}
	return 0;
}
