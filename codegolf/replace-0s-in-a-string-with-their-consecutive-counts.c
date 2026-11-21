/*

Challenge
Given a string s of any length which contains only digits from 0 to 9 replace each consecutive run of the digit 0 with its length.

Test Cases
1. string = '1234500362000440' output = '1234523623441'
2. string = '123450036200044'  output = '123452362344'
3. string = '000000000000'     output = '12'
4. string = '0123456789'       output = '1123456789'
5. string = '1234567890'       output = '1234567891'
6. string = '123456789'        output = '123456789'
7. string = '010203004050'     output = '11121324151'

Note
The shortest answer in bytes wins as per code-golf rules

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
construct(const char *s, char *b)
{
	size_t i, j;
	size_t c;

	for (i = j = 0; s[i]; i++) {
		if (s[i] != '0')
			b[j++] = s[i];
		else {
			for (c = 1; s[i + 1] == '0'; i++)
				c++;
			j += sprintf(b + j, "%zu", c);
		}
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	construct(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1234500362000440", "1234523623441");
	test("123450036200044", "123452362344");
	test("000000000000", "12");
	test("0123456789", "1123456789");
	test("1234567890", "1234567891");
	test("123456789", "123456789");
	test("010203004050", "11121324151");

	return 0;
}
