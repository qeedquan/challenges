#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
move(int dice[6], int a, int b, int c, int d)
{
	int tmp;

	tmp = dice[a];
	dice[a] = dice[b];
	dice[b] = dice[c];
	dice[c] = dice[d];
	dice[d] = tmp;
}

int
play(const char **cmds, size_t ncmd)
{
	const char *cmd;
	int dice[6];
	size_t i;

	for (i = 0; i < 6; i++)
		dice[i] = i + 1;

	for (i = 0; i < ncmd; i++) {
		cmd = cmds[i];
		if (!strcmp(cmd, "north"))
			move(dice, 1, 0, 4, 5);
		else if (!strcmp(cmd, "south"))
			move(dice, 1, 5, 4, 0);
		else if (!strcmp(cmd, "east"))
			move(dice, 3, 0, 2, 5);
		else if (!strcmp(cmd, "west"))
			move(dice, 3, 5, 2, 0);
	}
	return dice[0];
}

int
main()
{
	const char *cmds1[] = { "north" };
	const char *cmds2[] = { "north", "east", "south" };

	assert(play(cmds1, nelem(cmds1)) == 5);
	assert(play(cmds2, nelem(cmds2)) == 1);

	return 0;
}
