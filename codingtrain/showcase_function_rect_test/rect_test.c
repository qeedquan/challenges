#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

bool isgreen;
SDL_FRect rect;

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
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", strerror(errno));

	if (!SDL_CreateWindowAndRenderer("Rect Test", 600, 400, 0, &window, &renderer))
		fatal("Failed to create SDL window: %s", strerror(errno));
}

void
reset(void)
{
	isgreen = false;
	rect = (SDL_FRect){ 300, 200, 100, 100 };
}

bool
mouseinrect()
{
	SDL_FPoint mouse;

	SDL_GetMouseState(&mouse.x, &mouse.y);
	return SDL_PointInRectFloat(&mouse, &rect);
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
			case SDLK_SPACE:
				reset();
				break;
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			if (mouseinrect())
				isgreen = !isgreen;
			break;
		}
	}
}

void
draw(void)
{
	if (isgreen)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	else
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	if (mouseinrect()) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 200, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderRect(renderer, &rect);

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
