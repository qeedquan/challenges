#!/usr/bin/env python3

r"""

Challenge:
Given inputs i and n, calculate R_i(n) where:

R[0](n) = n
R[i](n) = Sum[j=0, n] R[i-1](j)

Note that R[1] is triangular function, and R[2] is tetrahedral function.

This is code golf, shortest answer in bytes wins.

Test cases:
[0,0]   => 0
[0,1]   => 1
[0,999] => 999
[1,0]   => 0
[1,1]   => 1
[1,2]   => 3
[1,3]   => 6
[1,4]   => 10
[1,10]  => 55
[1,30]  => 465
[1,99]  => 4950
[2,0]   => 0
[2,1]   => 1
[2,2]   => 4
[2,3]   => 10
[2,10]  => 220
[3,10]  => 715
[4,10]  => 2002
[4,11]  => 3003
[9,10]  => 92378
[32,6]  => 501942

"""

from math import comb

def R(i, n):
    return comb(n + i, i + 1)

def main():
    assert(R(0, 0) == 0)
    assert(R(0, 1) == 1)
    assert(R(0, 999) == 999)
    assert(R(1, 0) == 0)
    assert(R(1, 1) == 1)
    assert(R(1, 2) == 3)
    assert(R(1, 3) == 6)
    assert(R(1, 4) == 10)
    assert(R(1, 10) == 55)
    assert(R(1, 30) == 465)
    assert(R(1, 99) == 4950)
    assert(R(2, 0) == 0)
    assert(R(2, 1) == 1)
    assert(R(2, 2) == 4)
    assert(R(2, 3) == 10)
    assert(R(2, 10) == 220)
    assert(R(3, 10) == 715)
    assert(R(4, 10) == 2002)
    assert(R(4, 11) == 3003)
    assert(R(9, 10) == 92378)
    assert(R(32, 6) == 501942)

main()
