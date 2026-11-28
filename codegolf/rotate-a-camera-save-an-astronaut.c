/*

Note: Minor spoilers for The Martian are in this challenge. Read ahead with caution

The Martian is a Science Fiction novel about astronaut and botanist extraordinaire, Mark Watney, who has been accidentally stranded on Mars. At one point in the book, Mark tries communicating with NASA, but the only means of communication they have is a camera. Mark sends messages by writing on index cards, and, since NASA can rotate the camera 360 degrees, NASA sends replies back by pointing the camera at cards labeled "Yes" or "No".

Since the only data NASA can send is the direction the camera is facing, Mark comes up with a system where they can point at cards with alphabet characters on them to type messages. But using the letters 'a-z' would be impractical. To quote the book (from this answer, over on scifi.se):

We’ll need to talk faster than yes/no questions every half hour. The camera can rotate 360 degrees, and I have plenty of antenna parts. Time to make an alphabet. But I can’t just use the letters A through Z. Twenty-six letters plus my question card would be twenty-seven cards around the lander. Each one would only get 13 degrees of arc. Even if JPL points the camera perfectly, there’s a good chance I won’t know which letter they meant.

So I’ll have to use ASCII. That’s how computers manage characters. Each character has a numerical code between 0 and 255. Values between 0 and 255 can be expressed as 2 hexadecimal digits. By giving me pairs of hex digits, they can send any character they like, including numbers, punctuation, etc.

...

So I’ll make cards for 0 through 9, and A through F. That makes 16 cards to place around the camera, plus the question card. Seventeen cards means over 21 degrees each. Much easier to deal with.

Your goal today, as one of the top software engineers at NASA, is to write a program to encode the various angles of the camera. The seventeen cards Mark has for you to point at are (in order):

?0123456789ABCDEF
and each of these cards is 21 degrees apart, so to rotate the camera from ? to 0, you should rotate the camera 21 degrees, and 2 to 1 is -21 degrees. (It's not exactly 21, but we'll round to keep it simpler) This wraps, so to go from F to 3 is 105 degrees (5 turns, 5 * 21 = 105). This is more efficient than going -252, since the camera won't have to move as far.

Here's what your program or function must do.

Take a string as input. We'll call this string s. To keep it simple, we'll say that the input will only ever be printable ASCII. For our example, let's say that the input was STATUS

Convert each character to its hexadecimal representation. This would convert STATUS to 53 54 41 54 55 53.

Print out or return the consecutive degree turns the camera will need to make in order to point at each card and return to the "Question Card". For our example, this would be:

6  * 21 = 126   (?-5)
-2 * 21 = -42   (5-3)
2  * 21 = 42    (3-5)
-1 * 21 = -21   (5-4)
0  * 21 = 0     (4-4)
-3 * 21 = -63   (4-1)
4  * 21 = 84    (1-5)
-1 * 21 = -21   (5-4)
1  * 21 = 21    (4-4)
0  * 21 = 0     (5-5)
0  * 21 = 0     (5-5)
-2 * 21 = -42   (5-3)
-4 * 21 = -84   (3-?)
Or, in array format:

[126, -42, 42, -21, 0, -63, 84, -21, 21, 0, 0, -42, -84]
Note that you must always take the smallest of the possible rotations. So if the input was NO, which is 4E 4F, you should output:

5    * 21 = 105
-7   * 21 = -147
7    * 21 = 147
-6   * 21 = -126
1    * 21 = 21
Rather than:

 5   * 21 = 105
 10  * 21 = 210
 -10 * 21 = -210
 11  * 21 = 231
 -16 * 21 = -336
Here are some more worked examples:

Input: CROPS?
ASCII: 43 52 4F 50 53 3F
Worked Example:

5  * 21 = 105
-1 * 21 = -21
2  * 21 = 42
-3 * 21 = -63
2  * 21 = 42
-6 * 21 = -126
7  * 21 = 147
-5 * 21 = -105
5  * 21 = 105
-2 * 21 = -42
0  * 21 = 0
-5  * 21 = -105
1 * 21 = 21

Result: [105 -21 42 -63 42 -126 147 -105 105 -42 0 -105 21]


Input: DDD
ASCII: 44 44 44
Worked Example:

5   * 21 = 105
0   * 21 = 0
0   * 21 = 0
0   * 21 = 0
0   * 21 = 0
0   * 21 = 0
-5  * 21 = -105

Result: [105, 0, 0, 0, 0, 0, -105]


Input: Hello world!
ASCII: 48 65 6c 6c 6f 20 77 6f 72 6c 64 21
Worked example:

5   * 21 = 105
4   * 21 = 84
-2  * 21 = -42
-1  * 21 = -21
1   * 21 = 21
6   * 21 = 126
-6  * 21 = -126
6   * 21 = 126
-6  * 21 = -126
-8  * 21 = -168
4   * 21 = 84
-2  * 21 = -42
7   * 21 = 147
0   * 21 = 0
-1  * 21 = -21
-8  * 21 = -168
-8  * 21 = -168
-5  * 21 = -105
4   * 21 = 84
6   * 21 = 126
-6  * 21 = -126
-2  * 21 = -42
-2  * 21 = -42
-1  * 21 = -21
-2  * 21 = -42

Result: [105 84 -42 -21 21 126 -126 126 -126 -168 84 -42 147 0 -21 -168 -168 -105 84 126 -126 -42 -42 -21 -42]
Since NASA prides itself on efficiency, your goal is to write the shortest code possible. Standard loopholes apply. Now bring him home!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

int
move(int *x, int xn)
{
	int d0, d1, d;

	if (*x < xn) {
		d0 = xn - *x;
		d1 = mod(*x - xn, 17);
	} else {
		d0 = mod(xn - *x, 17);
		d1 = *x - xn;
	}
	*x = xn;

	d = (d0 < d1) ? d0 : -d1;
	return d * 21;
}

size_t
rotations(const char *s, int *r)
{
	size_t i, n;
	int x;

	x = 0;
	for (i = n = 0; s[i]; i++) {
		r[n++] = move(&x, ((s[i] >> 4) & 0xf) + 1);
		r[n++] = move(&x, (s[i] & 0xf) + 1);
	}
	r[n++] = move(&x, 0);
	return n;
}

void
test(const char *s, int *r, size_t nr)
{
	int p[128];
	size_t np;

	np = rotations(s, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	int r1[] = {126, -42, 42, -21, 0, -63, 84, -21, 21, 0, 0, -42, -84};
	int r2[] = {105, -147, 147, -126, 21};
	int r3[] = {105, -21, 42, -63, 42, -126, 147, -105, 105, -42, 0, -105, 21};
	int r4[] = {105, 0, 0, 0, 0, 0, -105};
	int r5[] = {105, 84, -42, -21, 21, 126, -126, 126, -126, -168, 84, -42, 147, 0, -21, -168, -168, -105, 84, 126, -126, -42, -42, -21, -42};

	test("STATUS", r1, nelem(r1));
	test("NO", r2, nelem(r2));
	test("CROPS?", r3, nelem(r3));
	test("DDD", r4, nelem(r4));
	test("Hello world!", r5, nelem(r5));

	return 0;
}
