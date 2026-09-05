/*

https://en.wikipedia.org/wiki/Pong

*/

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <raylib.h>

using namespace std;

struct App;

struct Paddle
{
	float x, y, w, h;
	float ychange;

	void init(bool isleft);
	void update();
	void move(float steps);
	void show();
};

struct Puck
{
	float x, y, r;
	float xspeed;
	float yspeed;

	void init();
	void reset();
	void update();
	void check_paddle_left(const Paddle &p);
	void check_paddle_right(const Paddle &p);
	void edges(App *app);
	void show();
};

struct App
{
	Music ding;
	Paddle left;
	Paddle right;
	Puck puck;
	int left_score;
	int right_score;

	void play_ding();
	void init();
	void event();
	void update();
	void draw();
	void draw_score();
};

float unlerp(float t, float a, float b)
{
	return (t - a) / (b - a);
}

float linear_remap(float x, float a, float b, float c, float d)
{
	return lerp(unlerp(x, a, b), c, d);
}

void Paddle::init(bool isleft)
{
	y = GetRenderHeight() / 2.0f;
	w = 20.0f;
	h = 100.0f;
	ychange = 0.0f;
	if (isleft)
		x = w;
	else
		x = GetRenderWidth() - w;
}

void Paddle::update()
{
	y += ychange;
	y = clamp(y, h / 2.0f, GetRenderHeight() - (h / 2.0f));
}

void Paddle::move(float steps)
{
	ychange = steps;
}

void Paddle::show()
{
	DrawRectangleRec({ x - (w / 2.0f), y - (h / 2.0f), w, h }, WHITE);
}

void Puck::init()
{
	r = 12.0f;
	reset();
}

void Puck::reset()
{
	x = GetRenderWidth() / 2.0f;
	y = GetRenderHeight() / 2.0f;

	float angle = PI / 4.0f * GetRandomValue(-1, 1);
	xspeed = 5.0f * cos(angle);
	yspeed = 5.0f * sin(angle);

	if (GetRandomValue(0, 10) < 5)
		xspeed *= -1;
}

void Puck::update()
{
	x += xspeed;
	y += yspeed;
}

void Puck::check_paddle_left(const Paddle &p)
{
	if (y - r < p.y + p.h / 2 &&
		y + r > p.y - p.h / 2 &&
		x - r < p.x + p.w / 2)
	{
		if (x > p.x)
		{
			float diff = y - (p.y - p.h / 2);
			float rad = 45 * DEG2RAD;
			float angle = linear_remap(diff, 0, p.h, -rad, rad);
			xspeed = 5 * cos(angle);
			yspeed = 5 * sin(angle);
			x = p.x + p.w / 2 + r;
		}
	}
}

void Puck::check_paddle_right(const Paddle &p)
{
	if (y - r < p.y + p.h / 2 &&
		y + r > p.y - p.h / 2 &&
		x + r > p.x - p.w / 2)
	{
		if (x < p.x)
		{
			float diff = y - (p.y - p.h / 2);
			float angle = linear_remap(diff, 0, p.h, 225 * DEG2RAD, 135 * DEG2RAD);
			xspeed = 5 * cos(angle);
			yspeed = 5 * sin(angle);
			x = p.x - (p.w / 2) - r;
		}
	}
}

void Puck::edges(App *app)
{
	if (y < 0 || y > GetRenderHeight())
		yspeed *= -1;

	if (x - r > GetRenderWidth())
	{
		app->play_ding();
		app->left_score += 1;
		reset();
	}

	if (x + r < 0)
	{
		app->play_ding();
		app->right_score += 1;
		reset();
	}

	app->left_score = clamp(app->left_score, 0, 100);
	app->right_score = clamp(app->right_score, 0, 100);
}

void Puck::show()
{
	DrawCircle(x, y, r, WHITE);
}

void App::init()
{
	auto width = 600;
	auto height = 400;

	InitWindow(width, height, "Pong");
	InitAudioDevice();
	SetTargetFPS(60);

	ding = LoadMusicStream("ding.mp3");
	ding.looping = false;

	left.init(true);
	right.init(false);
	puck.init();
}

void App::event()
{
	left.move(0);
	right.move(0);

	if (IsKeyDown(KEY_A))
		left.move(-10);
	else if (IsKeyDown(KEY_Z))
		left.move(10);

	if (IsKeyDown(KEY_J))
		right.move(-10);
	else if (IsKeyDown(KEY_M))
		right.move(10);
}

void App::play_ding()
{
	StopMusicStream(ding);
	PlayMusicStream(ding);
}

void App::update()
{
	UpdateMusicStream(ding);
	puck.check_paddle_left(left);
	puck.check_paddle_right(right);
	left.update();
	right.update();
	puck.update();
	puck.edges(this);
}

void App::draw_score()
{
	char left_text[32];
	char right_text[32];
	snprintf(left_text, sizeof(left_text), "%d", left_score);
	snprintf(right_text, sizeof(right_text), "%d", right_score);

	DrawText(left_text, 50, 40, 32, WHITE);
	DrawText(right_text, GetRenderWidth() - 64, 40, 32, WHITE);
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	left.show();
	right.show();
	puck.show();
	draw_score();
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
