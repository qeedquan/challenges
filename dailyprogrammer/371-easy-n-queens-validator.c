/*

For the purpose of this challenge, the N queens problem consists of putting one queen on every column (labeled a, b, c, ...) of an NxN chessboard, such that no two queens are in the same row or diagonal. An example valid solution for N = 6 is:

6  . . Q . . .
5  . . . . . Q
4  . Q . . . .
3  . . . . Q .
2  Q . . . . .
1  . . . Q . .
   a b c d e f
In chess notation, the squares with queens in this solution are called a2, b4, c6, d1, e3, and f5. We'll represent solutions by listing the rows that each column's queen appears in from left to right, so this solution is represented as the array {2, 4, 6, 1, 3, 5}.

Solving the N queens problem was #25 (difficult) on r/dailyprogrammer, but you don't need to actually solve it for today's challenge.

Challenge
Given an array of 8 integers between 1 and 8, determine whether it represents a valid 8 queens solution.

qcheck({4, 2, 7, 3, 6, 8, 5, 1}) => true
qcheck({2, 5, 7, 4, 1, 8, 6, 3}) => true
qcheck({5, 3, 1, 4, 2, 8, 6, 3}) => false   (b3 and h3 are on the same row)
qcheck({5, 8, 2, 4, 7, 1, 3, 6}) => false   (b8 and g3 are on the same diagonal)
qcheck({4, 3, 1, 8, 1, 3, 5, 2}) => false   (multiple problems)
You may optionally handle solutions for any N, not just N = 8.

Optional bonus
In this bonus, you are given an invalid solution where it's possible to swap two numbers and produce a valid solution, which you must find. (Be aware that most invalid solutions will not have this property.)

For example, {8, 6, 4, 2, 7, 1, 3, 5} is invalid because c4 and f1 are on the same diagonal. But if you swap the 8 and the 4 (i.e. replace a8 and c4 with a4 and c8), you get the valid solution {4, 6, 8, 2, 7, 1, 3, 5}.

qfix({8, 6, 4, 2, 7, 1, 3, 5}) => {4, 6, 8, 2, 7, 1, 3, 5}
qfix({8, 5, 1, 3, 6, 2, 7, 4}) => {8, 4, 1, 3, 6, 2, 7, 5}
qfix({4, 6, 8, 3, 1, 2, 5, 7}) => {4, 6, 8, 3, 1, 7, 5, 2}
qfix({7, 1, 3, 6, 8, 5, 2, 4}) => {7, 3, 1, 6, 8, 5, 2, 4}

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

// Ported from @skeeto solution

uint64_t
down(uint64_t a, uint64_t b, int d)
{
	static const uint64_t masks[] = {
		UINT64_MAX, 0
	};

	uint64_t m, s;

	m = masks[!d];
	s = d * 8;
	return (a << (-s & 0x3f) & m) | (b >> s);
}

uint64_t
right(uint64_t a, uint64_t b, int d)
{
	static const uint64_t masks[] = {
		0x0000000000000000, 0x8080808080808080,
		0xc0c0c0c0c0c0c0c0, 0xe0e0e0e0e0e0e0e0,
		0xf0f0f0f0f0f0f0f0, 0xf8f8f8f8f8f8f8f8,
		0xfcfcfcfcfcfcfcfc, 0xfefefefefefefefe
	};

	uint64_t m;

	m = masks[d];
	a = (a << (8 - d)) & m;
	b = (b >> d) & ~m;
	return a | b;
}

uint64_t
queen(int x, int y)
{
	static const uint64_t queen[] = {
		0x8040201008040201, 0x808182848890a0c0,
		0xff01020408102040, 0xffc0a09088848281
	};

	uint64_t le, ri;

	le = down(queen[0], queen[2], y);
	ri = down(queen[1], queen[3], y);
	return right(le, ri, x);
}

uint64_t
point(int x, int y)
{
	return UINT64_C(1) << (63 - 8 * y - x);
}

int
qcheck(const int pos[8])
{
	uint64_t place, attack;
	uint64_t bit;
	int i;

	place = 0;
	attack = 0;
	for (i = 0; i < 8; i++) {
		bit = point(i, pos[i]);
		place |= bit;
		attack |= queen(i, pos[i]) & ~bit;
	}
	return (place ^ attack) == UINT64_MAX;
}

void
test(int pos[8], int res)
{
	int i;

	for (i = 0; i < 8; i++)
		pos[i] -= 1;

	assert(qcheck(pos) == res);
}

int
main()
{
	int pos1[] = { 4, 2, 7, 3, 6, 8, 5, 1 };
	int pos2[] = { 2, 5, 7, 4, 1, 8, 6, 3 };
	int pos3[] = { 5, 3, 1, 4, 2, 8, 6, 3 };
	int pos4[] = { 5, 8, 2, 4, 7, 1, 3, 6 };
	int pos5[] = { 4, 3, 1, 8, 1, 3, 5, 2 };

	test(pos1, true);
	test(pos2, true);
	test(pos3, false);
	test(pos4, false);
	test(pos5, false);

	return 0;
}
