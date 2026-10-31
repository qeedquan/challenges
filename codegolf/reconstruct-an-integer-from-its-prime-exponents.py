#!/usr/bin/env python3

"""

All integers n > 0 can be expressed in the form

n = ∏prime p p^e = 2^e2 * 3^e3 * 5e^5 * 7^e7 ...

This form is also known as it's prime factorisation or prime decomposition, and each integer has a unique prime factorisation.

As the bases are fixed, it is possible to reconstruct an integer when just given a list of the exponents of it's prime factorisation. For example, given E=[0,3,2,1,0,2] we can reconstruct n as

n=2^0 * 3^3 * 5^2 * 7^1 * 11^0 * 13^2 = 798525

Therefore, [0,3,2,1,0,2] -> 798525, and is the only such list (ignoring trailing zeros) that does so.

You are to take an input consisting of non-negative integers representing the exponents of the prime factorisation of some integer and output the integer with that prime factorisation.

Both the integer and the elements of the input will be within the bounds of your language, and you can take input in any convenient method. You may have an arbitrary (from 0 to infinite) number of trailing zeros in the input. The array will never be empty, but may be [0]

This is code-golf so the shortest code in bytes wins

Test cases
[0] -> 1
[1] -> 2
[3, 2] -> 72
[0, 1, 2] -> 75
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1] -> 347
[6, 2] -> 576
[1, 7] -> 4374
[5, 7] -> 69984
[10, 5] -> 248832
[1, 0, 0, 8, 4] -> 168804902882
[3, 8, 10] -> 512578125000
[7, 9, 0, 8] -> 14523977994624
[4, 4, 7, 0, 0, 5, 5] -> 53377275216476250000
[1, 8, 1, 7, 8, 1] -> 150570936449966222190
[10, 0, 2, 8, 9] -> 347983339699826969600
[4, 8, 2, 3, 7, 9] -> 186021488852335961308083600
[7, 6, 6, 8, 6, 8, 4] -> 1014472920935186644572261278658000000
[9, 6, 7, 5, 1, 8, 10] -> 8865565384329431006794755470280000000

"""

from sympy import *

def reconstruct(a):
    n = len(a)
    if n == 0:
        return 0

    r = 1
    p = 2
    for i in range(n):
        r *= p**a[i]
        p = nextprime(p)
    return r

def main():
    assert(reconstruct([0]) == 1)
    assert(reconstruct([1]) == 2)
    assert(reconstruct([3, 2]) == 72)
    assert(reconstruct([0, 1, 2]) == 75)
    assert(reconstruct([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1]) == 347)
    assert(reconstruct([6, 2]) == 576)
    assert(reconstruct([1, 7]) == 4374)
    assert(reconstruct([5, 7]) == 69984)
    assert(reconstruct([10, 5]) == 248832)
    assert(reconstruct([1, 0, 0, 8, 4]) == 168804902882)
    assert(reconstruct([3, 8, 10]) == 512578125000)
    assert(reconstruct([7, 9, 0, 8]) == 14523977994624)
    assert(reconstruct([4, 4, 7, 0, 0, 5, 5]) == 53377275216476250000)
    assert(reconstruct([1, 8, 1, 7, 8, 1]) == 150570936449966222190)
    assert(reconstruct([10, 0, 2, 8, 9]) == 347983339699826969600)
    assert(reconstruct([4, 8, 2, 3, 7, 9]) == 186021488852335961308083600)
    assert(reconstruct([7, 6, 6, 8, 6, 8, 4]) == 1014472920935186644572261278658000000)
    assert(reconstruct([9, 6, 7, 5, 1, 8, 10]) == 8865565384329431006794755470280000000)

main()
