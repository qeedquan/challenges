/*

We have a function that takes in an integer n, and returns a number x.

Lets call this function findX(n)/find_x(n) (depending on your language):

function findX(n) {
  let x = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < 2*n; j++)
      x += i + j;
  }
  return x;
}
The functions loops throught the number n and at every iteration, performs a nested loop on 2*n, at each iteration of this nested loop it increments x with the (nested loop index + parents loop index).

This works well when the numbers are reasonably small.

findX(2) //=> 16
findX(3) //=> 63
findX(5) //=> 325
But may be slow for numbers > 10^3

So your task is to optimize the function findX/find_x, so it works well for large numbers.

Input Range
1 <= n <= 10^6 (10^5 in JS)

Note: This problem is more about logical reasoning than it is about finding a mathematicial formula, infact there are no complex math formula involved

*/

#include <assert.h>

int
findxbf(int n)
{
	int i, j, x;

	x = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n; j++)
			x += i + j;
	}
	return x;
}

int
findx(int n)
{
	if (n < 0)
		return 0;
	return (3 * n - 2) * n * n;
}

int
main()
{
	int i;

	assert(findx(2) == 16);
	assert(findx(3) == 63);
	assert(findx(5) == 325);

	for (i = 0; i <= 1000; i++)
		assert(findx(i) == findxbf(i));

	return 0;
}
