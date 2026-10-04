#!/usr/bin/env python3

"""

Earlier, we talked about exponential generating functions (e.g.f.).

Task
You will take a few terms of a sequence.

Your task is to find another sequence with that many terms, whose e.g.f., when multiplied to the original e.g.f., would be exactly the constant function 1 accurate to that many terms.

That is, given a0=1, a1, a2, ..., an, find b0=1, b1, b2, ..., bn such that a0 + a1x + a2x^2/2! + a3x^3/3! + ... + anx^n/n! multiplied by b0 + b1x + b2x^2/2! + b3x^3/3! + ... + bnx^n/n! equals 1 + O(x^(n+1)).

Specs
They will start at the zeroth power and will be consecutive.
The first term is guaranteed to be 1.
All the terms are guaranteed to be integers.
There will not be negative powers.
Testcases
Input : 1,0,-1,0,1,0,-1,0 (this is actually cos x)
Output: 1,0, 1,0,5,0,61,0 (this is actually sec x)

Input : 1, 2, 4, 8, 16, 32 (e^(2x))
Output: 1,-2, 4,-8, 16,-32 (e^(-2x))

Input : 1,-1,0,0, 0,  0,  0 (1-x)
Output: 1, 1,2,6,24,120,720 (1/(1-x) = 1+x+x^2+...)

"""

# Ported from Sp3000 answer
def inverse(L):
    n = len(L)
    E = [1] + [0]*(n + 1)
    F = []
    I = []

    f = 1
    for i in range(1, n+1):
        F.append(f)
        f *= i

    for i in range(n):
        c = E[i] // L[0]
        I.append(c)
        for j in range(n - i):
            E[i + j] -= (c * L[j] * F[i + j]) // F[j] // F[i]
    return I

def main():
    assert(inverse([1, 0, -1, 0, 1, 0, -1, 0]) == [1, 0, 1, 0, 5, 0, 61, 0])
    assert(inverse([1, 2, 4, 8, 16, 32]) == [1, -2, 4, -8, 16, -32])
    assert(inverse([1, -1, 0, 0, 0, 0, 0]) == [1, 1, 2, 6, 24, 120, 720])

main()
