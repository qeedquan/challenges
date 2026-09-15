#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Color bg;

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

int
randn(int min, int max)
{
	return min + SDL_rand(max - min + 1);
}

SDL_Color
randbg()
{
	return (SDL_Color){
		randn(200, 255),
		randn(200, 255),
		randn(200, 255),
		255,
	};
}

void
initsdl()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", strerror(errno));

	if (!SDL_CreateWindowAndRenderer("Sensitive Squares", 500, 500, 0, &window, &renderer))
		fatal("Failed to create SDL window: %s", strerror(errno));

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	bg = randbg();
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
			case SDLK_SPACE:
				break;
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			bg = randbg();
			break;
		}
	}
}

void
fill(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void
square(float x, float y, float size)
{
	SDL_FRect rect;

	rect.x = x;
	rect.y = y;
	rect.w = size;
	rect.h = size;
	SDL_RenderFillRect(renderer, &rect);
}

void
draw()
{
	SDL_FPoint mouse;

	SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
	SDL_RenderClear(renderer);

	SDL_GetMouseState(&mouse.x, &mouse.y);

	fill(mouse.x, mouse.y, 0, 50);
	square(100, 100, 100);
	fill(mouse.x - 150, mouse.y, 0, 50);
	square(300, 100, 100);
	fill(mouse.x - 150, mouse.y - 150, 0, 50);
	square(300, 300, 100);
	fill(mouse.x, mouse.y - 150, 0, 50);
	square(100, 300, 100);

	SDL_RenderPresent(renderer);
}

int
main()
{
	initsdl();
	for (;;) {
		event();
		draw();
	}
	return 0;
}
