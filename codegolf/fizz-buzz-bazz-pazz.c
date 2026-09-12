/*

Fizz-Buzz-Bazz-Pazz
Problem Summary
Write a program that prints numbers from 1 to 100 with replacements based on the following rules:

Word	Condition	Examples
Fizz	Multiple of 3	3 → "Fizz"
Buzz	Multiple of 7	7 → "Buzz"
Bazz	Multiple of 5	5 → "Bazz"
Pazz	Multiple of 10	10 → "Pazz"
Note: If no rules apply, print the number itself.

Key Requirements
Concatenate ALL matching words in this exact order:
Fizz → Buzz → Bazz → Pazz
(e.g., 21 → FizzBuzz, 35 → BuzzBazz, 30 → FizzBazzPazz)
Forbidden: No hardcoded string literals (Fizz, Buzz, Bazz, Pazz) in your code.
Expected Output (First 15 Lines)
1
2
Fizz
4
Bazz
Fizz
Buzz
8
Fizz
BazzPazz
11
Fizz
13
Buzz
FizzBazz
Edge Case Examples
Number	Output	Reason
70	BuzzBazzPazz	7×10 (Buzz + Pazz), also +Bazz because it is a multiple of 5, namely 5 × 14
30	FizzBazzPazz	3×5×10 (Three of the 4 words, not divisible by 7)
Scoring System
This is code-golf, so shortest code in bytes wins (per language).

*/

#include <assert.h>
#include <stdio.h>

char *
nonsense(unsigned n, char *b)
{
	char *p;

	p = b;
	if (!(n % 3))
		p += sprintf(p, "Fizz");
	if (!(n % 7))
		p += sprintf(p, "Buzz");
	if (!(n % 5))
		p += sprintf(p, "Bazz");
	if (!(n % 10))
		p += sprintf(p, "Pazz");
	if (p == b)
		sprintf(p, "%u", n);
	return b;
}

int
main()
{
	unsigned i;
	char b[32];

	for (i = 0; i <= 100; i++)
		printf("%u %s\n", i, nonsense(i, b));
	return 0;
}
