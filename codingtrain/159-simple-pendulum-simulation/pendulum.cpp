/*

https://en.wikipedia.org/wiki/Pendulum
http://www.myphysicslab.com/pendulum1.html

*/

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <raylib.h>

using namespace std;

struct Pendulum
{
	Vector2 origin;
	Vector2 position;
	float radius;
	float angle;

	float velocity;
	float acceleration;
	float damping;
	float ball_radius;

	void init(float x, float y, float r);
	void update();
	void draw();
};

struct App
{
	Pendulum pendulum;

	void init();
	void reset();
	void event();
	void update();
	void draw();
};

void Pendulum::init(float x, float y, float r)
{
	origin = { x, y };
	position = {};
	radius = r;
	angle = PI / 4.0f;

	velocity = 0.0f;
	acceleration = 0.0f;
	damping = 1.0f;
	ball_radius = 48.0f;
}

void Pendulum::update()
{
	float gravity = 0.4f;

	acceleration = (-1.0f * gravity / radius) * sin(angle);
	velocity += acceleration;
	velocity *= damping;
	angle += velocity;
}

void Pendulum::draw()
{
	position.x = origin.x + (radius * sin(angle));
	position.y = origin.y + (radius * cos(angle));

	DrawLineEx(origin, position, 2.0f, WHITE);
	DrawCircleV(position, ball_radius, WHITE);
	DrawCircleV(position, ball_radius * 0.95, GRAY);
}

void App::init()
{
	auto width = 640;
	auto height = 360;

	InitWindow(width, height, "Pendulum");
	SetTargetFPS(60);

	reset();
}

void App::reset()
{
	pendulum.init(GetRenderWidth() / 2.0f, 0.0f, 175.0f);
}

void App::event()
{
	if (IsKeyPressed(KEY_SPACE))
		reset();
}

void App::update()
{
	pendulum.update();
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	pendulum.draw();
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
