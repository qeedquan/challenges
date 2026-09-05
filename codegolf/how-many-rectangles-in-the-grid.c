/*

Well, although this challenge turned out to be a huge success, it also turned out to be very trivial to solve. Therefore, for those of looking for more of a challenge, I created a sequel to this challenge in which you must now count the number of unique rectangles. Check it out!

Now, for those of you looking to solve this challenge, here it comes.

Well, we don't really have a challenge like this yet, so here we go.

Consider this 3 x 3 grid of rectangles:

https://i.sstatic.net/DoLX6.png

How many rectangles are there? Well, counting visually, we can see that there are actually 36 rectangles, including the entire plane itself, which are all shown in the animated GIF below:

https://i.sstatic.net/ItYuw.gif

The Task
The counting of rectangles as shown above is the task. In other words, given 2 integers greater than or equal to 0, m and n, where m represents the width and n represents the height, output the total number of rectangles in that m x n grid of rectangles.

Rules
The use of any built-ins that directly solve this problem is explicitly disallowed.

This challenge is not about finding the shortest answer, but finding the shortest answer in every language. Therefore, no answer will be accepted.

Standard loopholes are prohibited.

Test Cases
Presented in the format Array of Integers Input -> Integer Output:

[0,0] -> 0
[1,1] -> 1
[3,3] -> 36 (Visualized above)
[4,4] -> 100
[6,7] -> 588

References
http://oeis.org/A096948
Remember, this is code-golf, so shortest code wins!

*/

#include <assert.h>

/*

@xnor

The formula m*n*(m+1)*(n+1)/4 is shortened using the bit-complement ~m=-(m+1), expressing (m+1)*(n+1) as ~m*~n.

Why is the number of rectangles m*n*(m+1)*(n+1)/4? Each rectangle is specified by the choice of two horizontal lines (top and bottom) and two vertical lines (left and right). There are m+1 horizontal lines, of which we choose a subset of two distinct ones. So the number of choices is choose(m+1,2), which is m*(m+1)/2. Multiplying by the n*(n+1)/2 choices for vertical lines gives the result.

*/

int
count(int n, int m)
{
	return m * n * (m + 1) * (n + 1) / 4;
}

int
main()
{
	assert(count(0, 0) == 0);
	assert(count(1, 1) == 1);
	assert(count(3, 3) == 36);
	assert(count(4, 4) == 100);
	assert(count(6, 7) == 588);

	return 0;
}
