/*

Fix the function
I created this function to add five to any number that was passed in to it and return the new value. It doesn't throw any errors but it returns the wrong number.

Can you help me fix the function?

*/

#include <assert.h>

int
addfive(int n)
{
	return n + 5;
}

int
main()
{
	assert(addfive(20) == 25);
	assert(addfive(25) == 30);
	return 0;
}
