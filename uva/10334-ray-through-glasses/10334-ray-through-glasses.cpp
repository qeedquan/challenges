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
