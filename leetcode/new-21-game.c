/*

Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets k or more points.

Return the probability that Alice has n or fewer points.

Answers within 10^-5 of the actual answer are considered accepted.


Example 1:

Input: n = 10, k = 1, maxPts = 10
Output: 1.00000
Explanation: Alice gets a single card, then stops.
Example 2:

Input: n = 6, k = 1, maxPts = 10
Output: 0.60000
Explanation: Alice gets a single card, then stops.
In 6 out of 10 possibilities, she is at or below 6 points.
Example 3:

Input: n = 21, k = 17, maxPts = 10
Output: 0.73278


Constraints:

0 <= k <= n <= 10^4
1 <= maxPts <= 10^4

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// https://walkccc.me/LeetCode/problems/0837/
double
prob21(int n, int k, int m)
{
	double *dp, r, w;
	int i;

	if (n < 0 || k < 0 || m < 1)
		return -1;

	if (k == 0 || n >= k - 1 + m)
		return 1;

	dp = calloc(n + 1, sizeof(*dp));
	if (!dp)
		return -1;

	r = 0;
	w = 1;
	dp[0] = w;
	for (i = 1; i <= n; i++) {
		dp[i] = w / m;
		if (i < k)
			w += dp[i];
		else
			r += dp[i];

		if (i - m >= 0)
			w -= dp[i - m];
	}

	free(dp);
	return r;
}

void
test(int n, int k, int m, double r)
{
	double p;

	p = prob21(n, k, m);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-5);
}

int
main(void)
{
	test(10, 1, 10, 1);
	test(6, 1, 10, 0.6);
	test(21, 17, 10, 0.73278);

	return 0;
}
