/*

A Spirograph is a toy that draws hypotrochoids and epitrochoids. For this challenge, we'll just focus on the hypotrochoids.

From Wikipedia:

A hypotrochoid is a roulette traced by a point attached to a circle of radius r rolling around the inside of a fixed circle of radius R, where the point is a distance d from the center of the interior circle.

The parametric equations for them can be defined as:

https://i.sstatic.net/hH2sM.png
https://i.sstatic.net/D7HS8.png

Where θ is the angle formed by the horizontal and the center of the rolling circle.

Your task is to write a program that will draw the path traced by the point defined above. As input, you'll be given R, r, and d, all integers between 1 and 200 inclusive.

You can receive this input from stdin, arguments, or user input, but it cannot be hardcoded into the program. You can accept it in whatever form is most convenient for you; as strings, integers, etc.

Assume:

Input units are given in pixels.
R >= r
Output should be a graphical representation of the hypotrochoid defined by the input. No ASCII- or other text-based output is allowed. This image can be saved to a file or displayed on screen. Include a screenshot or image of the output for an input of your choosing.

You can choose any colors you like for the path/background, subject to a contrast restriction. The two colors must have HSV 'Value' component at least half the scale apart. For instance, if you're measuring HSV from [0...1], there should be at least 0.5 difference. Between [0...255] there should be a minimum 128 difference.

This is a code golf, minimum size of source code in bytes wins.

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <math.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum {
	WINDOW_WIDTH = 800,
	WINDOW_HEIGHT = 800,
};

typedef struct {
	int R, r, d;
} Param;

SDL_Window *window;
SDL_Renderer *renderer;
Param param;

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Spirograph", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	param.R = 65;
	param.r = 15;
	param.d = 24;

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
		case SDLK_UP:
			param.R++;
			break;
		case SDLK_DOWN:
			param.R--;
			break;
		case SDLK_LEFT:
			param.d--;
			break;
		case SDLK_RIGHT:
			param.d++;
			break;
		case SDLK_Q:
			param.r++;
			break;
		case SDLK_W:
			param.r--;
			break;
		}
		break;
	}
	printf("R: %d r: %d p: %d\n", param.R, param.r, param.d);
	return SDL_APP_CONTINUE;
}

void
spirograph(int R, int r, int d)
{
	static const float step = SDL_PI_F / 2e4;
	float i, x, y;
	int t, q;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	t = WINDOW_WIDTH / 2;
	q = (R - r) * 2;
	for (i = 0; i < R * SDL_PI_F; i += step) {
		x = q * sin(i) - d * sin(i * q / r) + t;
		y = q * cos(i) + d * cos(i * q / r) + t;
		SDL_RenderPoint(renderer, x, y);
	}
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 130, 130, 130, 255);
	SDL_RenderClear(renderer);
	spirograph(param.R, param.r, param.d);
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
