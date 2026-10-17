/*

https://en.wikipedia.org/wiki/Flappy_Bird

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <raylib.h>
#include <raymath.h>

using namespace std;

struct Bird
{
	float x, y;
	float gravity;
	float lift;
	float velocity;

	void init();
	void up();
	void update();
	void draw();
};

struct Pipe
{
	float spacing;
	float top;
	float bottom;
	float x;
	float w;
	float speed;
	bool highlight;

	void init();
	bool hit(Bird &bird);
	bool offscreen();
	void update();
	void draw();
};

struct App
{
	Bird bird;
	vector<Pipe> pipes;
	double start;
	bool invincible;

	void init();
	void reset();
	void event();
	void update();
	void draw();
};

void Bird::init()
{
	x = 64;
	y = GetRenderHeight() / 2.0f;
	gravity = 0.7;
	lift = -12;
	velocity = 0;
}

void Bird::up()
{
	velocity += lift;
}

void Bird::update()
{
	velocity += gravity;
	y += velocity;

	auto height = GetRenderHeight();
	if (y > height)
	{
		y = height;
		velocity = 0;
	}

	if (y < 0)
	{
		y = 0;
		velocity = 0;
	}
}

void Bird::draw()
{
	DrawCircle(x, y, 16, RAYWHITE);
}

void Pipe::init()
{
	auto width = GetRenderWidth();
	auto height = GetRenderHeight();

	spacing = 175;
	top = GetRandomValue(height / 6, height * 3 / 4);
	bottom = height - (top + spacing);
	x = width;
	w = 80;
	speed = 6;
	highlight = false;
}

bool Pipe::hit(Bird &bird)
{
	auto height = GetRenderHeight();
	if (bird.y < top || bird.y > height - bottom)
	{
		if (bird.x > x && bird.x < x + w)
		{
			highlight = true;
			return true;
		}
	}

	highlight = false;
	return false;
}

bool Pipe::offscreen()
{
	return x < -w;
}

void Pipe::update()
{
	x -= speed;
}

void Pipe::draw()
{
	Color color = RAYWHITE;
	if (highlight)
		color = RED;

	float height = GetRenderHeight();
	DrawRectangle(x, 0, w, top, color);
	DrawRectangle(x, height - bottom, w, bottom, color);
}

void App::init()
{
	auto width = 640;
	auto height = 480;

	srand48(time(NULL));

	InitWindow(width, height, "Flappy Bird");
	SetTargetFPS(60);

	reset();
}

void App::reset()
{
	bird.init();

	Pipe pipe;
	pipe.init();
	pipes.clear();
	pipes.push_back(pipe);

	invincible = false;
	start = GetTime();
}

void App::event()
{
	if (IsKeyPressed(KEY_ESCAPE))
		exit(0);

	if (IsKeyPressed(KEY_SPACE))
		bird.up();

	if (IsKeyPressed(KEY_ENTER))
	{
		invincible = !invincible;
		printf("Invincible: %d\n", invincible);
	}
}

void App::update()
{
	for (ssize_t i = pipes.size() - 1; i >= 0; i--)
	{
		pipes[i].update();
		if (pipes[i].hit(bird) && !invincible)
			reset();

		if (pipes[i].offscreen())
			pipes.erase(pipes.begin() + i);
	}

	bird.update();

	auto now = GetTime();
	if (now - start > 1.5)
	{
		start = now;
		Pipe pipe;
		pipe.init();
		pipes.push_back(pipe);
	}
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (size_t i = 0; i < pipes.size(); i++)
		pipes[i].draw();
	bird.draw();

	EndDrawing();
}

int main()
{
	auto app = new App();
	app->init();
	while (!WindowShouldClose())
	{
		app->event();
		app->update();
		app->draw();
	}
	return 0;
}
