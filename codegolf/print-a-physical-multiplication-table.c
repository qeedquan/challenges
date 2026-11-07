/*

Rectangles have this nice property - an n×m rectangle consists of exactly n×m characters!

A.. more interesting property is that the rectangles can be aligned nicely in a multiplication table - for example, a 3×3 table:

# ## ###

# ## ###
# ## ###

# ## ###
# ## ###
# ## ###
Your challenge is to, given a number n (n>1), output a formatted n×n multiplication table.

Rules
You can take the input one above or below  n

Default I/O rules apply
You can choose any non-whitespace character to represent the blocks; every other character (though newlines are special) is considered whitespace. The chosen character can be different for different inputs, but must be the same throughout the input
The result can have unneeded characters, as long as the table aligns up and there are no occurrences of the chosen character that aren't part of the required output
The separators must be 1 character wide/tall, and the rectangles must be packed (i.e. no separators between their characters)
The empty lines can be empty, padding isn't required
The result can be a string, matrix, vector of lines, array of character arrays, or anything 2Dish
You may alternatively output a matrix/vector-of-vectors/anything 2Dish of numbers, but the background & foreground must be 2 distinct numbers (which can vary input to input, but not throughout an output) and no other numbers can be present. Extra surrounding characters are allowed with this format too (though they must match the background number)
This is code-golf, shortest answer in bytes, per-language, wins!

Examples
For the input 2, a valid ascii-art output, with the character ∙, is:

        ∙ ∙∙

Result: ∙ ∙∙.
        ∙ ∙∙
yes the period is there just to confuse you
Another valid answer as a number matrix, with 2 being the background number and 9 the foreground:

[[9,2,9,9,2,2],
 [2,2,2,2,2,2],
 [9,2,9,9,2,2],
 [9,2,9,9,2,2]]
An invalid output example would be

#  # #


#  # #

#  # #
as the rectangles have separators in between them.

Example outputs for 4×4:

# ## ### ####

# ## ### ####
# ## ### ####

# ## ### ####
# ## ### ####
# ## ### ####

# ## ### ####
# ## ### ####
# ## ### ####
# ## ### ####


1 0 1 1 0 1 1 1 0 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 1 1 1
1 0 1 1 0 1 1 1 0 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 1 1 1
1 0 1 1 0 1 1 1 0 1 1 1 1
1 0 1 1 0 1 1 1 0 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 1 1 1
1 0 1 1 0 1 1 1 0 1 1 1 1
1 0 1 1 0 1 1 1 0 1 1 1 1
1 0 1 1 0 1 1 1 0 1 1 1 1

*/

#include <stdio.h>
#include <math.h>

int
issqr(int n)
{
	int s;

	if (n < 0)
		return 0;

	s = sqrt(n);
	return s * s == n;
}

int
at(int x, int y)
{
	return !issqr(17 + 8 * x) && !issqr(17 + 8 * y);
}

/*

@Arnauld

How?
The width w of the matrix is given by:

w = T[n] + n - 1 = binomial(n + 1, 2) + n - 1 = n*(n-3)/2 - 1

(NB: As allowed by the challenge rules, we output a matrix of width w+1 instead.)

Similarly, the cell located at (X,Y) is empty if the following quadratic admits an integer root for either k=X or k=Y:

x*(x+3)/2 - 1 - k = 0
x^2 + 3x - 2 - 2k = 0

whose determinant is:
determinant = 9 - 4*(-2 - 2*k) = 17 + 8*k

*/

void
table(int n)
{
	int s, x, y;

	printf("n=%d\n", n);
	s = n * (n + 3) / 2;
	for (y = 0; y < s; y++) {
		for (x = 0; x < s; x++)
			printf("%d ", at(x, y));
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 1; i <= 5; i++)
		table(i);

	return 0;
}
