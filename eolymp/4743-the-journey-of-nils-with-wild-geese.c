/*

When Nils traveled with the wild geese, his flock flew over a series of lakes.
They decided to take a break, and the geese began landing on the lakes.
On the first lake, half of the entire flock plus half a goose landed.
On the second lake, half of the remaining flock plus half a goose landed.
This pattern continued until all the geese had settled on K lakes.

Now, Nils wants to determine how many geese were in the flock initially. Can you help him figure it out?

Input
The input file contains a single number K (1≤K≤20).

Output
Output the initial number of geese in the flock.

Examples

Input #1
1

Answer #1
1

*/

#include <assert.h>

int
solve(int k)
{
	if (k < 0)
		return 0;
	return (1 << k) - 1;
}

int
main()
{
	assert(solve(1) == 1);

	return 0;
}
