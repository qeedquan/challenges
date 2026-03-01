/*

Implement the McCarthy 91 function, which is defined as

M(n) = n - 10        if n > 100
       M(M(n + 11))  if n <= 100

*/

#include <assert.h>

int
M(int n)
{
	if (n > 100)
		return n - 10;
	return M(M(n + 11));
}

int
main(void)
{
	int i;

	for (i = 0; i <= 100; i++)
		assert(M(i) == 91);
	for (i = 101; i <= 1000; i++)
		assert(M(i) == i - 10);

	return 0;
}
