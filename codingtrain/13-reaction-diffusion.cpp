/*

https://en.wikipedia.org/wiki/Reaction%E2%80%93diffusion_system

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <SDL3/SDL.h>

using namespace std;

struct Cell
{
	double a, b;
};

struct RD
{
	vector<vector<Cell> > grid;
	vector<vector<Cell> > next;
	int width;
	int height;

	double dA, dB;
	double feed;
	double k;

	void init(int width, int height);

	void update();
	void draw(uint8_t *data);

	double laplaceA(int x, int y);
	double laplaceB(int x, int y);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	RD rd;

	int width, height;

	bool paused;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void event();
	void update();
	void draw_rd();
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

void RD::init(int width, int height)
{
	this->width = width;
	this->height = height;

	grid.resize(width);
	next.resize(width);
	for (auto x = 0; x < width; x++)
	{
		grid[x].resize(height);
		next[x].resize(height);
		for (auto y = 0; y < height; y++)
		{
			grid[x][y] = { 1, 0 };
			next[x][y] = { 1, 0 };
		}
	}

	auto x0 = width / 2;
	auto y0 = height / 2;
	auto x1 = min(x0 + 10, width);
	auto y1 = min(y0 + 10, height);
	for (auto x = x0; x < x1; x++)
	{
		for (auto y = y0; y < y1; y++)
		{
			grid[x][y].b = 1;
		}
	}
}

double RD::laplaceA(int x, int y)
{
	auto sumA = 0.0;
	sumA += grid[x][y].a * -1;
	sumA += grid[x - 1][y].a * 0.2;
	sumA += grid[x + 1][y].a * 0.2;
	sumA += grid[x][y + 1].a * 0.2;
	sumA += grid[x][y - 1].a * 0.2;
	sumA += grid[x - 1][y - 1].a * 0.05;
	sumA += grid[x + 1][y - 1].a * 0.05;
	sumA += grid[x + 1][y + 1].a * 0.05;
	sumA += grid[x - 1][y + 1].a * 0.05;
	return sumA;
}

double RD::laplaceB(int x, int y)
{
	auto sumB = 0.0;
	sumB += grid[x][y].b * -1;
	sumB += grid[x - 1][y].b * 0.2;
	sumB += grid[x + 1][y].b * 0.2;
	sumB += grid[x][y + 1].b * 0.2;
	sumB += grid[x][y - 1].b * 0.2;
	sumB += grid[x - 1][y - 1].b * 0.05;
	sumB += grid[x + 1][y - 1].b * 0.05;
	sumB += grid[x + 1][y + 1].b * 0.05;
	sumB += grid[x - 1][y + 1].b * 0.05;
	return sumB;
}

void RD::update()
{
	for (auto x = 1; x < width - 1; x++)
	{
		for (auto y = 1; y < height - 1; y++)
		{
			auto a = grid[x][y].a;
			auto b = grid[x][y].b;
			next[x][y].a = a +
						   (dA * laplaceA(x, y)) -
						   (a * b * b) +
						   (feed * (1 - a));
			next[x][y].b = b +
						   (dB * laplaceB(x, y)) +
						   (a * b * b) -
						   ((k + feed) * b);

			next[x][y].a = SDL_clamp(next[x][y].a, 0, 1);
			next[x][y].b = SDL_clamp(next[x][y].b, 0, 1);
		}
	}
}

void RD::draw(uint8_t *pixels)
{
	for (auto x = 0; x < width; x++)
	{
		for (auto y = 0; y < height; y++)
		{
			auto pix = (x + y * width) * 4;
			auto a = next[x][y].a;
			auto b = next[x][y].b;
			auto c = floor((a - b) * 255);
			c = SDL_clamp(c, 0, 255);
			pixels[pix + 0] = c;
			pixels[pix + 1] = c;
			pixels[pix + 2] = c;
			pixels[pix + 3] = 255;
		}
	}

	swap(grid, next);
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
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 800;
	height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("Reaction Diffusion", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	paused = false;
	resize(width, height);
	reset();
}

void App::reset()
{
	rd.dA = 1;
	rd.dB = 0.5;
	rd.feed = 0.055;
	rd.k = 0.062;
	rd.init(width, height);
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
			case SDLK_SPACE:
				paused = !paused;
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

void App::update()
{
	if (paused)
		return;

	rd.update();
}

void App::draw_rd()
{
	void *data;
	int pitch;
	SDL_LockTexture(texture, NULL, &data, &pitch);
	rd.draw((uint8_t *)data);
	SDL_UnlockTexture(texture);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	draw_rd();

	auto dimension = SDL_FRect{ 0, 0, (float)width, (float)height };
	SDL_RenderTexture(renderer, texture, &dimension, &dimension);

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
