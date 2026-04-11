/*

n people board an airplane with n seats. The first passenger has lost his boarding pass, so he sits
in a random seat. Each subsequent passenger sits in his own seat if it’s available or takes a random
unoccupied seat if it’s not.
What’s the probability that the nth passenger finds his seat occupied?

Input
The input file contains several test cases. Each test case is described with one integer n on a single line
(2 ≤ n ≤ 1000).
The last line contains a single ‘0’ and should not be processed.

Output
For each test case, output the probability that the n-th passenger finds his seat occupied on a single
line.

If the probability is 0, output ‘0/1’. Otherwise, the probability should be expressed as an irreducible
fraction a/b, where a and b are positive integers and a and b be are relatively prime. Do not print any
spaces between the numbers or the division sign.

Sample Input
2
0

Sample Output
1/2

*/

#include <assert.h>
#include <string.h>

/*

F[1] = 1
F[2] = 0.5, 50% sit on his own seat
F[3] = 1/3*F[2] + 1/3 = 0.5
F[4] = 2/4*F[3] + 1/4 = 0.5

Pattern shows that it is all p=0.5 when n > 1

*/

const char *
solve(int n)
{
	if (n < 1)
		return "0/1";

	if (n == 1)
		return "1/1";

	return "1/2";
}

int
main()
{
	assert(!strcmp(solve(2), "1/2"));

	return 0;
}
