/*

The barfoos, a hypothetical alien species, go about charity in an interesting way.

Every morning, barfoo Specialists come up with an ordered list of causes to donate to, and for each cause they recommend what quantity of resources should be donated.

That wasn't the weird part. Here's the weird part:

A random civilian barfoo will donate the recommended quantity of resources to the first cause. Another one will likewise donate to the very next cause on the list, and keep going down the list until it has given at least as much as its compatriot, at which point it immediately stops.

This continues, each civilian giving at least as much as the one directly before, until the remaining elements of the Great List of Charitable Causes can no longer satisfy this donation arms race, at which point the Specialists themselves just chip in.

How many civilian barfoos are involved?

Input: a sequence of 1≤n≤100000 integers each of value 1≤i≤1000, representing the recommended donation sizes for the Great List of Charitable Causes in the order in which it's given to the barfoos.

Output: a single integer representing the number of civilian barfoos who donate something.

Sample 1
Input: 5 2 3 1 3 4 2 5

Output: 3

This may be divided into the buckets 5, 2 3 (sum 5), 1 3 4 (sum 8) and 2 5 (sum 7, cannot satisfy a fourth civilian barfoo).

Sample 2
Input: 4 1 2 3 6 6

Output: 4

This may be divided into the buckets 4, 1 2 3 (sum 6), 6 and 6. (In this case, no Specialists need to involve themselves.)

code-golf; the shortest code in bytes wins.
The linked rules apply.
Please explain your code.
Please link to Try It Online! or another online demo.
Credit: 'Nomnomnom' (AIO 2009, Senior)

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// ported from @xnor solution
int
donations(int *a, size_t n)
{
	size_t i;
	int u, v, r;

	u = v = r = 0;
	for (i = 0; i < n; i++) {
		v += a[i];
		if (v >= u) {
			r += 1;
			u = v;
			v = 0;
		}
	}
	return r;
}

int
main(void)
{
	int a1[] = {5, 2, 3, 1, 3, 4, 2, 5};
	int a2[] = {4, 1, 2, 3, 6, 6};
	int a3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int a4[] = {2, 2, 1};

	assert(donations(a1, nelem(a1)) == 3);
	assert(donations(a2, nelem(a2)) == 4);
	assert(donations(a3, nelem(a3)) == 10);
	assert(donations(a4, nelem(a4)) == 2);

	return 0;
}
