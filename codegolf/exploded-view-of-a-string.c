/*

Don't you love those exploded-view diagrams in which a machine or object is taken apart into its smallest pieces?

https://i.stack.imgur.com/6lcse.jpg

Let's do that to a string!

The challenge
Write a program or function that

inputs a string containing only printable ASCII characters;
dissects the string into groups of non-space equal characters (the "pieces" of the string);
outputs those groups in any convenient format, with some separator between groups.
For example, given the string

Ah, abracadabra!
the output would be the following groups:

!
,
A
aaaaa
bb
c
d
h
rr
Each group in the output contains equal characters, with spaces removed. A newline has been used as separator between groups. More about allowed formats below.

Rules
The input should be a string or an array of chars. It will only contain printable ASCII chars (the inclusive range from space to tilde). If your language does not support that, you can take the input in the form of numbers representing ASCII codes.

You can assume that the input contains at least one non-space character.

The output should consist of characters (even if the input is by means of ASCII codes). There has to be an unambiguous separator between groups, different than any non-space character that may appear in the input.

If the output is via function return, it may also be an array or strings, or an array of arrays of chars, or similar structure. In that case the structure provides the necessary separation.

A separator between characters of each group is optional. If there is one, the same rule applies: it can't be a non-space character that may appear in the input. Also, it can't be the same separator as used between groups.

Other than that, the format is flexible. Here are some examples:

The groups may be strings separated by newlines, as shown above.

The groups may be separated by any non-ASCII character, such as ¬. The output for the above input would be the string:

!¬,¬A¬aaaaa¬bb¬c¬d¬h¬rr
The groups may be separated by n>1 spaces (even if n is variable), with chars between each group separated by a single space:

!  ,    A   a a a a a    b b  c       d   h  r r
The output may also be an array or list of strings returned by a function:

['!', 'A', 'aaaaa', 'bb', 'c', 'd', 'h', 'rr']
Or an array of char arrays:

[['!'], ['A'], ['a', 'a', 'a', 'a', 'a'], ['b', 'b'], ['c'], ['d'], ['h'], ['r', 'r']]
Examples of formats that are not allowed, according to the rules:

A comma can't be used as separator (!,,,A,a,a,a,a,a,b,b,c,d,h,r,r), because the input may contain commas.
It's not accepted to drop the separator between groups (!,Aaaaaabbcdhrr) or to use the same separator between groups and within groups (! , A a a a a a b b c d h r r).
The groups may appear in any order in the output. For example: alphabetical order (as in the examples above), order of first appearance in the string, ... The order need not be consistent or even deterministic.

Note that the input cannot contain newline characters, and A and a are different characters (grouping is case-sentitive).

Shortest code in bytes wins.

Test cases
In each test case, first line is input, and the remaining lines are the output, with each group in a different line.

Test case 1:

Ah, abracadabra!
!
,
A
aaaaa
bb
c
d
h
rr
Test case 2:

\o/\o/\o/
///
\\\
ooo
Test case 3:

A man, a plan, a canal: Panama!
!
,,
:
A
P
aaaaaaaaa
c
ll
mm
nnnn
p
Test case 4:

"Show me how you do that trick, the one that makes me scream" she said
""
,
S
aaaaa
cc
dd
eeeeeee
hhhhhh
ii
kk
mmmm
n
ooooo
rr
ssss
tttttt
u
ww
y

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
explodedview(const char *s)
{
	size_t h[256];
	size_t i, j;
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	for (i = 0; i < nelem(h); i++) {
		if (!h[i] || i == ' ')
			continue;

		c = i;
		for (j = 0; j < h[i]; j++)
			printf("%c", c);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	explodedview("Ah, abracadabra!");
	explodedview("\\o/\\o/\\o/");
	explodedview("A man, a plan, a canal: Panama!");
	explodedview("\"Show me how you do that trick, the one that makes me scream\" she said");

	return 0;
}
