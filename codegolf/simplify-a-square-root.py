#!/usr/bin/env python3

"""

Given a positive integer n, simplify the square root √n into the form a√b by extracting all square factors. The outputted a,b should be positive integers with n = a^2 * b with b as small as possible.

You may output a and b in either order in any reasonable format. You may not omit outputs of 1 as implicit.

The outputs for n=1..36 as (a,b):

1 (1, 1)
2 (1, 2)
3 (1, 3)
4 (2, 1)
5 (1, 5)
6 (1, 6)
7 (1, 7)
8 (2, 2)
9 (3, 1)
10 (1, 10)
11 (1, 11)
12 (2, 3)
13 (1, 13)
14 (1, 14)
15 (1, 15)
16 (4, 1)
17 (1, 17)
18 (3, 2)
19 (1, 19)
20 (2, 5)
21 (1, 21)
22 (1, 22)
23 (1, 23)
24 (2, 6)
25 (5, 1)
26 (1, 26)
27 (3, 3)
28 (2, 7)
29 (1, 29)
30 (1, 30)
31 (1, 31)
32 (4, 2)
33 (1, 33)
34 (1, 34)
35 (1, 35)
36 (6, 1)
These are OEIS A000188 and A007913.

Related: A more complex version.
https://codegolf.stackexchange.com/questions/18535/convert-radicals-to-mixed-entire-radicals-and-to-real-numbers

"""

from sympy.ntheory.factor_ import core
from sympy import integer_nthroot, factorint
from math import prod

# https://oeis.org/A000188
def A000188(n):
    return integer_nthroot(n//core(n), 2)[0]

# https://oeis.org/A007913
def A007913(n):
    return prod(p for p, e in factorint(n).items() if e % 2)

def simplify(n):
    return (A000188(n), A007913(n))

def main():
    assert(simplify(1)) == (1, 1)
    assert(simplify(2)) == (1, 2)
    assert(simplify(3)) == (1, 3)
    assert(simplify(4)) == (2, 1)
    assert(simplify(5)) == (1, 5)
    assert(simplify(6)) == (1, 6)
    assert(simplify(7)) == (1, 7)
    assert(simplify(8)) == (2, 2)
    assert(simplify(9)) == (3, 1)
    assert(simplify(10)) == (1, 10)
    assert(simplify(11)) == (1, 11)
    assert(simplify(12)) == (2, 3)
    assert(simplify(13)) == (1, 13)
    assert(simplify(14)) == (1, 14)
    assert(simplify(15)) == (1, 15)
    assert(simplify(16)) == (4, 1)
    assert(simplify(17)) == (1, 17)
    assert(simplify(18)) == (3, 2)
    assert(simplify(19)) == (1, 19)
    assert(simplify(20)) == (2, 5)
    assert(simplify(21)) == (1, 21)
    assert(simplify(22)) == (1, 22)
    assert(simplify(23)) == (1, 23)
    assert(simplify(24)) == (2, 6)
    assert(simplify(25)) == (5, 1)
    assert(simplify(26)) == (1, 26)
    assert(simplify(27)) == (3, 3)
    assert(simplify(28)) == (2, 7)
    assert(simplify(29)) == (1, 29)
    assert(simplify(30)) == (1, 30)
    assert(simplify(31)) == (1, 31)
    assert(simplify(32)) == (4, 2)
    assert(simplify(33)) == (1, 33)
    assert(simplify(34)) == (1, 34)
    assert(simplify(35)) == (1, 35)
    assert(simplify(36)) == (6, 1)

main()
