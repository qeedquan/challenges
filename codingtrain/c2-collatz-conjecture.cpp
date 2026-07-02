/*

https://en.wikipedia.org/wiki/Collatz_conjecture

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <SDL3/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

	int width, height;

	void resize(int new_width, int new_height);

	void init();

	void event();
	void render();
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

int collatz(int n)
{
	if (!(n & 1))
		return n / 2;
	return (n * 3 + 1) / 2;
}

void App::resize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;

	if (texture)
		SDL_DestroyTexture(texture);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, width, height);
	if (!texture)
		fatal("Failed to create texture: %s", SDL_GetError());

	render();
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 800;
	height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("Collatz", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	resize(width, height);
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
			}
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			break;
		}
	}
}

void App::render()
{
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 10);
	for (auto iteration = 1; iteration < 10000; iteration++)
	{
		vector<int> sequence;
		auto value = iteration;
		do
		{
			sequence.push_back(value);
			value = collatz(value);
		} while (value != 1);
		sequence.push_back(1);

		float length = 5.0;
		float angle = 0.15;
		auto matrix = glm::translate(mat4(1), vec3(width / 2, height, 0));
		for (size_t index = sequence.size(); index > 0; index--)
		{
			auto value = sequence[index - 1];
			if (value % 2 == 0)
				matrix = glm::rotate(matrix, angle, vec3(0, 0, 1));
			else
				matrix = glm::rotate(matrix, -angle, vec3(0, 0, 1));

			auto p1 = matrix * vec4(0, 0, 0, 1);
			auto p2 = matrix * vec4(0, -length, 0, 1);
			SDL_RenderLine(renderer, p1.x, p1.y, p2.x, p2.y);

			matrix = glm::translate(matrix, vec3(0, -length, 0));
		}
	}
	SDL_SetRenderTarget(renderer, NULL);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main()
{
	auto app = new App();
	app->init();
	for (;;)
	{
		app->event();
		app->draw();
	}

	return 0;
}
