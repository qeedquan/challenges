#!/usr/bin/env python3

"""

A number is a de Polignac number if and only if it is odd and cannot be represented in the form p + 2n where n is a non-negative integer and p is a prime integer.

Task
Write some code that takes a positive integer and determines if it is a de Polignac number. You may output two distinct values one for true and one for false. You should aim to minimize your byte count.

Test Cases
For positive cases here's the OEIS

1, 127, 149, 251, 331, 337, 373, 509, 599, 701, 757, 809, 877, 905, 907, 959, 977, 997, 1019, 1087, 1199, 1207, 1211, 1243, 1259, 1271, 1477, 1529, 1541, 1549, 1589, 1597, 1619, 1649, 1657, 1719, 1759, 1777, 1783, 1807, 1829, 1859, 1867, 1927, 1969, 1973, ...
Here are some negative cases:

22, 57

"""

from sympy import isprime

# https://oeis.org/A006285
def de_polignac(n):
    if n < 1 or n&1 == 0:
        return False

    l = n.bit_length()
    for i in range(n - 1, -1, -1):
        if isprime(n - (1<<i)):
            return False
    return True

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if de_polignac(i):
            r.append(i)
        i += 2
    return r

def main():
    tab = [1, 127, 149, 251, 331, 337, 373, 509, 599, 701, 757, 809, 877, 905, 907, 959, 977, 997, 1019, 1087, 1199, 1207, 1211, 1243, 1259, 1271, 1477, 1529, 1541, 1549, 1589, 1597, 1619, 1649, 1657, 1719, 1759, 1777, 1783, 1807, 1829, 1859, 1867, 1927, 1969, 1973, 1985, 2171, 2203, 2213, 2231, 2263, 2279, 2293, 2377, 2429, 2465, 2503, 2579, 2669]
    
    assert(gen(len(tab)) == tab)

main()
