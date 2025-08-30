/*

Write function which solves equation of degree less than or equal to 2 (ax^2 + bx + c = 0).

Input
Function should get 3 parameters - floating point numbers which are coefficients of this equation. Coefficients may be zero (that means function must able to solve bx + c = 0 and c = 0 too).
Coefficients are between -1000 and 1000 with 3 significant decimal digits but maximum 3 digits after comma, for example, 999. or 3.14 or 0.233 but not 1001 or 0.0123.

Rules
You may use only + - * / % & | xor ~ && || ! < > >= <= == != << >> operators
No built-in functions (that means no square root or power or similar functions)
No variables except 3 function parameters
You can't use complicated expressions - only statements of the form a = b @ c or a = @ b are allowed (@ - any allowed operator and a, b, c - any variables, may be same or constants)
No loops, recursion, goto's, custom types
Casts and type conversion between integral data types are allowed
Using features of dynamic typing (changing floating point number to array/object/something else that is not number) is not allowed
If's are allowed with one or none operators in condition (if (a) {...} else {...} or if (a==b) {...} else {...}). Note that if itself and its condition scores separately
You may use try{}catch{}
Output
Output should be passed by reference to input variables, if your language doesn't have such feature, you anyway should put result to input variables and print their values
In variable a - number of real roots - 0, 1, 2, 3 (value greater than 2 stands for infinitely many roots)
In variables b and c - 1st and 2nd roots (if none or infinitely many roots than any values, if one root then c - any value)
Note that 2 equal roots is not the same as 1 root
Precision should be at least 3 significant decimal digits
Score
Score is [number of operators] + [number of if's]. Assignment operators have score 0.
Answer with lowest score wins.
In case of same score answer with greater precision wins. If precision is same then first answer wins.
if(a != 0) and if(a == 0) has score 1 (instead of 2) because if(a) or if(a)else{} can be used, however not all languages support it.
For each catch{} +2 to score
Use of 1 temporary variable of numeric type is +20 to score.

*/

#include <stdio.h>

/*

@Martin Ender

I happen to use the same square root algorithm (Newton) as Peter.
However, I think we need to use two different starting values in order to get away with even 8 iterations.
The maximum value of b²/4-c (the normalised discriminant) is for b = -c = 1000.
The minimum value is for b = 0.001; c = 0 (in fact, there are smaller values but these would be beyond the significant digits of b and c).
If we split the range of values at 20, we can use 0.1 as the starting guess for
the lower range and 100 as the starting guess for the upper range and always converge in 8 steps.
If I could be bothered to keep searching I think I could get this down to 7,
and with a few more subdivisions probably even below 6 while still saving operations (but I can't be bothered right now).

*/

void
qe(double a, double b, double c, double r[3])
{
	double t;

	if (a) {
		b = b / a;
		c = c / a;
		b = b / -2;
		t = b * b;
		c = t - c;
		if (c < 0) {
			a = 0;
		} else {
			if (c < 20)
				a = .1;
			else
				a = 100;

			t = c / a;
			a = a + t;
			a = a / 2;

			t = c / a;
			a = a + t;
			a = a / 2;

			t = c / a;
			a = a + t;
			a = a / 2;

			t = c / a;
			a = a + t;
			a = a / 2;

			t = c / a;
			a = a + t;
			a = a / 2;

			t = c / a;
			t = a + t;
			t = t / 2;

			t = c / a;
			t = a + t;
			t = t / 2;

			t = c / a;
			t = a + t;
			t = t / 2;

			a = 2;
			c = b + t;
			b = b - t;
		}
	} else if (b) {
		a = 1;
		b = b / c;
		b = -b;
	} else if (c) {
		a = 0;
	} else {
		a = 3;
	}

	r[0] = a;
	r[1] = b;
	r[2] = c;
}

int
main()
{
	double r[3];

	qe(1, -1, -42, r);
	printf("%f %f\n", r[1], r[2]);

	qe(1, 25, 150, r);
	printf("%f %f\n", r[1], r[2]);

	return 0;
}
