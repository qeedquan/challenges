#!/usr/bin/env python3

"""

Recently, Vasya discovered that it is possible to play a very interesting game with balls.
In this game, balls are arranged in the form of various geometric figures and solids.
Currently, Vasya is arranging balls in the shape of an equilateral triangle.
However, there is a problem: sometimes he does not have enough balls,
and then he wants to know what is the maximum possible side length of such a triangle given the number of balls he has.

Help Vasya: write a program that computes n — the side length of the equilateral triangle for a given number of balls k.

Below is an example of arranging balls in the shape of an equilateral triangle:

https://static.e-olymp.com/content/c0/c0522613f2195bf12b87fd6c2c32eb8dbb171e72.gif

Input
One non-negative integer k (0≤k≤2⋅10^8) — the number of balls available.

Output
Print the number n — the answer to the problem.

Examples

Input #1
6

Answer #1
3

Input #2
5

Answer #2
2

"""

from math import isqrt

def solve(k):
    if k < 0:
        return 0
    return (isqrt(1 + 8*k) - 1) // 2

def main():
    assert(solve(6) == 3)
    assert(solve(5) == 2)

main()

