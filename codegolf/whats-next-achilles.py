#!/usr/bin/env python3

"""

Powerful numbers are positive integers such that, when expressed as a prime factorisation:

a=pe11×pe22×pe33⋯×pekk

all exponents e1,e2,... are greater than or equal to 2.
Note that the exponents do not include zero exponents, as exampled by 200=23×30×52=23×52 being a powerful number.
This includes all perfect powers, and a few "extra" numbers that are not perfect powers.

Achilles numbers are powerful numbers that are not perfect powers. The smallest Achilles number is 72=23×32. The Achilles numbers less than or equal to 500 are 72,108,200,288,392,432 and 500.

You are to take an Achilles number as input and output the smallest Achilles number greater than the input.

You may input and output in any convenient method. This is code-golf so the shortest code in bytes wins

Test Cases
input output
   72    108
  108    200
  200    288
  800    864
 1152   1323
 4500   4563
 3456   3528
 4563   4608
43808  43904
90828  91592
28800  29403
64800  64827
29768  30375

The program I used to generate these test cases. Contains spoilers for anyone who can understand Jelly.

‘ÆE;g/$ċ1İƑƲ1#

"""

from math import gcd
from itertools import count
from sympy import factorint

# https://oeis.org/A052486
def achilles(n):
    f = factorint(n)
    v = f.values()
    for x in v:
        if x < 2:
            return False
    return gcd(*v) == 1

def next(n):
    for i in count(n + 1):
        if achilles(i):
            return i
    return 0

def main():
    assert(next(72) == 108)
    assert(next(108) == 200)
    assert(next(200) == 288)
    assert(next(800) == 864)
    assert(next(1152) == 1323)
    assert(next(4500) == 4563)
    assert(next(3456) == 3528)
    assert(next(4563) == 4608)
    assert(next(43808) == 43904)
    assert(next(90828) == 91592)
    assert(next(28800) == 29403)
    assert(next(64800) == 64827)
    assert(next(29768) == 30375)

main()
