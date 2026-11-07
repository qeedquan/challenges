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
	screen_width = 800;
	screen_height = 600;

	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(screen_width, screen_height, "2D PID Controller");
	SetTargetFPS(60);
}

int
main()
{
	Vector2 bob;
	Vector2 prev_error;
	Vector2 sum_error;
	Vector2 error;
	Vector2 mouse;
	float P, I, D;

	initrl();

	bob = (Vector2){};
	prev_error = (Vector2){};
	sum_error = (Vector2){};
	P = 0.1;
	I = 0.005;
	D = 0.1;
	while (!WindowShouldClose()) {
		mouse = GetMousePosition();
		error = Vector2Subtract(mouse, bob);
		sum_error = Vector2Add(sum_error, error);
		bob.x = bob.x + (error.x * P) + ((error.x - prev_error.x) * D) + (sum_error.x * I);
		bob.y = bob.y + (error.y * P) + ((error.y - prev_error.y) * D) + (sum_error.y * I);
		prev_error = error;

		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircleV(mouse, 5, WHITE);
		DrawCircleV(bob, 5, YELLOW);

		EndBlendMode();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
