/*

This task provides practice for core property of remainder taking operation in arithmetic - persisting of the remainder over addition and multiplication. This important property is often used for checking results of calculations, in competitive programming, in calculation checksums and especially for encryption.
See Modular arithmetic for thorough explanations.

We have a kind of long arithmetic calculation here, and we are asked about the result modulo some number (result % M in many languages).

If you are curious why modular arithmetic is that important, you can see Public Key Cryptography Intro and RSA Cryptography exercises.

Input data will have:

initial integer number in the first line;
one or more lines describing operations, in form sign value where sign is either + or * and value is an integer;
last line in the same form, but with sign % instead and number by which the result should be divided to get the remainder.
Answer should give remainder of the result of all operations applied sequentially (starting with initial number) divided by the last number.

If you have troubles with this problem, please feel free to type its name in the "Search" box in the top menu and find relevant topics at our forum - probably you will get enough enlightenment from there.

Example:

input data:
5
+ 3
* 7
+ 10
* 2
* 3
+ 1
% 11

answer:
1
In this case result after all operations applied sequentially is 397.

All numbers will not exceed 10000 (though intermediate results could be very large).

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
binop(int op, int x, int y)
{
	switch (op) {
	case '+':
		x += y;
		break;
	case '-':
		x -= y;
		break;
	case '*':
		x *= y;
		break;
	case '/':
		if (y)
			x /= y;
		break;
	case '%':
		if (y)
			x %= y;
		break;
	}
	return x;
}

int
calc(const char **ops, size_t nops)
{
	size_t i;
	int acc;
	int val;
	char op;

	acc = 0;
	for (i = 0; i < nops; i++) {
		if (sscanf(ops[i], "%d", &val) == 1)
			acc = val;
		else if (sscanf(ops[i], "%c %d", &op, &val) == 2)
			acc = binop(op, acc, val);
	}
	return acc;
}

int
main()
{
	const char *ops[] = {
		"5",
		"+ 3",
		"* 7",
		"+ 10",
		"* 2",
		"* 3",
		"+ 1",
		"% 11",
	};

	assert(calc(ops, nelem(ops)) == 1);

	return 0;
}
