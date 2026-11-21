#!/usr/bin/env python3

"""

So we already seen and used Linear Congruential Generator for random numbers.

It is still used as default generator in some languages and platforms, for example in Java (see java.util.Random documentation). But it is not good for use when some degree of security is needed. For example if we create Online Casino and use LCG to generate random values in some game - someone can "hack" the generator - i.e. observe several consecutive values and predict all following sequence!

There are many variants of such task depending on how end-values are created from LCG output numbers, but let's try such hacking ourselves with very simple setup.

Problem Statement
We have LCG which for each current random value Xcur generates next one Xnext using formula

Xnext = (A * Xcur + C) % M

(where M is 2^64)
In this problem M is known, while A and C are secret. In real life M may be not known too, but also could be guessed by hacker observing some more random values and keeping in mind there are certain constraints on M according to algorithm.

We are given 3 consecutive random values and need to guess next one.

Input data contain number of testcases in the first line.
Every test-case is in separate line and consists of 3 consecutive random values.
Answer should give next random value for each triple.

Example:

input data:
2
1583335398591491603 4594626647299482044 5406677071358476037
91747539843581256 16069457834793478749 9723492319865122198

answer:
12537733515844291054 11832547052504454083

"""

"""

https://github.com/jvdsn/crypto-attacks/blob/master/attacks/lcg/parameter_recovery.py

To recover a and b given m, we need at least 3 values in the sequence:

Solve for a:
X2 - X1 ≡ a*(X1 - X0) mod m
a ≡ (X2 - X1) * (X1 - X0)^-1 mod m

Solve for b:
X1 ≡ (a*X0 + b) mod m
b ≡ (X1 - a*X0) mod m

Note that the modular inverse has to exist for this to work

"""

def solve(x0, x1, x2):
    m = 2**64
    a = ((x2 - x1) * pow(x1 - x0, -1, m)) % m
    b = (x1 - a*x0) % m
    return (a*x2 + b) % m

def main():
    assert(solve(1583335398591491603, 4594626647299482044, 5406677071358476037) == 12537733515844291054)
    assert(solve(91747539843581256, 16069457834793478749, 9723492319865122198) == 11832547052504454083)

main()
