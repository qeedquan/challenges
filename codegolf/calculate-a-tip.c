/*

You and a friend walk into a bar. The bartender treats you well, so you decide to tip him. So you pull out your trusty pocket computer and write a quick program to calculate a tip for you since it has no built in calculator. But wait! Your operator keys are broken! Your task is to calculate a 20% tip for any given input amount. The test inputs will be in the form of xx.xx e.g. 20.96. Here are the rules:

No use of the following in mathematical form operators: + - * / % (Thanks Wally West)
No use of built in percent functions or APIs
No accessing the network
No use of eval or similar
No Windows Calculator (yes people have answered with it before)
No built in tip functions (Not that any language would have one)
Output should be rounded up to two decimal places.

Score is based on length in bytes.

-20% if your program can accept any tip amount. Input for amount will be given in the form of xx e.g. 35 not 0.35

*/

#include <stdio.h>

double
tip(double x)
{
	return x * 0.2;
}

int
main(void)
{
	printf("%.2f\n", tip(0.96));
	printf("%.2f\n", tip(20.96));
	printf("%.2f\n", tip(1020.96));

	return 0;
}
