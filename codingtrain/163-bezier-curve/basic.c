#include <raylib.h>

int
main()
{
	Vector2 control1;
	Vector2 control3;
	Vector2 control4;
	Vector2 mouse;
	float pointsize;
	float thickness;
	int screensize;

	screensize = 600;
	control1 = (Vector2){ 0.0f, 300.0f };
	control3 = (Vector2){ 400.0f, 400.0f };
	control4 = (Vector2){ 600.0f, 300.0f };
	thickness = 4.0f;
	pointsize = 14.0f;

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(screensize, screensize, "Bezier Curve (Basic)");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		mouse = GetMousePosition();

		BeginDrawing();

		ClearBackground(BLACK);

		DrawSplineSegmentBezierCubic(control1, mouse, control3, control4, thickness, WHITE);

		DrawCircleV(control1, pointsize, WHITE);
		DrawCircleV(mouse, pointsize, WHITE);
		DrawCircleV(control3, pointsize, WHITE);
		DrawCircleV(control4, pointsize, WHITE);

		DrawLineEx(control1, mouse, thickness, WHITE);
		DrawLineEx(control3, control4, thickness, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
