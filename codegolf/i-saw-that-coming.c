/*

Write a program or function that takes in an integer greater than 1 or less than -1. That is, the input won't be 0, 1, or -1.

If the input is 2, the output should be:

|\_/|
|___|
If the input is 3, the output should be:

|\_/\_/|
|______|
If the input is 4, the output should be:

|\_/\_/\_/|
|_________|
The pattern continues in the same exact manner for larger inputs. For example, if the input is 10, the output should be:

|\_/\_/\_/\_/\_/\_/\_/\_/\_/|
|___________________________|
If the input is -2, the output should be:

 ____
|    |
|_/\_|
If the input is -3, the output should be:

 _______
|       |
|_/\_/\_|
If the input is -4, the output should be:

 __________
|          |
|_/\_/\_/\_|
The pattern continues in the same exact manner for smaller inputs. For example, if the input is -10, the output should be:

 ____________________________
|                            |
|_/\_/\_/\_/\_/\_/\_/\_/\_/\_|
The output can be printed or returned as a string with an optional trailing newline. The top right "empty" corner of the output for negative inputs may be a space or it may remain empty.

The shortest code in bytes wins.

*/

#include <stdio.h>
#include <stdlib.h>

void
positive(int n)
{
	int i;

	printf("|");
	for (i = 1; i < n; i++)
		printf("\\_/");
	printf("|\n");

	printf("|");
	for (i = 1; i < n; i++)
		printf("___");
	printf("|\n");
}

void
negative(int n)
{
	int i;

	n = abs(n);

	printf(" ");
	for (i = 1; i < n; i++)
		printf("___");
	printf("_\n");

	printf("|");
	for (i = 1; i < n; i++)
		printf("   ");
	printf(" |\n");

	printf("|");
	for (i = 1; i < n; i++)
		printf("_/\\");
	printf("_|\n");
}

void
decor(int n)
{
	printf("n=%d\n", n);
	if (n > 0)
		positive(n);
	else
		negative(n);
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 2; i <= 10; i++)
		decor(-i);
	for (i = 2; i <= 10; i++)
		decor(i);

	return 0;
}
