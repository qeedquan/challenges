#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>

int
main(int argc, char *argv[])
{
	Music sound;
	int width;
	int height;
	int fontsize;
	int fontwidth;
	int duration;
	int timeleft;
	bool finished;
	time_t time0;
	time_t time1;
	char text[32];

	width = 640;
	height = 240;
	fontsize = 96;

	duration = 10;
	if (argc >= 2)
		duration = abs(atoi(argv[1]));

	time0 = time(NULL);
	timeleft = duration;
	finished = false;

	InitWindow(width, height, "Countdown Timer");
	InitAudioDevice();
	SetTargetFPS(60);

	sound = LoadMusicStream("ding.mp3");
	sound.looping = false;

	while (!WindowShouldClose()) {
		if (IsKeyDown(KEY_SPACE)) {
			timeleft = duration;
			time0 = time(NULL);
			finished = false;
		}

		UpdateMusicStream(sound);

		BeginDrawing();
		ClearBackground(BLACK);

		if (timeleft > 0) {
			time1 = time(NULL);
			timeleft -= time1 - time0;
			time0 = time1;
		} else if (!finished) {
			timeleft = 0;
			finished = true;
			PlayMusicStream(sound);
		}

		snprintf(text, sizeof(text), "%02d:%02d", timeleft / 60, timeleft % 60);
		fontwidth = MeasureText(text, fontsize);
		DrawText(text, (width - fontwidth) / 2, (height - fontsize) / 2, fontsize, WHITE);

		EndDrawing();
	}

	UnloadMusicStream(sound);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
