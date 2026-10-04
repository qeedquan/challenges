/*

Proto space invaders

This is a graphical output challenge where the task is to give the shortest code per language.

Task

Your code should allow the user to move the following alien around the screen/window.

Your code can simply load it from a local file. Feel free to convert it to another standard image format or even to fix the small pixel errors in the image that were pointed out in the comments.

The background should be white and the window/screen must be at least 400 pixels by 400 pixels. If your language doesn't support windows/screens that large then use the largest size it does support as long as that is not less than 200 by 200.

To move the alien around the screen the code should support up/down/left/right using the arrows keys on a standard keyboard.

Your code should be a full program.

Restrictions/constraints

The alien should stop at the borders. It should also move at a uniform rate smoothly with no visible flickering or stuttering and be shown at at least 24fps. It should take between 2 and 5 seconds to go from one side of the screen/window to the other.

Languages and libraries

You can use any language or library you like (that wasn't designed for this challenge). However, I would like to be able to test your code if possible so if you can provide clear instructions for how to run it in Ubuntu that would be very much appreciated.

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum {
	WINDOW_WIDTH = 640,
	WINDOW_HEIGHT = 480,
};

SDL_Window *window;
SDL_Renderer *renderer;

SDL_Texture *texture;
int texture_width;
int texture_height;

SDL_FPoint invader;

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	SDL_Surface *surface;
	char *bmp_path;
	SDL_AppResult status;

	status = SDL_APP_CONTINUE;
	bmp_path = NULL;
	surface = NULL;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		goto error;
	}

	if (!SDL_CreateWindowAndRenderer("Proto Space Invader", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		goto error;
	}

	SDL_asprintf(&bmp_path, "%sinvader.bmp", SDL_GetBasePath());
	if (!bmp_path) {
		SDL_Log("Couldn't allocate memory for BMP path");
		goto error;
	}

	surface = SDL_LoadBMP(bmp_path);
	if (!surface) {
		SDL_Log("Couldn't load bitmap: %s", SDL_GetError());
		goto error;
	}

	texture_width = surface->w;
	texture_height = surface->h;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) {
		SDL_Log("Couldn't create static texture: %s", SDL_GetError());
		goto error;
	}

	if (0) {
	error:
		status = SDL_APP_FAILURE;
	}

	SDL_free(bmp_path);
	SDL_DestroySurface(surface);

	return status;
}

SDL_AppResult
SDL_AppEvent(void *, SDL_Event *event)
{
	int step;

	step = 10;
	switch (event->type) {
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.key) {
		case SDLK_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDLK_UP:
			invader.y -= step;
			break;
		case SDLK_DOWN:
			invader.y += step;
			break;
		case SDLK_LEFT:
			invader.x -= step;
			break;
		case SDLK_RIGHT:
			invader.x += step;
			break;
		}
		break;
	}
	invader.x = SDL_clamp(invader.x, 0, WINDOW_WIDTH - texture_width);
	invader.y = SDL_clamp(invader.y, 0, WINDOW_HEIGHT - texture_height);
	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_FRect dst_rect;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	dst_rect.x = invader.x;
	dst_rect.y = invader.y;
	dst_rect.w = texture_width;
	dst_rect.h = texture_height;
	SDL_RenderTexture(renderer, texture, NULL, &dst_rect);

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
	SDL_DestroyTexture(texture);
}
