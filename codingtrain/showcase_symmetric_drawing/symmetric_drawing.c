#include <stdio.h>
#include <math.h>
#include <raylib.h>

int screen_width;
int screen_height;
RenderTexture2D target;
Color background;

Color
subrgb(Color c, int s)
{
	int r, g, b;

	r = fmax(c.r - s, 0);
	g = fmax(c.g - s, 0);
	b = fmax(c.b - s, 0);
	return (Color){ r, g, b, 255 };
}

void
reset()
{
	background = (Color){ 200, 200, 200, 255 };
	BeginTextureMode(target);
	ClearBackground(background);
	EndTextureMode();
}

void
initrl()
{
	screen_width = 800;
	screen_height = 800;

	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(screen_width, screen_height, "Symmetric Drawing");
	SetTargetFPS(60);

	target = LoadRenderTexture(screen_width, screen_height);
	reset();
}

void
render()
{
	Vector2 mouse;
	Color color;

	BeginTextureMode(target);
	color = (Color){ 0, 200, 200, 75 };
	mouse = GetMousePosition();
	DrawCircle(mouse.x, mouse.y, 32, color);
	DrawCircle(mouse.y, mouse.x, 32, color);

	color = (Color){ mouse.x, 0, mouse.y, 255 };
	DrawCircle(mouse.x, mouse.y, 10, color);
	DrawCircle(mouse.y, mouse.x, 10, color);
	EndTextureMode();
}

int
main()
{
	initrl();

	while (!WindowShouldClose()) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			background = subrgb(background, 40);
		if (IsKeyPressed(KEY_SPACE))
			reset();

		render();

		BeginDrawing();
		BeginBlendMode(BLEND_ALPHA);
		DrawTextureRec(target.texture, (Rectangle){ 0, 0, screen_width, -screen_height }, (Vector2){}, background);
		EndBlendMode();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
