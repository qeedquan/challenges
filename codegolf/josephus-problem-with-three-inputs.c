/*

There's a question on this site that is similar to this question, but I have added a twist.
https://codegolf.stackexchange.com/questions/5891/josephus-problem-counting-out

You have three inputs, the number of people in the circle n, the k-th person counted out at each step, and the q-th person that survives. The people in the circle are numbered 1 to n.

For example, in a circle of 20 people, the 20th person to survive is the very first person removed, the 19th survivor is the second person removed and so on. Normally, the Josephus problem is to determine the last person removed, here called the first survivor.

Write the shortest program or function that, with those three inputs, returns the number of the q-th person to survive.

If there are any issues with clarity, please let me know.

Some examples:

>>> josephus(20, 3, 9)
4
>>> josephus(4, 3, 1)
1
>>> josephus(100, 9, 12)
46

Edit: Assume all inputs are valid. That is no one will ask for 0 or any negative numbers and no one will ask for the 20th survivor in a circle of 5 people (that is, 1 ≤ q ≤ n)

*/

#include <assert.h>

// ported from @user81655 solution
int
josephus3(int n, int k, int q)
{
	int i, r;

	if (n < 1 || k < 1 || q < 1 || q > n)
		return -1;

	r = (k - 1) % q;
	for (i = q; i < n; i++)
		r = (r + k) % (i + 1);
	return r + 1;
}

int
main(void)
{
	assert(josephus3(20, 3, 9) == 4);
	assert(josephus3(4, 3, 1) == 1);
	assert(josephus3(100, 9, 12) == 46);

	return 0;
}
