/*

https://en.wikipedia.org/wiki/Hilbert_curve

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <SDL3/SDL.h>

using namespace std;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width, height;

	Uint64 start;
	bool paused;

	vector<SDL_FPoint> path;
	int order;

	size_t counter;

	void resize(int new_width, int new_height);

	SDL_FPoint hilbert(int location);
	void generate(int size);

	void draw_hilbert_curve();

	void init();

	void event();
	void update();
	void draw();
};

void hsv2rgb(double &R, double &G, double &B, double H, double S, double V)
{
	auto C = V * S;
	auto HP = fmod(H / 60.0, 6);
	auto X = C * (1 - fabs(fmod(HP, 2) - 1));
	auto M = V - C;

	if (0 <= HP && HP < 1)
	{
		R = C;
		G = X;
		B = 0;
	}
	else if (1 <= HP && HP < 2)
	{
		R = X;
		G = C;
		B = 0;
	}
	else if (2 <= HP && HP < 3)
	{
		R = 0;
		G = C;
		B = X;
	}
	else if (3 <= HP && HP < 4)
	{
		R = 0;
		G = X;
		B = C;
	}
	else if (4 <= HP && HP < 5)
	{
		R = X;
		G = 0;
		B = C;
	}
	else if (5 <= HP && HP < 6)
	{
		R = C;
		G = 0;
		B = X;
	}
	else
	{
		R = 0;
		G = 0;
		B = 0;
	}

	R += M;
	G += M;
	B += M;
}

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(c, d, unlerp(x, a, b));
}

[[noreturn]] void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

SDL_FPoint App::hilbert(int location)
{
	static const SDL_FPoint points[] = {
		{ 0, 0 },
		{ 0, 1 },
		{ 1, 1 },
		{ 1, 0 },
	};

	auto point = points[location & 3];
	for (auto index = 1; index < order; index++)
	{
		location >>= 2;

		auto length = 1 << index;
		switch (location & 3)
		{
		case 0:
			swap(point.x, point.y);
			break;

		case 1:
			point.y += length;
			break;

		case 2:
			point.x += length;
			point.y += length;
			break;

		case 3:
			auto temp = length - 1 - point.x;
			point.x = length - 1 - point.y;
			point.y = temp;
			point.x += length;
			break;
		}
	}
	return point;
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 512;
	height = 512;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("Hilbert Curve", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(width, height);

	start = SDL_GetTicks();
	paused = false;
}

void App::generate(int size)
{
	size = 1 << size;
	auto total = size * size;

	order = size;
	path.resize(total);
	for (auto i = 0; i < total; i++)
	{
		path[i] = hilbert(i);
		auto length = width / size;
		path[i].x *= length;
		path[i].y *= length;
		path[i].x += length / 2;
		path[i].y += length / 2;
	}
	counter = 0;
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
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			break;
		}
	}
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 10)
		return;
	start = now;

	if (paused)
		return;

	counter += 50;
	if (counter >= path.size())
		counter = 0;
}

void App::draw_hilbert_curve()
{
	for (size_t i = 1; i < counter; i++)
	{
		double r, g, b;

		hsv2rgb(r, g, b, linear_remap(i, 0, path.size(), 0, 360), 1, 1);
		SDL_SetRenderDrawColor(renderer, r * 255, g * 255, b * 255, 255);
		SDL_RenderLine(renderer, path[i].x, path[i].y, path[i - 1].x, path[i - 1].y);
	}
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	draw_hilbert_curve();
	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
	auto size = 8;
	if (argc >= 2)
		size = atoi(argv[1]);

	auto app = new App();
	app->init();
	app->generate(size);
	for (;;)
	{
		app->event();
		app->update();
		app->draw();
	}

	return 0;
}
