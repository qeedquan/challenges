/*

We are all used to the old-school telephone keypad, right? For reference, here is what it looks like:

Telephone Keypad
https://i.stack.imgur.com/MPi6I.png

Given a String consisting only of lowercase ASCII letters and single spaces, your task is to return the number of taps one should make in order to type down the full String with a telephone keypad as the one above.

For those who are unfamiliar with this, here's how it works:

The key with the digit 2, for example, also has the string abc written down on it. In order to type a, you must press this key once, for b you must press twice and for c you must press thrice.

For consecutive letters that are on the same key, you must wait 1 second before pressing again. So, if you want to type cb, you must press 3 times for c, wait a second and then press twice for b, so still 5 taps.

The same applies for all other keys, except for a single space, which only requires 1 press. Also note that the keys 7 and 9 have four letters on them. The same algorithm is applied, the only difference being the number of letters. The strings corresponding to each key can be found in the image above (but lowercase), or in the following list, that contains all the characters you might receive:

"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", " "
Test Cases
Input  ->  Output  (Explanation)

"" -> 0                   (nothing should be tapped)
"water" -> 8              ("w,a,t" each require 1 tap (on keys 9, 2 and 8), "e" requires 2 taps (on key 3), "r" requires 3 taps (on key 7), 1+1+1+2+3 = 8)
"soap"  -> 9              (4+3+1+1)
"candela" -> 13           (3+1+2+1+2+3+1)
"code golf" -> 20         (3+3+1+2+1(for the space)+1+3+3+3)
"king of the hill" -> 33  (2+3+2+1+1+3+3+1+1+2+2+1+2+3+3+3)
Specs
Standard I/O rules and Default Loopholes apply.

You may only take input in your language's native String type. Output can either be an integer or a string representation of that integer.

This is code-golf, the shortest answer in every language wins.

*/

#include <assert.h>
#include <stdio.h>

int
presses(const char *s)
{
	static const int tab[256] = {
	    ['A'] = 1,
	    ['B'] = 2,
	    ['C'] = 3,
	    ['D'] = 1,
	    ['E'] = 2,
	    ['F'] = 3,
	    ['G'] = 1,
	    ['H'] = 2,
	    ['I'] = 3,
	    ['J'] = 1,
	    ['K'] = 2,
	    ['L'] = 3,
	    ['M'] = 1,
	    ['N'] = 2,
	    ['O'] = 3,
	    ['P'] = 1,
	    ['Q'] = 2,
	    ['R'] = 3,
	    ['S'] = 4,
	    ['T'] = 1,
	    ['U'] = 2,
	    ['V'] = 3,
	    ['W'] = 1,
	    ['X'] = 2,
	    ['Y'] = 3,
	    ['Z'] = 4,
	    ['a'] = 1,
	    ['b'] = 2,
	    ['c'] = 3,
	    ['d'] = 1,
	    ['e'] = 2,
	    ['f'] = 3,
	    ['g'] = 1,
	    ['h'] = 2,
	    ['i'] = 3,
	    ['j'] = 1,
	    ['k'] = 2,
	    ['l'] = 3,
	    ['m'] = 1,
	    ['n'] = 2,
	    ['o'] = 3,
	    ['p'] = 1,
	    ['q'] = 2,
	    ['r'] = 3,
	    ['s'] = 4,
	    ['t'] = 1,
	    ['u'] = 2,
	    ['v'] = 3,
	    ['w'] = 1,
	    ['x'] = 2,
	    ['y'] = 3,
	    ['z'] = 4,
	    [' '] = 1,
	};

	size_t i;
	int r;

	r = 0;
	for (i = 0; s[i]; i++)
		r += tab[s[i] & 0xff];
	return r;
}

void
test(const char *s, int r)
{
	int v;

	v = presses(s);
	printf("%d\n", v);
	assert(v == r);
}

int
main(void)
{
	test("", 0);
	test("water", 8);
	test("soap", 9);
	test("candela", 13);
	test("code golf", 20);
	test("king of the hill", 33);

	return 0;
}
