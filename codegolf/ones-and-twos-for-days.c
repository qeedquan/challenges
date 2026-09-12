/*

Inspiring myself on a recent challenge, we ought to compute a sequence that is very close to A160242.

Task
Your task is to generate the sequence {si}∞i=0:

1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, ...

Which is more easily understandable in this format:

      1 2 1
    1 2 2 2 1
  1 2 2 2 2 2 1
1 2 2 2 2 2 2 2 1 ...
Another way to think of it is, this sequence is the concatenation of blocks bi,0≤i where block bi is a 1, followed by 2i+1 2s, followed by another 1.

Input
If your program takes input, the input is a non-negative integer n, telling you how far you should go in computing the sequence.

The sequence can

be 0-indexed, so that s0=1,s1=2,s2=1,...
be 1-indexed, so that s1=1,s2=2,s3=1,...

Output
Your code may do one of the following:

indefinitely print the sequence
print/return the term n as given by the input
print/return all the terms up to the term n as given by the input

Test cases
(the test cases are 0-indexed)

0 -> 1
1 -> 2
2 -> 1
3 -> 1
4 -> 2
5 -> 2
6 -> 2
7 -> 1
8 -> 1
9 -> 2
10 -> 2
11 -> 2
12 -> 2
13 -> 2
14 -> 1
15 -> 1
16 -> 2
17 -> 2
18 -> 2
19 -> 2
20 -> 2
21 -> 2
22 -> 2
23 -> 1
24 -> 1
25 -> 2
26 -> 2
27 -> 2
28 -> 2
29 -> 2

This is code-golf so the shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
seq(int n)
{
	int s;

	s = sqrt(n + 1);
	return (n > s * s) ? 2 : 1;
}

int
main(void)
{
	static const int tab[] = {
	    1,
	    2,
	    1,
	    1,
	    2,
	    2,
	    2,
	    1,
	    1,
	    2,
	    2,
	    2,
	    2,
	    2,
	    1,
	    1,
	    2,
	    2,
	    2,
	    2,
	    2,
	    2,
	    2,
	    1,
	    1,
	    2,
	    2,
	    2,
	    2,
	    2,
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(seq(i + 1) == tab[i]);

	return 0;
}
