#!/usr/bin/env python3

"""

Definitions
Quadratic residues
An integer r is called a quadratic residue modulo n if there exists an integer x such that:

x^2 ≡ r (mod n)

The set of quadratic residues modulo n can be simply computed by looking at the results of x^2 mod n for 0≤x≤⌊n/2⌋.

The challenge sequence
We define an as the minimum number of occurrences of the same value (r0-r1+n)mod n for all pairs (r0,r1) of quadratic residues modulo n.

The first 30 terms are:

1,2,1,1,1,2,2,1,1,2,3,1,3,4,1,1,4,2,5,1,2,6,6,1,2,6,2,2,7,2

This is A316975 (submitted by myself).

"""

# ported from @Chas Brown solution
# https://oeis.org/A316975
def quadratic_residue(n):
    r = {i * i % n for i in range(n)}
    r = [(s - t) % n for s in r for t in r]
    return min(map(r.count, r))

def main():
    tab = [
        1, 2, 1, 1, 1, 2, 2, 1, 1, 2, 3, 1, 3, 4, 1, 1, 4, 2, 5, 1, 2, 6, 6, 1,
        2, 6, 2, 2, 7, 2, 8, 1, 3, 8, 2, 1, 9, 10, 3, 1, 10, 4, 11, 3, 1, 12,
        12, 1, 8, 4, 4, 3, 13, 4, 3, 2, 5, 14, 15, 1, 15, 16, 2, 1, 3, 6, 17,
        4, 6, 4, 18, 1, 18, 18, 2, 5, 6, 6, 20, 1, 4, 20
    ]

    for i in range(len(tab)):
        assert(quadratic_residue(i + 1) == tab[i])

main()
