/*

https://en.wikipedia.org/wiki/Particle_system

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <cfloat>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <SDL3/SDL.h>

using namespace std;

struct Particle
{
	SDL_FPoint position;
	SDL_FPoint velocity;
	float alpha;

	Particle(float width, float height);
	bool finished();
	void update();
	void draw(SDL_Renderer *renderer);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	float width;
	float height;
	bool paused;

	vector<Particle> particles;

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

void circle(SDL_Renderer *renderer, float x, float y, float radius, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	for (float w = 0; w < radius * 2; w++)
	{
		for (float h = 0; h < radius * 2; h++)
		{
			float dx = radius - w;
			float dy = radius - h;
			if ((dx * dx + dy * dy) <= (radius * radius))
				SDL_RenderPoint(renderer, x + dx, y + dy);
		}
	}
}

Particle::Particle(float width, float height)
{
	position.x = width / 2;
	position.y = height - 20;
	velocity.x = (SDL_randf() * 2) - 1;
	velocity.y = (SDL_randf() * 6) - 5;
	alpha = 255;
}

bool Particle::finished()
{
	return alpha < 0;
}

void Particle::update()
{
	position.x += velocity.x;
	position.y += velocity.y;
	alpha -= 5;
}

void Particle::draw(SDL_Renderer *renderer)
{
	circle(renderer, position.x, position.y, 16, SDL_Color{ 255, 255, 255, (Uint8)alpha });
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 1024;
	height = 768;
	if (!SDL_CreateWindowAndRenderer("Particle System", width, height, SDL_WINDOW_RESIZABLE, &window, &renderer))
		fatal("Failed to create window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_srand(time(NULL));

	paused = false;
	reset();
}

void App::reset()
{
	particles.clear();
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
			width = ev.window.data1;
			height = ev.window.data2;
			reset();
			break;
		}
	}
}

void App::update()
{
	if (paused)
		return;

	for (auto i = 0; i < 5; i++)
	{
		particles.push_back(Particle(width, height));
	}

	for (ssize_t i = particles.size() - 1; i >= 0; i--)
	{
		particles[i].update();
		if (particles[i].finished())
			particles.erase(particles.begin() + i);
	}
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
	SDL_RenderClear(renderer);

	for (auto &particle : particles)
		particle.draw(renderer);

	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	for (;;)
	{
		app->event();
		app->update();
		app->draw();
	}

	return 0;
}
