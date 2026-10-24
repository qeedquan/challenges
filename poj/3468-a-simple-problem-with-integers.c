/*

Description

You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.

Input

The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.

Output

You need to answer all Q commands in order. One answer in a line.

Sample Input

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output

4
55
9
15
Hint

The sums may exceed the range of 32-bit integers.
Source

POJ Monthly--2007.11.25, Yang Yi

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
apply(int op, int *vals, size_t numvals, size_t a, size_t b, long c)
{
	size_t i;
	long sum;

	if (a == 0 || b == 0)
		return;

	sum = 0;
	for (i = a - 1; i <= b - 1 && i < numvals; i++) {
		if (op == 'C')
			vals[i] += c;
		else if (op == 'Q')
			sum += vals[i];
	}
	if (op == 'Q')
		printf("%ld\n", sum);
}

void
execute(int *vals, size_t numvals, const char **ops, size_t numops)
{
	size_t a, b, i;
	long c;

	for (i = 0; i < numops; i++) {
		if (sscanf(ops[i], "C %zu %zu %ld", &a, &b, &c) == 3)
			apply('C', vals, numvals, a, b, c);
		else if (sscanf(ops[i], "Q %zu %zu", &a, &b) == 2)
			apply('Q', vals, numvals, a, b, 0);
	}
}

int
main(void)
{
	int vals[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const char *ops[] = {
	    "Q 4 4",
	    "Q 1 10",
	    "Q 2 4",
	    "C 3 6 3",
	    "Q 2 4",
	};

	execute(vals, nelem(vals), ops, nelem(ops));

	return 0;
}
