#!/usr/bin/env python3

"""

I'm surprised we don't have the crossed ladders problem as a task here yet.
https://en.wikipedia.org/wiki/Crossed_ladders_problem

https://upload.wikimedia.org/wikipedia/commons/thumb/4/47/CrossedLadders.svg/781px-CrossedLadders.svg.png

Two ladders of lengths a and b lie oppositely across an alley, as shown in the figure. The ladders cross at a height of h above the alley floor. What is the width of the alley?

Without loss of generality we can set h = 1. In this MSE answer I show that with this assumption the width w satisfies the following quartic in w^2:

w^8 - 2*(a^2 + b^2 − 2)*w^6 + (a^4 + 4*a^2*b^2 + b^4 - 6*a^2 - 6*b^2)*w^4 - 2*(a^4*b^2 + a^2*b^4 - a^4 - 4*a^2*b^2 - b^4)*w^2 + (a*b + a + b)(a*b + a - b)(a*b − a + b)(a*b - a - b) = 0

Obviously we must have a,b>1 to be able to cross the ladders at height 1.
In this range of the input variables the quartic in w^2 will have two real roots.
The smaller real root of the quartic is negative if ab<a+b, and in this case the configuration cannot be physically realised;
otherwise that root is the correct value of w^2.

For this task, however, you are free to use any method to obtain w.

Task
Given ladder lengths a,b > 1 with ab≥a+b and assuming the crossing height h = 1, calculate the alley width w to at least 4 decimal places.

Test cases
a, b, w
2, 2, 0.0
2, 3, 1.23118572377867
3, 3, 2.23606797749979
8/3, 10/3, 2.10872747840039
1.5, 4.5, 0.763513778701349
1.125, 9, 0.0
6, 9, 5.88439718860116
10, 10, 9.79795897113271

"""

import numpy as np

def solve(a, b):
    c8 = 1
    c6 = -2 * (a**2 + b**2 - 2)
    c4 = a**4 + 4*a**2*b**2 + b**4 - 6*a**2 - 6*b**2
    c2 = -2 * (a**4*b**2 + a**2*b**4 - a**4 - 4*a**2*b**2 - b**4)
    c0 = (a*b + a + b) * (a*b + a - b) * (a*b - a + b) * (a*b - a - b)
    return np.roots([c8, 0, c6, 0, c4, 0, c2, 0, c0])

def test(a, b, r):
    for p in solve(a, b):
        if np.allclose(p, r):
            print(p, r)
            return
    assert(False)

def main():
    test(2, 2, 0.0)
    test(2, 3, 1.23118572377867)
    test(3, 3, 2.23606797749979)
    test(8/3, 10/3, 2.10872747840039)
    test(1.5, 4.5, 0.763513778701349)
    test(1.125, 9, 0.0)
    test(6, 9, 5.88439718860116)
    test(10, 10, 9.79795897113271)

main()
