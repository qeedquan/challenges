/*

Output this table:

-2*	-1*	-	0	-	1	2
-1*	0	1	-	2	3	4
1	2	3	-	4	5	6
3	4	-	5	-	6	7
5	6	-	7	-	8	9
6	7	8	-	9	10	11
8	9	10	-	11	12	13
10	11	-	12	-	13	14

You can output one string with two types of split, 1D string array with one type of split, or 2D string array
If your language support mixed type then you can fill numbers in number cells(but not -1* and -2*)
If your number type has one value - then you can use it in - cells. Otherwise they should be text -.
This table comes from here but I removed 1st row and 1st column

Shortest code wins

*/

#include <stdio.h>

void
table(void)
{
	static const char tab[8][7][4] = {
	    {"-2*", "-1*", "-", "0", "-", "1", "2"},
	    {"-1*", "0", "1", "-", "2", "3", "4"},
	    {"1", "2", "3", "-", "4", "5", "6"},
	    {"3", "4", "-", "5", "-", "6", "7"},
	    {"5", "6", "-", "7", "-", "8", "9"},
	    {"6", "7", "8", "-", "9", "10", "11"},
	    {"8", "9", "10", "-", "11", "12", "13"},
	    {"10", "11", "-", "12", "-", "13", "14"},
	};

	size_t x, y;

	for (y = 0; y < 8; y++) {
		for (x = 0; x < 7; x++)
			printf("%-5s", tab[y][x]);
		printf("\n");
	}
}

int
main(void)
{
	table();
	return 0;
}
