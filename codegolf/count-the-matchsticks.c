/*

Most people here are familiar with seven segment displays, which are also used in matchstick puzzles. Below are the digits 0 through 9 and letters a through z, except k,m,t,v,w, written in this format.

 _        _   _         _    _    _    _    _
| |   |   _|  _|  |_|  |_   |_     |  |_|  |_|
|_|   |  |_   _|    |   _|  |_|    |  |_|   _|

 _       _      _  _  _                        _   _      _               _
|_| |_  |   _| |_ |_ |   |_  |   | |   _   _  |_| |_|  _ |_      |_| |_|  _|
| | |_| |_ |_| |_ |  |_| | | | |_| |_ | | |_| |     | |   _| |_| | |   | |_

The challenge here is simple. Given an input string, output the number of matchsticks required to represent that string. If the string contains a character outside of the above representation, ignore it (count it as 0).

For example, for input 53, a total of 10 matchsticks are required, 5 for the 5 and 5 for the 3, so the output is 10.

For input hello a total of 19 matchsticks are required, h (4), e (5), l (3), l (3), o (4), so the output is 19.

For clarity, here are the matchsticks required to build each character:

0 -> 6
1 -> 2
2 -> 5
3 -> 5
4 -> 4
5 -> 5
6 -> 6
7 -> 3
8 -> 7
9 -> 6
a -> 6
b -> 5
c -> 4
d -> 5
e -> 5
f -> 4
g -> 5
h -> 4
i -> 2
j -> 4
l -> 3
n -> 3
o -> 4
p -> 5
q -> 5
r -> 2
s -> 5
u -> 3
x -> 5
y -> 4
z -> 5
Now for the twist, and there are two of them.

The first is that the input is considered case-insensitive. That is, A and a should both count for 6 matchsticks, even though the visual representation looks like an uppercase A.
Your score is your source code run through this algorithm, plus the length of your source code in bytes, lower is better. For example, if your source code was abc123, your score would be 6+5+4+2+5+5 = 27 + 6 = 33. If your source code was #&@()*, your score would be 0 + 6 = 6.

Input/Output Examples
0    -> 6
53   -> 10
111  -> 6
112  -> 9
8888 -> 28
hello -> 19
PPCG  -> 19
Programming Puzzles & Code Golf -> 99
#&()mt!!~ -> 0
*DḌƤÆE%Ḅċ0 -> 16

Rules
If applicable, you can assume that the input/output will fit in your language's native Integer type.
The input and output can be given by any convenient method.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
matchstick(const char *s)
{
	static const int value[256] = {
	    ['0'] = 6,
	    ['1'] = 2,
	    ['2'] = 5,
	    ['3'] = 5,
	    ['4'] = 4,
	    ['5'] = 5,
	    ['6'] = 6,
	    ['7'] = 3,
	    ['8'] = 7,
	    ['9'] = 6,
	    ['a'] = 6,
	    ['b'] = 5,
	    ['c'] = 4,
	    ['d'] = 5,
	    ['e'] = 5,
	    ['f'] = 4,
	    ['g'] = 5,
	    ['h'] = 4,
	    ['i'] = 2,
	    ['j'] = 4,
	    ['l'] = 3,
	    ['n'] = 3,
	    ['o'] = 4,
	    ['p'] = 5,
	    ['q'] = 5,
	    ['r'] = 2,
	    ['s'] = 5,
	    ['u'] = 3,
	    ['x'] = 5,
	    ['y'] = 4,
	    ['z'] = 5,
	};

	size_t i;
	int c, r;

	r = 0;
	for (i = 0; s[i]; i++) {
		c = tolower(s[i]);
		r += value[c];
	}
	return r;
}

int
main()
{
	assert(matchstick("0") == 6);
	assert(matchstick("53") == 10);
	assert(matchstick("111") == 6);
	assert(matchstick("112") == 9);
	assert(matchstick("8888") == 28);
	assert(matchstick("hello") == 19);
	assert(matchstick("PPCG") == 19);
	assert(matchstick("Programming Puzzles & Code Golf") == 99);
	assert(matchstick("#&() mt !!~") == 0);
	assert(matchstick("*DḌƤÆE%Ḅċ0") == 16);

	return 0;
}
