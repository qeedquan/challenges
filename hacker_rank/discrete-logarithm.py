#!/usr/bin/env python3

"""

You are probably familiar with the concept logarithm or log. The logarithm of a number b to the base a is the exponent by which a must be raised to yield b. In other words, it is the number x such that

a^x = b

For example, the logarithm of 1/8 to the base 2 is -3, because 2^-3 = 1/8.

Note that in complex numbers, there can be multiple logarithms of a number to a given base. For example, pi*i and 3*pi*i are two of the logarithms of -1 to the base e, because e^(pi*i)=-1 (Euler's identity), so by cubing both sides we also get e^(3*pi*i) = -1. There are also times when logarithms do not exist at all. For example, there is no logarithm of 2 to the base 1.


The discrete logarithm, or discrete log, is similar to the ordinary logarithm. A discrete logarithm modulo g of an integer b to the base a is an integer x such that

a^x ≅ b (mod g)

The problem of computing the discrete logarithm given a, b, and g is a well-known challenge in the field of cryptography, and is in fact the basis of some cryptographic systems, such as the Diffie-Hellman key exchange.

Professor Devu was teaching cryptography in the class and told that if we could find a solution of a given problem in logarithmic time, then all cryptosystems relying on the difficulty of the discrete log problem (such as the Diffie-Hellman key exchange) will break. Students were interested in the best way to solve the discrete log problem for small values of g (at least relatively small compared to the sizes of numbers actually used in cryptography). Devu gave this problem to his students as an assignment and explained the meet-in-the-middle technique as a hint.

Could you help them solve the problem? See constraints and I/O format for more details.

Input Format

The first line will contain an integer, T, denoting the number of test cases.

The next T lines will contain three integers which will denote the value of a, b, and g, respectively.

Constraints:
1 <= T <= 10
1 <= a < g
1 <= b < g
2 <= g < 10^10
gcd(a, g) = 1

Output Format

For each a, b, and g, print the smallest positive discrete log of b to the base a, modulo g. If there are no discrete logs, print -1.

Sample Input

5
3 2 5
2 5 11
233529 184091 329746
26161 23893 62356
126995 142647 270599

Sample Output

3
4
57897
223
204

"""

from sympy.ntheory import *

def solve(a, b, g):
    return discrete_log(g, b, a)

def main():
    assert(solve(3, 2, 5) == 3)
    assert(solve(2, 5, 11) == 4)
    assert(solve(233529, 184091, 329746) == 57897)
    assert(solve(26161, 23893, 62356) == 223)
    assert(solve(126995, 142647, 270599) == 204)

main()
