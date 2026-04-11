#!/usr/bin/env python3

"""

Alice is really bad at arithmetic. Sometimes she can’t properly add two single-digit numbers without
using a computer! It is quite embarrassing, so she comes up with silly explanations when someone spots
an error. Last time, after writing 5 + 4 = 10, Alice said — “Hey, this is right in base 9!”.
Since you know how to program, can you help Alice and check her last bunch of calculations for
any mistakes she might have left? She considers expression “correct” if equality is satisfied for any
positional numeral system with base B (1 ≤ B) (in base 1 character ‘1’ is used as only possible digit).

Input

The number of expressions T (T ≤ 100) is given on the first line. Following T lines each have an
expression in format A + B = C, where A, B, C (0 ≤ A + B, C ≤ 10^5) are non-negative decimal integers.

Output
For each expression, output a single line with the smallest counting system base B in which expression
is correct. In case there is no such base, output ‘0’.

Sample Input
4
155 + 102 = 301
1022 + 221 = 1303
6502 + 6800 = 11202
515 + 7 = 522

Sample Output
6
4
0
10

"""

def convb(n, b, p):
    if b < 1:
        return 0

    d = []
    while n > 0:
        d.append(n % b)
        n //= b
    
    r = 0
    for i in range(len(d)-1, -1, -1):
        r = (r * p) + d[i]
    return r

def solve(x, y, z):
    n = max(x, y, 36) + 1
    for i in range(1, n):
        a = convb(x, 10, i)
        b = convb(y, 10, i)
        c = convb(z, 10, i)
        if a+b == c:
            return i
    return 0

def main():
    assert(solve(5, 4, 10) == 9)
    assert(solve(155, 102, 301) == 6)
    assert(solve(1022, 221, 1303) == 4)
    assert(solve(6502, 6800, 11202) == 0)
    assert(solve(515, 7, 522) == 10)

main()

