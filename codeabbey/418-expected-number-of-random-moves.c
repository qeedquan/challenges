/*

https://imgur.com/1cYEfY6

Let's imagine a number line of sequential integer values labeled 0 to n. We take a stone and place it on 0, so the stone's position is p = 0. We then use a random number generator to obtain a random value r in the range [1, n - p], and then we reposition the stone to the new value p + r, repeating the process until the stone is positioned at n.

For a number line of length n, the minimum possible amount of moves it could take to reach the end would be 1, if the first roll yielded n. The maximum amount of moves it could take would be n, if each roll only yielded 1.

What is the expected value of moves required to reach the end of a number line of length n?

Problem Statement
Input data gives the number of testcases (T) in the first line.
The second line will consist of T integer values for n separated by spaces.

Answer should contain T space-separated decimal values corresponding to the expected values of turns required to reach the end of a number line of length n. Precision of 1e-8 should be enough.

Example

input data:
3
2 4 10

answer:
1.5 2.08333333 2.92896825

*/

#include <stdio.h>

/*

Let E[k] be the expected number of remaining moves when the stone is at a distance of k
steps away from the goal n (so k=n-p)

When k=0, the stone has reached the end:
E0 = 0

When the stones is k step away (k > 0), the random number generator chooses a step size r
uniformly at random from the integer range [1, k]. Each outcome has a probablity of 1/k.
After taking a step of size r, the new distance from the goal becomes k-r.

The recurrence relation for expected remaining move is:

E[k] = 1 + 1/k*Sum[r=1, k] E[k-r] = 1 + 1/k*Sum[i=0, k-1] E[i]

Writing out a few terms of E[i] shows that this is a harmonic series in disguise.

*/

double
solve(int n)
{
	double r;
	int i;

	r = 0;
	for (i = 1; i <= n; i++)
		r += 1.0 / i;
	return r;
}

int
main()
{
	printf("%f\n", solve(2));
	printf("%f\n", solve(4));
	printf("%f\n", solve(10));
	return 0;
}
