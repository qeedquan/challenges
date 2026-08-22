/*

https://en.wikipedia.org/wiki/Snake_(video_game_genre)

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdarg>
#include <ctime>
#include <algorithm>
#include <vector>
#include <SDL3/SDL.h>

using namespace std;

struct Vec2
{
	float x, y;

	void operator+=(const Vec2 vector)
	{
		x += vector.x;
		y += vector.y;
	}

	Vec2 operator*(float scale)
	{
		return Vec2{ x * scale, y * scale };
	}
};

struct Snake
{
	Vec2 position;
	Vec2 velocity;
	vector<Vec2> tail;
	size_t total;

	void reset();
	bool eat(Vec2 food);
	void direction(float x, float y);
	void death();
	void update(float width, float height, float scale);
	void draw(SDL_Renderer *renderer, float scale);
};

struct App
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	int width, height;
	float scale;

	Snake snake;
	Vec2 food;

	Uint64 start;
	bool paused;

	void resize(int new_width, int new_height);

	void init();
	void reset();

	void pick_location();

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

float distance(Vec2 vector1, Vec2 vector2)
{
	return hypot(vector1.x - vector2.x, vector1.y - vector2.y);
}

void Snake::reset()
{
	position = Vec2{};
	velocity = Vec2{};
	total = 0;
	tail.clear();
}

void Snake::direction(float x, float y)
{
	velocity = Vec2{ x, y };
}

bool Snake::eat(Vec2 food)
{
	if (distance(position, food) < 1)
	{
		total += 1;
		return true;
	}
	return false;
}

void Snake::death()
{
	for (size_t i = 0; i < tail.size(); i++)
	{
		if (distance(position, tail[i]) < 1)
		{
			printf("Starting Over!\n");
			total = 0;
			tail.clear();
		}
	}
}

void Snake::update(float width, float height, float scale)
{
	while (tail.size() < total)
		tail.push_back(position);

	for (size_t i = 1; i < tail.size(); i++)
		tail[i - 1] = tail[i];

	if (total >= 1)
		tail[total - 1] = position;

	position += velocity * scale;
	position.x = clamp(position.x, 0.0f, width - scale);
	position.y = clamp(position.y, 0.0f, height - scale);
}

void Snake::draw(SDL_Renderer *renderer, float scale)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (size_t i = 0; i < tail.size(); i++)
	{
		auto rect = SDL_FRect{ tail[i].x, tail[i].y, scale, scale };
		SDL_RenderFillRect(renderer, &rect);
	}
	auto rect = SDL_FRect{ position.x, position.y, scale, scale };
	SDL_RenderFillRect(renderer, &rect);
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

	width = 800;
	height = 600;
	auto wflag = SDL_WINDOW_RESIZABLE;
	if (!SDL_CreateWindowAndRenderer("Snake", width, height, wflag, &window, &renderer))
		fatal("Failed to create a window/renderer: %s", SDL_GetError());

	SDL_srand(time(NULL));

	resize(width, height);

	paused = false;
}

void App::reset()
{
	start = SDL_GetTicks();
	scale = 20;
	snake.reset();
	pick_location();
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
			case SDLK_UP:
				snake.direction(0, -1);
				break;
			case SDLK_DOWN:
				snake.direction(0, 1);
				break;
			case SDLK_LEFT:
				snake.direction(-1, 0);
				break;
			case SDLK_RIGHT:
				snake.direction(1, 0);
				break;
			}
			break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			snake.total += 1;
			break;

		case SDL_EVENT_WINDOW_RESIZED:
			resize(ev.window.data1, ev.window.data2);
			break;
		}
	}
}

void App::pick_location()
{
	auto cols = floor(width / scale);
	auto rows = floor(height / scale);
	food = Vec2{
		.x = floor(SDL_randf() * cols) * scale,
		.y = floor(SDL_randf() * rows) * scale,
	};
}

void App::update()
{
	auto now = SDL_GetTicks();
	if (now - start < 100)
		return;
	start = now;

	if (paused)
		return;

	if (snake.eat(food))
		pick_location();

	snake.death();
	snake.update(width, height, scale);
}

void App::draw()
{
	SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
	SDL_RenderClear(renderer);

	snake.draw(renderer, scale);

	SDL_SetRenderDrawColor(renderer, 255, 0, 100, 255);
	auto rect = SDL_FRect{ food.x, food.y, scale, scale };
	SDL_RenderFillRect(renderer, &rect);

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
