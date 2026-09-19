/*

https://en.wikipedia.org/wiki/Verlet_integration

*/

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <raylib.h>
#include <raymath.h>

using namespace std;

struct Particle
{
	Vector2 pos;
	Vector2 prev;
	Vector2 force;
	float weight;
	float inv_weight;
	bool locked;

	void init(float x, float y);

	void lock();

	void add_force(Vector2 force);
	void scale_velocity(float scale);

	void update();
};

struct Gravity
{
	Vector2 force;
	Vector2 scaled_force;
	float timestep;

	void init(Vector2 force);

	void configure(float timestep);

	void apply_behavior(Particle *p);
};

struct Spring
{
	Particle *a, *b;
	float rest_length;
	float strength;

	void init(Particle *a, Particle *b);
	void update();
	void draw();
};

struct Physics
{
	int iterations;
	float drag;
	float timestep;

	vector<Gravity *> gravities;
	vector<Particle *> particles;
	vector<Spring *> springs;

	void init();

	void add_gravity(Gravity *gravity);
	void add_particle(Particle *particle);
	void add_spring(Spring *springs);

	void set_drag(float drag);

	void update();

private:
	void update_particles();
	void update_springs();
};

struct App
{
	Physics physics;
	Gravity gravity;
	vector<vector<Particle> > particles;
	vector<Spring> springs;

	void init();
	void reset();
	void event();
	void update();
	void draw();
};

void Particle::init(float x, float y)
{
	pos = { x, y };
	prev = {};
	force = {};
	weight = 1.0;
	inv_weight = 1.0 / weight;
	locked = false;
}

void Particle::lock()
{
	locked = true;
}

void Particle::add_force(Vector2 force)
{
	this->force = Vector2Add(this->force, force);
}

void Particle::scale_velocity(float scale)
{
	prev = Vector2Lerp(prev, pos, 1 - scale);
}

void Particle::update()
{
	if (locked)
		return;

	auto temp = pos;
	auto scaled_force = Vector2Scale(force, weight);
	auto delta = Vector2Subtract(pos, prev);
	delta = Vector2Add(delta, scaled_force);
	pos = Vector2Add(pos, delta);
	prev = temp;
	force = {};
}

void Spring::init(Particle *a, Particle *b)
{
	this->a = a;
	this->b = b;
	rest_length = 10.0;
	strength = 1.1;
}

void Spring::update()
{
	static const float EPS = 1e-6;

	auto delta = Vector2Subtract(b->pos, a->pos);
	auto dist = Vector2Length(delta) + EPS;
	auto norm_dist_strength = (dist - rest_length) / (dist * (a->inv_weight + b->inv_weight)) * strength;
	if (!a->locked)
	{
		auto delta_scaled = Vector2Scale(delta, norm_dist_strength * a->inv_weight);
		a->pos = Vector2Add(a->pos, delta_scaled);
	}
	if (!b->locked)
	{
		auto delta_scaled = Vector2Scale(delta, -norm_dist_strength * b->inv_weight);
		b->pos = Vector2Add(b->pos, delta_scaled);
	}
}

void Spring::draw()
{
	DrawLineEx(a->pos, b->pos, 2, WHITE);
}

void Gravity::init(Vector2 force)
{
	this->force = force;
	configure(0);
}

void Gravity::configure(float timestep)
{
	this->timestep = timestep;
	scaled_force = Vector2Scale(force, timestep * timestep);
}

void Gravity::apply_behavior(Particle *p)
{
	p->add_force(scaled_force);
}

void Physics::init()
{
	iterations = 50;
	timestep = 1;
	set_drag(0);

	gravities.clear();
	particles.clear();
	springs.clear();
}

void Physics::set_drag(float drag)
{
	this->drag = 1 - drag;
}

void Physics::add_gravity(Gravity *gravity)
{
	gravity->configure(timestep);
	gravities.push_back(gravity);
}

void Physics::add_particle(Particle *particle)
{
	particles.push_back(particle);
}

void Physics::add_spring(Spring *spring)
{
	springs.push_back(spring);
}

void Physics::update_particles()
{
	for (auto gravity : gravities)
	{
		for (auto particle : particles)
			gravity->apply_behavior(particle);
	}

	for (auto particle : particles)
	{
		particle->scale_velocity(drag);
		particle->update();
	}
}

void Physics::update_springs()
{
	for (auto i = iterations; i > 0; i--)
	{
		for (auto spring : springs)
			spring->update();
	}
}

void Physics::update()
{
	update_particles();
	update_springs();
}

void App::init()
{
	auto width = 1024;
	auto height = 768;

	InitWindow(width, height, "2D Cloth");
	SetTargetFPS(60);

	reset();
}

void App::reset()
{
	physics.init();
	gravity.init({ 0, 1.0 });
	physics.add_gravity(&gravity);

	auto cols = 20;
	auto rows = 20;
	particles.resize(cols);
	for (auto i = 0; i < cols; i++)
		particles[i].resize(rows);

	auto x = GetRenderWidth() / 4;
	auto w = 10;
	for (auto i = 0; i < cols; i++)
	{
		auto y = GetRenderHeight() / 4;
		for (auto j = 0; j < rows; j++)
		{
			particles[i][j].init(x, y);
			physics.add_particle(&particles[i][j]);
			y += w;
		}
		x += w;
	}

	size_t n = 0;
	springs.clear();
	for (auto i = 0; i < cols; i++)
	{
		for (auto j = 0; j < rows; j++)
		{
			auto a = &particles[i][j];
			if (i != cols - 1)
			{
				auto b1 = &particles[i + 1][j];
				springs.push_back(Spring{});
				springs[n].init(a, b1);
				n += 1;
			}
			if (j != rows - 1)
			{
				auto b2 = &particles[i][j + 1];
				springs.push_back(Spring{});
				springs[n].init(a, b2);
				n += 1;
			}
		}
	}
	for (size_t i = 0; i < n; i++)
		physics.add_spring(&springs[i]);

	particles[0][0].lock();
	particles[cols - 1][0].lock();
}

void App::event()
{
	if (IsKeyPressed(KEY_ESCAPE))
		exit(0);
}

void App::update()
{
	physics.update();
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (auto &spring : springs)
		spring.draw();

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
