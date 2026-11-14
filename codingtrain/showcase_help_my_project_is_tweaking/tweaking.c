#include <stdio.h>
#include <math.h>
#include <raylib.h>

int screen_width;
int screen_height;

Color
random_color()
{
	return (Color){
		GetRandomValue(0, 255),
		GetRandomValue(0, 255),
		GetRandomValue(0, 255),
		255,
	};
}

Rectangle
random_rect()
{
	return (Rectangle){
		GetRandomValue(0, 255),
		GetRandomValue(0, 255),
		GetRandomValue(0, 255),
		GetRandomValue(0, 255),
	};
}

void
initrl()
{
	screen_width = 400;
	screen_height = 400;

	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(screen_width, screen_height, "Tweaking");
	SetTargetFPS(30);
}

void
draw_tweakings()
{
	Rectangle rect; 
	Color color;

	rect = random_rect();
	color = random_color();
	DrawRectangleRec(rect, color);
}

int
main()
{
	initrl();

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground((Color){ 200, 200, 200, 255 });
		draw_tweakings();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
