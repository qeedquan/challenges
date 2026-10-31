#!/usr/bin/env python3

"""

Given an integer n >= 2, output the largest exponent in its prime factorization. This is OEIS sequence A051903.

Example
Let n = 144. Its prime factorization is 2^4 * 3^2. The largest exponent is 4.

Test Cases
2 -> 1
3 -> 1
4 -> 2
5 -> 1
6 -> 1
7 -> 1
8 -> 3
9 -> 2
10 -> 1
11 -> 1
12 -> 2
144 -> 4
200 -> 3
500 -> 3
1024 -> 10
3257832488 -> 3

"""

from sympy import factorint

# https://oeis.org/A051903
def largest_prime_exponent(n):
    f = factorint(n)
    m = 0
    for p in f:
        m = max(m, f[p])
    return m

def main():
    assert(largest_prime_exponent(2) == 1)
    assert(largest_prime_exponent(3) == 1)
    assert(largest_prime_exponent(4) == 2)
    assert(largest_prime_exponent(5) == 1)
    assert(largest_prime_exponent(6) == 1)
    assert(largest_prime_exponent(7) == 1)
    assert(largest_prime_exponent(8) == 3)
    assert(largest_prime_exponent(9) == 2)
    assert(largest_prime_exponent(10) == 1)
    assert(largest_prime_exponent(11) == 1)
    assert(largest_prime_exponent(12) == 2)
    assert(largest_prime_exponent(144) == 4)
    assert(largest_prime_exponent(200) == 3)
    assert(largest_prime_exponent(500) == 3)
    assert(largest_prime_exponent(1024) == 10)
    assert(largest_prime_exponent(3257832488) == 3)

main()
