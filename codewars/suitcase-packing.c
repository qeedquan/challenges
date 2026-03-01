/*

Mr. Square is going on a holiday. He wants to bring 2 of his favorite squares with him, so he put them in his rectangle suitcase.

Write a function that, given the size of the squares and the suitcase, return whether the squares can fit inside the suitcase.

fit_in(a,b,m,n)
a,b are the sizes of the 2 squares
m,n are the sizes of the suitcase

Example
fit_in(1,2,3,2) should return True
fit_in(1,2,2,1) should return False
fit_in(3,2,3,2) should return False
fit_in(1,2,1,2) should return False

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
fitin(int a, int b, int m, int n)
{
	return a + b <= max(m, n) && max(a, b) <= min(m, n);
}

int
main()
{
	assert(fitin(1, 2, 3, 2) == true);
	assert(fitin(1, 2, 2, 1) == false);
	assert(fitin(3, 2, 3, 2) == false);
	assert(fitin(1, 2, 1, 2) == false);

	return 0;
}
