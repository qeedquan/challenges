#!/usr/bin/env python3

"""

Find the value of a^(b^c) (mod 10^9 + 7)

Input
The first line contains the number of test cases n. Each of the next n lines contains three numbers a,b,c (a,b,c≤10^9).

Output
For each test case print in a separate line the value of a^(b^c)(mod 10^9 + 7).

Examples
Input #1
3
3 7 1
15 2 2
3 4 5

Answer #1
2187
50625
763327764

"""

"""

https://stackoverflow.com/questions/62057039/calculating-abc-mod-1097

Because M = 10^9+7 is a prime number, Fermat's Little Theorem states that for any integer a not divisible by M:

a^(M-1) = 1 (mod M)

Since M-1 = 10^9+6, any exponent can be simplified by taking its value modulo 10^9+6 before raising the base a to that power.

So the expression can be simplified to:

E = (b^c (mod 10^9 + 6))
R = a^E (mod 10^9 + 7)

"""

def solve(a, b, c):
    mod = 1_000_000_007
    return pow(a, pow(b, c, mod - 1), mod)

def main():
    assert(solve(3, 7, 1) == 2187)
    assert(solve(15, 2, 2) == 50625)
    assert(solve(3, 4, 5) == 763327764)

main()
