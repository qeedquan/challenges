#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>

int screen_width;
int screen_height;
Color background;

Color
randcolor()
{
	return (Color){
		GetRandomValue(0, 255),
		GetRandomValue(0, 255),
		GetRandomValue(0, 255),
		255,
	};
}

void
initrl()
{
	screen_width = 500;
	screen_height = 500;

	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(screen_width, screen_height, "Monster Eyes");
	SetTargetFPS(60);

	background = randcolor();
}

void
draweyes()
{
	int row, col;
	Vector2 eye;
	Vector2 mouse;
	float angle;
	float radius;
	float diameter;

	mouse = GetMousePosition();
	radius = 50;
	diameter = radius * 2;
	for (col = 0; col < 5; col++) {
		for (row = 0; row < 5; row++) {
			eye.x = radius + (diameter * col);
			eye.y = radius + (diameter * row);
			angle = atan2(mouse.y - eye.y, mouse.x - eye.x);

			DrawCircleV(eye, radius - 10, WHITE);

			rlPushMatrix();
			rlTranslatef(eye.x, eye.y, 0);
			rlRotatef(angle * RAD2DEG, 0, 0, 1);
			DrawCircle(12.5, 0, 12.5, BLACK);
			rlPopMatrix();
		}
	}
}

int
main()
{
	initrl();
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(background);
		draweyes();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
