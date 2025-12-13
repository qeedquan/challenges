#!/usr/bin/env python3

"""

Given a positive integer n, output all of its anti-divisors in any order.

From OEIS A006272:

Anti-divisors are the numbers that do not divide a number by the largest possible margin. E.g. 20 has anti-divisors 3, 8 and 13. An alternative name for anti-divisor is unbiased non-divisors.

In other words, 1 < m < n is an anti-divisor of n if either

m is even and n % m == m/2, or
m is odd and n % m is equal to either (m-1)/2 or (m+1)/2.
Notably, 1 is not an anti-divisor of any number because it does not satisfy the phrase "do not divide a number".

Standard code-golf rules apply. Shortest code in bytes wins.

Test cases
1 -> []
2 -> []
3 -> [2]
4 -> [3]
5 -> [2, 3]
6 -> [4]
7 -> [2, 3, 5]
8 -> [3, 5]
9 -> [2, 6]
10 -> [3, 4, 7]
18 -> [4, 5, 7, 12]
20 -> [3, 8, 13]
234 -> [4, 7, 12, 36, 52, 67, 156]
325 -> [2, 3, 7, 10, 11, 21, 26, 31, 50, 59, 93, 130, 217]

"""

from sympy import divisors

# https://oeis.org/A066272 (related)
def antidivisors(n):
    r = []
    for i in range(2, n):
        x = 2*(n%i) - i
        if -2 < x and x < 2:
            r.append(i)
    return r

def main():
    assert(antidivisors(1) == [])
    assert(antidivisors(2) == [])
    assert(antidivisors(3) == [2])
    assert(antidivisors(4) == [3])
    assert(antidivisors(5) == [2, 3])
    assert(antidivisors(6) == [4])
    assert(antidivisors(7) == [2, 3, 5])
    assert(antidivisors(8) == [3, 5])
    assert(antidivisors(9) == [2, 6])
    assert(antidivisors(10) == [3, 4, 7])
    assert(antidivisors(18) == [4, 5, 7, 12])
    assert(antidivisors(20) == [3, 8, 13])
    assert(antidivisors(234) == [4, 7, 12, 36, 52, 67, 156])
    assert(antidivisors(325) == [2, 3, 7, 10, 11, 21, 26, 31, 50, 59, 93, 130, 217])

main()
