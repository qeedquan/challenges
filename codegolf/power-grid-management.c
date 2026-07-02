/*

You are writing the management software for one "node" of a power grid. A node has a layout like this

    +
    |
+---N---+
    |
    +
Each + is a measurement point for power flow. If power is flowing into (relative to the rest of the grid) a measurement point, it has a positive value. If power is flowing out of a measurement point, it has a negative value. However, people often try to tamper their meters, so a measurement point may report an incorrect value (More power outputted than drawn (for the purpose of the task we'll pretend stuff like selling energy back to the grid doesn't exist))

Your Task:
Write a control program that takes in the measurements from each of the points, and either outputs the amount of power used, or that tampering has occurred (No need to state specific meter). Lowest # of bytes wins

Test Data:
(Use any I/O format you want)

[10,10,10,-10] -> 20 Units used
[-5,-7,24,0] -> 12 Units used
[-10,100,-10,-10] -> 70 Units used
[10, -1, -5, -4] -> 0 Units used
[6, -7, 8, -8] -> TAMPER!
[6, -9, 8, -8] -> TAMPER!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
power(int *p, size_t n)
{
	int s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += p[i];
	return (s >= 0) ? s : -1;
}

int
main()
{
	int p1[] = { 10, 10, 10, -10 };
	int p2[] = { -5, -7, 24, 0 };
	int p3[] = { -10, 100, -10, -10 };
	int p4[] = { 10, -1, -5, -4 };
	int p5[] = { 6, -7, 8, -8 };
	int p6[] = { 6, -9, 8, -8 };

	assert(power(p1, nelem(p1)) == 20);
	assert(power(p2, nelem(p2)) == 12);
	assert(power(p3, nelem(p3)) == 70);
	assert(power(p4, nelem(p4)) == 0);
	assert(power(p5, nelem(p5)) == -1);
	assert(power(p6, nelem(p6)) == -1);

	return 0;
}
