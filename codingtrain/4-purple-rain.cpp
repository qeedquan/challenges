#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <chrono>
#include <random>
#include <vector>
#include <SDL3/SDL.h>

using namespace std;

struct Drop
{
	float x, y, z;
	float yspeed;
	float len;

	void init(float width);
	void fall(float height);
	void draw(SDL_Renderer *renderer);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width;
	int height;

	Uint64 start;
	bool pause;

	vector<Drop> drops;

	void init();
	void reset();

	void event();
	void update();
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

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(c, d, unlerp(x, a, b));
}

float randn(float a, float b)
{
	default_random_engine engine;
	engine.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_real_distribution<float> distribution(a, b);
	return distribution(engine);
}

void Drop::init(float width)
{
	x = randn(0, width);
	y = randn(-500, -50);
	z = randn(0, 20);
	yspeed = linear_remap(z, 0, 20, 5, 20);
	len = linear_remap(z, 0, 20, 10, 50);
}

void Drop::fall(float height)
{
	auto gravity = linear_remap(z, 0, 20, 0, 0.2);
	y += yspeed;
	yspeed += gravity;
	if (y > height)
	{
		y = randn(-200, -100);
		yspeed = linear_remap(z, 0, 20, 4, 10);
	}
}

void Drop::draw(SDL_Renderer *renderer)
{
	auto thick = linear_remap(z, 0, 20, 1, 3);
	SDL_SetRenderDrawColor(renderer, 138, 43, 226, 255);
	SDL_SetRenderScale(renderer, thick * 4, 1);
	SDL_RenderLine(renderer, x, y, x, y + len);
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 800;
	height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("Purple Rain", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void App::reset()
{
	drops.resize(width * 2);
	for (auto &drop : drops)
		drop.init(width);

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
			case SDLK_SPACE:
				reset();
				break;
			case SDLK_RETURN:
				pause = !pause;
				break;
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			width = ev.window.data1;
			height = ev.window.data2;
			break;
		}
	}
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 16)
		return;

	if (!pause)
	{
		for (auto &drop : drops)
			drop.fall(height);
	}
	start = now;
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 230, 230, 250, 255);
	SDL_RenderClear(renderer);

	for (auto &drop : drops)
		drop.draw(renderer);
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
