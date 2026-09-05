/*

https://en.wikipedia.org/wiki/Abelian_sandpile_model

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <SDL3/SDL.h>

const SDL_Color colors[] = {
	{ 255, 0, 0, 255 },
	{ 255, 255, 0, 255 },
	{ 0, 185, 63, 255 },
	{ 0, 104, 25, 255 },
	{ 122, 0, 229, 255 },
};

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int width, height;

long **sand;
long **next;

int pause;

Uint32
rgba(SDL_Color c)
{
	return c.b | (c.g << 8) | (c.r << 16) | (c.a << 24);
}

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

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	if (!nmemb)
		nmemb = 1;
	if (!size)
		size = 1;
	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

void
resize(int w, int h)
{
	int x;

	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	for (x = 0; x < width; x++) {
		free(sand[x]);
		free(next[x]);
	}
	free(sand);
	free(next);

	sand = xcalloc(w, sizeof(*sand));
	next = xcalloc(w, sizeof(*next));
	for (x = 0; x < w; x++) {
		sand[x] = xcalloc(h, sizeof(*sand[x]));
		next[x] = xcalloc(h, sizeof(*next[x]));
	}

	width = w;
	height = h;
}

void
initsdl()
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 640;
	h = 480;
	if (!SDL_CreateWindowAndRenderer("Sandpile", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(w, h);
}

void
reset()
{
	int x, y;

	for (x = 0; x < width; x++) {
		for (y = 0; y < height; y++) {
			sand[x][y] = 0;
			next[x][y] = 0;
		}
	}
	sand[width / 2][height / 2] = 1000000000;
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
				pause = !pause;
				break;

			case SDLK_RETURN:
				reset();
				break;
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			reset();
			break;
		}
	}
}

void
topple()
{
	int x, y;
	long num;
	long **tmp;

	for (x = 0; x < width; x++) {
		for (y = 0; y < height; y++) {
			next[x][y] = sand[x][y];
		}
	}

	for (x = 0; x < width; x++) {
		for (y = 0; y < height; y++) {
			num = sand[x][y];
			if (num >= 4) {
				next[x][y] -= 4;
				if (x + 1 < width)
					next[x + 1][y]++;
				if (x - 1 >= 0)
					next[x - 1][y]++;
				if (y + 1 < height)
					next[x][y + 1]++;
				if (y - 1 >= 0)
					next[x][y - 1]++;
			}
		}
	}

	tmp = next;
	next = sand;
	sand = tmp;
}

void
update()
{
	int i;

	if (!pause) {
		for (i = 0; i < 50; i++)
			topple();
	}
}

void
upload()
{
	Uint32 *pixels;
	Uint32 col;
	long num;
	void *data;
	int pitch;
	int x, y;

	SDL_LockTexture(texture, NULL, &data, &pitch);
	pixels = data;

	for (x = 0; x < width; x++) {
		for (y = 0; y < height; y++) {
			num = sand[x][y];
			col = rgba(colors[0]);
			if (0 <= num && num <= 3)
				col = rgba(colors[num + 1]);

			pixels[y * width + x] = col;
		}
	}
	SDL_UnlockTexture(texture);
}

void
draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	upload();
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main()
{
	initsdl();
	reset();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
