/*

The perplexity of a bigram model is 170. Compute its cross-entropy corrected to 2 decimal places.

You may either submit the final answer in the plain-text mode, or you may submit a program in the language of your choice to compute the required value.

Your answer should look like this:

5.50

Do not use any extra leading or trailing spaces or newlines.

*/

#include <stdio.h>
#include <math.h>

// perplexity = 2^cross-entropy
double
crossentropy(double p)
{
	return log2(p);
}

int
main(void)
{
	printf("%f\n", crossentropy(170));
	return 0;
}
