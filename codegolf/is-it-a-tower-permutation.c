/*

A tower is made out of layers, each one being one unit shorter than the one below it. Every layer is completely on top of the previous layer. For example, here is a tower along with it's height map:

  #
 ##
 ###
 ####
#####
14532
Because the lengths of the layers are the integers from 1 to n, and because the layers are completely on top of each other, the height map will always be a permutation of the integers from 1 to n. (Can you see why? Comment below)

The converse is not true. Some permutations are not the height map of a tower, meaning they are not tower permutations. For example, [2,1,3,5,4] is not the height map of any tower, meaning that it's not a tower permutation. However, [1,4,5,3,2] is a tower permutation, as you can see from the previous ascii drawing.

Just to be clear, the following is not a tower:

   #
   ##
  ###
# ###
#####
21354
Because each layer has to be continuous. This is instead a castle :P

Your task is to take a permutation of the integers 1 to n (inclusive) and decide if it's a tower permutation, as per usual code-golf and decision-problem rules. You can assume that n>0

Test cases (all permutations up to n=4)
[1] -> True
[1, 2] -> True
[2, 1] -> True
[1, 2, 3] -> True
[1, 3, 2] -> True
[2, 1, 3] -> False
[2, 3, 1] -> True
[3, 1, 2] -> False
[3, 2, 1] -> True
[1, 2, 3, 4] -> True
[1, 2, 4, 3] -> True
[1, 3, 2, 4] -> False
[1, 3, 4, 2] -> True
[1, 4, 2, 3] -> False
[1, 4, 3, 2] -> True
[2, 1, 3, 4] -> False
[2, 1, 4, 3] -> False
[2, 3, 1, 4] -> False
[2, 3, 4, 1] -> True
[2, 4, 1, 3] -> False
[2, 4, 3, 1] -> True
[3, 1, 2, 4] -> False
[3, 1, 4, 2] -> False
[3, 2, 1, 4] -> False
[3, 2, 4, 1] -> False
[3, 4, 1, 2] -> False
[3, 4, 2, 1] -> True
[4, 1, 2, 3] -> False
[4, 1, 3, 2] -> False
[4, 2, 1, 3] -> False
[4, 2, 3, 1] -> False
[4, 3, 1, 2] -> False
[4, 3, 2, 1] -> True

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@xnor

A tower permutation is one where no element is smaller than both its neighbors.

*/

bool
tower(int *a, size_t n)
{
	size_t i;

	if (n < 3)
		return true;

	for (i = 1; i < n - 1; i++) {
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			return false;
	}
	return true;
}

int
main()
{
	int a1[] = {1};
	int a2[] = {1, 2};
	int a3[] = {2, 1};
	int a4[] = {1, 2, 3};
	int a5[] = {1, 3, 2};
	int a6[] = {2, 1, 3};
	int a7[] = {2, 3, 1};
	int a8[] = {3, 1, 2};
	int a9[] = {3, 2, 1};
	int a10[] = {1, 2, 3, 4};
	int a11[] = {1, 2, 4, 3};
	int a12[] = {1, 3, 2, 4};
	int a13[] = {1, 3, 4, 2};
	int a14[] = {1, 4, 2, 3};
	int a15[] = {1, 4, 3, 2};
	int a16[] = {2, 1, 3, 4};
	int a17[] = {2, 1, 4, 3};
	int a18[] = {2, 3, 1, 4};
	int a19[] = {2, 3, 4, 1};
	int a20[] = {2, 4, 1, 3};
	int a21[] = {2, 4, 3, 1};
	int a22[] = {3, 1, 2, 4};
	int a23[] = {3, 1, 4, 2};
	int a24[] = {3, 2, 1, 4};
	int a25[] = {3, 2, 4, 1};
	int a26[] = {3, 4, 1, 2};
	int a27[] = {3, 4, 2, 1};
	int a28[] = {4, 1, 2, 3};
	int a29[] = {4, 1, 3, 2};
	int a30[] = {4, 2, 1, 3};
	int a31[] = {4, 2, 3, 1};
	int a32[] = {4, 3, 1, 2};
	int a33[] = {4, 3, 2, 1};
	int a34[] = {1, 4, 5, 3, 2};
	int a35[] = {2, 1, 3, 5, 4};

	assert(tower(a1, nelem(a1)) == true);
	assert(tower(a2, nelem(a1)) == true);
	assert(tower(a3, nelem(a1)) == true);
	assert(tower(a4, nelem(a1)) == true);
	assert(tower(a5, nelem(a5)) == true);
	assert(tower(a6, nelem(a6)) == false);
	assert(tower(a7, nelem(a7)) == true);
	assert(tower(a8, nelem(a8)) == false);
	assert(tower(a9, nelem(a9)) == true);
	assert(tower(a10, nelem(a10)) == true);
	assert(tower(a11, nelem(a11)) == true);
	assert(tower(a12, nelem(a12)) == false);
	assert(tower(a13, nelem(a13)) == true);
	assert(tower(a14, nelem(a14)) == false);
	assert(tower(a15, nelem(a15)) == true);
	assert(tower(a16, nelem(a16)) == false);
	assert(tower(a17, nelem(a17)) == false);
	assert(tower(a18, nelem(a18)) == false);
	assert(tower(a19, nelem(a19)) == true);
	assert(tower(a20, nelem(a20)) == false);
	assert(tower(a21, nelem(a21)) == true);
	assert(tower(a22, nelem(a22)) == false);
	assert(tower(a23, nelem(a23)) == false);
	assert(tower(a24, nelem(a24)) == false);
	assert(tower(a25, nelem(a25)) == false);
	assert(tower(a26, nelem(a26)) == false);
	assert(tower(a27, nelem(a27)) == true);
	assert(tower(a28, nelem(a28)) == false);
	assert(tower(a29, nelem(a29)) == false);
	assert(tower(a30, nelem(a30)) == false);
	assert(tower(a31, nelem(a31)) == false);
	assert(tower(a32, nelem(a32)) == false);
	assert(tower(a33, nelem(a33)) == true);
	assert(tower(a34, nelem(a34)) == true);
	assert(tower(a35, nelem(a35)) == false);

	return 0;
}
