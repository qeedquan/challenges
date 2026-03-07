/*

This challenge is highly "distilled" from this question. Special thanks to @Akababa!

In this task, you should insert an exclamation mark at the start of the string and after every character.

Rules
There will always be a non-empty-string input. The input will not contain tabs either. You can assume that the input only contain non-extended ASCII printable characters and newlines.
The input will not contain trailing newlines as long as your language can't detect a newline.
This is a code-golf contest; the shortest answer should win.
Examples
4 newlines result in 5 newline-delimited exclamation marks. It is very hard to put this as a Markdown text, so this is stated instead.
1 2 3 4 5 6
129591 129012 129127 129582

0
Outputs

!1! !2! !3! !4! !5! !6!
!1!2!9!5!9!1! !1!2!9!0!1!2! !1!2!9!1!2!7! !1!2!9!5!8!2!
!
!0!
asd afjoK ak:e
kPrLd
    fOJOE;
    KFO
KFkepjgop sgpaoj   faj
Outputs

!a!s!d! !a!f!j!o!K! !a!k!:!e!
!k!P!r!L!d!
! ! ! ! !f!O!J!O!E!;!
! ! ! ! !K!F!O!
!K!F!k!e!p!j!g!o!p! !s!g!p!a!o!j! ! ! !f!a!j!
A base test case with only one character:

a
Outputs

!a!
(Auto-completion! Just kidding, there is no such thing.) Contains exclamation marks:

!!
!!
!!
!!
!!
Outputs:

!!!!!
!!!!!
!!!!!
!!!!!
!!!!!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
exclaim(const char *s, char *b)
{
	size_t i, j;

	j = 0;
	b[j++] = '!';
	for (i = 0; s[i]; i++) {
		b[j++] = s[i];
		b[j++] = '!';
	}

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	exclaim(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1 2 3 4 5 6", "!1! !2! !3! !4! !5! !6!");
	test("129591 129012 129127 129582", "!1!2!9!5!9!1! !1!2!9!0!1!2! !1!2!9!1!2!7! !1!2!9!5!8!2!");
	test("", "!");
	test("0", "!0!");
	test("asd afjoK ak:e", "!a!s!d! !a!f!j!o!K! !a!k!:!e!");
	test("kPrLd", "!k!P!r!L!d!");
	test("    fOJOE;", "! ! ! ! !f!O!J!O!E!;!");
	test("    KFO", "! ! ! ! !K!F!O!");
	test("KFkepjgop sgpaoj   faj", "!K!F!k!e!p!j!g!o!p! !s!g!p!a!o!j! ! ! !f!a!j!");
	test("a", "!a!");
	test("!!", "!!!!!");

	return 0;
}
