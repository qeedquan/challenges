/*

Challenge
Create the image of a progress pride flag.

Output
Progress pride flag
https://i.sstatic.net/kuKsw.png

Dimensions
https://i.sstatic.net/GNIbl.png

Rules
Your program must create the image and not just load it from a website

The colours can be just your language's default if it is very difficult / impossible to load RGB values, else they should be: red: (255,0,0), orange: (255,140,0), yellow: (255,240,0), green: (0,138,40), (dark) blue: (0,80,255), purple: (120,0,140), black: (0,0,0), brown: (100,50,20), (light) blue: (110,220,240), pink: (255,180,200), white: (255,255,255)

The flag can be a scaled up version of the one shown, but the dimensions given are the smallest size allowed. An error of 1 pixel is allowed.

Please include an image of the output of your program.

This post was (somewhat) inspired by this one.

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum {
	WINDOW_WIDTH = 1059,
	WINDOW_HEIGHT = 672,
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

	if (!SDL_CreateWindowAndRenderer("Progress Pride Flag", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
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
push_rect(SDL_Vertex *verts, SDL_FRect rect, SDL_FColor col)
{
	size_t i;

	for (i = 0; i < 6; i++)
		verts[i].color = col;

	verts[0].position.x = rect.x;
	verts[0].position.y = rect.y;

	verts[1].position.x = rect.x + rect.w;
	verts[1].position.y = rect.y;

	verts[2].position.x = rect.x;
	verts[2].position.y = rect.y + rect.h;

	verts[3].position = verts[1].position;
	verts[4].position = verts[2].position;

	verts[5].position.x = rect.x + rect.w;
	verts[5].position.y = rect.y + rect.h;

	return 6;
}

size_t
push_tri(SDL_Vertex *verts, SDL_FPoint tri[3], SDL_FColor col)
{
	size_t i;

	for (i = 0; i < 3; i++) {
		verts[i].position = tri[i];
		verts[i].color = col;
	}
	return 3;
}

void
draw_pride_flag()
{
	static const SDL_FColor cols[] = {
		{ 1, 0, 0, 1 },         // red
		{ 1, 0.549, 0, 1 },     // orange
		{ 1, 0.941, 0, 1 },     // yellow
		{ 0, 0.541, 0.156, 1 }, // green
		{ 0, 0.313, 1, 1 },     // dark blue
		{ 0.470, 0, 0.549, 1 }, // purple

		{ 0, 0, 0, 1 },             // black
		{ 0.392, 0.196, 0.078, 1 }, // brown
		{ 0.431, 0.862, 0.941, 1 }, // light blue
		{ 1, 0.705, 0.784, 1 },     // pink
		{ 1, 1, 1, 1 },             // white
	};

	SDL_Vertex verts[128];
	SDL_FPoint tri[3];
	SDL_FRect rect;
	size_t nverts;
	size_t i, j;

	memset(verts, 0, sizeof(verts));
	nverts = 0;
	for (i = 0; i < 6; i++) {
		rect = (SDL_FRect){ 0, 112 * i, 1059, 112 };
		nverts += push_rect(verts + nverts, rect, cols[i]);
	}

	tri[0] = (SDL_FPoint){ 168, 0 };
	tri[1] = (SDL_FPoint){ 504, 336 };
	tri[2] = (SDL_FPoint){ 168, 672 };
	for (i = 0; i < 5; i++) {
		nverts += push_tri(verts + nverts, tri, cols[6 + i]);

		rect = (SDL_FRect){ 0, 0, tri[0].x, 672 };
		nverts += push_rect(verts + nverts, rect, cols[6 + i]);

		for (j = 0; j < 3; j++)
			tri[j].x -= 84;
	}

	SDL_RenderGeometry(renderer, NULL, verts, nverts, NULL, 0);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	draw_pride_flag();
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
