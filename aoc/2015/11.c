/*

--- Day 11: Corporate Policy ---
Santa's previous password expired, and he needs help choosing a new one.

To help him remember his new password after the old one expires, Santa has devised a method of coming up with a password based on the previous one. Corporate policy dictates that passwords must be exactly eight lowercase letters (for security reasons), so he finds his new password by incrementing his old password string repeatedly until it is valid.

Incrementing is just like counting with numbers: xx, xy, xz, ya, yb, and so on. Increase the rightmost letter one step; if it was z, it wraps around to a, and repeat with the next letter to the left until one doesn't wrap around.

Unfortunately for Santa, a new Security-Elf recently started, and he has imposed some additional password requirements:

Passwords must include one increasing straight of at least three letters, like abc, bcd, cde, and so on, up to xyz. They cannot skip letters; abd doesn't count.
Passwords may not contain the letters i, o, or l, as these letters can be mistaken for other characters and are therefore confusing.
Passwords must contain at least two different, non-overlapping pairs of letters, like aa, bb, or zz.
For example:

hijklmmn meets the first requirement (because it contains the straight hij) but fails the second requirement requirement (because it contains i and l).
abbceffg meets the third requirement (because it repeats bb and ff) but fails the first requirement.
abbcegjk fails the third requirement, because it only has one double letter (bb).
The next password after abcdefgh is abcdffaa.
The next password after ghijklmn is ghjaabcc, because you eventually skip all the passwords that start with ghi..., since i is not allowed.
Given Santa's current password (your puzzle input), what should his next password be?

--- Part Two ---
Santa's password expired again. What's the next one?

*/

#include <stdio.h>

void
next(char *s, size_t i)
{
	if (i > 0 && s[i] == 'z') {
		s[i] = 'a';
		next(s, i - 1);
	} else
		s[i] += 1;
}

bool
straight3(char *s, size_t n)
{
	size_t i;
	int c;

	c = 0;
	for (i = 1; i < n; i++) {
		if (s[i - 1] == s[i] - 1) {
			c += 1;
			if (c == 3)
				return true;
		} else
			c = 1;
	}
	return false;
}

bool
noiol(char *s, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		switch (s[i]) {
		case 'i':
		case 'o':
		case 'l':
			return false;
		}
	}
	return true;
}

bool
doublepair(char *s, size_t n)
{
	int p;
	bool f;
	size_t i;

	f = true;
	p = 0;
	for (i = 1; i < n; i++) {
		if (s[i - 1] == s[i]) {
			if (f) {
				p += 1;
				if (p == 2)
					return true;
			}
			f = !f;
		} else
			f = true;
	}
	return false;
}

void
solve(char *s, size_t n)
{
	if (n == 0)
		return;

	for (;;) {
		next(s, n - 1);
		if (straight3(s, n) && noiol(s, n) && doublepair(s, n))
			break;
	}
}

int
main()
{
	char s[] = "hxbxwxba";
	int i;

	for (i = 0; i < 2; i++) {
		solve(s, sizeof(s) - 1);
		puts(s);
	}

	return 0;
}
