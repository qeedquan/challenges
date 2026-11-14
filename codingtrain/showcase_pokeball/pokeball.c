#include <stdio.h>
#include <math.h>
#include <raylib.h>

int screen_width;
int screen_height;

void
initrl()
{
	screen_width = 400;
	screen_height = 300;

	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(screen_width, screen_height, "Pokeball");
	SetTargetFPS(60);
}

void
draw_pokeball()
{
	Rectangle rect;
	Vector2 center;
	float radius;

	center = (Vector2){ 200.0f, 150.0f };
	radius = 150.0f;
	DrawCircleSector(center, radius, 0, -180, 0, RED);
	DrawCircleSector(center, radius, 0, 180, 0, WHITE);

	rect = (Rectangle){ center.x - radius, center.y, radius * 2, 10 };
	DrawRectangle(rect.x, rect.y, rect.width, rect.height, BLACK);

	DrawCircleV(center, 30, BLACK);
	DrawCircleV(center, 20, WHITE);
	DrawCircleV(center, 17, BLACK);
	DrawCircleV(center, 13, WHITE);
}

int
main()
{
	initrl();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground((Color){ 180, 180, 180, 255 });

		draw_pokeball();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
