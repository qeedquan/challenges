/*

Given a string containing only the characters -, |, + and newline determine the longest straight line contained in it. A straight line is either an uninterupted run of -s and +s in a single row or an uninterupted run of |s and +s in a single column.

So for example:

    |
    |  ----
    |
  --+--
    |
    |
There are 3 lines here one vertical, two horizontal, with the vertical line being the longest since it is 6 characters.

Your challenge is to write a program or function which takes a string as input and gives the length of the longest line.

You may assume that the input is perfectly rectangular. That is that every row has the same number of characters. You may also assume that the input contains at least 1 of the non-whitespace characters (-, |, and +).

This is code-golf, answers will be scored in bytes with fewer bytes being the goal.

Test cases
    |
    |  ----
    |
  --+--
    |
    |
6


    +


1

 ---|---
    |
    |
    |
4

-
-|||||
-
1

   |
   |

+----+
6

 |+-
-+|
2

   |
   |
   |
   |  +
      |
   |  |
   |
   |  |

+-+
4

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
max(size_t a, size_t b)
{
	return (a > b) ? a : b;
}

size_t
measure(const char **s, size_t x, size_t y, size_t w, size_t h)
{
	size_t n, m;
	size_t i;

	n = 0;
	for (i = x; i < w && (s[y][i] == '+' || s[y][i] == '-'); i++)
		n += 1;

	m = 0;
	for (i = y; i < h && (s[i][x] == '+' || s[i][x] == '|'); i++)
		m += 1;

	return max(n, m);
}

size_t
longest(const char **s, size_t w, size_t h)
{
	size_t x, y, l;

	l = 0;
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			l = max(l, measure(s, x, y, w, h));
	}
	return l;
}

int
main()
{
	const char *s1[] = {
		"    |      ",
		"    |  ----",
		"    |      ",
		"  --+--    ",
		"    |      ",
		"    |      ",
	};

	const char *s2[] = {
		"+",
	};

	const char *s3[] = {
		" ---|---",
		"    |   ",
		"    |   ",
		"    |   ",

	};

	const char *s4[] = {
		"-     ",
		"-|||||",
		"-     ",
	};

	const char *s5[] = {
		"   |  ",
		"   |  ",
		"      ",
		"+----+",
	};

	const char *s6[] = {
		" |+-",
		"-+| ",
	};

	const char *s7[] = {
		"   |    ",
		"   |    ",
		"   |    ",
		"   |  + ",
		"      | ",
		"   |  | ",
		"   |    ",
		"   |  | ",
		"        ",
		"+-+     ",
	};

	assert(longest(s1, strlen(s1[0]), nelem(s1)) == 6);
	assert(longest(s2, strlen(s2[0]), nelem(s2)) == 1);
	assert(longest(s3, strlen(s3[0]), nelem(s3)) == 4);
	assert(longest(s4, strlen(s4[0]), nelem(s4)) == 1);
	assert(longest(s5, strlen(s5[0]), nelem(s5)) == 6);
	assert(longest(s6, strlen(s6[0]), nelem(s6)) == 2);
	assert(longest(s7, strlen(s7[0]), nelem(s7)) == 4);

	return 0;
}
