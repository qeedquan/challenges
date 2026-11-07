/*

Implement a function divide(int a, int b, int c) that prints the base 10 value of a/b. without using any floating point math nor BigInteger/BigDecimal or equivalent libraries whatsoever. At least c accurate characters within the set of 0123456789. must be printed, except for the (possible) exception in point 4 below.

a and b may be any 32 bit integers. Update: If, for golfing purposes, you would like to have input be 64 bit primitives that is okay, but you do not need to support the whole 64 bit range of data.
You do not need to check that c is positive (though hopefully your program does not crash) if it's not.
The minimum supported upper bound for c is 500. It is okay if your program does not support values of c above 500, but it is also okay if it does.
For numbers that divide evenly, it is your choice whether to print extra zeroes (based on the value of c) or nothing.
You do not need to be able to use the function to do any further tasks with the quotient, the only goal is printing.
For numbers between -1 and 1, it is your choice whether to print a leading 0. However, this is the only scenario where printing a leading zero is acceptable, and you may only print one such zero.
You may use any rounding / floor / ceil logic you prefer for the last decimal place.
For a negative answer, you must print a leading -. This does not count towards c. However, it is your choice if you wish to print  , +, or nothing for a positive answer.
Integer division and integer modulus are both allowed. However, keep in mind that you are restricted to primitives, unless you choose to implement your own BigInteger/BigDecimal library which counts against your code length.
You do not need to handle b being 0, though you can if you want. Your program may enter an infinite loop, or crash, if b=0, and you will not be penalized.
Slight rule change per comment. To make sure the playing field is level, while a and b are guaranteed to be 32 bit integers, you may use 64 bit long integers. If your chosen language goes beyond 64 bit integers as a primitive, you may not at any point use that functionality (pretend it is capped at 64 bits).
Another point that is unclear (it shouldn't change any of the current valid answers, though): while c may be interpreted as either the number of printed characters or the number of spaces after the decimal, your program must use c somehow in a relevant way to decide how many characters to print. In other words, divide(2,3,2) should be much shorter output than divide(2,3,500); it is not okay to print 500 characters without regard to c.
I actually don't care about the name of the function. d is okay for golfing purposes.

Input
Both a function call and reading from stdin are accepted. If you read from stdin, any character not in the set [-0123456789] is considered an argument delimiter.

Output
Characters to stdout as described above.

Example
for divide(2,3,5), all of the following are acceptable outputs:

0.666
0.667
.6666
.6667
 0.666
 0.667
 .6666
 .6667
+0.666
+0.667
+.6666
+.6667
Another example: for divide(371,3,5) the following are all acceptable outputs:

123.6
123.7
 123.6
 123.7
+123.6
+123.7
123.66666
123.66667
 123.66666
 123.66667
+123.66666
+123.66667
And for divide(371,-3,5) the following are are all acceptable:

-123.6
-123.7
-123.66666
-123.66667

*/

#include <stdio.h>
#include <gmp.h>

void
test(int a, int b, int c)
{
	mpf_t x, y, z;

	mpf_init(x);
	mpf_init(y);
	mpf_init(z);

	mpf_set_si(x, a);
	mpf_set_si(y, b);
	mpf_div(z, x, y);
	gmp_printf("%.*Ff\n", c, z);

	mpf_clear(x);
	mpf_clear(y);
	mpf_clear(z);
}

int
main(void)
{
	test(2, 3, 5);
	test(371, 3, 5);
	test(371, -3, 5);

	return 0;
}
