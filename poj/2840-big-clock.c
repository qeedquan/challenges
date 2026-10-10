/*

Description

Our vicar raised money to have the church clock repaired for several weeks. The big clock, which used to strike the hours days and nights, was damaged several weeks ago and had been silent since then.

After the clock was repaired, it works all right, but there is still something wrong with it: the clock will strike thirteen times at one o’clock, fourteen times at two o’clock... 24 times at 12:00, 1 time at 13:00...

How many times will it strike now?

Input

The first line consists of only one integer T (T <= 30), representing the number of test cases. Then T cases follow.

Each test case consists of only one line, representing the time now. Each line includes 2 integers H, M separated by a symbol ":". (0 <= H < 24, 0 <= M < 60)

Output

For each test case, output the answer in one line.
Sample Input

3
1:00
01:01
00:00

Sample Output

13
0
12

Source

POJ Monthly--2006.06.25, Lei Tao

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
strike(const char *s)
{
	static const int tab[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	unsigned h, m;

	if (sscanf(s, "%u:%u", &h, &m) != 2)
		return -1;
	return (m == 0) ? tab[h % nelem(tab)] : 0;
}

int
main(void)
{
	assert(strike("1:00") == 13);
	assert(strike("01:01") == 0);
	assert(strike("00:00") == 12);
	assert(strike("2:00") == 14);
	assert(strike("12:00") == 24);
	assert(strike("13:00") == 1);

	return 0;
}
