/*

The non-negative integers are bored of always having the same two* neighbours, so they decide to mix things up a little. However, they are also lazy and want to stay as close as possible to their original position.

They come up with the following algorithm:

The first element is 0.
The nth
 element is the smallest number which is not yet present in the sequence and which is not a neighbour of the (n−1)th
 element.
This generates the following infinite sequence:

0,2,4,1,3,5,7,9,6,8,10,12,14,11,13,15,17,19,16,18,20,22,24,21,23,25,27,29,26,28 ...
0 is the first element. 1 is the smallest number not yet in the sequence, but it is a neighbour of 0. The next smallest number is 2, so it is the second element of the sequence. Now the remaining numbers are 1,3,4,5,6,..., but as both 1 and 3 are neighbours of 2, 4 is the third member of the sequence. As 1 is not a neighbour of 4, it can finally take its place as fourth element.

The Task
Write a function or program in as few bytes as possible which generates the above sequence.

You may

output the sequence infinitely,
take an input n
 and return the nth
 element of the sequence, or
take an input n
 and return the first n
 elements of the sequence.
Both zero- or one-indexing is fine in case you choose one of the two latter options.

You don't need to follow the algorithm given above, any method which produces the same sequence is fine.

Inspired by Code golf the best permutation. Turns out this is A277618.
* Zero has literally only one neighbour and doesn't really care.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A277618
int
seq(int n)
{
	if (n < 0)
		return 0;
	return n - 2 + ((n + 2) % 5);
}

int
main()
{
	static const int tab[] = {
		0, 2, 4, 1, 3, 5, 7, 9, 6, 8, 10, 12, 14, 11, 13, 15, 17, 19, 16, 18,
		20, 22, 24, 21, 23, 25, 27, 29, 26, 28, 30, 32, 34, 31, 33, 35, 37,
		39, 36, 38, 40, 42, 44, 41, 43, 45, 47, 49, 46, 48, 50, 52, 54, 51, 53,
		55, 57, 59, 56, 58, 60, 62, 64, 61, 63, 65, 67, 69, 66, 68, 70, 72, 74,
		71, 73, 75, 77, 79, 76, 78, 80, 82, 84, 81, 83, 85, 87, 89, 86, 88, 90
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(seq(i) == tab[i]);

	return 0;
}
