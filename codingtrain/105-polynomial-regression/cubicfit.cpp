/*

https://en.wikipedia.org/wiki/Least_squares
https://en.wikipedia.org/wiki/Polynomial_regression
https://en.wikipedia.org/wiki/Vandermonde_matrix

*/

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <Eigen/Dense>
#include <raylib.h>

using namespace std;

struct App
{
	vector<Vector2> points;
	vector<float> fit;

	void init();
	void reset();
	void event();
	void draw();
	void draw_fit();
};

float poly_eval(const vector<float> coeffs, float x)
{
	float p = 1;
	float r = 0;
	for (auto c : coeffs)
	{
		r += c * p;
		p *= x;
	}
	return r;
}

vector<float> cubic_fit(const vector<Vector2> &points)
{
	auto degree = 3;
	auto size = points.size();

	// Vandermonde matrix: n x 4
	Eigen::MatrixXd A(size, degree + 1);
	Eigen::VectorXd y(size);
	size_t i = 0;
	for (auto p : points)
	{
		A(i, 0) = 1.0;
		A(i, 1) = p.x;
		A(i, 2) = p.x * p.x;
		A(i, 3) = p.x * p.x * p.x;
		y(i) = p.y;
		i += 1;
	}

	// Solve least-squares problem: A*c = y using QR decomposition
	Eigen::VectorXd z = A.colPivHouseholderQr().solve(y);
	auto c = z.cast<float>();
	return { c[0], c[1], c[2], c[3] };
}

void App::init()
{
	auto width = 800;
	auto height = 600;

	InitWindow(width, height, "Cubic Fit");
	SetTargetFPS(60);

	reset();
}

void App::reset()
{
	points.clear();
	fit = {};
}

void App::event()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		auto position = GetMousePosition();
		points.push_back(position);
		fit = cubic_fit(points);
	}

	if (IsKeyPressed(KEY_SPACE))
		reset();
}

void App::draw_fit()
{
	float step = 100.0f;
	float x0 = 0;
	float x1 = GetRenderWidth();
	float dx = (x1 - x0) / step;
	float px = x0;
	for (float x = x0 + dx; x <= x1; x += dx)
	{
		float py = poly_eval(fit, px);
		float y = poly_eval(fit, x);
		DrawLineEx({ px, py }, { x, y }, 3.0f, WHITE);
		px = x;
	}
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	for (auto point : points)
		DrawCircleV(point, 4, WHITE);
	draw_fit();
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
