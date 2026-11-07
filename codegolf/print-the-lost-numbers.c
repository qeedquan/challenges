/*

As a big fan of the Lost TV series, I always got intrigued by the sequence of numbers that repetitively appears on the episodes. These numbers are:

4,8,15,16,23,42 (A104101)

Using any programming language, write a code that outputs these numbers.

Scoring:
Shortest answer wins

The output must not contain any other numbers or letters. You may use any other character as separator, or even no separator at all.

You cannot separate digits of the same number. 48_15162342 is a valid answer, but  481_5162342 is not.

You must respect the order.

If your code does not contain any of the numbers from the sequence, reduce your score by 30%. This rule does allow you to enter the digits separately. E.g.:

abcde1fg5h
Is a valid candidate because the answer does not contain the number 15, only its digits. However, any 4 or 8 will invalidate the bonus.

If the code does not contain any digit at all, reduce your score by 50%. Other characters like ¹, ² or ³ are still valid for this bonus.

*/

#include <stdio.h>

// https://oeis.org/A104101
void
output()
{
	puts("4,8,15,16,23,42");
}

int
main()
{
	output();
	return 0;
}
