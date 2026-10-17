#include <assert.h>
#include <stdio.h>
#include <string.h>

void
solve(int src[3], const char *str)
{
	int cost[256][3];
	int c;

	memset(cost, 0, sizeof(cost));
	cost['M'][0] = cost['R'][0] = cost['B'][0] = cost['V'][0] = 1;
	cost['Y'][1] = cost['R'][1] = cost['B'][1] = cost['G'][1] = 1;
	cost['C'][2] = cost['V'][2] = cost['B'][2] = cost['G'][2] = 1;

	for (; *str; str++) {
		c = *str & 0xff;
		src[0] -= cost[c][0];
		src[1] -= cost[c][1];
		src[2] -= cost[c][2];
	}

	if (src[0] >= 0 && src[1] >= 0 && src[2] >= 0)
		printf("YES %d %d %d\n", src[0], src[1], src[2]);
	else
		printf("NO\n");
}

int
main()
{
	int src1[] = { 1, 1, 1 };
	int src2[] = { 3, 2, 1 };
	int src3[] = { 1, 1, 1 };

	solve(src1, "MCY");
	solve(src2, "MYWWCR");
	solve(src3, "RV");

	return 0;
}
