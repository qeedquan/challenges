/*

Description

Peter has n cigarettes. He smokes them one by one keeping all the butts. Out of k > 1 butts he can roll a new cigarette.
How many cigarettes can Peter have?

Input

Input is a sequence of lines. Each line contains two integer numbers giving the values of n and k.

Output

For each line of input, output one integer number on a separate line giving the maximum number of cigarettes that Peter can have.

Sample Input

4 3
10 3
100 5

Sample Output

5
14
124

*/

#include <assert.h>

int
cigarettes(int n, int k)
{
	int r, t;

	if (n < 1 || k < 1)
		return 0;

	r = 0;
	while (n >= k) {
		t = n % k;
		r += n - t;
		n = (n - t) / k + t;
	}
	return r + n;
}

int
main(void)
{
	assert(cigarettes(4, 3) == 5);
	assert(cigarettes(10, 3) == 14);
	assert(cigarettes(100, 5) == 124);

	return 0;
}
