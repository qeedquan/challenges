/*

The challenge is simple: Draw a rainbow in as few bytes as possible

The specs for the rainbow are as follows:

The figure must be exactly 400 pixels wide and 200 pixels high (optionally 401x201 if you want a single center pixel)
The red ring should touch all borders of the figure (outer radius = 200 pixels)
All rings shall have the same width (10 pixels)
The violet ring shall have an inner radius of 130 pixels
The bow should be the upper half of a perfect circle
The background shall be white (transparent is also accepted)
The figure shall not have borders, (exception is made if the border can't be suppressed)
Builtin rainbow making functions are not allowed!
The following colors are to be used in the rainbow:

https://i.sstatic.net/f4Sm1m.jpg

This is code golf, so the shortest code in bytes win!

Example:

https://i.sstatic.net/740pF.png

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <math.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define deg2rad(x) ((x) * SDL_PI_F / 180)

enum {
	WINDOW_WIDTH = 400,
	WINDOW_HEIGHT = 200,
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

	if (!SDL_CreateWindowAndRenderer("Rainbow", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
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

size_t
push_filled_circle(SDL_Vertex *verts, float center_x, float center_y, float radius, SDL_FColor col)
{
	static const size_t divisions = 80;

	SDL_FPoint points[256];
	size_t triangles;
	size_t i;
	float angle;
	float t;

	angle = 360.0 / divisions;
	triangles = divisions - 2;

	for (i = 0; i < triangles * 3; i++)
		verts[i].color = col;

	for (i = 0; i < divisions; i++) {
		t = deg2rad(angle * i);
		points[i] = (SDL_FPoint){
			center_x + (radius * cos(t)),
			center_y + (radius * sin(t)),
		};
	}

	for (i = 0; i < triangles; i++) {
		verts[(3 * i) + 0].position = points[0];
		verts[(3 * i) + 1].position = points[i + 1];
		verts[(3 * i) + 2].position = points[i + 2];
	}

	return triangles * 3;
}

void
draw_rainbow()
{
	static const SDL_FColor cols[] = {
		{ 1, 0, 0, 1 },         // red
		{ 1, 0.498, 0, 1 },     // orange
		{ 1, 1, 0, 1 },         // yellow
		{ 0, 1, 0, 1 },         // green
		{ 0, 0, 1, 1 },         // blue
		{ 0.274, 0, 0.509, 1 }, // brown
		{ 0.560, 0, 1, 1 },     // purple
		{ 1, 1, 1, 1 },         // white
	};

	SDL_Vertex verts[2048];
	float center_x, center_y, radius;
	size_t nverts;
	size_t i;

	memset(verts, 0, sizeof(verts));
	nverts = 0;
	center_x = WINDOW_WIDTH / 2;
	center_y = WINDOW_HEIGHT;
	radius = 200;
	for (i = 0; i < SDL_arraysize(cols); i++) {
		nverts += push_filled_circle(verts + nverts, center_x, center_y, radius, cols[i]);
		radius -= 10;
	}

	SDL_RenderGeometry(renderer, NULL, verts, nverts, NULL, 0);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	draw_rainbow();
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
