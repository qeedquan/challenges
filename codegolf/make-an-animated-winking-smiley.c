/*

Recently, I've been looking more and more into retrogaming programming, and I saw this nice example from an old GBDK wiki
(A tool to make Gameboy games with C, replaced by GBDK-2020):

https://i.sstatic.net/e83jMK4v.gif

This example program uses two similar 16x16 sprites :
https://i.sstatic.net/0NAy2UCY.png

The program loop is pretty easy to understand. The first sprite is displayed, then the program waits for 500ms, then the second sprite is displayed instead, and finally it waits once again for 500ms. You can see that the first half of each sprite is identical, and that the second half of the first sprite is identical to the first half flipped.

Your goal for this challenge is to recreate this animation using the same pixel-art winking face with as few bytes as possible. The winking smiley can appear anywhere on your drawing area, can be scaled however you want (as long as the shape remains the same, therefore its size will still have to be a multiple of 16x16), and each frame must be drawn approximately 500ms after the previous one (some margin of error allowed, standard rules about delays/time management apply). The program can be in pure black and white, or you can choose the colors you want.

This is code-golf, so the shortest program will win. Good luck ;)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <threads.h>

enum {
	SIZE = 128,
};

typedef struct {
	char state[SIZE][SIZE];
	int width;
	int height;
} Smiles;

int
sminit(Smiles *sm, int width, int height)
{
	if (width < 0 || height < 0 || width >= SIZE || height >= SIZE)
		return -1;
	sm->width = width;
	sm->height = height;
	return 0;
}

void
smreset(Smiles *sm)
{
	int x, y;

	for (y = 0; y < sm->height; y++) {
		for (x = 0; x < sm->width; x++) {
			sm->state[y][x] = rand() & 1;
		}
	}
}

void
smdraw(Smiles *sm)
{
	int x, y;

	printf("\033c");
	for (y = 0; y < sm->height; y++) {
		for (x = 0; x < sm->width; x++) {
			if (sm->state[y][x])
				printf("%s", u8"😉");
			else
				printf("%s", u8"😀");
		}
		printf("\n");
	}
	printf("\n");
}

void
smflip(Smiles *sm)
{
	int x, y;

	for (y = 0; y < sm->height; y++) {
		for (x = 0; x < sm->width; x++) {
			sm->state[y][x] ^= 1;
		}
	}
}

int
main()
{
	static const struct timespec delay = {
		.tv_sec = 1,
	};

	Smiles sm;

	srand(time(NULL));
	sminit(&sm, 32, 25);
	smreset(&sm);
	for (;;) {
		smdraw(&sm);
		smflip(&sm);
		thrd_sleep(&delay, NULL);
	}
	return 0;
}
