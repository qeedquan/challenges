#include <raylib.h>
#include "raymath.h"

typedef struct {
	float x, y;
	float dx, dy;
} Particle;

void
particle_init(Particle *p, float x, float y)
{
	p->x = x;
	p->y = y;
	p->dx = GetRandomValue(-8, 8);
	p->dy = GetRandomValue(-8, 8);
}

void
particle_update(Particle *p)
{
	p->x += p->dx;
	p->y += p->dy;

	if (p->x >= GetRenderWidth() || p->x < 0) {
		p->dx *= -1;
	}

	if (p->y >= GetRenderHeight() || p->y < 0) {
		p->dy *= -1;
	}
}

Vector2
quadratic(Particle p0, Particle p1, Particle p2, float t, Color color)
{
	float x1, y1, x2, y2, x, y;

	x1 = Lerp(p0.x, p1.x, t);
	y1 = Lerp(p0.y, p1.y, t);
	x2 = Lerp(p1.x, p2.x, t);
	y2 = Lerp(p1.y, p2.y, t);
	x = Lerp(x1, x2, t);
	y = Lerp(y1, y2, t);
	DrawLineEx((Vector2){ x1, y1 }, (Vector2){ x2, y2 }, 2.0f, color);
	return (Vector2){ x, y };
}

Vector2
cubic(Particle p0, Particle p1, Particle p2, Particle p3, float t, Color color)
{
	Vector2 v1, v2;
	float x, y;

	v1 = quadratic(p0, p1, p2, t, color);
	v2 = quadratic(p1, p2, p3, t, color);
	x = Lerp(v1.x, v2.x, t);
	y = Lerp(v1.y, v2.y, t);
	DrawLineEx(v1, v2, 2.0f, color);
	return (Vector2){ x, y };
}

int
main()
{
	Particle p0, p1, p2, p3;
	Color color;
	float delta;
	float t;
	int screensize;

	screensize = 600;

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(screensize, screensize, "Cubic Bezier Curve");
	SetTargetFPS(60);

	particle_init(&p0, 0.0f, GetRenderHeight() / 2.0f);
	particle_init(&p1, GetRenderWidth() / 4.0f, 0.0f);
	particle_init(&p2, 3.0f * GetRenderWidth() / 4.0f, GetRenderHeight());
	particle_init(&p3, GetRenderWidth(), GetRenderHeight() / 2.0f);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		particle_update(&p1);
		particle_update(&p2);

		delta = 0.02f;
		for (t = 0.0f; t <= 1.0f; t += delta) {
			color = ColorFromHSV(t * 360, 1, 1);
			color.a = 128;
			cubic(p0, p1, p2, p3, t, color);
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
