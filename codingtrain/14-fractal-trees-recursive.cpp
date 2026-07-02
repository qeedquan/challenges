/*

https://en.wikipedia.org/wiki/Fractal_canopy

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>
#include <SDL3/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

struct Tree
{
	float branch;
	float angle;

	void draw(SDL_Renderer *renderer, float width, float height);

private:
	vector<mat4> stack;

	void recurse(SDL_Renderer *renderer, float length);
	void line(SDL_Renderer *renderer, float x1, float y1, float x2, float y2);
	void translate(float x, float y);
	void rotate(float angle);
	void push();
	void pop();
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	int width;
	int height;

	Tree tree;

	void init();
	void reset();

	void event();
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

void Tree::draw(SDL_Renderer *renderer, float width, float height)
{
	stack.clear();
	stack.push_back(mat4(1));
	translate(width * 0.5, height);
	recurse(renderer, branch);
}

void Tree::push()
{
	stack.push_back(stack[stack.size() - 1]);
}

void Tree::pop()
{
	if (stack.size() > 1)
		stack.pop_back();
}

void Tree::translate(float x, float y)
{
	auto &matrix = stack[stack.size() - 1];
	matrix = glm::translate(matrix, vec3(x, y, 0));
}

void Tree::rotate(float angle)
{
	auto &matrix = stack[stack.size() - 1];
	matrix = glm::rotate(matrix, angle, vec3(0, 0, 1));
}

void Tree::line(SDL_Renderer *renderer, float x1, float y1, float x2, float y2)
{
	auto &matrix = stack[stack.size() - 1];
	auto point1 = matrix * vec4(x1, y1, 0, 1);
	auto point2 = matrix * vec4(x2, y2, 0, 1);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderLine(renderer, point1.x, point1.y, point2.x, point2.y);
}

void Tree::recurse(SDL_Renderer *renderer, float length)
{
	line(renderer, 0, 0, 0, -length);
	translate(0, -length);
	if (length > 4)
	{
		push();
		rotate(angle);
		recurse(renderer, length * 0.67);
		pop();
		push();
		rotate(-angle);
		recurse(renderer, length * 0.67);
		pop();
	}
}

void App::init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL: %s", SDL_GetError());

	width = 800;
	height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("Fractal Trees", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window: %s", SDL_GetError());

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	reset();
}

void App::reset()
{
	tree.branch = 100;
	tree.angle = SDL_PI_F / 4;
}

void App::event()
{
	static const float step = 1e-1;

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
			case SDLK_LEFT:
				tree.angle -= step;
				break;
			case SDLK_RIGHT:
				tree.angle += step;
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

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	tree.draw(renderer, width, height);
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
