/*

https://en.wikipedia.org/wiki/Least_squares

*/

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <raylib.h>

using namespace std;

struct LineFit
{
	float m;
	float c;

	float eval(float x)
	{
		return (x * m) + c;
	}
};

struct App
{
	vector<Vector2> points;
	LineFit linefit;

	void init();
	void reset();
	void event();
	void draw();
};

bool least_squares(const vector<Vector2> &points, LineFit &result)
{
	result = {};

	auto size = points.size();
	if (size < 1)
		return false;

	float sum_x = 0.0;
	float sum_y = 0.0;
	float sum_xy = 0.0;
	float sum_xx = 0.0;
	for (auto p : points)
	{
		sum_x += p.x;
		sum_y += p.y;
		sum_xy += p.x * p.y;
		sum_xx += p.x * p.x;
	}

	float denominator = (size * sum_xx) - (sum_x * sum_x);
	if (denominator == 0.0)
		return false;

	result.m = (size * sum_xy - sum_x * sum_y) / denominator;
	result.c = (sum_y - (result.m * sum_x)) / size;
	return true;
}

void App::init()
{
	auto width = 800;
	auto height = 600;

	InitWindow(width, height, "Line Fit");
	SetTargetFPS(60);

	reset();
}

void App::reset()
{
	points.clear();
	linefit = {};
}

void App::event()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		auto position = GetMousePosition();
		points.push_back(position);
		least_squares(points, linefit);
	}

	if (IsKeyPressed(KEY_SPACE))
		reset();
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	for (auto point : points)
		DrawCircleV(point, 4, WHITE);

	float x1 = 0.0f;
	float x2 = GetRenderWidth();
	float y1 = linefit.eval(x1);
	float y2 = linefit.eval(x2);
	DrawLineEx({ x1, y1 }, { x2, y2 }, 3.0f, WHITE);

	EndDrawing();
}

int main()
{
	auto app = new App();
	app->init();
	while (!WindowShouldClose())
	{
		app->event();
		app->draw();
	}
	return 0;
}
