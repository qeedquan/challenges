#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(const char **cmds, size_t ncmds)
{
	const char *cmd;
	size_t i;
	int pile1;
	int pile2;
	int amount;

	pile1 = pile2 = 0;
	for (i = 0; i < ncmds; i++) {
		cmd = cmds[i];
		if (sscanf(cmd, "DROP %d", &amount) == 1) {
			printf("DROP 2 %d\n", amount);
			pile2 += amount;
		} else if (sscanf(cmd, "TAKE %d", &amount) == 1) {
			if (pile1 >= amount) {
				printf("TAKE 1 %d\n", amount);
				pile1 -= amount;
			} else {
				if (pile1) {
					printf("TAKE 1 %d\n", pile1);
					amount -= pile1;
					pile1 = 0;
				}
				printf("MOVE 2->1 %d\n", pile2);
				pile1 += pile2;
				pile2 = 0;
				if (amount) {
					printf("TAKE 1 %d\n", amount);
					pile1 -= amount;
				}
			}
		}
	}
	puts("");
}

int
main()
{
	const char *cmds1[] = {
		"DROP 100",
		"TAKE 50",
		"TAKE 20",
	};

	const char *cmds2[] = {
		"DROP 3",
		"DROP 5",
		"TAKE 8",
	};

	solve(cmds1, nelem(cmds1));
	solve(cmds2, nelem(cmds2));

	return 0;
}
