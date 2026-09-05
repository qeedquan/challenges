/*

The code on this site is rapidly being depleted. We need to invest in renewable strings. So you must write a program that takes a string and converts it into a windmill.

The Challenge
Let's take a simple wind-mill string as an example. Take the string abc. The pivot is the center character, in this case b. Since the string is 3 chars long, every output will be exactly three lines tall and three characters wide. Here is your output on step 1. (Note the whitespace)


abc

To get the next step, rotate each character around the pivot clockwise. Here is step 2:

a
 b
  c
Here are steps 3-8:

 a
 b
 c
  a
 b
c

cba

c
 b
  a
 c
 b
 a
  c
 b
a
And on the ninth step, it comes around full circle to the original string:


abc

Note that the b stayed in the same spot the whole time. This is because b is the pivot character. You must write a program or function that takes a string as input and repeatedly prints out this sequence until the program is closed.

Clarifications
All input strings will have an odd number of characters. (So that every windmill will have a pivot)

To keep the challenge simple, all strings will only contain upper and lowercase alphabet characters.

The output must be len(input_string) characters wide and tall.

It doesn't matter which step of the sequence you start on, just as long as you continue rotating and looping forever.

More Test IO:
Since the post is already pretty long, here is a link to the output for "windmill":

Sidenote:
Since this is supposed to be a windmill, it would be awesome if you include some boilerplate code to animate it with a small time delay or a user input between each step. However, since some languages don't have time builtins, this is not mandatory. The competing part of your submission can just print the sequence as fast as possible.

*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef int (*fn)(const char *, size_t, size_t, size_t);

void
clear()
{
	printf("\033c");
}

int
north(const char *s, size_t n, size_t x, size_t y)
{
	if (y != n / 2)
		return ' ';
	return s[x];
}

int
northeast(const char *s, size_t, size_t x, size_t y)
{
	if (x != y)
		return ' ';
	return s[x];
}

int
east(const char *s, size_t n, size_t x, size_t y)
{
	if (x != n / 2)
		return ' ';
	return s[y];
}

int
southeast(const char *s, size_t n, size_t x, size_t y)
{
	if (x != n - y - 1)
		return ' ';
	return s[n - x - 1];
}

int
south(const char *s, size_t n, size_t x, size_t y)
{
	if (y != n / 2)
		return ' ';
	return s[n - x - 1];
}

int
southwest(const char *s, size_t n, size_t x, size_t y)
{
	if (x != y)
		return ' ';
	return s[n - x - 1];
}

int
west(const char *s, size_t n, size_t x, size_t y)
{
	if (x != n / 2)
		return ' ';
	return s[n - y - 1];
}

int
northwest(const char *s, size_t n, size_t x, size_t y)
{
	if (x != n - y - 1)
		return ' ';
	return s[x];
}

void
paint(fn f, const char *s, size_t n)
{
	size_t x, y;

	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++)
			printf("%c", f(s, n, x, y));
		printf("\n");
	}
}

void
windmill(const char *s)
{
	static const fn f[] = {north, northeast, east, southeast, south, southwest, west, northwest};
	struct timespec t;
	size_t i, n;

	t.tv_nsec = 100000000L;
	t.tv_sec = 0;
	n = strlen(s);
	for (i = 0; i < nelem(f); i++) {
		clear();
		paint(f[i], s, n);
		thrd_sleep(&t, NULL);
	}
}

int
main()
{
	for (;;)
		windmill("abc");
	return 0;
}
