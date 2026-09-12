#include <stdio.h>

void
triangle(int a, int f)
{
	int i, j, k;

	for (i = 0; i < f; i++) {
		for (j = 1; j <= a; j++) {
			for (k = 0; k < j; k++)
				printf("%d", j);
			printf("\n");
		}

		for (j = a - 1; j >= 1; j--) {
			for (k = 0; k < j; k++)
				printf("%d", j);
			printf("\n");
		}
		if (i != f - 1)
			printf("\n");
	}
	printf("\n");
}

int
main()
{
	triangle(3, 2);
	return 0;
}
