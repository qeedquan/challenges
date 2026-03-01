#!/usr/bin/env python3

"""

Task description
In number theory, the Carmichael function λ takes a positive integer n and returns the least positive integer k so that the k-th power of each integer coprime to n equals 1 modulo n.

Given a positive integer n, your solution must compute λ(n). The shortest code in bytes wins.

Your program should theoretically work for arbitrarily large inputs, but doesn’t need to be efficient.

Tips
The sequence of all λ(n) is OEIS A002322.

An ungolfed Python implementation would look like

from fractions import gcd

def carmichael(n):
    coprimes = [x for x in range(1, n) if gcd(x, n) == 1]
    k = 1
    while not all(pow(x, k, n) == 1 for x in coprimes):
        k += 1
    return k

(In Python, pow(A, B, C) efficiently computes pow(A, B) % C.)

Test cases
Input    Output
1        1
2        1
3        2
10       4
35       12
101      100
530      52
3010     84
6511     3056
10000    500

"""

from sympy import reduced_totient

# https://oeis.org/A002322
def psi(n):
    return reduced_totient(n)

def main():
    tab = [1, 1, 2, 2, 4, 2, 6, 2, 6, 4, 10, 2, 12, 6, 4, 4, 16, 6, 18, 4, 6, 10, 22, 2, 20, 12, 18, 6, 28, 4, 30, 8, 10, 16, 12, 6, 36, 18, 12, 4, 40, 6, 42, 10, 12, 22, 46, 4, 42, 20, 16, 12, 52, 18, 20, 6, 18, 28, 58, 4, 60, 30, 6, 16, 12, 10, 66, 16, 22, 12, 70, 6, 72, 36, 20, 18, 30, 12, 78, 4, 54]

    for i in range(len(tab)):
        assert(psi(i + 1) == tab[i])

    assert(psi(1) == 1)
    assert(psi(2) == 1)
    assert(psi(3) == 2)
    assert(psi(10) == 4)
    assert(psi(35) == 12)
    assert(psi(101) == 100)
    assert(psi(530) == 52)
    assert(psi(3010) == 84)
    assert(psi(6511) == 3056)
    assert(psi(10000) == 500)

main()
