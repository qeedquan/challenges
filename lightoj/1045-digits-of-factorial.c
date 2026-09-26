/*

Factorial of an integer is defined by the following function

f(n) = 1         if n is 0
       n*f(n-1)  if n > 0

So, factorial of 5 is 120. But in different bases, the factorial may be different. For example, factorial of 5 in base 8 is 170.

In this problem, you have to find the number of digit(s) of the factorial of an integer in a certain base.

Input
Input starts with an integer T (≤ 50000), denoting the number of test cases.

Each case begins with two integers n (0 ≤ n ≤ 10^6) and base (2 ≤ base ≤ 1000). Both of these integers will be given in decimal.

Output
For each case of input you have to print the case number and the digit(s) of factorial n in the given base.

Sample
Input	Output
5
5 10
8 10
22 3
1000000 2
0 100

Case 1: 3
Case 2: 5
Case 3: 45
Case 4: 18488885
Case 5: 1

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long vlong;

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

void
build(double *logsum, size_t size)
{
	size_t i;

	logsum[0] = 0;
	for (i = 1; i < size; i++)
		logsum[i] += logsum[i - 1] + log(i);
}

/*

For base 10, the digit length is:

Digits = ⌊log10(N!)⌋ + 1

To convert into base B:

Digits = ⌊logb(N!)⌋ + 1 = ⌊(log(N!))/(log(base))⌋ + 1

To calculate log(N!) we can use the identity
log(N!) = log(1) + log(2) + ... log(N)

*/

vlong
solve(double *logsum, vlong number, vlong base)
{
	return logsum[number] / log(base) + 1;
}

int
main()
{
	double *logsum;
	size_t size;

	size = 1000001;
	logsum = xcalloc(size, sizeof(*logsum));
	build(logsum, size);
	assert(solve(logsum, 5, 10) == 3);
	assert(solve(logsum, 8, 10) == 5);
	assert(solve(logsum, 22, 3) == 45);
	assert(solve(logsum, 1000000, 2) == 18488885);
	assert(solve(logsum, 0, 100) == 1);
	free(logsum);

	return 0;
}
