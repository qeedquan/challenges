/*

In mathematics, the nth harmonic number is the sum of the reciprocals of the first n natural numbers:

Hn=1 + 1/2 + 1/3 + 1/4 + … + 1/n = Sum[k=1, n] 1/k

In this problem, you are given n, you have to find Hn.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 10^8).

Output
For each case, print the case number and the nth harmonic number. Errors less than 10-8 will be ignored.

Sample
Input	Output
12
1
2
3
4
5
6
7
8
9
90000000
99999999
100000000

Case 1: 1
Case 2: 1.5
Case 3: 1.8333333333
Case 4: 2.0833333333
Case 5: 2.2833333333
Case 6: 2.450
Case 7: 2.5928571429
Case 8: 2.7178571429
Case 9: 2.8289682540
Case 10: 18.8925358988
Case 11: 18.9978964039
Case 12: 18.9978964139

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long ulong;

double
harmonic(ulong n)
{
	double r;
	ulong i;

	r = 0;
	for (i = 1; i <= n; i++)
		r += 1.0 / i;
	return r;
}

void
test(ulong n, double r)
{
	double v;

	v = harmonic(n);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-10);
}

int
main()
{
	test(1, 1);
	test(2, 1.5);
	test(3, 1.8333333333);
	test(4, 2.0833333333);
	test(5, 2.2833333333);
	test(6, 2.450);
	test(7, 2.5928571429);
	test(8, 2.7178571429);
	test(9, 2.8289682540);
	test(90000000, 18.8925358988);
	test(99999999, 18.9978964039);
	test(100000000, 18.9978964139);

	return 0;
}
