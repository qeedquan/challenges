/*

Given an integer between 0 and 141 (inclusive), list all 24-hour times whose hour, minute, and second units add to that integer.

Rules of addition

Numbers are added by their time units, not by single digits.

For example, take 17:43:59

17+43+59=119

Remember, that is an example of digits being added. In reality, you would enter 119, and 17:43:59 would be one of the results. Output should be given as HH:MM:SS or H:MM:SS.

Also keep in mind the highest number possible is 141, being 23:59:59. This is code golf, so the lowest amount wins. Trial and error is permitted, but there may be a better way to go about this.

Edit: Please specify where in your code the input value is.

*/

#include <stdio.h>

void
solve(int n)
{
	int h, m, s;

	printf("n=%d\n", n);
	for (h = 0; h < 24; h++) {
		for (m = 0; m < 60; m++) {
			for (s = 0; s < 60; s++) {
				if (h + m + s == n)
					printf("%02d:%02d:%02d\n", h, m, s);
			}
		}
	}
	printf("\n");
}

int
main()
{
	solve(119);
	solve(141);

	return 0;
}
