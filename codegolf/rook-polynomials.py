#!/usr/bin/env python3

"""

In combinatorics, the rook polynomial Rm,n(x) of a m×n chessboard is the generating function for the numbers of arrangements of non-attacking rooks. To be precise:

Rm,n(x) = Sum[k=0, min(m, n)] r[k]*x^[k]

where r[k] is the number of ways to place k rooks on an m×n chessboard such that no two rooks attack each other; that is, no two rooks are in the same row or column.

The first few rook polynomials on square chessboards are:

R1,1(x)=x + 1
R2,2(x)=2x^2 + 4x + 1
R3,3(x)=6x^3 + 18x^2 + 9x + 1
R4,4(x)=24x^4 + 96x^3 + 72x^2 + 16x + 1

For example, there are 2 ways to place two rooks on a 2×2 chessboard, 4 ways to place one rook, and 1 way to place no rooks. Therefore, R2,2(x)=2x^2 + 4x + 1.

Rook placements on a 2x2 chessboard

(The image above comes from Wolfram MathWorld.)

The rook polynomials are closely related to the generalized Laguerre polynomials by the following formula:

Rm,n(x) = n! * x^n * L(m-n, n) * (-x^-1)

Task

Your task is to write a program or function that, given two positive integers m and n, outputs or returns the rook polynomial Rm,n(x).

You may output the polynomials in any reasonable format. Here are some example formats:

a list of coefficients, in descending order, e.g. 24x^4 + 96x^3 + 72x^2 + 16x + 1 is represented as [24,96,72,16,1];
a list of coefficients, in ascending order, e.g. 24x^4 + 96x^3 + 72x^2 + 16x + 1 is represented as [1,16,72,96,24];
a function that takes an input k and gives the coefficient of x[k];
a built-in polynomial object.
You may also take three integers m, n, and k as input, and output the coefficient of x[k] in Rm,n(x). You may assume that 0≤k≤min(m,n).

This is code-golf, so the shortest code in bytes wins.

Test Cases
Here I output lists of coefficients in descending order.

1,1 -> [1,1]
1,2 -> [2,1]
1,3 -> [3,1]
1,4 -> [4,1]
1,5 -> [5,1]
2,1 -> [2,1]
2,2 -> [2,4,1]
2,3 -> [6,6,1]
2,4 -> [12,8,1]
2,5 -> [20,10,1]
3,1 -> [3,1]
3,2 -> [6,6,1]
3,3 -> [6,18,9,1]
3,4 -> [24,36,12,1]
3,5 -> [60,60,15,1]
4,1 -> [4,1]
4,2 -> [12,8,1]
4,3 -> [24,36,12,1]
4,4 -> [24,96,72,16,1]
4,5 -> [120,240,120,20,1]
5,1 -> [5,1]
5,2 -> [20,10,1]
5,3 -> [60,60,15,1]
5,4 -> [120,240,120,20,1]
5,5 -> [120,600,600,200,25,1]

"""

from math import *

# https://en.wikipedia.org/wiki/Rook_polynomial
def rookpoly(m, n):
    r = []
    for k in range(min(m, n) + 1):
        r.append(factorial(k) * comb(m, k) * comb(n, k))
    return r[::-1]

def main():
    assert(rookpoly(1, 1) == [1, 1])
    assert(rookpoly(1, 2) == [2, 1])
    assert(rookpoly(1, 3) == [3, 1])
    assert(rookpoly(1, 4) == [4, 1])
    assert(rookpoly(1, 5) == [5, 1])
    assert(rookpoly(2, 1) == [2, 1])
    assert(rookpoly(2, 2) == [2, 4, 1])
    assert(rookpoly(2, 3) == [6, 6, 1])
    assert(rookpoly(2, 4) == [12, 8, 1])
    assert(rookpoly(2, 5) == [20, 10, 1])
    assert(rookpoly(3, 1) == [3, 1])
    assert(rookpoly(3, 2) == [6, 6, 1])
    assert(rookpoly(3, 3) == [6, 18, 9, 1])
    assert(rookpoly(3, 4) == [24, 36, 12, 1])
    assert(rookpoly(3, 5) == [60, 60, 15, 1])
    assert(rookpoly(4, 1) == [4, 1])
    assert(rookpoly(4, 2) == [12, 8, 1])
    assert(rookpoly(4, 3) == [24, 36, 12, 1])
    assert(rookpoly(4, 4) == [24, 96, 72, 16, 1])
    assert(rookpoly(4, 5) == [120, 240, 120, 20, 1])
    assert(rookpoly(5, 1) == [5, 1])
    assert(rookpoly(5, 2) == [20, 10, 1])
    assert(rookpoly(5, 3) == [60, 60, 15, 1])
    assert(rookpoly(5, 4) == [120, 240, 120, 20, 1])
    assert(rookpoly(5, 5) == [120, 600, 600, 200, 25, 1])

main()
