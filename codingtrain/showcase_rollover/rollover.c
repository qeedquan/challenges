#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

Uint64 start;

SDL_FRect bounds;
Uint8 color;

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
initsdl()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", strerror(errno));

	if (!SDL_CreateWindowAndRenderer("Rollover", 640, 360, 0, &window, &renderer))
		fatal("Failed to create SDL window: %s", strerror(errno));

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	bounds = (SDL_FRect){ 270, 130, 100, 100 };
	color = 255;
	start = SDL_GetTicks();
}

void
event()
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
			break;
		}
	}
}

void
update()
{
	SDL_FPoint mouse;
	Uint64 now;

	now = SDL_GetTicks();
	if (now - start > 10) {
		color = SDL_max(color - 1, 175);
		start = now;
	}

	SDL_GetMouseState(&mouse.x, &mouse.y);
	if (SDL_PointInRectFloat(&mouse, &bounds))
		color = 255;
}

void
draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, color, color, color, color);
	SDL_RenderFillRect(renderer, &bounds);
	SDL_RenderPresent(renderer);
}

int
main()
{
	initsdl();
	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
