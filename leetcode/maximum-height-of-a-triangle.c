/*

You are given two integers red and blue representing the count of red and blue colored balls.
You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.

All the balls in a particular row should be the same color, and adjacent rows should have different colors.

Return the maximum height of the triangle that can be achieved.

Example 1:
Input: red = 2, blue = 4
Output: 3
Explanation:
https://assets.leetcode.com/uploads/2024/06/16/brb.png
The only possible arrangement is shown above.

Example 2:
Input: red = 2, blue = 1
Output: 2
Explanation:
https://assets.leetcode.com/uploads/2024/06/16/br.png
The only possible arrangement is shown above.

Example 3:
Input: red = 1, blue = 1
Output: 1

Example 4:
Input: red = 10, blue = 1
Output: 2
Explanation:
https://assets.leetcode.com/uploads/2024/06/16/br.png

The only possible arrangement is shown above.

Constraints:

1 <= red, blue <= 100

Hint 1
Count the max height using both possibilities. That is, red ball as top and blue ball as top.

Hint 2
For counting the max height, use a simple for loop and remove the number of balls required at this level.

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxheight(int r, int b)
{
	int c[2], i, j, k, h;

	h = 0;
	for (k = 0; k < 2; k++) {
		c[0] = r;
		c[1] = b;
		for (i = j = 1; i <= c[j]; i++) {
			c[j] -= i;
			h = max(h, i);
			j ^= 1;
		}
	}
	return h;
}

int
main()
{
	assert(maxheight(2, 4) == 3);
	assert(maxheight(2, 1) == 2);
	assert(maxheight(1, 1) == 1);
	assert(maxheight(10, 1) == 2);

	return 0;
}
