/*

Objective
In this challenge, we practice calculating the correlation between two elements.

Resources
Here are some useful articles explaining the relationship between r and the slopes of the regression lines.

1. Correlation and R-squared
2. Khan Academy tutorial about the coefficient of determination

Formula: r^2 = bxy * byx where the symbols used are the standard ones, given the context.

Task
For a particular scatter plot, the line of regression of y on x is:

3x + 4y + 8 = 0

And the line of regression of x on y is:
4x + 3y + 7 = 0

Find the Pearson Product moment coefficient, r, correct to a scale of 2 decimal places.

Output Format

Your answer should be a single floating point/decimal number, correct to a scale of  decimal places. You can submit solutions in either of the  following ways:

Solve the problem manually and submit your result as Plain Text. In the text box below, enter a single floating point/decimal number.
Submit an R or Python program, which uses the above parameters (hard-coded), then computes and prints the score.
Your answer should follow the format below, and must not contain any extra white space or newline characters:

4.23

*/

#include <stdio.h>
#include <math.h>

/*

Given two line equations

ax + by + c = 0

The bxy and byx coefficients are the slope when we solve for x or y.

bxy = -b/a
byx = -a/b

*/

double
pearsonr(double l0[3], double l1[3])
{
	double bxy, byx, r;

	bxy = -l1[1] / l1[0];
	byx = -l0[0] / l0[1];
	r = sqrt(bxy * byx);
	if (bxy < 0 || byx < 0)
		r = -r;
	return r;
}

int
main(void)
{
	double l0[] = {3, 4, 8};
	double l1[] = {4, 3, 7};

	printf("%.2f\n", pearsonr(l0, l1));
	return 0;
}
