/*

Math hasn"t always been your best subject, and these programming symbols always trip you up! I mean, does ** mean "Times, Times" or "To the power of"? Luckily, you can create the function to write out the expressions for you!

The operators you"ll need to use are:

"+"   -->  "Plus"
"-"   -->  "Minus"
"*"   -->  "Times"
"/"   -->  "Divided By"
"**"  -->  "To The Power Of"
"="   -->  "Equals"
"!="  -->  "Does Not Equal"
Notes:

the input will always be given as a string, in the following format: number space operator space number; for example: "1 + 3" or "2 - 10"
the numbers used will be 1 to 10
the valid operators and the relevant texts are stored in the preloaded dictionary/hash OPERATORS
invalid operators will also be tested, to which you should return "That"s not an operator!"
Examples
"4 ** 9"  -->  "Four To The Power Of Nine"
"10 - 5"  -->  "Ten Minus Five"
"2 = 2"   -->  "Two Equals Two"
"2 x 3"   -->  "That"s not an operator!"
Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
expr(const char *s, char *b)
{
	static const char *ops[][2] = {
		{ "+", "Plus" },
		{ "-", "Minus" },
		{ "*", "Times" },
		{ "/", "Divided By" },
		{ "**", "To The Power Of" },
		{ "=", "Equals" },
		{ "!=", "Does Not Equal" },
	};

	static const char *nums[] = {
		"Zero", "One", "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten"
	};

	char op[4];
	int x, y;
	size_t i;

	if (sscanf(s, "%d %3s %d", &x, op, &y) != 3)
		goto error;
	if (x < 0 || x > 10 || y < 0 || y > 10)
		goto error;

	for (i = 0; i < nelem(ops); i++) {
		if (!strcmp(op, ops[i][0]))
			break;
	}
	if (i == nelem(ops))
		goto error;

	sprintf(b, "%s %s %s", nums[x], ops[i][1], nums[y]);

	if (0) {
	error:
		sprintf(b, "That\"s not an operator!");
	}

	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	assert(expr(s, b));
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("1 + 3", "One Plus Three");
	test("2 - 10", "Two Minus Ten");
	test("6 ** 9", "Six To The Power Of Nine");
	test("5 = 5", "Five Equals Five");
	test("7 * 4", "Seven Times Four");
	test("2 / 2", "Two Divided By Two");
	test("8 != 5", "Eight Does Not Equal Five");

	return 0;
}
