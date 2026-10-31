/*

https://en.wikipedia.org/wiki/Superellipse

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum {
	WINDOW_WIDTH = 1024,
	WINDOW_HEIGHT = 768,
};

typedef struct {
	float a;
	float b;
	float n;
} Superellipse;

SDL_Window *window;
SDL_Renderer *renderer;

Superellipse se;

float
sgn(float x)
{
	if (x == 0)
		return 0;
	if (x < 0)
		return -1;
	return 1;
}

void
reset()
{
	se = (Superellipse){
		.a = 100,
		.b = 100,
		.n = 10,
	};
}

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Superellipse", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	reset();

	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppEvent(void *, SDL_Event *event)
{
	static const float step = 1e-1;

	switch (event->type) {
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.key) {
		case SDLK_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDLK_LEFT:
			se.n -= step;
			break;
		case SDLK_RIGHT:
			se.n += step;
			break;
		}
		break;
	}
	se.n = SDL_clamp(se.n, 0, se.n);
	return SDL_APP_CONTINUE;
}

SDL_FPoint
formula(float a, float b, float n, float angle)
{
	float na;
	float x, y;

	na = 2 / n;
	x = pow(fabs(cos(angle)), na) * a * sgn(cos(angle));
	y = pow(fabs(sin(angle)), na) * b * sgn(sin(angle));
	x += WINDOW_WIDTH / 2.0;
	y += WINDOW_HEIGHT / 2.0;
	return (SDL_FPoint){ x, y };
}

void
draw_superellipse()
{
	SDL_FPoint p0, p1, p2;
	float angle;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	p0 = formula(se.a, se.b, se.n, 0);
	p1 = p0;
	for (angle = 0.1; angle < 2 * SDL_PI_F; angle += 0.1) {
		p2 = formula(se.a, se.b, se.n, angle);
		SDL_RenderLine(renderer, p1.x, p1.y, p2.x, p2.y);
		p1 = p2;
	}
	SDL_RenderLine(renderer, p1.x, p1.y, p0.x, p0.y);
	SDL_RenderDebugTextFormat(renderer, 16, 16, "n=%.3f", se.n);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);
	draw_superellipse();
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
