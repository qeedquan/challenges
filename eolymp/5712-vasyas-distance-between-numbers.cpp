/*

Vasya has come up with his own way to measure the distance between numbers. He defines Vasya's distance as the number of differing digits in the binary representations of two numbers.

For example, consider the illustration provided:

https://static.e-olymp.com/content/58/580fd93794f31e4ff7c8a2c2c39bc517c6d75cf7.jpg

In this image, the differing binary digits that contribute to Vasya's distance are marked in red.

Your task is to write a program that computes Vasya's distance between two non-negative integers.

Input
The input consists of a single line containing two non-negative integers A and B (0≤A,B≤10^9), separated by a space.

Output
Output a single integer on a single line, representing the calculated Vasya's distance.

Examples

Input #1
173 198

Answer #1
5

*/

#include <cassert>
#include <bit>

using namespace std;

typedef unsigned int uint;

uint solve(uint a, uint b)
{
	return popcount(a ^ b);
}

int main()
{
	assert(solve(173, 198) == 5);
	assert(solve(189, 189) == 0);

	return 0;
}
