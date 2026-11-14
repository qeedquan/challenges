#!/usr/bin/env python3

"""

In mathematics, a Padé approximant (Wikipedia, MathWorld) is the "best" approximation of a function by a rational function. For a function f(x), the Padé approximant of order [m/n] is a rational function of the form

R(x) = Sum[k=0, m] a[k]*x^k / Sum[k=0, n] b[k]*x^k

such that R(x) agrees with f(x) up to order m+n at x=0, i.e.

f(0) = R(0)
f'(0) = R'(0)
f[m+n](0) = R[m+n](0)

When it exists, the Padé approximant (as a rational function) is unique. Sometimes we also require that b0=1, so that the coefficients a[k] and b[k] are also uniquely determined. But in this challenge, we will not require this.

Task
In this challenge, you need to find the Padé approximant of the exponential function exp(x) of order [n/n], where n is a nonnegative integer. Here are the first few results:

[n=0] = 1/1
[n=2] = (2 + x)/(2 - x)
[n=3] = (12 + 6x + x^2)/(12 - 6x + x^2)
[n=4] = (1680 + 840x + 180x^2 + 20x^3 + x^4) / (1680 - 840x + 180x^2 - 20x^3 + x^4)

You can see that the numerator and denominator are basically the same, only with alternating signs.
This is only true for the Padé approximant of exp(x), not for other functions.
So you can choose to only output the numerator, or the denominator, or the whole rational function.

As with standard sequence challenges, you may choose to:

Take an integer n as input and output the nth term of the sequence.
Take an integer n as input and output the first n terms of the sequence.
Take no input and output the sequence indefinitely.
You may also use 1-based indexing, i.e. taking n and outputting the Padé approximant of order [n−1/n−1].

You may output in any reasonable format, e.g. a list of coefficients (numerator and/or denominator), in either ascending or descending order.
When you only output the numerator or the denominator, you can scale the coefficients by any nonzero factor, but the factor must be the same for the same n.
The coefficients do not need to be integers.

Just like other challenges with both sequence and polynomials tags, you can also take two inputs n and k and output the kth coefficient (of either the numerator or the denominator) of the nth Padé approximant.

This is code-golf, so the shortest code in bytes wins.

Test cases
Here I output the coefficients of the numerators in ascending order.

0 -> [1]
1 -> [2, 1]
2 -> [12, 6, 1]
3 -> [120, 60, 12, 1]
4 -> [1680, 840, 180, 20, 1]
5 -> [30240, 15120, 3360, 420, 30, 1]
6 -> [665280, 332640, 75600, 10080, 840, 42, 1]
7 -> [17297280, 8648640, 1995840, 277200, 25200, 1512, 56, 1]

"""

from math import *

"""

@Tbw

Takes n and k and outputs the coefficient of x[k] in the numerator of the nth approximant. This is (2n-k)! / [k!*(n-k)!].

"""

def coeffs(n):
    r = []
    for k in range(n + 1):
        x = factorial(2*n - k) // (factorial(k)*factorial(n - k))
        r.append(x)
    return r

def main():
    assert(coeffs(0) == [1])
    assert(coeffs(1) == [2, 1])
    assert(coeffs(2) == [12, 6, 1])
    assert(coeffs(3) == [120, 60, 12, 1])
    assert(coeffs(4) == [1680, 840, 180, 20, 1])
    assert(coeffs(5) == [30240, 15120, 3360, 420, 30, 1])
    assert(coeffs(6) == [665280, 332640, 75600, 10080, 840, 42, 1])
    assert(coeffs(7) == [17297280, 8648640, 1995840, 277200, 25200, 1512, 56, 1])

main()
