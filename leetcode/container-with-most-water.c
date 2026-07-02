/*

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned int uint;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

uint
maxarea(uint *h, size_t n)
{
	size_t l, r;
	uint m;

	if (n == 0)
		return 0;

	m = 0;
	l = 0;
	r = n - 1;
	while (l < r) {
		m = max(m, min(h[l], h[r]) * (r - l));
		(h[l] < h[r]) ? l++ : r--;
	}
	return m;
}

int
main(void)
{
	uint h1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	uint h2[] = {1, 1};

	assert(maxarea(h1, nelem(h1)) == 49);
	assert(maxarea(h2, nelem(h2)) == 1);

	return 0;
}
