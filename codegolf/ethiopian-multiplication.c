/*

This question is inspired by this answer. Coincidentally, I used to use Ethiopian Multiplication when I was a kid, but had never known the name of the method until recently.

Ethiopian multiplication is a method of multiplying integers using only addition, doubling, and halving.

Method:

Take two numbers to be multiplied and write them down at the top of two columns.
In the left-hand column repeatedly halve the last number, discarding any remainders, and write the result below the last in the same column, until you write a value of 1.
In the right-hand column repeatedly double the last number and write the result below. stop when you add a result in the same row as where the left hand column shows 1.
Examine the table produced and discard any row where the value in the left column is even. Sum the values in the right-hand column that remain to produce the result of multiplying the original two numbers together.
For example: 17 x 34

17    34
Halving the first column:

17    34
 8
 4
 2
 1
Doubling the second column:

17    34
 8    68
 4   136
 2   272
 1   544
Strike-out rows whose first cell is even, we'll do this by encasing those numbers on the right in square brackets:

17    34
 8   [68]
 4  [136]
 2  [272]
 1   544
Sum the remaining numbers in the right-hand column:

17    34
 8   [68]
 4  [136]
 2  [272]
 1   544
    =====
     578
So 17 multiplied by 34, by the Ethiopian method is 578.

The Task:

Golf code that takes two numbers between 1 and 1000 and perform the same layout and algorithm, displaying the product below.

Input Method: However you choose...

Example Input:

19 427
Resulting Output:

19   427
 9   854
 4 [1708]
 2 [3416]
 1  6832
   ======
    8113
Please note the alignment of the digits. This is most important in the layout. Also note that the double line laid out by equal signs must be two characters longer than the overall answer and must be centre justified.

Testing

How will you be testing this? By providing a run of your program using two numbers. These numbers can be extracted from your user ID number (this can be obtained by hovering your cursor over your avatar on the top window). Take your number and take the last three digits, this will be number B, take whatever else remains at the front, that will be number A. Then test for A times B.

Testing example:

My user ID number is 8555, so my numbers are 8 and 555. So my output should look like this:

8  [555]
4 [1110]
2 [2220]
1  4440
  ======
   4440
Restrictions:

No native multiplication operators permitted save for in the use of "doubling", as per mentioned in the algorithm. In other words, if you're using an operator like *, it can only be used for multiplying by 2 only.

Entries that do not adhere to this will not be considered and the user will be escorted off the premises with a cardboard box full of their belongings. Each entry will have code, plus the test based on your user ID number.

This is code golf. Shortest number of bytes will receive the prize, glory and admiration of their peers... (And maybe a Lamborghini... I said "maybe"!)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
print1(int a, int b)
{
	int c0, c1;

	c0 = '[';
	c1 = ']';
	if (a % 2)
		c0 = c1 = ' ';

	printf("%*d %c%*d%c\n", 5, a, c0, 9, b, c1);
}

void
print2(int r)
{
	char s[32];
	int n;

	n = snprintf(s, sizeof(s) - 3, "%d", r);
	memset(s, '=', n + 2);
	s[n + 3] = '\0';

	printf("%*c%*s\n%*d\n\n", 5, ' ', 12, s, 16, r);
}

int
ethmul(int a, int b)
{
	int r;

	if (a < 1 || b < 1)
		return a * b;

	r = 0;
	print1(a, b);
	while (a > 1) {
		r += (a % 2) * b;
		a /= 2;
		b *= 2;
		print1(a, b);
	}
	r += b;
	print2(r);

	return r;
}

int
main()
{
	int a, b, n;

	ethmul(17, 34);
	ethmul(19, 427);

	n = 100;
	for (a = 1; a <= n; a++) {
		for (b = 1; b <= n; b++)
			assert(ethmul(a, b) == a * b);
	}
	return 0;
}
