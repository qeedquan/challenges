/*

Challenge
Given an integer n (where 4<=n<=10**6) as input create an ASCII art "prison door"* measuring n-1 characters wide and n characters high, using the symbols from the example below.

Example
╔╦╗
╠╬╣
╠╬╣
╚╩╝
The characters used are as follows:

┌───────────────┬─────────┬───────┐
│ Position      │ Symbol  │ Char  │
├───────────────┼─────────┼───────┤
│ Top Left      │    ╔    │ 9556  │
├───────────────┼─────────┼───────┤
│ Top           │    ╦    │ 9574  │
├───────────────┼─────────┼───────┤
│ Top Right     │    ╗    │ 9559  │
├───────────────┼─────────┼───────┤
│ Right         │    ╣    │ 9571  │
├───────────────┼─────────┼───────┤
│ Bottom Right  │    ╝    │ 9565  │
├───────────────┼─────────┼───────┤
│ Bottom        │    ╩    │ 9577  │
├───────────────┼─────────┼───────┤
│ Bottom Left   │    ╚    │ 9562  │
├───────────────┼─────────┼───────┤
│ Left          │    ╠    │ 9568  │
├───────────────┼─────────┼───────┤
│ Inner         │    ╬    │ 9580  │
└───────────────┴─────────┴───────┘
Rules
You may take input by any reasonable, convenient means as long as it's permitted by standard I/O rules.
For the purposes of this challenge, in languages where the symbols used to build the "door" are multi-byte characters, they may be counted towards your score as a single byte each.
All other characters (single- or multi-byte) should be counted as normal.
Output may not contain any trailing spaces but a trailing newline is permitted if absolutely necessary.
This is code-golf so lowest byte count wins.
Test Cases
Input: 4
Output:
╔╦╗
╠╬╣
╠╬╣
╚╩╝

Input: 8
Output:
╔╦╦╦╦╦╗
╠╬╬╬╬╬╣
╠╬╬╬╬╬╣
╠╬╬╬╬╬╣
╠╬╬╬╬╬╣
╠╬╬╬╬╬╣
╠╬╬╬╬╬╣
╚╩╩╩╩╩╝

Input: 20
Output:
╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╠╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╣
╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝
* Yes, I'm aware that the bigger it gets the less it looks like a prison door! :D

*/

#include <stdio.h>

void
append(char *b, size_t *l, const unsigned char *s)
{
	*l += sprintf(b + *l, "%s", s);
}

char *
jailhouse(int n, char *b)
{
	size_t l;
	int i, j;

	*b = '\0';
	if (n < 4)
		return b;

	n -= 3;
	l = 0;
	append(b, &l, u8"╔");
	for (i = 0; i < n; i++)
		append(b, &l, u8"╦");
	append(b, &l, u8"╗\n");

	for (i = 0; i <= n; i++) {
		append(b, &l, u8"╠");
		for (j = 0; j < n; j++)
			append(b, &l, u8"╬");
		append(b, &l, u8"╣\n");
	}
	append(b, &l, u8"╚");
	for (i = 0; i < n; i++)
		append(b, &l, u8"╩");
	append(b, &l, u8"╝");

	return b;
}

void
test(int n)
{
	char b[4096];

	jailhouse(n, b);
	printf("n=%d\n%s\n", n, b);
}

int
main(void)
{
	test(4);
	test(8);
	test(20);

	return 0;
}
