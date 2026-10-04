/*

Description

Joseph likes taking part in programming contests. His favorite problem is, of course, Joseph's problem.

It is stated as follows.
There are n persons numbered from 0 to n - 1 standing in a circle. The person numberk, counting from the person number 0, is executed. After that the person number k of the remaining persons is executed, counting from the person after the last executed one. The process continues until only one person is left. This person is a survivor. The problem is, given n and k detect the survivor's number in the original circle.

Of course, all of you know the way to solve this problem. The solution is very short, all you need is one cycle:
	r := 0;

	for i from 1 to n do

		r := (r + k) mod i;

	return r;

Here "x mod y" is the remainder of the division of x by y, But Joseph is not very smart. He learned the algorithm, but did not learn the reasoning behind it. Thus he has forgotten the details of the algorithm and remembers the solution just approximately.

He told his friend Andrew about the problem, but claimed that the solution can be found using the following algorithm:
	r := 0;

	for i from 1 to n do

		r := r + (k mod i);

	return r;

Of course, Andrew pointed out that Joseph was wrong. But calculating the function Joseph described is also very interesting.

Given n and k, find ∑1<=i<=n(k mod i).

Input

The input file contains n and k (1<= n, k <= 109).
Output

Output the sum requested.
Sample Input

5 3
Sample Output

7
Source

Northeastern Europe 2005

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
josbig(int n, int k)
{
	int a, b, e, i, s, r;

	if (n < 1 || k < 1)
		return 0;

	a = sqrt(k);
	b = k / a;
	
	r = 0;
	if (n > k)
		r += (n - k) * k;

	for (i = a; i > 1; i--) {
		s = k / i;
		e = k / (i - 1);
		if (s > n)
			break;
		if (e > n)
			e = n;
		r += ((k % e) + (k % (s + 1))) * (e - s) / 2;
	}

	for (i = 1; i <= n && i <= b; i++)
		r += k % i;

	return r;
}

int
josbf(int n, int k)
{
	int i, r;

	r = 0;
	for (i = 1; i <= n; i++)
		r += k % i;
	return r;
}

int
main(void)
{
	int n, k, N;

	assert(josbig(5, 3) == 7);

	N = 1000;
	for (n = 0; n <= N; n++) {
		for (k = 0; k <= N; k++)
			assert(josbig(n, k) == josbf(n, k));
	}

	return 0;
}
