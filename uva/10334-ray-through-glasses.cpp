/*

Suppose we put two panes of glass back-to-back. How many ways an are there for light rays to pass
through or be reflected after changing direction n times? Following figure shows the situations when
the value of n is 0, 1 and 2.

Input
It is a set of lines with an integer n where 0 ≤ n ≤ 1000 in each of them.
Output
For every one of these integers a line containing an as described above.

Sample Input
0
1
2

Sample Output
1
2
3

*/

#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

uint1024_t fib(uint1024_t n)
{
	uint1024_t a = 1;
	uint1024_t b = 2;
	for (uint1024_t i = 0; i < n; i++)
	{
		auto c = a + b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	assert(fib(0) == 1);
	assert(fib(1) == 2);
	assert(fib(2) == 3);

	return 0;
}
