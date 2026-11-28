/*

A binary recurrence sequence is a recursively-defined sequence of the following form:

F(1)=a1
...
F(y)=ay

F(n)=αF(n−x) + βF(n−y), n>y

This is a generalization of the Fibonacci (x=1,y=2,a=[1,1],α=1,β=1) sequence and the Lucas (x=1,y=2,a=[2,1],α=1,β=1) sequence.

The Challenge
Given n,x,y,a,α, and β, in any reasonable format, output the nth term of the corresponding binary recurrence sequence.

Rules
You may choose for the sequence to be either 1-indexed or 0-indexed, but your choice must be consistent across all inputs, and you must make note of your choice in your answer.
You may assume that no invalid inputs would be given (such as a sequence that terminates prior to n, or a sequence that references undefined terms, like F(−1) or F(k) where k>n).
As a result of this, x and y will always be positive.
The inputs and outputs will always be integers, within the boundaries of your language's natural integer type.
If your language has unbounded integers, the inputs and outputs will be within the range [-2^31,2^31-1] (i.e. the range for a 32-bit signed two's complement integer).
a will always contain exactly y alues (as per the definition).

Test Cases
Note: all test cases are 0-indexed.

x = 1, y = 2, a = [1, 1], alpha = 1, beta = 1, n = 6 => 13
x = 1, y = 2, a = [2, 1], alpha = 1, beta = 1, n = 8 => 47
x = 3, y = 5, a = [2, 3, 5, 7, 11], alpha = 2, beta = 3, n = 8 => 53
x = 1, y = 3, a = [-5, 2, 3], alpha = 1, beta = 2, n = 10 => -67
x = 5, y = 7, a = [-5, 2, 3, -7, -8, 1, -9], alpha = -10, beta = -7, n = 10 => 39

*/

#include <cassert>
#include <vector>

using namespace std;

int recurrence(unsigned x, unsigned y, const vector<int> &a, int alpha, int beta, unsigned n)
{
	if (n < y)
		return a[n];
	return (alpha * recurrence(x, y, a, alpha, beta, n - x)) + (beta * recurrence(x, y, a, alpha, beta, n - y));
}

int main()
{
	assert(recurrence(1, 2, { 1, 1 }, 1, 1, 6) == 13);
	assert(recurrence(1, 2, { 2, 1 }, 1, 1, 8) == 47);
	assert(recurrence(3, 5, { 2, 3, 5, 7, 11 }, 2, 3, 8) == 53);
	assert(recurrence(1, 3, { -5, 2, 3 }, 1, 2, 10) == -67);
	assert(recurrence(5, 7, { -5, 2, 3, -7, -8, 1, -9 }, -10, -7, 10) == 39);

	return 0;
}
