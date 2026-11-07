/*

In this problem you will be given two decimal integer number N, M.
You will have to find the last non-zero digit of the P[N, M].
This means no of permutations of N things taking M at a time.

Input
The input file contains several lines of input. Each line of the input file contains two integers N
(0 ≤ N ≤ 20000000), M (0 ≤ M ≤ N). Input is terminated by end-of-file.

Output
For each line of the input file you should output a single digit, which is the last non-zero digit of P[N, M].
For example, if P[N, M] is 720 then the last non-zero digit is 2. So in this case your output should be 2.

Sample Input
10 10
10 5
25 6

Sample Output
8
4
2

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong n, vlong m)
{
	vlong i, r;

	r = 1;
	for (i = n; i > n - m; i--) {
		r *= i;
		while (!(r % 10))
			r /= 10;
		r %= 1000000000;
	}
	return r % 10;
}

int
main()
{
	assert(solve(10, 10) == 8);
	assert(solve(10, 5) == 4);
	assert(solve(25, 6) == 2);

	return 0;
}
