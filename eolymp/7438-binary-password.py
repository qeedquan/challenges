#!/usr/bin/env python3

"""

Jomart uses a binary string as the password for his computer.
Recently, he forgot his old password and now wants to obtain a new one, which will be a binary string of length n.
He considers a password sufficiently secure if it does not contain two consecutive zeros.

To obtain a new password, Jomart generates a random binary string of length n.
If the string is not secure, he generates another one and repeats the process until he obtains a secure password.

Find the expected number of randomly generated passwords Jomart will need before he finds a secure one.

Input
One integer n (1≤n≤60).

Output
Print the expected value as a fraction p/q, where p and q are coprime positive integers.

Examples
Input #1
1

Answer #1
1/1

Input #2
4

Answer #2
2/1

"""

from sympy import fibonacci
from math import gcd

def solve(n):
    p = fibonacci(n + 2) 
    q = 2**n
    m = gcd(p, q)
    return "%d/%d" % (q//m, p//m)

def main():
    assert(solve(1) == "1/1")
    assert(solve(4) == "2/1")

main()
