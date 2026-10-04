/*

Objective
In this challenge, we practice calculating standard deviation.

Task
The heights of a group of children are measured. The resulting data has a mean of 0.675 meters, and a standard deviation of 0.065 meters. One particular child is 90.25 centimeters tall. Compute z, the number of standard deviations away from the mean that the particular child is.

Enter the value of z, correct to a scale of two decimal places.

Output Format

Your output must be a floating point/decimal number, correct to a scale of  decimal places. You can submit solutions in either of the  following ways:

Solve the problem manually and submit your result as Plain Text.

Submit an R or Python program, which uses the above parameters (hard-coded), and computes the answer.

Your answer format should resemble something like:

4.23
(This is NOT the answer, just a demonstration of the answering format.)

*/

#include <stdio.h>

/*

https://www.investopedia.com/terms/z/zscore.asp

Z-Score Formula
The statistical formula for a value's z-score is calculated using the following formula:

z = ( x - μ ) / σ

*/

double
solve(void)
{
	double height;
	double mean;
	double stddev;

	height = 90.25 / 100;
	mean = 0.675;
	stddev = 0.065;
	return (height - mean) / stddev;
}

int
main(void)
{
	printf("%.2f\n", solve());
	return 0;
}
