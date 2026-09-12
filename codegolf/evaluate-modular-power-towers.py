#!/usr/bin/env python3

"""

Given two numbers n and m, evaluate the infinite power tower:

n^(n+1)^(n+2)^(n+3)^(n+4)^... mod m

Keep in mind that ^ is right-associative. So 2^3^4 = 2^(3^4). Now how can you possibly assign a value to an infinite sequence of right-associative operators?

Define f(n,m,i) as the power tower containing the first i terms of the infinite power tower.
Then there is some constant C such that for every i > C, f(n,m,i) = f(n,m,C).
So you could say the infinite power tower converges on a certain value. We're interested in that value.

Your program must be able to compute n = 2017, m = 10^10 in under 10 seconds on a reasonable modern PC. That is, you should implement an actual algorithm, no bruteforcing.

You may assume that n < 2^30 and m < 2^50 for the numerical limits in your programming language, but your algorithm must theoretically work for any size n, m.
However your program must be correct for inputs within these size limits, intermediate value overflows are not excused if the inputs are within these limits.

Examples:

2, 10^15
566088170340352

4, 3^20
4

32, 524287
16

"""

import sympy

"""

@Anders Kaseorg

Why it works
We use the following generalization of Euler’s theorem.

Lemma. n^2φ(m) ≡ n^φ(m) (mod m) for all n (whether or not n is coprime to m).

Proof: For all prime powers p^k dividing m,

If p divides n, then because φ(m) ≥ φ(p^k) = p^k - 1(p − 1) ≥ 2^k − 1 ≥ k, we have n^2φ(m) ≡ 0 ≡ n^φ(m) (mod p^k).
Otherwise, because φ(p^k) divides φ(m), Euler’s theorem gives n^2φ(m) ≡ 1 ≡ n^φ(m) (mod p^k).
Therefore, n^2φ(m) ≡ n^φ(m) (mod m).

Corollary. If k ≥ φ(m), then n^k ≡ n^(φ(m) + (k mod φ(m))) (mod m).

Proof: If k ≥ 2φ(m), the lemma gives n^k = n^(2φ(m)) * n^(k - 2φ(m)) ≡ n^φ(m)n^(k - 2φ(m)) = n^(k - φ(m)) (mod m) and we repeat until the exponent is less than 2φ(m).

"""
def mpt(n, m):
    if m < 2:
        return 0
    t = sympy.totient(m)
    p = t + mpt(n + 1, t)
    return pow(n, int(p), int(m))

def main():
    assert(mpt(2, 10**15) == 566088170340352)
    assert(mpt(4, 3**20) == 4)
    assert(mpt(32, 524287) == 16)

main()
