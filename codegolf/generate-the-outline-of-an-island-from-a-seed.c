/*

The challenge is to draw the outline of an 'island', generated using a seed as input.

Input (seed): string of 6 characters (exactly) allowing only lowercase letters (i.e. abcdefghijklmnopqrstuvwxyz) - examples: 'island', 'aaaaaa', 'jhgcfj'
Each seed is to give a unique island (i.e. no two seeds will give the same output)
No output is to be a transformation of another seed's output. That's translation, reflection, rotation, scaling or any combination thereof.
Using the same seed should always give the same output
Output: 600px by 600px image
A valid island is drawn using a single line, which:

forms a closed loop
is 1px thick with no smoothing, blurring etc.
is continuous (i.e. after drawing a pixel the next pixel will be in one of the 8 adjoining spaces that isn't occupied)
does not cross itself at any point
does not leave the boundaries of the image
is black (#000), on a background of white (#FFF)
has no lines of reflective symmetry
must enclose white space
Source code has a limit of 500 bytes.

Aside from that, popularity decides; most votes wins.

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

SDL_Window *window;
SDL_Renderer *renderer;
char shape[16];

SDL_AppResult
SDL_AppInit(void **, int argc, char *argv[])
{
	if (argc < 2 || strlen(argv[1]) != 6) {
		SDL_Log("usage: string");
		return SDL_APP_FAILURE;
	}

	snprintf(shape, sizeof(shape), "%s}@", argv[1]);

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Island Outline", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
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

/*

@Level River St

Here's a very simple algorithm, which could be refined for more realism. If there are further changes in the rules I'm willing to change / delete.

take the 6 character string and add }@ to ensure asymmetry (this particular choice of characters gives islands that vaguely resemble Antarctica)

draw a line that connects 8 points at 45 degree intervals, with distance from the centre determined by the ASCII code.

*/

void
draw_island(const char *shape)
{
	SDL_FPoint p0, p1, p2;
	size_t i;
	float r;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	p0 = (SDL_FPoint){ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
	p1 = p0;
	for (i = 0; shape[i]; i++) {
		r = (4 * shape[i]) - 192;
		p2.x = p0.x + (r * cos(i * SDL_PI_F / 4));
		p2.y = p0.y + (r * sin(i * SDL_PI_F / 4));
		SDL_RenderLine(renderer, p1.x, p1.y, p2.x, p2.y);
		p1 = p2;
	}
	SDL_RenderLine(renderer, p1.x, p1.y, p0.x, p0.y);
}

SDL_AppResult
SDL_AppIterate(void *)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	draw_island(shape);
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void
SDL_AppQuit(void *, SDL_AppResult)
{
}
