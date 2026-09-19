#!/usr/bin/env python3

"""

What is the Ultraradical?
The ultraradical, or the Bring radical, of a real number a is defined as the only real root of the quintic equation x^5+x+a=0.

Here we use UR(⋅) to denote the ultraradical function. For example, UR(−100010)=10, since 10^5+10-100010=0.

Challenge
Write a full program or a function, that takes a real number as input, and returns or outputs its ultraradical.

Requirements
No standard loopholes are allowed. The results for the test cases below must be accurate to at least 6 significant digits, but in general the program should calculate the corresponding values for any valid real number inputs.

Test Cases
9 decimal places rounded towards 0 are given for reference. Explanation is added for some of the test cases.

 a                         | UR(a)
---------------------------+---------------------
             0             |   0.000 000 000        # 0
             1             |  -0.754 877 (666)      # UR(a) < 0 when a > 0
            -1             |   0.754 877 (666)      # UR(a) > 0 when a < 0
             1.414 213 562 |  -0.881 616 (566)      # UR(sqrt(2))
            -2.718 281 828 |   1.100 93(2 665)      # UR(-e)
             3.141 592 653 |  -1.147 96(5 385)      # UR(pi)
            -9.515 716 566 |   1.515 71(6 566)      # 5th root of 8, fractional parts should match
            10             |  -1.533 01(2 798)
          -100             |   2.499 20(3 570)
         1 000             |  -3.977 89(9 393)
      -100 010             |  10.000 0(00 000)      # a = (-10)^5 + (-10)
 1 073 741 888             | -64.000 0(00 000)      # a = 64^5 + 64

Winning Criteria
The shortest valid submission in every language wins.

"""

import numpy as np
import math

def ultraradical(a):
    eps = 1e-8
    r = np.roots([1, 0, 0, 0, 1, a])
    x = r.real[abs(r.imag) < eps]
    if len(x) == 0:
        return math.NAN
    return x[0]

def test(a, r):
    x = ultraradical(a)
    print(x)
    assert(abs(x-r) < 1e-6)

def main():
    test(1, -0.754877666)
    test(-1, 0.754877666)
    test(1.414213562, -0.881616566) 
    test(-2.718281828, 1.100932665)
    test(3.141592653, -1.147965385)
    test(-9.515716566, 1.515716566)
    test(10, -1.533012798)
    test(-100, 2.499203570)
    test(1000, -3.977899393)
    test(-100010, 10.000000000)
    test(1073741888, -64.000000000)

main()
