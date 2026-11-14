/*

Challenge
Implement binary search on a list of length 256 with no branches.

Specification
Input an integer X and a strictly increasing list of integers
Output is the greatest element of the list that is less than or equal to X
The output will always exist
List will always have exactly 256 elements and be strictly increasing
The algorithm must be a binary search on the list
Example code (with branches)
Without branches, these examples would be valid entries.

First a functional example (actually valid Haskell code):

b value list = b' 0 7
  where
    b' pos bitpos | bitpos < 0                          = list !! pos
                  | (list !! (pos + 2^bitpos)) <  value = b' (pos + 2^bitpos) (bitpos - 1)
                  | (list !! (pos + 2^bitpos)) == value = list !! (pos + 2^bitpos)
                  | otherwise                           = b' pos (bitpos - 1)
Now a pseudocode iterative example:

b(value, list):
  pos = 0
  bitpos = 7
  while bitpos >= 0:
    if list[pos + 2^bitpos] < value
       pos    += 2^bitpos
    elseif list[pos + 2^bitpos] == value
      return list[pos + 2^bitpos]
    bitpos -= 1
  return list[pos]

Rules
Branches include: if/then, switch, case, for, while, ?:, guards, and all other branches
Instead of a list, you may use a list-like object, so space separated string, vector, etc.
Entry may be a function or full program
If your language has a function that solves this challenge, it is not allowed
Score is in bytes, lowest score wins!
Example Input/Output (abbreviated)
Input:  50, [..21,34,55,89,144..]
Output: 34

Input:  15, [..2,3,15,25,34,35..]
Output: 15

Input:  144, [..37,50,65,82,101,122,145..]
Output: 122

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
binsearch(int a[256], int x)
{
	int i;

	i = 256;

	i >>= 1;
	a += (a[i] <= x) * i;

	i >>= 1;
	a += (a[i] <= x) * i;

	i >>= 1;
	a += (a[i] <= x) * i;

	i >>= 1;
	a += (a[i] <= x) * i;

	i >>= 1;
	a += (a[i] <= x) * i;

	i >>= 1;
	a += (a[i] <= x) * i;

	i >>= 1;
	a += (a[i] <= x) * i;

	i >>= 1;
	a += (a[i] <= x) * i;

	return *a;
}

void
fill(int *a, size_t n, int r[256])
{
	size_t i, j;

	j = (256 - n) / 2;
	for (i = 0; i < j; i++)
		r[i] = INT_MIN;
	for (; i < j + n; i++)
		r[i] = a[i - j];
	for (; i < 256; i++)
		r[i] = INT_MAX;
}

void
testlinear(int s, int o)
{
	int a[256];
	int i;

	for (i = 0; i < 256; i++)
		a[i] = (s * i) + o;
	for (i = 0; i < 256; i++)
		assert(binsearch(a, a[i]) == a[i]);
}

void
testarray(int *a, size_t n, int x, int r)
{
	int p[256];

	fill(a, n, p);
	assert(binsearch(p, x) == r);
}

int
main(void)
{
	int a1[] = {21, 34, 55, 89, 144};
	int a2[] = {2, 3, 15, 25, 34, 35};
	int a3[] = {37, 50, 65, 82, 101, 122, 145};

	int i, j;

	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++)
			testlinear(i, j);
	}

	testarray(a1, nelem(a1), 50, 34);
	testarray(a2, nelem(a2), 15, 15);
	testarray(a3, nelem(a3), 144, 122);

	return 0;
}
