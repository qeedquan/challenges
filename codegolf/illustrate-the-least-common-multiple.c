/*

Given two positive integers, A and B, illustrate their least common multiple by outputting two lines of dashes (-) with length lcm(A,B) after replacing every Ath dash in the first line and every Bth dash in the second line with vertical bars (|).

In this way, the end of each line will be the only place two |'s line up.

For example, if A=6 and B=4, lcm(6,4)=12, so:

two lines of 12 dashes:
------------
------------

replace every 6th dash in the first line with a vertical bar:
-----|-----|
------------

replace every 4th dash in the second line with a vertical bar:
-----|-----|
---|---|---|
Thus the final output would be

-----|-----|
---|---|---|
The order of the input numbers should correspond to the order of the lines.

The shortest code in bytes wins.

Testcases
A B
line for A
line for B

1 1
|
|

1 2
||
-|

2 1
-|
||

2 2
-|
-|

6 4
-----|-----|
---|---|---|

4 6
---|---|---|
-----|-----|

2 3
-|-|-|
--|--|

3 2
--|--|
-|-|-|

3 6
--|--|
-----|

2 5
-|-|-|-|-|
----|----|

4 3
---|---|---|
--|--|--|--|

10 10
---------|
---------|

10 5
---------|
----|----|

10 6
---------|---------|---------|
-----|-----|-----|-----|-----|

24 8
-----------------------|
-------|-------|-------|

7 8
------|------|------|------|------|------|------|------|
-------|-------|-------|-------|-------|-------|-------|

6 8
-----|-----|-----|-----|
-------|-------|-------|

13 11
------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|
----------|----------|----------|----------|----------|----------|----------|----------|----------|----------|----------|----------|----------|

*/

#include <stdio.h>

unsigned
gcd(unsigned a, unsigned b)
{
	unsigned t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

unsigned
lcm(unsigned a, unsigned b)
{
	return (a * b) / gcd(a, b);
}

void
vis(unsigned a, unsigned b)
{
	unsigned i, j, l, x[2];

	x[0] = a;
	x[1] = b;
	l = lcm(x[0], x[1]);

	printf("%u %u\n", x[0], x[1]);
	for (i = 0; i < 2; i++) {
		for (j = 1; j <= l; j++)
			printf("%c", !(j % x[i]) ? '|' : '-');
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	vis(1, 1);
	vis(1, 2);
	vis(2, 1);
	vis(2, 2);
	vis(6, 4);
	vis(2, 3);
	vis(3, 2);
	vis(3, 6);
	vis(2, 5);
	vis(4, 3);
	vis(10, 10);
	vis(10, 5);
	vis(10, 6);
	vis(24, 8);
	vis(7, 8);
	vis(6, 8);
	vis(13, 11);
	vis(6, 4);

	return 0;
}
