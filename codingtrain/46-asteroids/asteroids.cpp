/*

https://en.wikipedia.org/wiki/Asteroids_(video_game)

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <raylib.h>
#include <raymath.h>

using namespace std;

struct Entity
{
	Vector2 position;
	Vector2 velocity;
	float radius = 0;

	bool hits(Entity &other);
	void update();
};

struct Asteroid : public Entity
{
	vector<float> offsets;

	void init(Vector2 position, float radius);
	vector<Asteroid> breakup();
	void edges();
	void draw();
};

struct Laser : public Entity
{
	void init(Vector2 start, float angle);
	bool offscreen();
	void draw();
};

struct Ship : public Entity
{
	float heading;
	float rotation;
	bool boosting;

	void init();
	void turn();
	void edges();
	void boost();
	void update();
	void draw();
};

struct App
{
	Ship ship;
	vector<Laser> lasers;
	vector<Asteroid> asteroids;

	void init();
	void reset();
	void event();
	void update();
	void draw();
};

Vector2 Vector2RandomUnit()
{
	return { (float)drand48(), (float)drand48() };
}

Vector2 Vector2RandomOnScreen()
{
	return { (float)drand48() * GetRenderWidth(), (float)drand48() * GetRenderHeight() };
}

Vector2 Vector2FromAngle(float angle)
{
	return { cos(angle), sin(angle) };
}

Vector2 Vector2ScreenCenter()
{
	return { GetRenderWidth() / 2.0f, GetRenderHeight() / 2.0f };
}

bool Entity::hits(Entity &other)
{
	auto distance = Vector2Distance(position, other.position);
	return distance < radius + other.radius;
}

void Entity::update()
{
	position = Vector2Add(position, velocity);
}

void Asteroid::init(Vector2 position, float radius)
{
	this->position = position;
	this->radius = radius;
	velocity = Vector2RandomUnit();

	auto total = GetRandomValue(5, 15);
	for (auto i = 0; i < total; i++)
		offsets.push_back(GetRandomValue(-radius * 0.5, radius * 0.5));
}

vector<Asteroid> Asteroid::breakup()
{
	Asteroid asteroid1, asteroid2;
	asteroid1.init(position, radius / 2);
	asteroid2.init(position, radius / 2);
	return { asteroid1, asteroid2 };
}

void Asteroid::edges()
{
	auto width = GetRenderWidth();
	auto height = GetRenderHeight();
	if (position.x > width + radius)
		position.x = -radius;
	else if (position.x < -radius)
		position.x = width + radius;

	if (position.y > height + radius)
		position.y = -radius;
	else if (position.y < -radius)
		position.y = height + radius;
}

void Asteroid::draw()
{
	float sx, sy, px, py;
	for (size_t i = 0; i < offsets.size(); i++)
	{
		float angle = Remap(i, 0, offsets.size(), 0, 2 * PI);
		float r = radius + offsets[i];
		float x = position.x + (r * cos(angle));
		float y = position.y + (r * sin(angle));
		if (i != 0)
			DrawLine(x, y, px, py, RAYWHITE);
		if (i == 0)
		{
			sx = x;
			sy = y;
		}
		px = x;
		py = y;
	}
	DrawLine(sx, sy, px, py, RAYWHITE);
}

bool Laser::offscreen()
{
	auto width = GetRenderWidth();
	auto height = GetRenderHeight();
	if (position.x > width || position.x < 0)
		return true;
	if (position.y > height || position.y < 0)
		return true;
	return false;
}

void Laser::init(Vector2 start, float angle)
{
	position = start;
	velocity = Vector2FromAngle(angle);
	velocity = Vector2Scale(velocity, 10);
}

void Laser::draw()
{
	DrawCircleV(position, 3, RAYWHITE);
}

void Ship::init()
{
	position = Vector2ScreenCenter();
	radius = 20;
	heading = 0;
	rotation = 0;
	velocity = {};
	boosting = false;
}

void Ship::turn()
{
	heading += rotation;
}

void Ship::edges()
{
	auto width = GetRenderWidth();
	auto height = GetRenderHeight();
	if (position.x > width + radius)
		position.x = -radius;
	else if (position.x < -radius)
		position.x = width + radius;

	if (position.y > height + radius)
		position.y = -radius;
	else if (position.y < -radius)
		position.y = height + radius;
}

void Ship::boost()
{
	auto force = Vector2FromAngle(heading);
	force = Vector2Scale(force, 0.1);
	velocity = Vector2Add(velocity, force);
}

void Ship::update()
{
	if (boosting)
		boost();

	position = Vector2Add(position, velocity);
	velocity = Vector2Scale(velocity, 0.99);
}

void Ship::draw()
{
	Vector2 points[] = {
		{ -radius, radius },
		{ radius, radius },
		{ 0, -radius },
	};

	for (size_t i = 0; i < size(points); i++)
	{
		points[i] = Vector2Rotate(points[i], heading + (PI / 2.0));
		points[i] = Vector2Add(points[i], position);
	}
	DrawTriangleLines(points[0], points[1], points[2], RAYWHITE);
}

void App::init()
{
	auto width = 800;
	auto height = 600;

	srand48(time(NULL));

	InitWindow(width, height, "Asteroids");
	SetTargetFPS(60);

	reset();
}

void App::reset()
{
	ship.init();
	lasers.clear();
	asteroids.clear();
	for (size_t i = 0; i < 5; i++)
	{
		Asteroid asteroid;
		asteroid.init(Vector2RandomOnScreen(), GetRandomValue(25, 40));
		asteroids.push_back(asteroid);
	}
}

void App::event()
{
	ship.rotation = 0;
	ship.boosting = false;

	if (IsKeyPressed(KEY_ESCAPE))
		exit(0);

	if (IsKeyPressed(KEY_ENTER))
		reset();

	if (IsKeyPressed(KEY_SPACE))
	{
		Laser laser;
		laser.init(ship.position, ship.heading);
		lasers.push_back(laser);
	}

	if (IsKeyDown(KEY_RIGHT))
		ship.rotation = 0.1;
	if (IsKeyDown(KEY_LEFT))
		ship.rotation = -0.1;
	if (IsKeyDown(KEY_UP))
		ship.boosting = true;
}

void App::update()
{
	for (size_t i = 0; i < asteroids.size(); i++)
	{
		if (ship.hits(asteroids[i]))
		{
			reset();
			return;
		}

		asteroids[i].update();
		asteroids[i].edges();
	}

	ship.turn();
	ship.update();
	ship.edges();
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (size_t i = 0; i < asteroids.size(); i++)
		asteroids[i].draw();

	for (ssize_t i = lasers.size() - 1; i >= 0; i--)
	{
		lasers[i].draw();
		lasers[i].update();
		if (lasers[i].offscreen())
		{
			lasers.erase(lasers.begin() + i);
			continue;
		}

		for (ssize_t j = asteroids.size() - 1; j >= 0; j--)
		{
			if (lasers[i].hits(asteroids[j]))
			{
				if (asteroids[j].radius > 10)
				{
					for (auto debris : asteroids[j].breakup())
						asteroids.push_back(debris);
				}
				asteroids.erase(asteroids.begin() + j);
				lasers.erase(lasers.begin() + i);
				break;
			}
		}
	}

	ship.draw();
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
