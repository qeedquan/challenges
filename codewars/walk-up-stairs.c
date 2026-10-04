/*

Raj was to move up through a pattern of stairs of a given number (n). Help him to get to the top using the function stairs.

##Keep in mind :

If n<1 then return ' ' .
There are a lot of spaces before the stair starts except for pattern(1)
##Examples : pattern(1)

      1 1
pattern(6)

                      1 1
                  1 2 2 1
              1 2 3 3 2 1
          1 2 3 4 4 3 2 1
      1 2 3 4 5 5 4 3 2 1
  1 2 3 4 5 6 6 5 4 3 2 1
pattern(12)

                                              1 1
                                          1 2 2 1
                                      1 2 3 3 2 1
                                  1 2 3 4 4 3 2 1
                              1 2 3 4 5 5 4 3 2 1
                          1 2 3 4 5 6 6 5 4 3 2 1
                      1 2 3 4 5 6 7 7 6 5 4 3 2 1
                  1 2 3 4 5 6 7 8 8 7 6 5 4 3 2 1
              1 2 3 4 5 6 7 8 9 9 8 7 6 5 4 3 2 1
          1 2 3 4 5 6 7 8 9 0 0 9 8 7 6 5 4 3 2 1
      1 2 3 4 5 6 7 8 9 0 1 1 0 9 8 7 6 5 4 3 2 1
  1 2 3 4 5 6 7 8 9 0 1 2 2 1 0 9 8 7 6 5 4 3 2 1

*/

#include <stdio.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
stairs(int n)
{
	static const char nums[] = "1234567890";

	int i, j;

	printf("n=%d\n", n);
	for (i = 0; i < n; i++) {
		repeat("  ", (2 * n) - (2 * i) - 1);
		for (j = 0; j <= i; j++)
			printf("%c ", nums[j % 10]);
		for (j = i; j >= 0; j--)
			printf("%c ", nums[j % 10]);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	stairs(6);
	stairs(12);

	return 0;
}
