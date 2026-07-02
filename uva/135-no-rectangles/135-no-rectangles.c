#include <stdio.h>

void
solve(int K)
{
	int i, j, m, s;

	m = K - 1;
	for (i = 0; i < K; i++) {
		printf("%d", 1);
		for (j = 1; j < K; j++)
			printf(" %d", i * m + j + 1);
		puts("");
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("%d", i + 2);
			for (s = 0; s < m; s++)
				printf(" %d", ((j + s * i) % m) + (s * m) + K + 1);
			puts("");
		}
	}
	puts("");
}

int
main()
{
	solve(2);
	solve(1);
	return 0;
}
