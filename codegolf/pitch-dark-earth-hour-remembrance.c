/*

Your goal is simple: the program must turn the screen of your computer totally black.

After the program is started, the screen must quickly turn completely black, and remain so until the program is exited (any key, or alt+F4, mouse movement, etc.),
after which things should turn back to normal. So shutting down the computer or turning the power of the monitor off is NOT allowed. Not a single non-black pixel should be visible during this time, not even a blinking cursor.

The user should not do any preparation (moving the mouse outside the screen, disconnecting cables, etc. or user input after the program started), just start the program.

You can safely assume the computer has only one monitor attached. We also assume a standard desktop or notebook computer, because doing it on a specific device without a normal monitor would be too simple.

If you use any external resources (a black image, a GUI file, etc.) their size in bytes is added to your code size.

It's OK if it only works on one OS family, or if it requires opengl etc., but requiring a very specific hardware configuration is frowned upon.

Your source code must be written in a programming language, not just a configuration file some other program (like a screen saver) will use.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
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
initsdl(void)
{
	SDL_DisplayID id;
	const SDL_DisplayMode *dm;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	id = SDL_GetPrimaryDisplay();
	dm = SDL_GetCurrentDisplayMode(id);
	if (!dm)
		fatal("Failed to get current display: %s", SDL_GetError());

	if (!SDL_CreateWindowAndRenderer("PITCH BLACK", dm->w, dm->h, SDL_WINDOW_FULLSCREEN, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());
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
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();
	for (;;) {
		event();
		draw();
	}

	return 0;
}
