/*

Johann Carl Friedrich Gauß (1777–1855) was one of the most important German mathematicians.
For those who remember the Deutsche Mark, his portrait was featured on the 10 DM note.
In elementary school, his teacher J. G. Büttner tried to keep the pupils occupied by asking them to add up the integers from 1 to 100.
The young Gauß surprised everyone by producing the correct answer (5050) within seconds.

Can you write a program that can compute such sums very quickly?

Given two integers n and m, calculate the sum of all integers from n to m. In other words, compute

Sum[i=n, m] i = n+(n+1)+(n+2)+⋯+(m−1)+m

Input
The first line contains the number of scenarios. Each scenario consists of a line containing the numbers n and m (−10^9≤n≤m≤10^9).

Output
The output for each scenario should start with a line containing "Scenario #i:", where i is the scenario number, starting from 1.
Then print the sum of all integers from n to m. End the output for the scenario with a blank line.

Examples

Input #1
3
1 100
-11 10
-89173 938749341

Answer #1
Scenario #1:
5050

Scenario #2:
-11

Scenario #3:
440625159107385260

*/

#include <cassert>

typedef long long vlong;

vlong solve(vlong a, vlong b)
{
	return (a + b) * (b - a + 1) / 2;
}

int main()
{
	assert(solve(1, 100) == 5050);
	assert(solve(-11, 10) == -11);
	assert(solve(-89173, 938749341) == 440625159107385260);

	return 0;
}
