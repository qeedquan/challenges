/*

Task:
You have to write a function pattern which returns the following Pattern(See Examples) upto (3n-2) rows, where n is parameter.

Note:Returning the pattern is not the same as Printing the pattern.
Rules/Note:
The pattern should be created using only unit digits.
If n < 1 then it should return "" i.e. empty string.
The length of each line is same, and is equal to the length of longest line in the pattern i.e. length = (3n-2).
Range of Parameters (for the sake of CW Compiler) :
n ∈ (-∞,50]
Examples:
pattern(5) :

    11111
    22222
    33333
    44444
1234555554321
1234555554321
1234555554321
1234555554321
1234555554321
    44444
    33333
    22222
    11111

pattern(11):

          11111111111
          22222222222
          33333333333
          44444444444
          55555555555
          66666666666
          77777777777
          88888888888
          99999999999
          00000000000
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
1234567890111111111110987654321
          00000000000
          99999999999
          88888888888
          77777777777
          66666666666
          55555555555
          44444444444
          33333333333
          22222222222
          11111111111

*/

#include <stdio.h>

void
print1(int x, int n)
{
	int i;

	for (i = 1; i < n; i++)
		printf(" ");
	for (i = 0; i < n; i++)
		printf("%d", x % 10);
	printf("\n");
}

void
print2(int n)
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%d", i % 10);
	for (i = 1; i < n; i++)
		printf("%d", n % 10);
	for (i = n - 1; i >= 1; i--)
		printf("%d", i % 10);
	printf("\n");
}

void
pattern(int n)
{
	int i;

	printf("n=%d\n", n);
	for (i = 1; i <= n - 1; i++)
		print1(i, n);
	for (i = 0; i < n; i++)
		print2(n);
	for (i = n - 1; i >= 1; i--)
		print1(i, n);
	printf("\n");
}

int
main()
{
	pattern(5);
	pattern(11);
	return 0;
}
