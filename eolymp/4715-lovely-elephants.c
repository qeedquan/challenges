/*

In one Indian village the teacher asked the boy Manmohan to count the number of elephants in the village.
Manmohan counted all the elephants in the village, and he obtained a two-digit number n.
But instead of reporting the answer to the teacher, Manmohan decided to play a trifle a bit.
For this Manmohan subtracted the sum of digits from the resulting number, divided the result by 9 (discarding the fractional part of the result),
increased the number by 1, then added the last digit of the original number n to the end of the received number and subtracted 10 from the result.
The final result he told the teacher.

Despite Manmohan's cunning, the teacher was able by the obtained number to determine how many elephants were in the village. Find this number.

Input
The integer that Manmohan received.

Output
Print the number of elephants in the village.

Examples

Input #1
17

Answer #1
17

*/

#include <assert.h>

int
solve(int n)
{
	return n;
}

int
main()
{
	assert(solve(17) == 17);

	return 0;
}
