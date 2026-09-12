#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <raylib.h>
#include <raymath.h>

int screen_width;
int screen_height;

void
initrl()
{
	screen_width = 1280;
	screen_height = 960;

	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(screen_width, screen_height, "Stacked Circles");
	SetTargetFPS(60);
}

int
main()
{
	Color color;
	Vector2 mouse;
	Vector2 center;
	float angle;
	float offset;
	float diameter;
	float dist_mouse;
	float dist_vertical;
	float step;

	initrl();

	angle = 0.0f;
	while (!WindowShouldClose()) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			angle = fmod(angle + 40.0f, 360.0f);

		mouse = GetMousePosition();
		center = (Vector2){
			GetRenderWidth() / 2.0f,
			GetRenderHeight() / 2.0f,
		};

		dist_mouse = hypot(mouse.x - center.x, mouse.y - center.y) * 2;
		dist_vertical = fabs(mouse.y - center.y);
		step = Remap(dist_vertical, 0, 600, 50, 150);
		offset = fmin(offset + 0.04f, 1.0f);

		BeginDrawing();
		BeginBlendMode(BLEND_ALPHA);
		ClearBackground(BLACK);

		for (diameter = dist_mouse; diameter > 0; diameter -= step) {
			color = ColorFromHSV(angle, offset, offset);
			color.a = 10;
			DrawCircleV(center, diameter, color);
		}

		EndBlendMode();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
