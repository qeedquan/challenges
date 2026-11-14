/*

Introduction:
Inspired by this comment of @MagicOctopusUrn on @Emigna's 05AB1E answer for my "It was just a bug" challenge:

8F9ÝÀNð×ý}».∊ I done did made a spaceship maw! And I was all excited about suggesting a 12-byte edit. – Magic Octopus Urn Jul 17 '17 at 20:10

Which is a 05AB1E (legacy) program resulting in this:

1234567890
1 2 3 4 5 6 7 8 9 0
1  2  3  4  5  6  7  8  9  0
1   2   3   4   5   6   7   8   9   0
1    2    3    4    5    6    7    8    9    0
1     2     3     4     5     6     7     8     9     0
1      2      3      4      5      6      7      8      9      0
1       2       3       4       5       6       7       8       9       0
1      2      3      4      5      6      7      8      9      0
1     2     3     4     5     6     7     8     9     0
1    2    3    4    5    6    7    8    9    0
1   2   3   4   5   6   7   8   9   0
1  2  3  4  5  6  7  8  9  0
1 2 3 4 5 6 7 8 9 0
1234567890
Try it online.

Challenge:
Input: A non-empty string

Output: From outwards going inwards, add one more space between each character every line, similar as done in the output above, equal to the length - 1. So for an input 1234567890 the output would actually be this instead:

1234567890
1 2 3 4 5 6 7 8 9 0
1  2  3  4  5  6  7  8  9  0
1   2   3   4   5   6   7   8   9   0
1    2    3    4    5    6    7    8    9    0
1     2     3     4     5     6     7     8     9     0
1      2      3      4      5      6      7      8      9      0
1       2       3       4       5       6       7       8       9       0
1        2        3        4        5        6        7        8        9        0
1         2         3         4         5         6         7         8         9         0
1        2        3        4        5        6        7        8        9        0
1       2       3       4       5       6       7       8       9       0
1      2      3      4      5      6      7      8      9      0
1     2     3     4     5     6     7     8     9     0
1    2    3    4    5    6    7    8    9    0
1   2   3   4   5   6   7   8   9   0
1  2  3  4  5  6  7  8  9  0
1 2 3 4 5 6 7 8 9 0
1234567890
Why? The length of 1234567890 is 10. So we start by outputting 10 lines: the first line without spaces; second with one space delimiter; third with two; etc. And then (without have the middle line with length - 1 spaces duplicated), we go back to the initial input while going down.

Challenge rules:
Input is guaranteed to be non-empty (a length >= 1). (For single char inputs we simply output that character.)
Any amount of trailing/leading spaces/newlines are allowed, as long as the output itself (wherever on the screen) is correct. (Empty line(s) in between output lines also isn't allowed.)
Input will only contain printable ASCII characters excluding whitespaces (code-point range [33, 126])
I/O is flexible. Input may be taken as STDIN, argument, or function parameter. May be a list/array/stream of characters instead of string. Output may also be a list/array/stream of characters instead of strings; may be printed to STDOUT; returned as newline-delimited string; etc.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, adding an explanation for your answer is highly recommended.
Test cases:
Input: @
Output:
@

Input: test
Output:
test
t e s t
t  e  s  t
t   e   s   t
t  e  s  t
t e s t
test

Input: ?!
Output:
?!
? !
?!

Input: Spaceship
Output:
Spaceship
S p a c e s h i p
S  p  a  c  e  s  h  i  p
S   p   a   c   e   s   h   i   p
S    p    a    c    e    s    h    i    p
S     p     a     c     e     s     h     i     p
S      p      a      c      e      s      h      i      p
S       p       a       c       e       s       h       i       p
S        p        a        c        e        s        h        i        p
S       p       a       c       e       s       h       i       p
S      p      a      c      e      s      h      i      p
S     p     a     c     e     s     h     i     p
S    p    a    c    e    s    h    i    p
S   p   a   c   e   s   h   i   p
S  p  a  c  e  s  h  i  p
S p a c e s h i p
Spaceship

Input: 05AB1E
Output:
05AB1E
0 5 A B 1 E
0  5  A  B  1  E
0   5   A   B   1   E
0    5    A    B    1    E
0     5     A     B     1     E
0    5    A    B    1    E
0   5   A   B   1   E
0  5  A  B  1  E
0 5 A B 1 E
05AB1E

Input: )}/\
Output:
)}/\
) } / \
)  }  /  \
)   }   /   \
)  }  /  \
) } / \
)}/\

*/

#include <stdio.h>
#include <string.h>

void
line(const char *s, size_t p)
{
	size_t i, j;

	for (i = 0; s[i]; i++) {
		printf("%c", s[i]);
		if (s[i + 1]) {
			for (j = 0; j < p; j++)
				printf(" ");
		}
	}
	printf("\n");
}

void
spaceship(const char *s)
{
	size_t i, n;

	n = strlen(s);
	if (n == 0)
		goto nl;

	for (i = 0; i < n; i++)
		line(s, i);
	for (i = n - 1; i > 0; i--)
		line(s, i - 1);
nl:
	printf("\n");
}

int
main(void)
{
	spaceship("1234567890");
	spaceship("@");
	spaceship("test");
	spaceship("?!");
	spaceship("Spaceship");
	spaceship("05AB1E");
	spaceship(")}/\\");

	return 0;
}
