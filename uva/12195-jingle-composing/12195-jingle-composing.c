#include <assert.h>

typedef long long vlong;

vlong
solve(const char *jingle)
{
	vlong find, sum;

	for (find = sum = 0; *jingle; jingle++) {
		switch (*jingle) {
		case '/':
			if (sum == 1000000)
				find += 1;
			sum = 0;
			break;
		case 'W':
			sum += 1000000;
			break;
		case 'H':
			sum += 500000;
			break;
		case 'Q':
			sum += 250000;
			break;
		case 'E':
			sum += 125000;
			break;
		case 'S':
			sum += 62500;
			break;
		case 'T':
			sum += 31250;
			break;
		case 'X':
			sum += 15625;
			break;
		}
	}
	return find;
}

int
main()
{
	assert(solve("/HH/QQQQ/XXXTXTEQH/W/HW/") == 4);
	assert(solve("/W/W/SQHES/") == 3);
	assert(solve("/WE/TEX/THES/") == 0);

	return 0;
}
