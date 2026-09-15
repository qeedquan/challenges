/*

https://en.wikipedia.org/wiki/Random_walk

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

Uint64 start;

int pause;
int pointsize;

SDL_Point pos;

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
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);
}

void
resize(int w, int h)
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
		tw = SDL_min(w, tw);
		th = SDL_min(h, th);

		r = (SDL_FRect){ 0, 0, tw, th };
		SDL_RenderTexture(renderer, texture, &r, &r);
		SDL_DestroyTexture(texture);
	}

	texture = t;
}

void
initsdl()
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 1024;
	h = 768;
	if (!SDL_CreateWindowAndRenderer("Random Walk", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	resize(w, h);
}

void
reset()
{
	int w, h;

	pointsize = 2;

	SDL_GetCurrentRenderOutputSize(renderer, &w, &h);
	pos.x = (w / 2) / pointsize;
	pos.y = (h / 2) / pointsize;

	clear(texture);
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
			break;
		}
	}
}

void
move()
{
	SDL_FRect r;

	switch (SDL_rand(4)) {
	case 0:
		pos.x--;
		break;
	case 1:
		pos.x++;
		break;
	case 2:
		pos.y--;
		break;
	case 3:
		pos.y++;
		break;
	}

	r = (SDL_FRect){
		pos.x * pointsize,
		pos.y * pointsize,
		pointsize,
		pointsize,
	};

	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
	SDL_RenderFillRect(renderer, &r);
}

void
update()
{
	Uint64 ticks;

	ticks = SDL_GetTicks();
	if (ticks - start < 20)
		return;

	if (!pause)
		move();

	start = ticks;
}

void
draw()
{
	clear(NULL);
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main()
{
	SDL_srand(time(NULL));
	initsdl();
	reset();

	for (;;) {
		event();
		update();
		draw();
	}
	return 0;
}
