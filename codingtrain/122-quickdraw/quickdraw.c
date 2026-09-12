#include <stdio.h>
#include <raylib.h>
#include "cat.h"

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
main()
{
	RenderTexture2D target;
	Rectangle bounds;
	float thickness;
	int screensize;
	int targetsize;
	size_t frame;
	size_t index;
	Vector2 center;
	Vector2 previous;
	Vector2 current;

	screensize = 512;
	targetsize = 256;
	thickness = 3.0f;
	frame = 0;
	index = 0;
	previous = (Vector2){ -1, -1 };
	current = previous;

	InitWindow(screensize, screensize, "Quick Draw");
	SetTargetFPS(60);

	target = LoadRenderTexture(targetsize, targetsize);
	bounds = (Rectangle){ 0, 0, targetsize, -targetsize };
	center = (Vector2){ (screensize - targetsize) / 2.0f, (screensize - targetsize) / 2.0f };

	while (!WindowShouldClose()) {
		BeginTextureMode(target);
		current = CAT[frame][index];
		if (previous.x >= 0)
			DrawLineEx(previous, current, thickness, BLACK);

		index += 1;
		if (CAT[frame][index].x < 0) {
			previous = (Vector2){ -1, -1 };
			current = previous;
			index = 0;
			frame += 1;
			if (frame >= nelem(CAT)) {
				frame = 0;
				UnloadRenderTexture(target);
				target = LoadRenderTexture(targetsize, targetsize);
			}
		} else {
			previous = current;
		}
		EndTextureMode();

		BeginDrawing();
		ClearBackground(WHITE);
		DrawTextureRec(target.texture, bounds, center, WHITE);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
