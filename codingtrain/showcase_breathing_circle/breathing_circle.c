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
	InitWindow(screen_width, screen_height, "Breathing Circle");
	SetTargetFPS(60);
}

int
main()
{
	float maxsize;
	float size;
	float speed;

	initrl();

	maxsize = 100;
	size = 10;
	speed = 1;
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		size += speed;
		if (fabs(size) > maxsize)
			speed = -speed;

		DrawCircle(200, 150, size, WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
