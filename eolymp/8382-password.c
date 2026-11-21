/*

We call a password crypto-stable if 5 criteria are satisfied:

The password contains lowercase Latin letters.

The password contains uppercase Latin letters.

The password contains digits.

The password contains at least one of the following symbols: ! " # $ % & ' ( ) * +

The length of the password is not less than 8 characters.

Given a password consisting only of Latin letters, digits, and the specified symbols, determine how many of the crypto stability criteria are satisfied by this password.

Input
The input consists of a single line containing no more than 100 characters. The line contains only Latin letters (uppercase and lowercase), digits, and the specified symbols.

Output
Print the number of crypto stability criteria satisfied by the password.

Examples

Input #1
1aA

Answer #1
3

Input #2
AaBbCc12

Answer #2
4

Input #3
AAAaaaAAA

Answer #3
3

Input #4
#Abc23$$$

Answer #4
5

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

int
score(const char *password)
{
	size_t length;
	unsigned mask;

	mask = 0;
	for (length = 0; password[length]; length++) {
		switch (password[length]) {
		case 'a' ... 'z':
			mask |= 0x1;
			break;

		case 'A' ... 'Z':
			mask |= 0x2;
			break;

		case '0' ... '9':
			mask |= 0x4;
			break;

		case '!':
		case '"':
		case '#':
		case '$':
		case '%':
		case '&':
		case '\'':
		case '(':
		case ')':
		case '*':
		case '+':
			mask |= 0x8;
			break;
		}
	}
	if (length >= 8)
		mask |= 0x10;

	return stdc_count_ones(mask);
}

int
main()
{
	assert(score("1aA") == 3);
	assert(score("AaBbCc12") == 4);
	assert(score("AAAaaaAAA") == 3);
	assert(score("#Abc23$$$") == 5);

	return 0;
}
