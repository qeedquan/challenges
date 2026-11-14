/*

The game Final Doom on the original PlayStation has a simple algorithm for animating fire, which looks like this:

https://i.sstatic.net/f5zMlyq6.gif

Here's how it works:

1. Define a palette of attractive fire-like colors like this one, which increases from least to most intensity:
https://i.sstatic.net/AGn9zL8J.png

2. Paint a canvas with some number of rows of the first color in the palette followed by a single row of the last color in the palette.
3. For each pixel in the canvas from bottom to top:
If this is the bottom row, do nothing; otherwise:
Get the palette index i of the color of the pixel directly below this pixel.
Generate a random integer n between 0 and 3 (inclusive).
Find the pixel n−1 pixels to the left of this pixel. (This may be the pixel to the right if  n−1 is negative.)
This is the target pixel. If the target pixel is out of bounds for the row, wrap around to the other end of the row.
Set the color of the target pixel to the color in the palette with index  i−n, or 0, whichever is greater.
Go to (3).
The algorithm is discussed in more detail in this blog post and many implementations (and variations) can be found in this GitHub repo.
https://fabiensanglard.net/doom_fire_psx/
https://github.com/filipedeschamps/doom-fire-algorithm

Task
Write a program or function that animates fire using this algorithm.

Input
The program or function must take as input a palette of at least 16 colors in any convenient format. Here is an example RGB palette:

[[7,7,7],[31,7,7],[47,15,7],[71,15,7],[87,23,7],[103,31,7],[119,31,7],[143,39,7],[159,47,7],[175,63,7],[191,71,7],[199,71,7],[223,79,7],[223,87,7],[223,87,7],[215,95,7],[215,95,7],[215,103,15],[207,111,15],[207,119,15],[207,127,15],[207,135,23],[199,135,23],[199,143,23],[199,151,31],[191,159,31],[191,159,31],[191,167,39],[191,167,39],[191,175,47],[183,175,47],[183,183,47],[183,183,55],[207,207,111],[223,223,159],[239,239,199],[255,255,255]]
You may assume the palette size is fixed or take a size as an additional parameter if necessary.

Output
The output must be a moving image of at least 64×64 pixels or cells shown on the screen (e.g. in the terminal or as an HTML page) or in a common video or animation file format. It must run for at least 100 cycles, or indefinitely. (An animation that has 10 frames and then loops does not count as running for at least 100 cycles. It must have 100 or more unique frames.)

Note: This suggested image I/O rule does not apply.

Entries must include an image or (preferably) GIF of the entry's output.

Rules
This is code-golf. Shortest answer in bytes wins.

Default I/O rules and standard rules apply, except as noted above. Standard loopholes are forbidden.

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <SDL3/SDL.h>

#define deg2rad(x) (((x) * SDL_PI_F) / 180)

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	int iterations;
	int fire_height;
	vector<int> fire;
	vector<int> next_fire;
	vector<uint32_t> canvas;
	vector<uint32_t> palette;

	int width, height;

	Uint64 start;
	bool paused;

	void resize(int new_width, int new_height);

	void init();
	void reset_fire();
	void reset();

	void event();
	void update_fire();
	void update();
	void upload();
	void draw();
};

[[noreturn]] void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

uint32_t rgb(uint32_t r, uint32_t g, uint32_t b)
{
	return b | (g << 8) | (r << 16) | (0xff << 24);
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;

	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	fire.resize(width * height);
	next_fire.resize(width * height);
	canvas.resize(width * height);
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 512;
	height = 512;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("DOOM Fire Effect", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	resize(width, height);
}

void App::reset_fire()
{
	fire_height = 1;

	for (auto y = 0; y < height - 1; y++)
	{
		for (auto x = 0; x < width; x++)
			fire[y * width + x] = 0;
	}
	for (auto y = height - fire_height; y < height; y++)
	{
		for (auto x = 0; x < width; x++)
		{
			fire[y * width + x] = palette.size() - 1;
		}
	}

	next_fire = fire;
	iterations = 1;
}

void App::reset()
{
	palette = {
		rgb(7, 7, 7),
		rgb(31, 7, 7),
		rgb(47, 15, 7),
		rgb(71, 15, 7),
		rgb(87, 23, 7),
		rgb(103, 31, 7),
		rgb(119, 31, 7),
		rgb(143, 39, 7),
		rgb(159, 47, 7),
		rgb(175, 63, 7),
		rgb(191, 71, 7),
		rgb(199, 71, 7),
		rgb(223, 79, 7),
		rgb(223, 87, 7),
		rgb(223, 87, 7),
		rgb(215, 95, 7),
		rgb(215, 95, 7),
		rgb(215, 103, 15),
		rgb(207, 111, 15),
		rgb(207, 119, 15),
		rgb(207, 127, 15),
		rgb(207, 135, 23),
		rgb(199, 135, 23),
		rgb(199, 143, 23),
		rgb(199, 151, 31),
		rgb(191, 159, 31),
		rgb(191, 159, 31),
		rgb(191, 167, 39),
		rgb(191, 167, 39),
		rgb(191, 175, 47),
		rgb(183, 175, 47),
		rgb(183, 183, 47),
		rgb(183, 183, 55),
		rgb(207, 207, 111),
		rgb(223, 223, 159),
		rgb(239, 239, 199),
		rgb(255, 255, 255),
	};

	reset_fire();

	SDL_srand(time(NULL));
	start = SDL_GetTicks();
}

void App::event()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_EVENT_QUIT:
			exit(0);

		case SDL_EVENT_KEY_DOWN:
			switch (ev.key.key)
			{
			case SDLK_ESCAPE:
				exit(0);
			case SDLK_RETURN:
				paused = !paused;
				break;
			case SDLK_SPACE:
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

void App::update_fire()
{
	for (auto y = height - fire_height - 1; y >= 0; y--)
	{
		for (auto x = 0; x < width; x++)
		{
			auto i = fire[(y + 1) * width + x];
			auto n = SDL_rand(4);
			auto nx = x - (n - 1);
			if (nx < 0)
				nx = width + nx;

			next_fire[y * width + nx] = max(i - n, 0);
		}
	}
	swap(fire, next_fire);

	for (size_t i = 0; i < fire.size(); i++)
		canvas[i] = palette[fire[i]];
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 10)
		return;

	if (!paused)
	{
		for (auto i = 0; i < iterations; i++)
			update_fire();
	}

	start = now;
}

void App::upload()
{
	void *pixels;
	int pitch;
	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	memcpy(pixels, &canvas[0], pitch * height);
	SDL_UnlockTexture(texture);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	upload();

	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	app->reset();
	for (;;)
	{
		app->event();
		app->update();
		app->draw();
	}

	return 0;
}
