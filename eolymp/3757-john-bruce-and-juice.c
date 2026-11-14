/*

John has some money.
Bruce has some money too.
They know the price of a bottle of juice (unfortunately, juice is not free).
How many bottles of juice can they buy if they put their money together?

Input
The first line of input contains John's amount of money.
The second line contains Bruce's amount of money.
The third line contains the price of a bottle of juice.
Each amount or price is represented by a non-empty integer part, a decimal point, and exactly two digits after the point.
Each (John's and Bruce's) amount of money is non-negative and strictly less than 1000000.00.
Juice is not free and costs strictly less than 1000.00.

Output
Your program should output exactly one integer: the maximum number of bottles the guys can buy by pooling their money together.

Examples
Input #1
22.00
23.00
5.00

Answer #1
9

*/

#include <stdio.h>

double
solve(double a, double b, double c)
{
	return (a + b) / c;
}

int
main()
{
	printf("%.2f\n", solve(22, 23, 5));

	return 0;
}
