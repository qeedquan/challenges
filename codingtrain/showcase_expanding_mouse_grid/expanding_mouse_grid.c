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
	InitWindow(screen_width, screen_height, "Expanding Mouse Grid");
	SetTargetFPS(60);
}

int
main()
{
	Color color;
	float mousex, mousey;
	float x, y;

	initrl();
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		mousex = GetMouseX();
		mousey = GetMouseY();
		for (x = -100; x <= mousex + 20; x += 50) {
			for (y = -100; y <= 100; y += 50) {
				color = (Color){
					GetRandomValue(0, 255),
					mousex / 5,
					GetRandomValue(0, 255),
					255,
				};
				DrawCircle(mousex + x, mousey + y, 25 / 2.0f, WHITE);
				DrawCircle(mousex + x, mousey + y, 23 / 2.0f, color);
			}
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
