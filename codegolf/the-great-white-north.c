/*

Eh!
You know, the problem with us Canadians is that sometimes, after a long day of moose hunting and dam repairing, we forget our way back to our cabins!
Wouldn't it be great if our handy laptop (which, is always at our side), had some way to point us home?
Well, it's been long told that, if you display a compass on your computer, it will be the brightest when pointed North.
I'd like to test this out, but I need a compact program to take with me on my next trip,
because my hard drive is already filled with maple syrup recipes (and those CANNOT go).
So, your task is to design me a program which, when run, saves or displays an image of the following compass rose:

https://i.sstatic.net/YhAGL.png

The letters may be in a different font. Remember, least is best, so lowest byte count wins!

Specifications
Colors

Light purple: #9999FF
Gray: #E5E5E5
Lengths and Angles

https://i.sstatic.net/fe0nU.png

Angle a = 45°
Angle b = 90°
Length c = 250 units
Length d = 200 units
Length e = 40 units
Length f = 45 units
Clarifications

The text may be in any appropriate font, where appropriate denotes that it is readable to the average, educated human being.
The text must be 3 units away from the spikes at its closest point, must not touch the rose, and must be upright
If a line is drawn from the center of the rose, through the end point of the spike and beyond, it should cross through the center of the text with a precision of +/- 2 units (the text must be centered along an axis a, where a extends from the middle of the page, through the end of the spike, and beyond)
Each character must be at least 15 units by 15 units, and have an x/y or y/x ratio of no more than 2:1 (no stretching – readability)
The dim circle passing through the longer spikes and text closest to the middle on the reference image is not to be drawn.
The image must be square, and at least 400px by 400px
A compressed image within the source is disallowed
A unit must be at least 1 pixel

*/

#define SDL_MAIN_USE_CALLBACKS 1
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define deg2rad(x) ((x) * SDL_PI_F / 180)

enum {
	WINDOW_WIDTH = 400,
	WINDOW_HEIGHT = 400,
};

SDL_Window *window;
SDL_Renderer *renderer;

SDL_FColor fillcolor;

SDL_Vertex vertices[64];
size_t nvertices;

SDL_AppResult
SDL_AppInit(void **, int, char **)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Compass", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY, &window, &renderer)) {
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
fill(int r, int g, int b)
{
	fillcolor = (SDL_FColor){
		r / 255.0,
		g / 255.0,
		b / 255.0,
		1,
	};
}

void
triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	SDL_Vertex *v;

	v = &vertices[nvertices];
	v[0].position = (SDL_FPoint){ x1, y1 };
	v[1].position = (SDL_FPoint){ x2, y2 };
	v[2].position = (SDL_FPoint){ x3, y3 };

	v[0].color = fillcolor;
	v[1].color = fillcolor;
	v[2].color = fillcolor;

	nvertices += 3;
}

void
text(const char *str, int x, int y)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDebugText(renderer, x, y, str);
}

// ported from @bubalou solution
void
compass()
{
	int s, h, b, t, n, m;

	nvertices = 0;

	s = 400;
	h = s / 2;
	b = 125;
	t = 71;
	n = 32;
	m = 28;

	fill(229, 299, 299);
	triangle(h, h, h - t, h - t, h - m, h);
	triangle(h, h, h - t, h + t, h, h + m);
	triangle(h, h, h + t, h - t, h, h - m);
	triangle(h, h, h + t, h + t, h + m, h);

	fill(0x99, 0x99, 0xFF);
	triangle(h, h, h - t, h - t, h, h - m);
	triangle(h, h, h - t, h + t, h - m, h);
	triangle(h, h, h + t, h - t, h + m, h);
	triangle(h, h, h + t, h + t, h, h + m);
	triangle(h, h, h - b, h, h - n, h - n);
	triangle(h, h, h + b, h, h + n, h + n);
	triangle(h, h, h, h - b, h + n, h - n);
	triangle(h, h, h, h + b, h - n, h + n);

	fill(229, 229, 229);
	triangle(h, h, h - b, h, h - n, h + n);
	triangle(h, h, h + b, h, h + n, h - n);
	triangle(h, h, h, h - b, h - n, h - n);
	triangle(h, h, h, h + b, h + n, h + n);

	text("NW", h - t - 20, h - t - 10);
	text("NE", h + t + 6, h - t - 6);
	text("SW", h - t - 14, h + t + 10);
	text("SE", h + t, h + t + 10);
	text("N", h - 5, h - b - 12);
	text("S", h - 5, h + b + 12);
	text("E", h + b + 5, h - 3);
	text("W", h - b - 14, h - 3);

	SDL_RenderGeometry(renderer, NULL, vertices, nvertices, NULL, 0);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 130, 130, 130, 255);
	SDL_RenderClear(renderer);
	compass();
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
