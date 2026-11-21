/*

https://codegolf.stackexchange.com/questions/194750/keyboard-spell-word-mysterious-subtract-1
(based on this deleted question)

Take the English alphabet a b c d e f g h i j k l m n o p q r s t u v w x y z (spaces added for clarity), and split it into chunks of X width, padding any leftover lines with spaces if necessary for your language. For example, splitting it into width 4 results in

a b c d
e f g h
i j k l
m n o p
q r s t
u v w x
y z
Now, given a word composed of [a-z]+, output the path taken to spell that word when starting from a and using ! to specify selecting that letter, with D U R L for Down, Up, Right, Left, respectively.

For the above X=4 example, and the word dog, the output would be R R R ! L D D D ! U U ! (spaces added for clarity and not required in output).

If X=3, you get a different picture of the alphabet:

a b c
d e f
g h i
j k l
m n o
p q r
s t u
v w x
y z
And a different solution for the word dog -- D ! D D D R R ! L L U U !.

Examples
"dog" 4 --> R R R ! L D D D ! U U !
"dog" 3 --> D ! D D D R R ! L L U U !
"hello" 6 --> R D ! R R R U ! R D ! ! D L L L !
"codegolf" 10 --> R R ! R R D ! L U ! R ! R R ! L L D ! L L L ! U R R R R !
"acegikmoqsuwy" 2 --> ! D ! D ! D ! D ! D ! D ! D ! D ! D ! D ! D ! D !

Rules
Note that the grid doesn't wrap, so to get from the leftmost column to the rightmost column requires traversing the entire X distance.
The output must be a shortest possible path, but doesn't necessarily need to be in a particular order. For example, for the first dog example you could instead produce R R R ! D D D L ! U U !, swapping the order of the Downs and the Left, because that's the same length path and achieves the same character.
Similarly, please output only one path (because there will likely be multiple), but that doesn't need to be deterministic (i.e., multiple runs of your program may produce different paths, provided they're all the shortest).
The output doesn't have to have delimiters (like I do here with spaces), that's up to your aesthetic choice.
You can choose input as all-lowercase or all-uppercase, but it must be consistent.
The input number is guaranteed to be in the range 1 to 26 (i.e., a single column to a single row of letters).
Input words are guaranteed to be at least one character long, and match [a-z]+ with no other punctuation, spaces, etc., (i.e., you'll never receive empty string "" as input), but it may not be an actual English word.
Instead of D U R L !, you can choose five characters/numbers/arrows/etc. to represent the direction and selection. For example, you could choose 1 2 3 4 x. This output choice must be consistent across all runs of your code, and please specify in your submission what the output is.
Input and output can be given by any convenient method.
You can print it to STDOUT or return it as a function result.
Either a full program or a function are acceptable.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#include <assert.h>
#include <stdio.h>

void
spell(const char *s, int w, char *b)
{
	int x, y, X, Y;
	char *p;

	p = b;
	for (x = y = 0; *s; s++) {
		X = (*s - 'a') % w;
		Y = (*s - 'a') / w;
		for (; X > x; x++)
			*p++ = 'R';
		for (; X < x; x--)
			*p++ = 'L';
		for (; Y > y; y++)
			*p++ = 'D';
		for (; Y < y; y--)
			*p++ = 'U';
		*p++ = '!';
	}
	*p = '\0';
}

void
test(const char *s, int w)
{
	char b[128];

	spell(s, w, b);
	printf("%s\n", b);
}

int
main()
{
	test("dog", 4);
	test("dog", 3);
	test("hello", 6);
	test("codegolf", 10);
	test("acegikmoqsuwy", 2);
	return 0;
}
