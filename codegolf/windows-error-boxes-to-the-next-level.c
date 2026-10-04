/*

You know those Windows boxes where you can only do one thing?

Windows Error Box: Proceeding will delete the contents of your hard drive. What do you want to do? <Proceed> <Delete>

Let's take this to the next level!
Challenge
Make a dialog box with a button that follows your cursor everywhere!

Specs
No input may be taken. There may be output to either STDOUT or STDERR. You must open a window with one button (no text is necessary, but text may be contained in either the window title, the dialog box, or the button). The button must be clickable, and it must always follow under your cursor so that you can only click it. Upon clicking, it can do anything you want, but please do not make it crash a computer because I will be testing this... The dialog box must stay open for as long as the button is not pressed, but it does not need to close when the button is closed.

Assumptions that you can make
You may assume that the cursor will stay within the drawing canvas.
You may assume that the window will stay in focus, but you must not put the window out of focus as long as the button is not pressed.
Example Pseudocode
Here's some example pseudocode:

Open Dialog Box
Add Button to Dialog Box at position X, Y
WHILE True:
    SET Dialog Box to CursorX - X, CursorY - Y
Test Cases cannot be provided for this challenge
This is a code-golf challenge, so the shortest valid submission by March 14th (Pi Day) wins!

*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

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
event(void)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_EVENT_QUIT:
			exit(0);
		case SDL_EVENT_KEY_DOWN:
			switch (ev.key.key) {
			case SDLK_ESCAPE:
				exit(0);
			}
		}
	}
}

void
update(void)
{
	int w, h;
	float mx, my;

	SDL_GetCurrentRenderOutputSize(renderer, &w, &h);
	SDL_GetGlobalMouseState(&mx, &my);
	SDL_SetWindowPosition(window, mx - (w / 2), my - (h / 2));
}

void
draw(void)
{
	int w, h;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_GetRenderOutputSize(renderer, &w, &h);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderLine(renderer, 0, 0, w, h);
	SDL_RenderLine(renderer, w, 0, 0, h);

	SDL_RenderPresent(renderer);
}

int
main(void)
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
		fatal("Failed to init SDL: %s", SDL_GetError());

	if (!SDL_CreateWindowAndRenderer("FOLLOWER", 256, 256, 0, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	for (;;) {
		event();
		update();
		draw();
	}

	return 0;
}
