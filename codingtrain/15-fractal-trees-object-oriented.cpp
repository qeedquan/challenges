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
#include <unordered_map>
#include <SDL3/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

struct Branch
{
	vec2 *begin;
	vec2 *end;
	bool finished;

	Branch(vec2 *begin, vec2 *end);

	void jitter();

	void draw(SDL_Renderer *renderer);

	Branch *branchA();
	Branch *branchB();

private:
	Branch *branchX(float angle);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	int width;
	int height;

	Uint64 start;

	vector<Branch *> tree;
	vector<vec2> leaves;
	int count;

	void init();
	void reset();

	void clear_tree();
	void grow_tree();

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

Branch::Branch(vec2 *begin, vec2 *end)
{
	this->begin = begin;
	this->end = end;
	finished = false;
}

void Branch::jitter()
{
	end->x += (SDL_randf() * 2) - 1;
	end->y += (SDL_randf() * 2) - 1;
}

void Branch::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderLine(renderer, begin->x, begin->y, end->x, end->y);
}

Branch *Branch::branchX(float angle)
{
	auto rotation = glm::rotate(glm::mat4(1), angle, vec3(0, 0, 1));
	auto direction = *end - *begin;
	auto new_direction = rotation * vec4(direction.x, direction.y, 0, 1);
	new_direction *= 0.67;
	return new Branch(end, new vec2(end->x + new_direction.x, end->y + new_direction.y));
}

Branch *Branch::branchA()
{
	return branchX(SDL_PI_F / 6);
}

Branch *Branch::branchB()
{
	return branchX(-SDL_PI_F / 4);
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
	SDL_srand(time(NULL));

	reset();
}

void App::clear_tree()
{
	unordered_map<uintptr_t, bool> seen;
	for (size_t i = 0; i < tree.size(); i++)
	{
		auto pointer0 = (uintptr_t)tree[i]->begin;
		auto pointer1 = (uintptr_t)tree[i]->end;
		if (seen.find(pointer0) == seen.end())
		{
			seen[pointer0] = true;
			delete tree[i]->begin;
		}
		if (seen.find(pointer1) == seen.end())
		{
			seen[pointer1] = true;
			delete tree[i]->end;
		}
		delete tree[i];
	}
	tree.clear();
	leaves.clear();
}

void App::reset()
{
	clear_tree();

	auto a = new vec2(width / 2, height);
	auto b = new vec2(width / 2, height - 100);
	tree.push_back(new Branch(a, b));

	count = 0;
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
			case SDLK_SPACE:
				reset();
				break;
			case SDLK_ESCAPE:
				exit(0);
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			grow_tree();
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			width = ev.window.data1;
			height = ev.window.data2;
			reset();
			break;
		}
	}
}

void App::grow_tree()
{
	for (ssize_t i = tree.size() - 1; i >= 0; i--)
	{
		if (!tree[i]->finished)
		{
			tree.push_back(tree[i]->branchA());
			tree.push_back(tree[i]->branchB());
		}
		tree[i]->finished = true;
	}

	if (count < 7)
		count += 1;

	if (count == 6)
	{
		for (size_t i = 0; i < tree.size(); i++)
		{
			if (!tree[i]->finished)
				leaves.push_back(*tree[i]->end);
		}
	}
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 16)
		return;
	start = now;

	for (size_t i = 0; i < tree.size(); i++)
		tree[i]->jitter();
	for (size_t i = 0; i < leaves.size(); i++)
		leaves[i].y += SDL_randf() * 2;
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);

	for (size_t i = 0; i < tree.size(); i++)
		tree[i]->draw(renderer);
	for (size_t i = 0; i < leaves.size(); i++)
		circle(renderer, leaves[i].x, leaves[i].y, 8, SDL_Color{ 255, 0, 100, 100 });

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
