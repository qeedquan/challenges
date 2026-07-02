/*

Two complex numbers are given. Find their sum or difference.

Input
Each line contains an example of addition or subtraction of complex numbers.
The complex number is given in the format a+bi or a−bi, where a is an integer, b is a non-negative integer.
The real and imaginary part of each complex number is no more than 10^9 by absolute value.

Output
For each input example, print in a separate line the answer.

Examples

Input #1
2+3i + 7-4i
12-4i - 5-4i
-1-1i - -1-1i
5-2i - -7+12i

Answer #1
9-1i
7+0i
0+0i
12-14i

*/

#include <iostream>
#include <complex>

using namespace std;

int main()
{
	auto z1 = (2.0 + 3i) + (7.0 - 4i);
	auto z2 = (12.0 - 4i) - (5.0 - 4i);
	auto z3 = (-1.0 - 1i) - (-1.0 - 1i);
	auto z4 = (5.0 - 2i) - (-7.0 + 12i);

	cout << z1 << endl;
	cout << z2 << endl;
	cout << z3 << endl;
	cout << z4 << endl;

	return 0;
}
