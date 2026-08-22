#include "raylib.h"
#include "raymath.h"

int
main()
{
	Vector2 control1;
	Vector2 control2;
	Vector2 control3;
	Vector2 start;
	Vector2 end;
	Color color;
	float thickness;
	float delta;
	float t;
	int screensize;

	screensize = 600;
	control1 = (Vector2){ 0.0f, 300.0f };
	control2 = (Vector2){ 300.0f, 0.0f };
	control3 = (Vector2){ 600.0f, 300.0f };
	thickness = 3.0f;

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(screensize, screensize, "Quadratic Bezier Curve");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		control2 = GetMousePosition();

		BeginDrawing();

		ClearBackground(BLACK);

		delta = 0.04f;
		for (t = 0.0f; t <= 1.0f; t += delta) {
			start.x = Lerp(control1.x, control2.x, t);
			start.y = Lerp(control1.y, control2.y, t);
			end.x = Lerp(control2.x, control3.x, t);
			end.y = Lerp(control2.y, control3.y, t);
			color = ColorFromHSV(t * 360, 1, 1);
			DrawLineEx(start, end, thickness, color);
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
