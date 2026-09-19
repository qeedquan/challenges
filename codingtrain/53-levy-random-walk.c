/*

https://en.wikipedia.org/wiki/L%C3%A9vy_flight

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

Uint64 start;

int width;
int height;

SDL_FPoint position;
SDL_FPoint previous;

bool paused;

SDL_FPoint
random2d()
{
	float t;

	t = SDL_randf() * 2 * SDL_PI_F;
	return (SDL_FPoint){
		.x = cos(t),
		.y = sin(t),
	};
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
resize(int w, int h)
{
	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, w, h);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	if (!SDL_SetRenderTarget(renderer, texture))
		fatal("Failed to set render target: %s", SDL_GetError());

	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_SetRenderTarget(renderer, NULL);

	width = w;
	height = h;
}

void
reset(int w, int h)
{
	position = (SDL_FPoint){ w * 0.5, h * 0.5 };
	previous = position;
	start = SDL_GetTicks();
	resize(w, h);
}

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	w = 800;
	h = 800;
	if (!SDL_CreateWindowAndRenderer("Levy Random Walk", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_srand(time(NULL));
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	reset(w, h);
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
		case SDLK_RETURN:
			reset(width, height);
			break;
		}
		break;
	case SDL_EVENT_WINDOW_RESIZED:
		reset(event->window.data1, event->window.data2);
		break;
	}
	return SDL_APP_CONTINUE;
}

void
update()
{
	Uint64 now;
	SDL_FPoint step;
	float scale;

	now = SDL_GetTicks();
	if (now - start < 5)
		return;
	start = now;

	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderLine(renderer, position.x, position.y, previous.x, previous.y);

	previous = position;
	step = random2d();
	scale = 2;
	if (SDL_rand(100) < 1)
		scale = 25 + SDL_rand(75);

	step.x *= scale;
	step.y *= scale;

	position.x += step.x;
	position.y += step.y;

	SDL_SetRenderTarget(renderer, NULL);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	if (!paused)
		update();

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
