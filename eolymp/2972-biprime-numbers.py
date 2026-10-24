#!/usr/bin/env python3

"""

A natural number greater than 1 is called prime if it is divisible only by 1 and itself.

A number P is called biprime if it is prime, and its decimal representation can be obtained by concatenating the decimal representations of two other prime numbers P1 and P2.
P1 and P2 must not have leading zeros.

For example, the prime number 1123 is biprime because it is written using the two prime numbers 11 and 23.
Similarly, the prime number 617 is biprime because it is made from 61 and 7, which are both prime.
The number 1103 is not biprime, since expressing it as 11 and 03 would require the second number to have a leading zero.

Given a natural number N (1<N≤10^10), determine whether it is biprime.

Input
The input file contains a single natural number N (1<N≤10^10).

Output
Output YES if the number from the input file is biprime; otherwise, output NO.

Examples

Input #1
1123

Answer #1
YES

"""

from sympy import isprime

# https://oeis.org/A105184
def biprime(n):
    if not isprime(n):
        return "NO"

    s = str(n)
    for i in range(len(s)):
        s1 = s[:i+1]
        s2 = s[i+1:]
        if s1 == "" or s2 == "" or s1.startswith("0") or s2.startswith("0"):
            continue

        p1 = int(s1, 10)
        p2 = int(s2, 10)
        if isprime(p1) and isprime(p2):
            return "YES"
    return "NO"

def main():
    tab = [
        23, 37, 53, 73, 113, 137, 173, 193, 197, 211, 223, 229, 233, 241, 271,
        283, 293, 311, 313, 317, 331, 337, 347, 353, 359, 367, 373, 379, 383,
        389, 397, 433, 523, 541, 547, 571, 593, 613, 617, 673, 677, 719, 733,
        743, 761, 773, 797, 977, 1013, 1033, 1093
    ]

    assert(biprime(1123) == "YES")
    assert(biprime(1103) == "NO")

    for i in range(max(tab) + 1):
        if i in tab:
            assert(biprime(i) == "YES")
        else:
            assert(biprime(i) == "NO")

main()
