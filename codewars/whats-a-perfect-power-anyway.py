#!/usr/bin/env python3

"""

A perfect power is a classification of positive integers:

In mathematics, a perfect power is a positive integer that can be expressed as an integer power of another positive integer. More formally, n is a perfect power if there exist natural numbers m > 1, and k > 1 such that mk = n.

Your task is to check wheter a given integer is a perfect power. If it is a perfect power, return a pair m and k with mk = n as a proof. Otherwise return Nothing, Nil, null, NULL, None or your language's equivalent.

Note: For a perfect power, there might be several pairs. For example 81 = 3^4 = 9^2, so (3,4) and (9,2) are valid solutions. However, the tests take care of this, so if a number is a perfect power, return any pair that proves it.

Examples
isPP 4 `shouldBe` Just (2,2)
isPP 9 `shouldBe` Just (3,2)
isPP 5 `shouldBe` Nothing

"""

from sympy import factorint

def is_perfect_power(n):
    f = factorint(n)
    if len(f) != 1:
        return None

    for x in f:
        if f[x] != 1:
            return [x, f[x]]
    return None

def main():
    assert(is_perfect_power(0) == None)
    assert(is_perfect_power(1) == None)
    assert(is_perfect_power(2) == None)
    assert(is_perfect_power(3) == None)
    assert(is_perfect_power(4) == [2, 2])
    assert(is_perfect_power(5) == None)
    assert(is_perfect_power(8) == [2, 3])
    assert(is_perfect_power(9) == [3, 2])

main()
