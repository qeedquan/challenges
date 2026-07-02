#!/usr/bin/env python3

"""

Taken from the book: Marvin Minsky 1967 - Computation:
Finite and Infinite Machines, chapter 14.

Background
As the Gödel proved, it is possible to encode with a unique positive integer not just any string but any list structure, with any level of nesting.

Procedure of encoding G(x) is defined inductively:

If x is a number, G(x)=2^x
If x is a list [n0,n1,n2,n3,…], G(x)=3^G(n0)*5^G(n1)*7^G(n2)*11*G(n^3)⋅...

Bases are consecutive primes.
Examples:
[0] → 3

[[0]] → 33 = 27

[1, 2, 3] → 321⋅522⋅723 = 32427005625

[[0, 1], 1] → 3320⋅521⋅521 = 15206669692833942727992099815471532675

Task
Create a program that encoding (in this way) any given (possibly ragged) list to integer number.
This is code-golf, so the shortest code in bytes wins.

Input
Valid non-empty list.
UPD
Some considerations regarding empty lists are given here.

You may assume:

There are no empty sublists
Structure is not broken (all parentheses are paired)
List contains only non-negative integers
Output
Positive integer obtained by the specified algorithm

Note
Numbers can be very large, be careful! Your code must be correct in principle, but it is acceptable that it cannot print some number. However, all test cases are checked for TIO with Mathematica program and work correctly.

Test cases
[0,0,0,0,0] → 15015
[1, 1, 1] → 11025
[[1], [1]] → 38443359375
[0, [[0]], 0] → 156462192535400390625
[[[0], 0], 0] → 128925668357571406980580744739545891609191243761536322527975268535


"""

from sympy import *

def encode(a):
    if isinstance(a, int):
        return 2**a
    elif isinstance(a, list):
        r = 1
        p = 3
        for v in a:
            r *= p**encode(v)
            p = nextprime(p)
        return r
    else:
        raise "unsupported type"

def main():
    assert(encode([0]) == 3)
    assert(encode([[0]]) == 27)
    assert(encode([1, 2, 3]) == 32427005625)
    assert(encode([[0, 1], 1]) == 15206669692833942727992099815471532675)
    assert(encode([0, 0, 0, 0, 0]) == 15015)
    assert(encode([1, 1, 1]) == 11025)
    assert(encode([[1], [1]]) == 38443359375)
    assert(encode([0, [[0]], 0]) == 156462192535400390625)
    assert(encode([[[0], 0], 0]) == 128925668357571406980580744739545891609191243761536322527975268535)
    assert(encode([1]) == 9)
    assert(encode([[0], [0]]) == 3375)
    assert(encode([0, [1]]) == 5859375)
    assert(encode([3, 2, 1, 0]) == 2210236875)
    assert(encode([[[0]]]) == 7625597484987)

main()
