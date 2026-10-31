/*

In some nations there are recommendations or laws on how to form emergency corridors on streets that have multiple lanes per direction.
(In the following we only consider the lanes going in the direction we are travelling.) These are the rules that hold in Germany:

If there is only one lane, everyone should drive to the right such that the rescue vehicles can pass on the left.
If there are two or more lanes, the cars on the left most lane should drive to the left, and everyone else should move to the right.

Challenge
Given the number N>0 of regular lanes, output the layout of the lanes when an emergency corridor is formed using a string of N+1 ASCII characters.
You can use any two characters from ASCII code 33 up to 126, one to denote the emergency corridor, and one for denoting the cars. Trailing or leading spaces, line breaks etc are allowed.

Examples
Here we are using E for the emergency corridor, and C for the cars.

N  Output
1  EC
2  CEC
3  CECC
4  CECCC
5  CECCCC
6  CECCCCC
   etc

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
make(int n, char *b)
{
	size_t l;
	int i;

	*b = '\0';
	if (n < 1)
		return b;

	l = 0;
	if (n > 1)
		l += sprintf(b + l, "C");
	l += sprintf(b + l, "EC");
	for (i = 0; i < n - 2; i++)
		l += sprintf(b + l, "C");
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	make(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(1, "EC");
	test(2, "CEC");
	test(3, "CECC");
	test(4, "CECCC");
	test(5, "CECCCC");
	test(6, "CECCCCC");

	return 0;
}
