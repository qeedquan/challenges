/*

A Munchausen Number in base b, also known as a Perfect digit-to-digit invariant or PDDI is a
peculiar type of positive integer where the sum of its base-b digits raised to themselves is equal to the number itself.
They are named for the fictional Baron Munchausen, who apparently hoisted himself up via his own ponytail to save himself from drowning.
A related concept is Narcissistic numbers.

For instance, 1 is trivially a Munchausen number in every base because 11=1.
Additionally, every positive integer is a base-1 Munchausen number by definition.

More interestingly, 3435 is a base-10 Munchausen number because 33+44+33+55=3435, and in fact is the only other base-10 Munchausen number.

A partial list of Munchausen numbers in every base up to 35 can be found on the OEIS as sequence A166623.

Given a positive integer n>0, determine if it is a Munchausen number in any base b≥2.

Rules
Default I/O rules apply, so:
Full program or functions are acceptable.
Input can be from STDIN, as a function argument, and output can be to STDOUT, as a function return value, etc.
Default loopholes apply.
The output must be one of two distinct, consistent results. So TRUE is fine for truthy and FALSE is fine for falsy, but you can reverse that or return None for truthy and 1 for falsy or whatever. Please specify the selected results in your answer.
Your answer has to work at least theoretically for any positive integer.
Munchausen numbers use the convention 00=1, so 2 is a base-2 Munchausen number as 11+00=2.
Your code must follow this convention.
Explanations are strongly encouraged, even though submissions will most likely use the brute-force search method.
Using esoteric languages earns you brownie points since Munchausen was apparently a strange person.

Test Cases
Truthy
1 (all bases)
2 (base 2)
5 (base 3)
28 (base 9 and base 25)
29 (base 4)
55 (base 4)
3435 (base 10)
923362 (base 9)
260 (base 128)
257 (base 64 and base 253)

Falsy
3
4
591912
3163
17

This is code-golf, so the shortest answer in each language (in bytes) wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A166623 (related)
bool
munchausen(vlong n)
{
	vlong i, j, s;

	if (n < 1)
		return false;
	if (n == 1)
		return true;

	for (i = 2; i <= n; i++) {
		s = 0;
		for (j = n; j > 0; j /= i)
			s += pow(j % i, j % i);
		if (s == n)
			return true;
	}
	return false;
}

int
main()
{
	static const vlong truthy[] = {
		1,
		2,
		5,
		28,
		29,
		55,
		3435,
		923362,
		260,
		257,
	};

	static const vlong falsy[] = {
		3,
		4,
		591912,
		3163,
		17,
	};

	size_t i;

	for (i = 0; i < nelem(truthy); i++)
		assert(munchausen(truthy[i]) == true);

	for (i = 0; i < nelem(falsy); i++)
		assert(munchausen(falsy[i]) == false);

	return 0;
}
