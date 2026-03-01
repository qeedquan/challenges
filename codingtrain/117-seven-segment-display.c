/*

https://en.wikipedia.org/wiki/Seven-segment_display

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

Uint64 start;

unsigned choice;
unsigned paused;

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
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 512;
	h = 512;
	if (!SDL_CreateWindowAndRenderer("Seven Segment Display", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	start = SDL_GetTicks();
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
				paused = !paused;
				break;
			}
			break;
		}
	}
}

void
update(void)
{
	Uint64 ticks;

	ticks = SDL_GetTicks();
	if (ticks - start < 1000)
		return;

	if (!paused)
		choice += 1;
	start = ticks;
}

SDL_Color
getcolor(unsigned value, unsigned shift)
{
	SDL_Color color;

	color.r = 255;
	color.g = 0;
	color.b = 0;
	color.a = 40 | (255 * ((value >> shift) & 1));

	if (paused)
		color.r = 200;

	return color;
}

void
drawssd(unsigned value)
{
	static const SDL_FRect segments[] = {
		{ 60, 20, 78, 18 },
		{ 140, 40, 18, 98 },
		{ 140, 160, 18, 98 },
		{ 60, 260, 78, 18 },
		{ 40, 160, 18, 98 },
		{ 40, 40, 18, 98 },
		{ 60, 140, 78, 18 },
	};

	SDL_FRect rect;
	SDL_Color color;
	int width, height, shift;
	size_t i;

	SDL_GetCurrentRenderOutputSize(renderer, &width, &height);

	shift = 6;
	for (i = 0; i < SDL_arraysize(segments); i++) {
		color = getcolor(value, shift--);
		rect = segments[i];
		rect.x -= 100;
		rect.y -= 140;
		rect.x += width / 2;
		rect.y += height / 2;

		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(renderer, &rect);
	}
}

void
draw(void)
{
	static const unsigned digits[] = { 0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b };
	unsigned value;

	value = digits[choice % SDL_arraysize(digits)];

	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);
	drawssd(value);
	SDL_RenderPresent(renderer);
}

int
main(void)
{
	initsdl();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
