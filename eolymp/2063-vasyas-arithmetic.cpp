/*

Father once gave Vasya the following task: Find the sum of all digits of the numbers from 1 to 10^n.
Vasya, who, in addition to mathematics, was interested in programming, quickly solved the problem.
But now Vasya's father has a new problem—how to check whether his son's answer is correct?

Help Vasya's father solve this problem, as he feels awkward not being able to verify his son's answer.

Input
A single line contains a non-negative integer 10^n. It is known that the length of the number does not exceed 10^7+1.

Output
A single integer: the required sum of digits.

Examples
Input #1
100

Answer #1
901

*/

#include <cassert>
#include <print>

using namespace std;

int digsum(int n)
{
	auto r = 0;
	for (; n > 0; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A037123
int solve(int n)
{
	auto r = 0;
	for (auto i = 1; i <= n; i++)
		r += digsum(i);
	return r;
}

int main()
{
	static const int tab[] = {
		0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 46, 48, 51, 55, 60, 66, 73, 81, 90,
		100, 102, 105, 109, 114, 120, 127, 135, 144, 154, 165, 168, 172, 177,
		183, 190, 198, 207, 217, 228, 240, 244, 249, 255, 262, 270, 279, 289,
		300, 312, 325, 330, 336, 343, 351, 360, 370, 381
	};

	assert(solve(100) == 901);

	for (size_t i = 0; i < size(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
