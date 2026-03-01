/*

Story
My seven brothers and I asked miss Esperanza to bake t cakes. Luckily she likes to cook, so she decided to bake ten times more cakes than we asked for. However, we can't eat that many, so we decided to split them equally between all of us and give the rest back to her.

Task
Please calculate how many cakes will each of us get.

Code Limit
Less than 25 characters.

*/

#include <assert.h>

int
pies(int n)
{
	return n / .8;
}

int
main()
{
	assert(pies(1) == 1);
	assert(pies(2) == 2);
	assert(pies(3) == 3);
	assert(pies(4) == 5);
	assert(pies(5) == 6);

	return 0;
}
