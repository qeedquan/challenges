/*

n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of the passengers will:

Take their own seat if it is still available, and
Pick other seats randomly when they find their seat occupied
Return the probability that the nth person gets his own seat.

Example 1:

Input: n = 1
Output: 1.00000
Explanation: The first person can only get the first seat.
Example 2:

Input: n = 2
Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).


Constraints:

1 <= n <= 10^5

Hint:
Let f(n) denote the probability of the n-th person getting correct seat in n-person case, then: f(1) = 1 (base case, trivial) f(2) = 1/2 (also trivial)
Try to calculate f(3), f(4), and f(5) using the base cases. What is the value of them? f(i) for i >= 2 will also be 1/2.
Try to proof why f(i) = 1/2 for i >= 2.

*/

#include <assert.h>

/*

https://medium.com/@chuncaohenli/1227-airplane-seat-assignment-probability-4784f81cafec

P(n will seat on his/her seat) = P(1 not seat on n-th seat, 2 not seat on n-th seat, ….. (n-1) not seat on n-th seat)

For 1st customer,

if 1 seats on 1st seat, then 2 will pick 2nd seat, 3 will pick third one and everyone will seat on assigned seat ( P = 1/n )
if 1 seats on 2nd seat, then 2 faces the same situation as 1. 2 needs to randomly pick a seat from (n-1) seats
if 1 seats on 3rd seat, then 2 has to pick 2nd and 3 will face the same situation as 1, randomly picking a seat from (n-2) seats
Now we can clearly see the patterns here. Assume that f(n) is the probability that we are looking for, when n > 2,

f(1) = 1
f(2) = 0.5
And we can prove that f(n) == f(n-1) when n > 2

f(n) = (f(n-1)*(n-1) + f(n-1)) / n = f(n-1)
So when n≥2 , f(n) is always 0.5

*/
double
prob(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	return 0.5;
}

int
main(void)
{
	assert(prob(1) == 1);
	assert(prob(2) == 0.5);

	return 0;
}
