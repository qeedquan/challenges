#include <stdio.h>
#include <math.h>
#include <raylib.h>
#include <raymath.h>

int screen_width;
int screen_height;

void
initrl()
{
	screen_width = 600;
	screen_height = 600;

	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(screen_width, screen_height, "Changing Ellipse");
	SetTargetFPS(60);
}

void
draw_ellipse()
{
	float width;
	float height;
	float size;
	Vector2 center;
	Vector2 mouse;
	Color color;

	width = GetRenderWidth();
	height = GetRenderHeight();
	mouse = GetMousePosition();
	color.r = Remap(mouse.x, 0, width, 225, 0);
	color.g = Remap(mouse.x, width, 0, 130, 0);
	color.b = 0;
	color.a = 255;
	size = Remap(mouse.y, 0, height, 80, 150);
	center = (Vector2){ width / 2.0f, height / 2.0f };

	DrawCircleV(center, size, BLACK);
	DrawCircleV(center, size - 4, color);
}

int
main()
{
	initrl();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground((Color){ 180, 180, 180, 255 });

		draw_ellipse();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
