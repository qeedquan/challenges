/*

During work on some project I needed to draw pixels on screen. I found some put-pixel function in JS, but code was quite big and clumsy - so I wonder, how small put-pixel function can be...

Challenge
Create the smallest put-pixel function.

We count size of whole program: initialization code (if needed), function and code necessary to draw the test case witch 11 pixels. If your language does not support functions, you can use what you have. Language must be capable of graphical output or drawing charts (saving files is not allowed).

The function (or program) should accept as input the following 6 independent integers pixel parameters (and other if needed):

x from 0 to at least 255 - horizontal position
y from 0 to at least 255 - vertical position
R from 0 to 255 - red color component
G from 0 to 255 - green color component
B from 0 to 255 - blue color component
A from 0 to 255 - alpha (if 0 then the pixel color is fully transparent, and we see old background pixel; if 255 then the pixel is completely opaque; for values 0<A<255 we calculate color in linear way, using the old and new pixel colors).
more parameters than above 6 is allowed and parameters can have any order. Number parameters can be strings and have base different than 10 or be coded in some way (if chosen language requires that).

Test case
On output you should draw following test-case with 11 pixels (I will use putPixel(x,y,R,G,B,A) as example to show case)

putPixel(126, 127, 255,   0,   0, 255) // Red
putPixel(127, 127,   0, 255,   0, 255) // Green
putPixel(128, 127,   0,   0, 255, 255) // Blue
putPixel(129, 127, 255,   0,   0, 255) // Red
putPixel(129, 127,   0, 255,   0, 127) // Dark Yellow (previous red + transparent green)

putPixel(126, 128,   0,   0,   0, 255) // Black
putPixel(127, 128, 255, 255, 255, 255) // White
putPixel(128, 128, 255,   0,   0, 255) // Red
putPixel(128, 128,   0,   0, 255, 127) // Dark pink (previous red + transparent blue)
putPixel(129, 128,   0, 255,   0, 255) // Blue
putPixel(129, 128,   0,   0, 255, 127) // Dark sea-blue (previous blue + transparent green)

We should see 8 pixel (but we paint 11pixel, but 3 of them are transparent paints on already colored pixels).

https://i.sstatic.net/6TgWT.png

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum {
	WINDOW_WIDTH = 692,
	WINDOW_HEIGHT = 346,
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

	if (!SDL_CreateWindowAndRenderer("PUT-PIXEL", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

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
		}
		break;
	}
	return SDL_APP_CONTINUE;
}

void
block(int x, int y, int r, int g, int b, int a)
{
	SDL_FRect rect;

	rect.w = WINDOW_WIDTH / 4;
	rect.h = WINDOW_HEIGHT / 2;
	rect.x = (x - 126) * rect.w;
	rect.y = (y - 127) * rect.h;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
}

void
draw()
{
	block(126, 127, 255, 0, 0, 255); // Red
	block(127, 127, 0, 255, 0, 255); // Green
	block(128, 127, 0, 0, 255, 255); // Blue
	block(129, 127, 255, 0, 0, 255); // Red
	block(129, 127, 0, 255, 0, 127); // Dark Yellow (previous red + transparent green)

	block(126, 128, 0, 0, 0, 255);       // Black
	block(127, 128, 255, 255, 255, 255); // White
	block(128, 128, 255, 0, 0, 255);     // Red
	block(128, 128, 0, 0, 255, 127);     // Dark pink (previous red + transparent blue)
	block(129, 128, 0, 255, 0, 255);     // Blue
	block(129, 128, 0, 0, 255, 127);     // Dark sea-blue (previous blue + transparent green)
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	draw();
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
