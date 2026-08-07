/*

Your task is to write a function bool equals(int a, int b) what returns same result as a == b, but you must not use == operator or any assignment operator (=, +=, and so on).

To check that, the test case will search = character in your solution. So don't use it even in comments.

*/

#include <assert.h>

bool
equal(int a, int b)
{
	return !(a ^ b);
}

int
main()
{
	assert(equal(1234, 1234) == true);
	assert(equal(12, 12) == true);
	assert(equal(1234, 1233) == false);

	return 0;
}
