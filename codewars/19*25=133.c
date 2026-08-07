/*

Silly Math
Dear Students,
in this lesson we will take on silly multiplication.

Before we will discuss in detail what a silly multiplication is , we will
first look at an example one.

19 * 25
--------
19 * 2 = 38
19 * 5 = 95
--------
38 + 95 = 133

Multiplication rules
After we had a look on the example multiplication let's take look on what we did.

19 * 25
------------
19 * 2 = 38   //First Number * first digit
19 * 5 = 95   //First NUmber * second digit

38 + 95 = 133  //sum the multiplication

Summary
A silly multiplication takes the first number and multilpies it with each digit of the second number.

Keep in mind the order of the multiplication is important!

In general n * m != m * n

But in some cases both orders will give the same solution
209 * 247 and 247 * 209, will give 2717

Your homework
Your homework for this lesson you have to implement the function SillyMultiply(int num1, int num2)

You can validate your solution with the tests given below.

If there are any questions left , just leave me a comment.

Your teacher CodeChrisB.

*/

#include <assert.h>
#include <stdio.h>

unsigned
sillymul(unsigned x, unsigned y)
{
	unsigned r;

	for (r = 0; y > 0; y /= 10)
		r += x * (y % 10);
	return r;
}

int
main()
{
	assert(sillymul(19, 25) == 133);
	assert(sillymul(209, 247) == 2717);
	assert(sillymul(247, 209) == 2717);
	return 0;
}
