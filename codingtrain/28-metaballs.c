/*

https://en.wikipedia.org/wiki/Metaballs

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>

typedef struct {
	float x, y;
	float vx, vy;
	float r;
} Blob;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

int width, height;

Blob blobs[10];

Uint64 start;

int pause;

void
hsv2rgb(float *R, float *G, float *B, float H, float S, float V)
{
	float C, HP, X, M;

	C = V * S;
	HP = fmod(H / 60.0, 6);
	X = C * (1 - fabs(fmod(HP, 2) - 1));
	M = V - C;

	if (0 <= HP && HP < 1) {
		*R = C;
		*G = X;
		*B = 0;
	} else if (1 <= HP && HP < 2) {
		*R = X;
		*G = C;
		*B = 0;
	} else if (2 <= HP && HP < 3) {
		*R = 0;
		*G = C;
		*B = X;
	} else if (3 <= HP && HP < 4) {
		*R = 0;
		*G = X;
		*B = C;
	} else if (4 <= HP && HP < 5) {
		*R = X;
		*G = 0;
		*B = C;
	} else if (5 <= HP && HP < 6) {
		*R = C;
		*G = 0;
		*B = X;
	} else {
		*R = 0;
		*G = 0;
		*B = 0;
	}

	*R += M;
	*G += M;
	*B += M;
}

Uint32
color(float h, float s, float v)
{
	float fr, fg, fb;
	Uint32 r, g, b, a;

	hsv2rgb(&fr, &fg, &fb, h, s, v);

	r = SDL_clamp(fr * 255.0, 0.0, 255.0);
	g = SDL_clamp(fg * 255.0, 0.0, 255.0);
	b = SDL_clamp(fb * 255.0, 0.0, 255.0);
	a = 255;
	return b | (g << 8) | (r << 16) | (a << 24);
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

void
newblob(Blob *b)
{
	float l;

	b->r = 120 + SDL_rand(280);
	b->x = SDL_rand(width - b->r);
	b->y = SDL_rand(height - b->r);

	b->vx = SDL_rand(100);
	b->vy = SDL_rand(100);
	l = hypot(b->vx, b->vy);
	b->vx = (b->vx / l) * 5;
	b->vy = (b->vy / l) * 5;
}

void
moveblob(Blob *b)
{
	b->x += b->vx;
	b->y += b->vy;
	if (b->x < 0 && b->vx < 0)
		b->vx = -b->vx;
	else if (b->x >= width && b->vx > 0)
		b->vx = -b->vx;

	if (b->y < 0 && b->vy < 0)
		b->vy = -b->vy;
	else if (b->y >= height && b->vy > 0)
		b->vy = -b->vy;
}

void
resize(int w, int h)
{
	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	width = w;
	height = h;
}

void
initsdl(void)
{
	int w, h;

	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	w = 800;
	h = 600;
	if (!SDL_CreateWindowAndRenderer("Metaballs", w, h, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	resize(w, h);
}

void
reset(void)
{
	size_t i;

	for (i = 0; i < SDL_arraysize(blobs); i++)
		newblob(&blobs[i]);
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
update(void)
{
	Uint64 ticks;
	size_t i;

	ticks = SDL_GetTicks();
	if (ticks - start < 5)
		return;

	if (!pause) {
		for (i = 0; i < SDL_arraysize(blobs); i++)
			moveblob(&blobs[i]);
	}

	start = ticks;
}

void
drawballs(void)
{
	Uint32 *pixels;
	void *data;
	int pitch;

	Blob *b;
	int x, y;
	float d, s;
	size_t i;

	SDL_LockTexture(texture, NULL, &data, &pitch);
	pixels = data;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			s = 0;
			for (i = 0; i < SDL_arraysize(blobs); i++) {
				b = &blobs[i];
				d = hypot(x - b->x, y - b->y);
				s += 10 * b->r / d;
			}
			pixels[y * width + x] = color(s, 1, 1);
		}
	}

	SDL_UnlockTexture(texture);
}

void
draw(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	drawballs();
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int
main(void)
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
