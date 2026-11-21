/*

https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

typedef struct {
	int rows;
	int cols;
	char **cur;
	char **nxt;
} Life;

SDL_Window *window;
SDL_Renderer *renderer;

Uint64 start;

Life life;

float width, height;
float resolution;

int paused;

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
lifenew(Life *l, int rows, int cols)
{
	int i, j;

	l->rows = rows;
	l->cols = cols;

	l->cur = xcalloc(l->cols, sizeof(*l->cur));
	l->nxt = xcalloc(l->cols, sizeof(*l->nxt));

	for (i = 0; i < l->cols; i++) {
		l->cur[i] = xcalloc(l->rows, sizeof(*l->cur[i]));
		l->nxt[i] = xcalloc(l->rows, sizeof(*l->nxt[i]));
		for (j = 0; j < l->rows; j++) {
			l->cur[i][j] = SDL_rand(2);
		}
	}
}

void
lifefree(Life *l)
{
	int i;

	if (!l)
		return;

	for (i = 0; i < l->cols; i++) {
		free(l->cur[i]);
		free(l->nxt[i]);
	}
	free(l->cur);
	free(l->nxt);
}

int
lifecount(char **grid, int rows, int cols, int x, int y)
{
	int sum;
	int row, col;
	int i, j;

	sum = 0;
	for (i = -1; i < 2; i++) {
		for (j = -1; j < 2; j++) {
			col = (x + i + cols) % cols;
			row = (y + j + rows) % rows;
			sum += grid[col][row];
		}
	}
	sum -= grid[x][y];
	return sum;
}

void
lifestep(Life *l)
{
	char **cur;
	char **nxt;
	int state;
	int neighbors;
	int i, j;

	for (i = 0; i < l->cols; i++) {
		for (j = 0; j < l->rows; j++) {
			state = l->cur[i][j];
			neighbors = lifecount(l->cur, l->rows, l->cols, i, j);

			if (state == 0 && neighbors == 3) {
				l->nxt[i][j] = 1;
			} else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
				l->nxt[i][j] = 0;
			} else {
				l->nxt[i][j] = state;
			}
		}
	}

	cur = l->nxt;
	nxt = l->cur;
	l->cur = cur;
	l->nxt = nxt;
}

void
lifedraw(Life *l)
{
	SDL_FRect rect;
	int i, j;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (i = 0; i < l->cols; i++) {
		for (j = 0; j < l->rows; j++) {
			rect.x = i * resolution;
			rect.y = j * resolution;
			rect.w = resolution - 1;
			rect.h = resolution - 1;
			if (l->cur[i][j])
				SDL_RenderFillRect(renderer, &rect);
		}
	}
}

void
reset()
{
	lifefree(&life);
	lifenew(&life, ceil(height / resolution), ceil(width / resolution));
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

	w = 600;
	h = 400;
	if (!SDL_CreateWindowAndRenderer("Game of Life", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_srand(time(NULL));

	width = w;
	height = h;
	resolution = 10;
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

	ticks = SDL_GetTicks();
	if (ticks - start < 50)
		return;
	start = ticks;

	if (!paused)
		lifestep(&life);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	lifedraw(&life);
	SDL_RenderPresent(renderer);

	update();

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
