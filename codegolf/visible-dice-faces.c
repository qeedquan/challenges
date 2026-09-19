/*

A traditional Western die is a cube, on which the integers 1 to 6 are marked on the faces. Pairs that add to 7 are placed on opposite faces.

As it is cube, we can only see between 1 and 3 faces (inclusive)1 at any given time. Opposite faces can never be seen at the same time.

Your task is to write a program or function which, given a list of integers representing sides on a die, determines if it is possible to see these faces at the same time.

[1] Okay, maybe you can see 4 or 5 faces with a pair of eyes, but for the purpose of this challenge we observing the die from a single point.

Rules:
Your submission may assume the input list:
Is non-empty.
Only contains values which satisfy 1 ≤ n ≤ 6.
Contains no duplicate elements.
You may not assume that the input is sorted.
Your submission should output a truthy / falsy value: truthy is the faces can be seen at the same time, falsy otherwise.
This is code-golf, so the shortest answer (in bytes) wins!
Standard loopholes are forbidden by default.

Test Cases
Truthy:

[6]                 (One face)
[6, 2]              (Share a side)
[1, 3]              (Share a side)
[2, 1, 3]           (Share a vertea)
[3, 2, 6]           (Share a vertea)
Falsy:

[1, 6]              (1 and 6 are opposite)
[5, 4, 2]           (2 and 5 are opposite)
[3, 1, 4]           (3 and 4 are opposite)
[5, 4, 6, 2]        (Cannot see 4 faces)
[1, 2, 3, 4, 5, 6]  (Cannot see 6 faces)

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@Arnauld

Takes input as any number of separate parameters. Returns 0 or 1.

(a,b,c,d)=>!(d|(a^b^c)%7)^!c
Test cases
Show code snippet

How?
Below are simplified versions of the main expression according to the number of parameters provided, undefined variables being coerced to either 0 or false:

# of param. | simplified expression        | comment
------------+------------------------------+---------------------------------------------
     1      | !(a % 7) ^ 1                 | always true
     2      | !((a ^ b) % 7) ^ 1           | false for (1,6), (2,5) and (3,4)
     3      | !((a ^ b ^ c) % 7)           | see the table below
     4+     | !(d | (a ^ b ^ c) % 7)       | always false
NB: The order of (a,b,c) doesn't matter because they're always XOR'd together.

The trickiest case is the 3rd one. Here is a table showing all possible combinations:

a | b | c | a^b^c | %7 | =0? | faces that sum to 7
--+---+---+-------+----+-----+--------------------
1 | 2 | 3 |   0   |  0 | Yes | none
1 | 2 | 4 |   7   |  0 | Yes | none
1 | 2 | 5 |   6   |  6 | No  | 2 + 5
1 | 2 | 6 |   5   |  5 | No  | 1 + 6
1 | 3 | 4 |   6   |  6 | No  | 3 + 4
1 | 3 | 5 |   7   |  0 | Yes | none
1 | 3 | 6 |   4   |  4 | No  | 1 + 6
1 | 4 | 5 |   0   |  0 | Yes | none
1 | 4 | 6 |   3   |  3 | No  | 1 + 6
1 | 5 | 6 |   2   |  2 | No  | 1 + 6
2 | 3 | 4 |   5   |  5 | No  | 3 + 4
2 | 3 | 5 |   4   |  4 | No  | 2 + 5
2 | 3 | 6 |   7   |  0 | Yes | none
2 | 4 | 5 |   3   |  3 | No  | 2 + 5
2 | 4 | 6 |   0   |  0 | Yes | none
2 | 5 | 6 |   1   |  1 | No  | 2 + 5
3 | 4 | 5 |   2   |  2 | No  | 3 + 4
3 | 4 | 6 |   1   |  1 | No  | 3 + 4
3 | 5 | 6 |   0   |  0 | Yes | none
4 | 5 | 6 |   7   |  0 | Yes | none

Alt. version #1, 32 bytes
Takes input as an array. Returns a boolean.

a=>a.every(x=>a.every(y=>x+y-7))

*/

bool
seenable(int *a, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i] + a[j] - 7 == 0)
				return false;
		}
	}
	return true;
}

int
main(void)
{
	int a1[] = {6};
	int a2[] = {6, 2};
	int a3[] = {1, 3};
	int a4[] = {2, 1, 3};
	int a5[] = {3, 2, 6};

	int a6[] = {1, 6};
	int a7[] = {5, 4, 2};
	int a8[] = {3, 1, 4};
	int a9[] = {5, 4, 6, 2};
	int a10[] = {1, 2, 3, 4, 5, 6};

	assert(seenable(a1, nelem(a1)) == true);
	assert(seenable(a2, nelem(a2)) == true);
	assert(seenable(a3, nelem(a3)) == true);
	assert(seenable(a4, nelem(a4)) == true);
	assert(seenable(a5, nelem(a5)) == true);

	assert(seenable(a6, nelem(a6)) == false);
	assert(seenable(a7, nelem(a7)) == false);
	assert(seenable(a8, nelem(a8)) == false);
	assert(seenable(a9, nelem(a9)) == false);
	assert(seenable(a10, nelem(a10)) == false);

	return 0;
}
