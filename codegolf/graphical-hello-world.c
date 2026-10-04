/*

In this challenge, you will create the shortest graphical program that displays exactly "Hello, world!"

You will need no input.

You might be asking yourself, "what does he mean by graphical?" Well, by graphical, I mean not writing to stdout. For example, look at my ES6 answer, which makes an alert box pop up rather than the traditional hello world where you do write to stdout:

alert('Hello, world!')
That doesn't write to stdout. Which is what I am challenging you to do today.

Formatting
This is an example post in markdown for the ES6 snippet I posted above:

# JavaScript (ES6), 22 bytes

    alert('Hello, world!')
View an example post.

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum {
	WINDOW_WIDTH = 256,
	WINDOW_HEIGHT = 128,
};

SDL_Window *window;
SDL_Renderer *renderer;

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Hello, World!", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

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
		}
		break;
	}
	return SDL_APP_CONTINUE;
}

void
draw_text(const char *text)
{
	int x, y, len;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	len = strlen(text);
	x = (WINDOW_WIDTH / 2) - ((8 * len) / 2);
	y = WINDOW_HEIGHT / 2;
	SDL_RenderDebugText(renderer, x, y, text);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
	SDL_RenderClear(renderer);
	draw_text("Hello, World!");
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
