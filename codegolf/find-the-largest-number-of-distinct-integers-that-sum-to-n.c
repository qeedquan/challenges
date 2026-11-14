/*

The Task
Given an input positive integer n (from 1 to your language's limit, inclusively), return or output the maximum number of distinct positive integers that sum to n.

Test Cases
Let f define a valid function according to the task:

The sequence for f, starting at 1:

1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, ...
As a larger test case:

>>> f(1000000000) // Might not be feasible with brute-forcers
44720
Test Code
For any test cases not explicitly given, the output of your code should match the result of the following:

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println((int) Math.floor(Math.sqrt(2*x + 1./4) - 1./2));
    }
}

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A003056
vlong
f(vlong n)
{
	vlong a, b, k, m, p;

	m = (n + 1) << 1;
	k = sqrt(m);

	a = m << 2;
	b = (k << 2) * (k + 1) + 1;
	p = (a > b);

	return k + p - 1;
}

int
main()
{
	static const vlong tab[] = {
		0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5,
		5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9,
		9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12,
		12, 12, 12, 12, 12, 12, 12, 12, 12
	};

	size_t i;

	assert(f(1000000000) == 44720);

	for (i = 0; i < nelem(tab); i++)
		assert(f(i) == tab[i]);

	return 0;
}
