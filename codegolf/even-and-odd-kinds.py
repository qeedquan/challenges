#!/usr/bin/env python3

"""

Let  n be some positive integer.
We say that n is of even kind if the prime factorisation of n (counting duplicates) has an even number of integers.
For example,  6=2×3 is of even kind.
Likewise, we say n is of odd kind of the prime factorisation of n has an odd number of integers, such as 18=2×3×3.
Note that as the prime factorisation of 1 contains 0 primes, it is of even kind.

Let E(n) be the count of positive integers of even kind less than or equal to n,
and O(n) be the count of positive integers of odd kind less than or equal to n.
For example, for  n=14, we have E(14)=6 (1,4,6,9,10,14), and O(14)=8 (2,3,5,7,8,11,12,13)
You are to write a program which takes some positive integer n≥1 as input, and outputs the two values E(n) and O(n).
You may input and output in any convenient method,
and you may output the two outputs in any format that consistently presents the values (e.g.
you cannot output one in unary and another in decimal),
and that clearly distinguishes between the two (typically, has some kind of obvious delimiter).

This is a code-golf challenge, so the shortest code in bytes wins.

Test cases
n -> [E(n), O(n)]
1 -> [1, 0]
2 -> [1, 1]
3 -> [1, 2]
4 -> [2, 2]
5 -> [2, 3]
6 -> [3, 3]
7 -> [3, 4]
8 -> [3, 5]
9 -> [4, 5]
10 -> [5, 5]
11 -> [5, 6]
12 -> [5, 7]
13 -> [5, 8]
14 -> [6, 8]
15 -> [7, 8]
16 -> [8, 8]
17 -> [8, 9]
18 -> [8, 10]
19 -> [8, 11]
20 -> [8, 12]

"""

from sympy import factorint

def count_factors(n):
    f = factorint(n)
    r = 0
    for p in f:
        r += f[p]
    return r

"""

@Bubbler

Trivia: Polya conjecture states that E(n) <= O(n) for all n >= 2.
This conjecture was proven to be false, with the smallest counterexample being n = 906,150,257

https://en.wikipedia.org/wiki/P%C3%B3lya_conjecture

"""

def solve(n):
    e, o = 0, 0
    for i in range(1, n + 1):
        if count_factors(i)%2 == 0:
            e += 1
        else:
            o += 1
    return [e, o]

def main():
    assert(solve(1) == [1, 0])
    assert(solve(2) == [1, 1])
    assert(solve(3) == [1, 2])
    assert(solve(4) == [2, 2])
    assert(solve(5) == [2, 3])
    assert(solve(6) == [3, 3])
    assert(solve(7) == [3, 4])
    assert(solve(8) == [3, 5])
    assert(solve(9) == [4, 5])
    assert(solve(10) == [5, 5])
    assert(solve(11) == [5, 6])
    assert(solve(12) == [5, 7])
    assert(solve(13) == [5, 8])
    assert(solve(14) == [6, 8])
    assert(solve(15) == [7, 8])
    assert(solve(16) == [8, 8])
    assert(solve(17) == [8, 9])
    assert(solve(18) == [8, 10])
    assert(solve(19) == [8, 11])
    assert(solve(20) == [8, 12])

main()
