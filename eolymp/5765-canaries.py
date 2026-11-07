#!/usr/bin/env python3

"""

Recently, n canaries arrived at the city zoo.
Currently, the birds are kept in temporary enclosures while the ornithologists are deciding how to distribute them among k cages so that no cage is left empty.
Comfort is the main criterion, so the specialists are primarily interested in the number of canaries in the cage that will contain the most birds.

You, as the main (and unfortunately, the only) programmer of the zoo, have been tasked to estimate this value:
find the minimum and the maximum number of canaries that can be in the most populated cage, under the condition that no cage remains empty.

Input
Two integers: the number of canaries n and the number of cages k (1≤k≤n≤10^9).

Output
Print two integers: the minimal and maximal possible number of canaries in the most populated cage.

Examples

Input #1
7 4

Answer #1
2 4

Input #2
12 3

Answer #2
4 10

"""

def solve(n, k):
    if k == 0:
        return (0, 0)
    if n%k == 0:
        return (n//k, n - k + 1)
    return (n//k + 1, n - k + 1)

def main():
    assert(solve(7, 4) == (2, 4))
    assert(solve(12, 3) == (4, 10))

main()
