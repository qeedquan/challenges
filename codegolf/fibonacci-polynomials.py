#!/usr/bin/env python3

"""

The Fibonacci polynomials are a polynomial sequence defined as:

F0(x)=0
F1(x)=1
Fn(x)=xFn-1(x)+Fn-2(x)
The first few Fibonacci polynomials are:

F0(x)=0
F1(x)=1
F2(x)=x
F3(x)=x^2+1
F4(x)=x^3+2x
F5(x)=x^4+3x^2+1
When you evaluate the Fibonacci polynomials for x=1, you get the Fibonacci numbers.

Task
Your task is to calculate the Fibonacci polynomial Fn(x).

The usual sequence rules apply. So you may:

Output all the Fibonacci polynomials.
Take an input n and output the n-th Fibonacci polynomial.
Take an input n and output the first n Fibonacci polynomial.
You may use 0-indexing or 1-indexing.

You may output the polynomials in any reasonable format. Here are some example formats:

a list of coefficients, in descending order, e.g. x^9 + 8x^7 + 21x^5 + 20x^3 + 5x is represented as [1,0,8,0,21,0,20,0,5,0];
a list of coefficients, in ascending order, e.g. x^9 + 8^x7 + 21x^5 + 20x^3 + 5x is represented as [0,5,0,20,0,21,0,8,0,1];
a function that takes an input n and gives the coefficient of xn ; a built-in polynomial object.
You may pad the coefficient lists with 0s. For example, the polynomial 0 can represented as [], [0] or even [0,0].

You may also take two integers n,k, and output the coefficient of xk in n-th Fibonacci polynomial. You may assume that k<n.

This is code-golf, so the shortest code in bytes wins.

Testcases
Here I output lists of coefficients in descending order.

0 -> []
1 -> [1]
2 -> [1, 0]
3 -> [1, 0, 1]
4 -> [1, 0, 2, 0]
5 -> [1, 0, 3, 0, 1]
6 -> [1, 0, 4, 0, 3, 0]
7 -> [1, 0, 5, 0, 6, 0, 1]
8 -> [1, 0, 6, 0, 10, 0, 4, 0]
9 -> [1, 0, 7, 0, 15, 0, 10, 0, 1]
10 -> [1, 0, 8, 0, 21, 0, 20, 0, 5, 0]
11 -> [1, 0, 9, 0, 28, 0, 35, 0, 15, 0, 1]
12 -> [1, 0, 10, 0, 36, 0, 56, 0, 35, 0, 6, 0]
13 -> [1, 0, 11, 0, 45, 0, 84, 0, 70, 0, 21, 0, 1]
14 -> [1, 0, 12, 0, 55, 0, 120, 0, 126, 0, 56, 0, 7, 0]
15 -> [1, 0, 13, 0, 66, 0, 165, 0, 210, 0, 126, 0, 28, 0, 1]

"""

from sympy import *

def fibpoly(n):
    if n < 1:
        return []

    x = symbols('x')
    a = 0
    b = 1
    for i in range(n):
        a, b = b, a + b*x
    return Poly(a, x).all_coeffs()

def main():
    assert(fibpoly(0) == [])
    assert(fibpoly(1) == [1])
    assert(fibpoly(2) == [1, 0])
    assert(fibpoly(3) == [1, 0, 1])
    assert(fibpoly(4) == [1, 0, 2, 0])
    assert(fibpoly(5) == [1, 0, 3, 0, 1])
    assert(fibpoly(6) == [1, 0, 4, 0, 3, 0])
    assert(fibpoly(7) == [1, 0, 5, 0, 6, 0, 1])
    assert(fibpoly(8) == [1, 0, 6, 0, 10, 0, 4, 0])
    assert(fibpoly(9) == [1, 0, 7, 0, 15, 0, 10, 0, 1])
    assert(fibpoly(10) == [1, 0, 8, 0, 21, 0, 20, 0, 5, 0])
    assert(fibpoly(11) == [1, 0, 9, 0, 28, 0, 35, 0, 15, 0, 1])
    assert(fibpoly(12) == [1, 0, 10, 0, 36, 0, 56, 0, 35, 0, 6, 0])
    assert(fibpoly(13) == [1, 0, 11, 0, 45, 0, 84, 0, 70, 0, 21, 0, 1])
    assert(fibpoly(14) == [1, 0, 12, 0, 55, 0, 120, 0, 126, 0, 56, 0, 7, 0])
    assert(fibpoly(15) == [1, 0, 13, 0, 66, 0, 165, 0, 210, 0, 126, 0, 28, 0, 1])

main()
