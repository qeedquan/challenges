/*

https://en.wikipedia.org/wiki/Bubble_sort

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

Uint64 start;

int *values;
int index;

int width, height;

int paused;

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!nmemb)
		nmemb = 1;
	if (!size)
		size = 1;
	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

void
reset()
{
	int i;

	free(values);
	values = xcalloc(width, sizeof(*values));
	for (i = 0; i < width; i++)
		values[i] = SDL_rand(height);

	index = 0;
	start = SDL_GetTicks();
}

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	w = 1024;
	h = 768;
	if (!SDL_CreateWindowAndRenderer("Bubble Sort Visualization", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_srand(time(NULL));

	width = w;
	height = h;
	reset();

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
			reset();
			break;
		}
		break;
	case SDL_EVENT_WINDOW_RESIZED:
		width = event->window.data1;
		height = event->window.data2;
		reset();
		break;
	}
	return SDL_APP_CONTINUE;
}

void
update()
{
	Uint64 ticks;
	int i;

	ticks = SDL_GetTicks();
	if (ticks - start < 10)
		return;
	start = ticks;

	if (paused)
		return;

	if (index >= width)
		return;

	for (i = 0; i < width - index - 1; i++) {
		if (values[i] > values[i + 1])
			swap(&values[i], &values[i + 1]);
	}
	index += 1;
}

void
draw()
{
	int i;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (i = 0; i < width; i++)
		SDL_RenderLine(renderer, i, height, i, height - values[i]);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	draw();
	SDL_RenderPresent(renderer);

	update();

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
