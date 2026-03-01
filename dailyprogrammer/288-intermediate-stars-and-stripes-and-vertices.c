/*

Description
This challenge is about drawing stars.

Specifically, each point should be equally spaced to the ones beside it, and should be connected to the two opposite points with a line.

Not the direct opposite though, like when you have an even number of points.

For example, take a look at this image. In the first star, the pentagram with an odd amount of points, it's clear what "connected to the two opposite points" means.

In the hexagram it's not just as clear. That's why the image shows that exactly opposite points should not be connected.

Formal Inputs and Outputs
Input
You will be given the amount of vertices, or points in the specific star.

Output
The output should be any type of image with the star rendered onto it.

Challenge input
8
7
20
Bonus challenge
Surround the star by a polygon with the same amount of vertices. For example, if the input is 5, the output should be a pentagram (5-pointed star) surrounded by a pentagon.

Tips
If you want to find a point's coordinates from only a distance and angle, here's how to do that:

x = d cos a
y = d sin a
Remember that many languages measure in radians! To convert from degrees to radians, multiply by pi/180. If you want to find the relationship to pi, just divide by 180.

For example, 360/180 is 2, so 360° is 2pi rad.

Also, wolfram alpha is really useful for simplifying math expressions quickly.

Credit
This challenge was suggested by u/tulanir, thank you. If you have a challenge idea, please share it in r/dailyprogrammer_ideas and there's a good chance we'll use it.

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Window *window;
SDL_Renderer *renderer;
int num_vertices;

enum {
	WINDOW_SIZE = 800
};

SDL_AppResult
SDL_AppInit(void **, int argc, char *argv[])
{
	num_vertices = 20;
	if (argc >= 2)
		num_vertices = atoi(argv[1]);

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Stars and Stripes", WINDOW_SIZE, WINDOW_SIZE, 0, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult
SDL_AppEvent(void *, SDL_Event *ev)
{
	switch (ev->type) {
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;

	case SDL_EVENT_KEY_DOWN:
		switch (ev->key.key) {
		case SDLK_ESCAPE:
			return SDL_APP_SUCCESS;

		case SDLK_LEFT:
			if (num_vertices > 3)
				num_vertices--;
			SDL_Log("Vertices: %d", num_vertices);
			break;

		case SDLK_RIGHT:
			if (num_vertices < INT_MAX)
				num_vertices++;
			SDL_Log("Vertices: %d", num_vertices);
			break;
		}
		break;
	}

	return SDL_APP_CONTINUE;
}

void
draw_shape(int n)
{
	SDL_FPoint center;
	SDL_FPoint first_point;
	SDL_FPoint second_point;
	float radius;
	float vert;
	float hori;
	float angle;
	int skip;
	int i;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	center.x = center.y = WINDOW_SIZE / 2;
	radius = center.x * 0.5 * 0.8;
	skip = floor((n / 2.0) - 0.5);

	// draw the diagonals
	for (i = 0; i < n; i++) {
		angle = (i * 2 * SDL_PI_F) / n;
		vert = radius * cos(angle);
		hori = radius * sin(angle);
		first_point = (SDL_FPoint){
			center.x + hori,
			center.y - vert,
		};

		angle = ((i + skip) * 2 * SDL_PI_F) / n;
		vert = radius * cos(angle);
		hori = radius * sin(angle);
		second_point = (SDL_FPoint){
			center.x + hori,
			center.y - vert,
		};
		SDL_RenderLine(renderer, first_point.x, first_point.y, second_point.x, second_point.y);
	}

	// draw surrounding polygon
	for (i = 0; i < n; i++) {
		angle = (i * 2 * SDL_PI_F) / n;
		vert = radius * cos(angle);
		hori = radius * sin(angle);
		first_point = (SDL_FPoint){
			center.x + hori,
			center.y - vert,
		};

		angle = (i + 1) * 2 * SDL_PI_F / n;
		vert = radius * cos(angle);
		hori = radius * sin(angle);
		second_point = (SDL_FPoint){
			center.x + hori,
			center.y - vert,
		};

		SDL_RenderLine(renderer, first_point.x, first_point.y, second_point.x, second_point.y);
	}
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	draw_shape(num_vertices);
	SDL_RenderPresent(renderer);
	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
