/*

Introduction
We know that the factorial notation is valid for all natural numbers. However, Euler had extended it for all positive real numbers, as well as for complex numbers by defining a function, which is known as the Gamma Function. It is represented by Γ.

Challenge
You will be given a non-negative floating point number, say 'n' (with a maximum of 2 decimal places in it), and you need to output the factorial of that number correct to at least 3 decimal places. Assume all inputs to be valid, and n <= 7.

Now talking about Gamma function, there is an integral which can be used to find the value of any factorial. You may choose to use it. You can find more information here. The Gamma function is recursive in nature. One important property, which would probably be useful to you is:

Γ(n) = (n-1)! , which means that, n! = Γ(n) . n

Also note that we really do not need to know Γ(n) for all values of n. For instance, look at the number 4.5 - we can write its factorial as:

4.5! = 4.5 * 3.5 * 2.5 * 1.5 * 0.5! = 59.0625 * 0.5!
So here we need only the value of 0.5! , which means the value of Γ(1.5). Also, similarly, we can find the factorial of any decimal if we know the values of factorials of numbers between 0 and 1, i.e, values of gamma function of numbers between 1 and 2. You need it, so that is why there is a table below for your help:

Table For Values of Gamma Function
https://i.stack.imgur.com/CB4Z9.png

Using this table, we can see that 0.5!, i.e, the value of Γ(1.5) = 0.88623, which gives our result: (4.5)! = 59.0625 * 0.88623 = 52.3429594 , which is indeed a good result. Similarly,

(5.7)! = (5.7)*(4.7)*(3.7)*(2.7)*(1.7)*(0.7)! = 454.97457 * 0.90864 = 413.408093
Also, if you do not wish to use the table for calculating the gamma function, here is a simple integral to help you out:

Integral for Gamma Function
https://i.imgur.com/EEe16jo.png

Remember that you can provide your answers only up to 3 decimal places if you want to. But the value should have minimum error. Like, +- 0.003 is acceptable.

You are free to decide in what way you want to compute the factorial - whether by the integral, or by the table, or using any other method.

Examples
Please note that here the answer is correct to 3 decimal places.

2.4 -> 2.981
3.9 -> 20.667
2.59 -> 3.675
1.7 -> 1.545
0.5 -> 0.886

Scoring
This is code-golf, so the shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
test(double x, double r)
{
	double v;

	v = tgamma(x + 1);
	printf("%f\n", v);
	assert(fabs(v - r) < 1e-3);
}

int
main(void)
{
	test(2.4, 2.981);
	test(3.9, 20.667);
	test(2.59, 3.675);
	test(1.7, 1.545);
	test(0.5, 0.886);

	return 0;
}
