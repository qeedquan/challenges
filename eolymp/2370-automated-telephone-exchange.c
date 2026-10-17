/*

In London, phone numbers have the format "XXX-XX-XX", where the first three digits represent the index of the Automated Telephone Exchange (ATE). Each ATE has exactly 10000 unique phone numbers.

Peter has just bought a new flat and wants to install a telephone line. He considers a phone number lucky if the value
of the arithmetic expression it represents is zero.
For example, the phone number 102-40-62 is lucky (102−40−62=0), while 157-10-47 is not lucky (157−10−47=100=0).

Peter knows the index of the ATE serving his house. He wants to calculate how many lucky numbers his ATE can have.

Input
A single integer n — the index of Peter's ATE (100≤n≤999).

Output
A single integer — the number of lucky phone numbers Peter's ATE has.

Examples

Input #1
196

Answer #1
3

*/

#include <assert.h>

int
solve(int n)
{
	int i, j, r;

	for (r = i = 0; i < 100; i++) {
		j = n - i;
		if (0 <= j && j <= 99)
			r += 1;
	}
	return r;
}

int
main()
{
	assert(solve(196) == 3);

	return 0;
}
