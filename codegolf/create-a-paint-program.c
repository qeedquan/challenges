/*

Introduction

One day, you were showing your kid how to draw on a computer. You type mspaint.exe in the run bar. To your horror, it says "No items match your search". You must create a simple version of paint so your kid can draw!
Challenge

You must create a simple drawing program. To do this, open a white display window (larger than 99x99 pixels). Anytime the mouse is pressed down, change the pixel that the mouse is on to black.

This is code-golf, so shortest answer in bytes wins!

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

float pointsize;

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
clear(SDL_Texture *t)
{
	SDL_SetRenderTarget(renderer, t);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

void
resize(float w, float h)
{
	SDL_Texture *t;
	SDL_FRect r;
	float tw, th;

	t = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, w, h);
	if (!t)
		fatal("Failed to create texture: %s", SDL_GetError());
	SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);

	if (texture) {
		clear(t);

		SDL_GetTextureSize(texture, &tw, &th);
		tw = fmin(w, tw);
		th = fmin(h, th);

		r = (SDL_FRect){ 0, 0, tw, th };
		SDL_RenderTexture(renderer, texture, &r, &r);
		SDL_DestroyTexture(texture);
	}

	texture = t;
}

void
initsdl(void)
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 1024;
	h = 768;
	if (!SDL_CreateWindowAndRenderer("Paint", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	resize(w, h);
}

void
reset(void)
{
	pointsize = 10;
	clear(texture);
}

void
pencil(float x, float y, float size, int clear)
{
	SDL_FRect r;
	int c;

	r = (SDL_FRect){ x, y, size, size };
	c = (clear) ? 255 : 0;
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, c, c, c, 255);
	SDL_RenderFillRect(renderer, &r);
}

void
setpointsize(float size)
{
	pointsize = size;
	if (pointsize < 0)
		pointsize = 0;
	else if (pointsize > 100)
		pointsize = 100;
	printf("Point size: %f\n", pointsize);
}

void
event(void)
{
	SDL_Event ev;
	float mousex, mousey;
	int button;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_EVENT_QUIT:
			exit(0);

		case SDL_EVENT_KEY_DOWN:
			switch (ev.key.key) {
			case SDLK_ESCAPE:
				exit(0);

			case SDLK_SPACE:
				reset();
				break;

			case SDLK_UP:
				setpointsize(pointsize + 1);
				break;

			case SDLK_DOWN:
				setpointsize(pointsize - 1);
				break;
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			break;
		}
	}

	button = SDL_GetMouseState(&mousex, &mousey);
	if (button & SDL_BUTTON_LMASK)
		pencil(mousex, mousey, pointsize, 0);
	if (button & SDL_BUTTON_RMASK)
		pencil(mousex, mousey, pointsize, 1);
}

void
draw(void)
{
	clear(NULL);
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	reset();

	for (;;) {
		event();
		draw();
	}
	return 0;
}
