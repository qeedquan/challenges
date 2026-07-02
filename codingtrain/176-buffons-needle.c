/*

https://en.wikipedia.org/wiki/Buffon%27s_needle_problem
Estimate PI using Buffon's Needle algorithm

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum {
	WINDOW_WIDTH = 800,
	WINDOW_HEIGHT = 800,
};

SDL_Window *window;
SDL_Renderer *renderer;

double t;
double len;
double total;
double intersecting;

bool paused;

SDL_FPoint
rotate(SDL_FPoint p, double t)
{
	double c, s;

	c = cos(t);
	s = sin(t);
	return (SDL_FPoint){
		p.x * c - p.y * s,
		p.x * s + p.y * c,
	};
}

SDL_FPoint
translate(SDL_FPoint p, double x, double y)
{
	p.x += x;
	p.y += y;
	return p;
}

void
reset()
{
	double col;

	t = 20;
	len = 10;
	total = 0;
	intersecting = 0;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	for (col = 0; col < WINDOW_WIDTH; col += t) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderLine(renderer, col, 0, col, WINDOW_HEIGHT);
	}
}

void
update()
{
	SDL_FPoint p1, p2;
	double x, y;
	double angle;
	double closest;
	double d;
	double prob;
	double pie;
	int i;

	for (i = 0; i < 100; i++) {
		angle = SDL_randf() * SDL_PI_D;
		x = SDL_randf() * WINDOW_WIDTH;
		y = SDL_randf() * WINDOW_HEIGHT;

		closest = round(x / t);
		d = fabs(closest * t - x);

		if (d < (len * sin(fabs(angle))) / 2) {
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			intersecting += 1;
		} else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
		}

		p1 = (SDL_FPoint){ 0, -len / 2 };
		p2 = (SDL_FPoint){ 0, len / 2 };
		p1 = rotate(p1, angle);
		p2 = rotate(p2, angle);
		p1 = translate(p1, x, y);
		p2 = translate(p2, x, y);
		SDL_RenderLine(renderer, p1.x, p1.y, p2.x, p2.y);

		total += 1;
	}

	prob = intersecting / total;
	pie = (2 * len) / (prob * t);
	printf("%.5f\n", pie);
}

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Buffon's Needle", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_srand(time(NULL));
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppEvent(void *, SDL_Event *event)
{
	switch (event->type) {
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.key) {
		case SDLK_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDLK_SPACE:
			paused = !paused;
			break;
		}
		break;

	case SDL_EVENT_WINDOW_EXPOSED:
		reset();
		break;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_RenderPresent(renderer);

	if (!paused)
		update();

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
