#!/usr/bin/env python3

"""

Description

Consider polynomials whose coefficients are 0 and 1. Addition of two polynomials is achieved by 'adding' the coefficients for the corresponding powers in the polynomials. The addition of coefficients is performed by addition modulo 2, i.e., (0 + 0) mod 2 = 0, (0 + 1) mod 2 = 1, (1 + 0) mod 2 = 1, and (1 + 1) mod 2 = 0. Hence, it is the same as the exclusive-or operation.

(x^6 + x^4 + x^2 + x + 1) + (x^7 + x + 1) = x^7 + x^6 + x^4 + x^2

Subtraction of two polynomials is done similarly. Since subtraction of coefficients is performed by subtraction modulo 2 which is also the exclusive-or operation, subtraction of polynomials is identical to addition of polynomials.

(x^6 + x^4 + x^2 + x + 1) - (x^7 + x + 1) = x^7 + x^6 + x^4 + x^2

Multiplication of two polynomials is done in the usual way (of course, addition of coefficients is performed by addition modulo 2).

(x^6 + x^4 + x^2 + x + 1) (x^7 + x + 1) = x^13 + x^11 + x^9 + x^8 + x^6 + x^5 + x^4 + x^3 + 1

Multiplication of two polynomials f(x) and g(x) modulo a polynomial h(x) is the remainder of f(x)g(x) divided by h(x).

(x^6 + x^4 + x^2 + x + 1) (x^7 + x + 1) modulo (x^8 + x^4 + x^3 + x + 1) = x^7 + x^6 + 1
The largest exponent of a polynomial is called its degree. For example, the degree of x^7 + x^6 + 1 is 7.

Given three polynomials f(x), g(x), and h(x), you are to write a program that computes f(x)g(x) modulo h(x).
We assume that the degrees of both f(x) and g(x) are less than the degree of h(x). The degree of a polynomial is less than 1000.

Since coefficients of a polynomial are 0 or 1, a polynomial can be represented by d+1 and a bit string of length d+1, where d is the degree of the polynomial and the bit string represents the coefficients of the polynomial. For example, x^7 + x^6 + 1 can be represented by 8 1 1 0 0 0 0 0 1.

Input

The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of three lines that contain three polynomials f(x), g(x), and h(x), one per line. Each polynomial is represented as described above.

Output

The output should contain the polynomial f(x)g(x) modulo h(x), one per line.

Sample Input

2
7 1 0 1 0 1 1 1
8 1 0 0 0 0 0 1 1
9 1 0 0 0 1 1 0 1 1
10 1 1 0 1 0 0 1 0 0 1
12 1 1 0 1 0 0 1 1 0 0 1 0
15 1 0 1 0 1 1 0 1 1 1 1 1 0 0 1

Sample Output

8 1 1 0 0 0 0 0 1
14 1 1 0 1 1 0 0 1 1 1 0 1 0 0

Source

Taejon 2001

"""

from sympy import *

def polymulmod(f, g, h):
    x = Symbol('x')
    a = Poly(f, x, modulus=2)
    b = Poly(g, x, modulus=2)
    m = Poly(h, x, modulus=2)
    _, r = divmod(a * b, m)
    return r.all_coeffs()

def main():
    assert(polymulmod([1, 0, 1, 0, 1, 1, 1], [1, 0, 0, 0, 0, 0, 1, 1], [1, 0, 0, 0, 1, 1, 0, 1, 1]) == [1, 1, 0, 0, 0, 0, 0, 1])
    assert(polymulmod([1, 1, 0, 1, 0, 0, 1, 0, 0, 1], [1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0], [1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1]) == [1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0])

main()
