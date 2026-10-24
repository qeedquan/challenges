#!/usr/bin/env python3

"""

Given the equation of a polynomial and an x-coordinate find the rate of change of the point at that x-coord on the curve.

A polynomial is in the form: axn + axn-1 + ... + ax1 + a, where a ϵ Q and n ϵ W. For this challenge, n can also be 0 if you don't want to have to deal with special cases (constants) where there is no x.

To find the rate of change at that x-coord, we can get the derivative of the polynomial and plug in the x-coord.

Input
The polynomial can be taken in any reasonable form, but you must state what that format is explicitly. For example, an array of the form [..[coefficient, exponent]..] is acceptable.

Output
The rate of change of the point at the x-coord given.

This is code-golf, so shortest code in bytes wins.
Examples
[[4, 3], [-2, 4], [5, 10]]   19    ->   16134384838410
                  [[0, 4]]  400    ->   0
           [[4, 0], [5,1]]  -13    ->   5
      [[4.14, 4], [48, 2]]   -3    ->   -735.12
         [[1, 3], [-5, 0]]    5.4  ->   87.48

"""

def derivative(a, x):
    r = 0
    for c, p in a:
        r += c * p * x**(p - 1)
    return round(r, 2)

def main():
    assert(derivative([[4, 3], [-2, 4], [5, 10]], 19) == 16134384838410)
    assert(derivative([[0, 4]], 400) == 0)
    assert(derivative([[4, 0], [5, 1]], -13) == 5)
    assert(derivative([[4.14, 4], [48, 2]], -3) == -735.12)
    assert(derivative([[1, 3], [-5, 0]], 5.4) == 87.48)

main()
