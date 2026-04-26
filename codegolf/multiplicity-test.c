/*

Use any programming language to display numbers between 1 and 99 (including both) in such a way, so that:

the numbers are separated by single space,
if a number is divisible by 3, it should be in parentheses,
if a number is divisible by 4, it should be in square brackets,
if a number is divisible by both 3 and 4, it should be in both parentheses and square brackets (with square brackets closer to the number).
Your program should display exactly:

1 2 (3) [4] 5 (6) 7 [8] (9) 10 11 ([12]) 13 14 (15) [16] 17 (18) 19 [20] (21) 22 23 ([24]) 25 26 (27) [28] 29 (30) 31 [32] (33) 34 35 ([36]) 37 38 (39) [40] 41 (42) 43 [44] (45) 46 47 ([48]) 49 50 (51) [52] 53 (54) 55 [56] (57) 58 59 ([60]) 61 62 (63) [64] 65 (66) 67 [68] (69) 70 71 ([72]) 73 74 (75) [76] 77 (78) 79 [80] (81) 82 83 ([84]) 85 86 (87) [88] 89 (90) 91 [92] (93) 94 95 ([96]) 97 98 (99)

*/

#include <stdio.h>

void
gen(int n)
{
	int i;

	for (i = 1; i <= n; i++) {
		if (i % 12 == 0)
			printf("([%d])", i);
		else if (i % 3 == 0)
			printf("(%d)", i);
		else if (i % 4 == 0)
			printf("[%d]", i);
		else
			printf("%d", i);
		if (i < n)
			printf(" ");
	}
	printf("\n");
}

int
main(void)
{
	gen(99);
	return 0;
}
