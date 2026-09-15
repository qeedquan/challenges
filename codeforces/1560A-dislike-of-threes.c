/*

Polycarp doesn't like integers that are divisible by 3 or end with the digit 3 in their decimal representation. Integers that meet both conditions are disliked by Polycarp, too.

Polycarp starts to write out the positive (greater than 0) integers which he likes: 1,2,4,5,7,8,10,11,14,16,….
Output the k-th element of this sequence (the elements are numbered from 1).

Input
The first line contains one integer t (1≤t≤100) — the number of test cases. Then test cases follow.

Each test case consists of one line containing one integer k (1≤k≤1000).

Output
For each test case, output in a separate line one integer x — the k-th element of the sequence that was written out by Polycarp.

Example
input
10
1
2
3
4
5
6
7
8
9
1000

output
1
2
4
5
7
8
10
11
14
1666

*/

#include <assert.h>

int
seq(int n)
{
	int i, j;

	for (i = j = 1; j <= n; i++) {
		if (!(i % 3 == 0 || i % 10 == 3))
			j++;
	}
	return i - 1;
}

int
main(void)
{
	assert(seq(1) == 1);
	assert(seq(2) == 2);
	assert(seq(3) == 4);
	assert(seq(4) == 5);
	assert(seq(5) == 7);
	assert(seq(6) == 8);
	assert(seq(7) == 10);
	assert(seq(8) == 11);
	assert(seq(9) == 14);
	assert(seq(1000) == 1666);

	return 0;
}
