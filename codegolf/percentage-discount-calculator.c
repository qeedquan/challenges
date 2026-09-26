/*

Given an original price and a percentage discount, calculate the resulting sale price using as few bytes of code as possible.

Task
Write a program or function that accepts:

An original price P
A discount percentage D
and returns the price after applying the discount.

The mathematical operation is equivalent to:

P × (1 - D / 100)

Examples
Original Price	Discount	Result
200	25%	150
80	15%	68
1250	30%	875
99.99	10%	89.991
Input
The input consists of two finite, non-negative numeric values:

P D
where:

P >= 0 is the original price.
0 <= D <= 100 is the discount percentage.
Decimal values may be supplied.
The exact input syntax may be adapted to the conventions of the submitted language.

Output
Return a numeric value representing the price after applying the discount.

For example:

200 25
produces:

150
and:

99.99 10
produces:

89.991
Precision
Submissions should preserve the precision supported by their language/runtime.

Do not round to two decimal places unless the submitted language naturally does so or the submission explicitly chooses to round.

For example:

99.99 - 10% = 89.991
is a valid result.

Restrictions
Built-in percentage/discount functions are not allowed if they directly perform the entire challenge.
External services, APIs, websites, or libraries specifically designed to calculate the answer are not allowed.
The calculation must be performed by the submitted code.
Standard arithmetic operators and standard-library functionality are allowed unless they directly solve the entire task.
Scoring
This is a code-golf challenge.

The winner is the valid submission with the lowest byte count.

Each submission must include:

Programming language
Language version, where relevant
Byte count
Complete code
Whitespace and syntax required by the language count toward the byte total.

Test Cases
Input       Output
200 25      150
80 15       68
1250 30     875
500 5       475
99.99 10    89.991
Optional Bonus
Extend the program so that it returns both:

The amount discounted
The final price
For example:

Input: 200 25

Discount: 50
Final: 150
The bonus is still scored by byte count; submissions should clearly state whether they implement the basic task or the optional extension.

Challenge Goal
The objective is to find the shortest valid implementation while demonstrating how different programming languages handle percentage arithmetic, numeric input, and output formatting.

*/

#include <stdio.h>

double
discount(double p, double d)
{
	return p * (1 - (d / 100));
}

int
main()
{
	printf("%f\n", discount(200, 25));
	printf("%f\n", discount(80, 15));
	printf("%f\n", discount(1250, 30));
	printf("%f\n", discount(500, 5));
	printf("%f\n", discount(99.99, 10));

	return 0;
}
