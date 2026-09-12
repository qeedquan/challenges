/*

Challenge:
There's a silly puzzle circulating on social networks that reads:

8 + 2 = 16106
5 + 4 = 2091
9 + 6 = ?
Implement a function or operator that, when given two positive integer numbers x and y such that x > y > 0, yields the correct answer as an integer, where the answer's digits are the digits of x * y followed by the digits of x + y followed by the digits of x - y. Very simple.

Rules:
Standard loopholes are disallowed.
This is code-golf so shortest code in bytes wins.
Input data validation is not required. This program may crash or return garbage when given invalid input.
You're allowed to use numeric functions and operators (including integer and floating point, math library functions, and other functions that accept and return numbers).
You're allowed to use a function that returns the number of digits of a number, if applicable.
You're not allowed to use strings or any kind of concatenation anywhere in your code.
The result may be returned or pushed to the stack, whichever applies in the language. The result must be an integer number, not a string.
Sample code:
Dyalog APL:

The following code creates a dyadic operator named X.

X←{(⍺-⍵)+((⍺+⍵)×10*1+⌊10⍟⍺-⍵)+⍺×⍵×10*(2+⌊10⍟⍺+⍵)+⌊10⍟⍺-⍵}

Explanation:

In APL, you evaluate from right to left.

⍺ and ⍵ are the left and right operand, respectively

⌊10⍟⍺-⍵ reads: floor of log10(⍺-⍵). First performs substraction then logarithm then floor. From right to left. log10 is done in order to count the digits of ⍺-⍵ (you must sum 1 afterwards).

⍺×⍵×10*(...) reads: 10 to the (...)th power, multiplied by ⍵, multiplied by ⍺

Hence, ⍺×⍵×10*(2+⌊10⍟⍺+⍵)+⌊10⍟⍺-⍵ is the product, shifted to the left by the sum of the number of digits of the sum and the difference. Multiplying by a power of 10 will shift an integer to the left.

((⍺+⍵)×10*1+⌊10⍟⍺-⍵) is the sum, shifted to the left by the number of digits of the difference.

(⍺-⍵) is the difference. No shifting is necessary here.

X←{...} is how you define an operator in APL.

Examples:

      8 X 2
16106
      5 X 4
2091
      9 X 6
54153
GNU dc:

The following code creates a macro named a:

[sysx10lxly-dseZdsclxly+dsd+Z1+^lxly**10lc^ld*+le+]sa
Explanation:

sx and sy pop an element from the stack and save it on the registers x and y, respectively.

lx and ly load an element from registers x and y respectively and push it to the stack.

d duplicates the last element in the stack.

^ computes the power of two numbers.

Z pops a number and returns its number of digits. This is done because dc has no logarithm function.

[...]sa stores a macro in register a. la loads it. x executes the macro at the top of the stack.

Examples:

8 2 laxn
16106
5 4 laxn
2091
9 6 laxn
54153

*/

#include <assert.h>

long
X(long a, long b)
{
	long c, d;

	c = 10;
	while (c <= a + b)
		c *= 10;

	d = (c * a * b) + a + b;
	c = 10;
	while (c <= a - b)
		c *= 10;
	a = (d * c) + a - b;

	return a;
}

int
main(void)
{
	assert(X(8, 2) == 16106L);
	assert(X(5, 4) == 2091L);
	assert(X(9, 6) == 54153L);

	return 0;
}
