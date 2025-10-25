/*

Inspired by this challenge.
https://codegolf.stackexchange.com/questions/188556/brute-force-the-switchboard

Goal:
Given a pre-configured switchboard and a list of indexes, invert the switches at the given indexes.

A switchboard is made up of some number of switches (v or ^) wrapped in -'s and arranged into rows of varying length. Here is an example switchboard:

-v-^-v-
-^-v-
-v-^-v-
To invert/flip a switch means changing it from v to ^, or from ^ to v.

The switches are indexed left-to-right, top-to-bottom. E.g., in the example above, the last v in the first row would be in position 3 and the ^ in the middle row would be at 4 (using 1-indexing).

Input:
A string (or list of strings) representing the switchboard. It is guaranteed to match the regex ((-[v^])+-)(\n(-[v^])+-)*.
A possibly empty list of numbers representing indexes, may be 0 or 1 (or some arbitrary number if you want) indexed. These are the switches that need to be flipped.
Output:
A switchboard in the same shape as the input with the specified switches inverted. Any unspecified switches should retain their initial state.
Rules:
Input will always be correctly formatted and no given indexes will be out of bounds.
The list of indexes will be sorted and will have no duplicates.
State in your answer what indexing you use, be it 0, 1, or some arbitrary one.
Trailing whitespace is fine as long as the output looks like the input.
This is code-golf so shortest code wins.
Examples:
#Using 1-indexing
input: #Empty Case
[],
-v-^-v-

output:
-v-^-v-

input: #Single switch
[1],
-v-

output:
-^-

input: #Skip a line
[3,5],
-^-v-v-
-v-
-^-^-

output:
-^-v-^-
-v-
-v-^-

input: #Flip one in each line + number wrap
[3,4,6],
-^-v-v-
-v-
-^-^-

output:
-^-v-^-
-^-
-^-v-

input: #Flip 'em all
[1,2,3,4,5,6],
-^-v-v-
-v-
-^-^-

output:
-v-^-^-
-^-
-v-v-

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
invert(char *s, size_t *p, size_t n)
{
	size_t i, w;

	w = 1;
	for (i = 0; *s; s++) {
		switch (*s) {
		case 'v':
		case '^':
			if (i < n && p[i] == w) {
				*s = (*s == 'v') ? '^' : 'v';
				i += 1;
			}
			w += 1;
			break;
		}
	}
}

void
test(char *s, size_t *p, size_t n, const char *r)
{
	invert(s, p, n);
	assert(!strcmp(s, r));
}

int
main()
{
	char s1[] = "-v-^-v-";
	char s2[] = "-v-";
	char s3[] = "-^-v-v-"
	            "-v-    "
	            "-^-^-  ";
	char s4[] = "-^-v-v-"
	            "-v-    "
	            "-^-^-  ";
	char s5[] = "-^-v-v-"
	            "-v-    "
	            "-^-^-  ";

	size_t p2[] = { 1 };
	size_t p3[] = { 3, 5 };
	size_t p4[] = { 3, 4, 6 };
	size_t p5[] = { 1, 2, 3, 4, 5, 6 };

	char r1[] = "-v-^-v-";
	char r2[] = "-^-";
	char r3[] = "-^-v-^-"
	            "-v-    "
	            "-v-^-  ";
	char r4[] = "-^-v-^-"
	            "-^-    "
	            "-^-v-  ";
	char r5[] = "-v-^-^-"
	            "-^-    "
	            "-v-v-  ";

	test(s1, NULL, 0, r1);
	test(s2, p2, nelem(p2), r2);
	test(s3, p3, nelem(p3), r3);
	test(s4, p4, nelem(p4), r4);
	test(s5, p5, nelem(p5), r5);

	return 0;
}
