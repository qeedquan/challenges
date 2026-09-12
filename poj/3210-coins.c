/*

Description

Snoopy has three coins. One day he tossed them on a table then and tried to flip some of them so that they had either all heads or all tails facing up. After several attempts, he found that regardless of the initial configuration of the coins, he could always achieve the goal by doing exactly two flippings, under the condition that only one coin could be flipped each time and a coin could be flipped more than once. He also noticed that he could never succeed with less than two flippings.

Snoopy then wondered, if he had n coins, was there a minimum number x such that he could do exactly x flippings to satisfy his requirements?

Input

The input contains multiple test cases. Each test case consists of a single positive integer n (n < 10,000) on a separate line. A zero indicates the end of input and should not be processed.

Output

For each test case output a single line containing your answer without leading or trailing spaces. If the answer does not exist, output “No Solution!”

Sample Input

2
3
0

Sample Output

No Solution!
2

Source

POJ Monthly--2007.04.01, Snoopy

*/

#include <assert.h>

int
flips(int n)
{
	return (n & 1) ? n - 1 : -1;
}

int
main(void)
{
	assert(flips(2) == -1);
	assert(flips(3) == 2);

	return 0;
}
