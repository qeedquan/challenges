#!/usr/bin/env python3

"""

Introduction to Bézout's identity
The GCD of two integers A, B is the largest positive integer that divides both of them leaving no remainder. Now because of Euclid's property that each integer N can be divided by another integer M as follows:

N = M*q + r where 0 <= r < M

there exist pairs u,v such that we can write:

gcd(A, B) = u*A + v*B

Since there is an infinite amount of those pairs, we'd like to find special ones. There are in fact exactly (A,B not being zero) two such pairs that satisfy

|u| < |B / gcd(A, B)| and
|v| < |A / gcd(A, B)|

eg
gcd(19, 17) = -8*19 + 9*17 = 9*19 + (-10)*17

Challenge
The goal of this challenge is to find the (ordered) pair of coefficients (u,v) that satify the above constraints and where u must be positive. This narrows down the output to a unique pair.

Input
We may assume that the input is positive, also A will always be larger than B (A > B).

Output
The output of our program/function must be the (ordered) pair specified in the challenge.

Rules
One must not use built-in extended Euclidean algorithms (e.g. in Mathematica one is allowed to use GCD but not ExtendedGCD - which would fail for 5,3 anyways).

The answer may be a full program (taking input via STDIN or similar and output via STDOUT) or a function (returning the pair).

Beside the pair (u,v) there shall not be any output, trailing newlines or spaces are allowed. (brackets or commas are fine)

This is code golf, all standard loopholes are forbidden and the program with the lowest byte count wins.

Examples
(A, B) -> (u, v)
(42, 12) -> (1, -3)
(4096, 84) -> (4, -195)
(5, 3) -> (2, -3)
(1155, 405) -> (20, -57)
(37377, 5204) -> (4365, -31351)
(7792, 7743) -> (7585, -7633)
(38884, 2737) -> (1707, -24251)
(6839, 746) -> (561, -5143)
(41908, 7228) -> (1104, -6401)
(27998, 6461) -> (3, -13)
(23780, 177) -> (20, -2687)
(11235813, 112358) -> (8643, -864301)

"""

# ported from @Sherlock9 solution
def exgcd(a, b):
    r = b
    x = a
    s = 0
    y = 1 
    t = 1
    z = 0
    while r != 0:
        q = x // r
        x, r = r, x % r
        y, s = s, y - q * s
        z, t = t, z - q * t
    return y % (b // x), z % (-a // x)

def main():
    assert(exgcd(42, 12) == (1, -3))
    assert(exgcd(4096, 84) == (4, -195))
    assert(exgcd(5, 3) == (2, -3))
    assert(exgcd(1155, 405) == (20, -57))
    assert(exgcd(37377, 5204) == (4365, -31351))
    assert(exgcd(7792, 7743) == (7585, -7633))
    assert(exgcd(38884, 2737) == (1707, -24251))
    assert(exgcd(6839, 746) == (561, -5143))
    assert(exgcd(41908, 7228) == (1104, -6401))
    assert(exgcd(27998, 6461) == (3, -13))
    assert(exgcd(23780, 177) == (20, -2687))
    assert(exgcd(11235813, 112358) == (8643, -864301))

main()
