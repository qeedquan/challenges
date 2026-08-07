/*

You are given four integers: e,s,b∈{0,1} and S∈{0,1,2,4}, where e,s,b,S stand for egg, sausage, bacon and spam respectively.

Your task is to figure out whether the corresponding ingredients match a valid entry in the following menu:

 [e]gg | [s]ausage | [b]acon | [S]pam
-------+-----------+---------+--------
   1   |     0     |    1    |   0
   1   |     1     |    1    |   0
   1   |     0     |    0    |   1
   1   |     0     |    1    |   1
   1   |     1     |    1    |   1
   0   |     1     |    1    |   2
   1   |     0     |    1    |   4
   1   |     0     |    0    |   4
   1   |     1     |    0    |   2
This is a subset of the menu described in the famous Monty Python's sketch, where dishes based on other ingredients are omitted.

Rules
You can take (e,s,b,S) in any order and any convenient format as long as they are clearly separated into 4 distinct values as described above (e.g. claiming that your code takes a single bitmask with all values packed in there is not allowed).

Examples: [1,0,1,4], "1014", or 4 distinct arguments

Each value is guaranteed to be valid (i.e. you don't have to support e=2 or S=3).

You may return (or print) either:
a truthy value for matching and a falsy value for not-matching
a falsy value for matching and a truthy value for not-matching
2 distinct, consistent values of your choice (please specify them in your answer)
This is code-golf
Test cases (all of them)
Format: [e, s, b, S] --> matching

[ 0, 0, 0, 0 ] --> false
[ 0, 0, 0, 1 ] --> false
[ 0, 0, 0, 2 ] --> false
[ 0, 0, 0, 4 ] --> false
[ 0, 0, 1, 0 ] --> false
[ 0, 0, 1, 1 ] --> false
[ 0, 0, 1, 2 ] --> false
[ 0, 0, 1, 4 ] --> false
[ 0, 1, 0, 0 ] --> false
[ 0, 1, 0, 1 ] --> false
[ 0, 1, 0, 2 ] --> false
[ 0, 1, 0, 4 ] --> false
[ 0, 1, 1, 0 ] --> false
[ 0, 1, 1, 1 ] --> false
[ 0, 1, 1, 2 ] --> true
[ 0, 1, 1, 4 ] --> false
[ 1, 0, 0, 0 ] --> false
[ 1, 0, 0, 1 ] --> true
[ 1, 0, 0, 2 ] --> false
[ 1, 0, 0, 4 ] --> true
[ 1, 0, 1, 0 ] --> true
[ 1, 0, 1, 1 ] --> true
[ 1, 0, 1, 2 ] --> false
[ 1, 0, 1, 4 ] --> true
[ 1, 1, 0, 0 ] --> false
[ 1, 1, 0, 1 ] --> false
[ 1, 1, 0, 2 ] --> true
[ 1, 1, 0, 4 ] --> false
[ 1, 1, 1, 0 ] --> true
[ 1, 1, 1, 1 ] --> true
[ 1, 1, 1, 2 ] --> false
[ 1, 1, 1, 4 ] --> false

Spam spam spam spam. Lovely spam! Wonderful spam!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
match(int e, int s, int b, int S)
{
	static const int tab[][4] = {
	    {1, 0, 1, 0},
	    {1, 1, 1, 0},
	    {1, 0, 0, 1},
	    {1, 0, 1, 1},
	    {1, 1, 1, 1},
	    {0, 1, 1, 2},
	    {1, 0, 1, 4},
	    {1, 0, 0, 4},
	    {1, 1, 0, 2},
	};
	const int x[] = {e, s, b, S};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!memcmp(x, tab[i], sizeof(x)))
			return true;
	}
	return false;
}

int
main(void)
{
	assert(match(0, 0, 0, 0) == false);
	assert(match(0, 0, 0, 1) == false);
	assert(match(0, 0, 0, 2) == false);
	assert(match(0, 0, 0, 4) == false);
	assert(match(0, 0, 1, 0) == false);
	assert(match(0, 0, 1, 1) == false);
	assert(match(0, 0, 1, 2) == false);
	assert(match(0, 0, 1, 4) == false);
	assert(match(0, 1, 0, 0) == false);
	assert(match(0, 1, 0, 1) == false);
	assert(match(0, 1, 0, 2) == false);
	assert(match(0, 1, 0, 4) == false);
	assert(match(0, 1, 1, 0) == false);
	assert(match(0, 1, 1, 1) == false);
	assert(match(0, 1, 1, 2) == true);
	assert(match(0, 1, 1, 4) == false);
	assert(match(1, 0, 0, 0) == false);
	assert(match(1, 0, 0, 1) == true);
	assert(match(1, 0, 0, 2) == false);
	assert(match(1, 0, 0, 4) == true);
	assert(match(1, 0, 1, 0) == true);
	assert(match(1, 0, 1, 1) == true);
	assert(match(1, 0, 1, 2) == false);
	assert(match(1, 0, 1, 4) == true);
	assert(match(1, 1, 0, 0) == false);
	assert(match(1, 1, 0, 1) == false);
	assert(match(1, 1, 0, 2) == true);
	assert(match(1, 1, 0, 4) == false);
	assert(match(1, 1, 1, 0) == true);
	assert(match(1, 1, 1, 1) == true);
	assert(match(1, 1, 1, 2) == false);
	assert(match(1, 1, 1, 4) == false);

	return 0;
}
