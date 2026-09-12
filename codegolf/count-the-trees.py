#!/usr/bin/env python3

"""

A tree is a connected, undirected graph with no cycles. Your task is to count how many distinct trees there are with a given number of vertices.

Two trees are considered distinct if they are not isomorphic. Two graphs are isomorphic if their respective vertices can be paired up in such a way that there is an edge between two vertices in one graph if and only if there is an edge between the vertices paired to those vertices in the other graph. For a more complete description, see the link above.

To see what all of the distinct trees of sizes 1 to 6 look like, take a look here.

The series you are trying to output is A000055 at the OEIS.

Restriction: Your solution must take in the range of minutes or less to run on the input 6. This is not intended to eliminate exponential time algorithms, but it is intended to eliminate doubly-exponential time algorithms, such as brute forcing over all edge sets.

Input: Any non-negative integer.

Input may be by any standard means, including STDIN, command line parameter, function input, etc.

Output: The number of distinct trees with as many vertices as the input.

Output may be by any standard means, including STDOUT, function return, etc.

Examples: 0, 1, 2, 3, 4, 5, 6, 7 should return 1, 1, 1, 1, 2, 3, 6, 11.

Scoring: Code golf, by bytes. May the shortest code win!

Standard loopholes forbidden.

"""

from functools import lru_cache
from sympy import divisors

@lru_cache(maxsize=None)
def divisor_tuple(n): # cached unordered tuple of divisors
    return tuple(divisors(n, generator=True))

# https://oeis.org/A000081
@lru_cache(maxsize=None)
def nurt(n):
    if n < 0:
        return 0
    if n <= 1:
        return n

    r = 0
    for k in range(1, n):
        v = 0
        for d in divisor_tuple(k):
            v += d * nurt(d)
        r += v * nurt(n-k)
    r //= (n - 1)
    
    return r

# https://oeis.org/A000055
def trees(n):
    if n < 0:
        return 0
    if n == 0:
        return 1

    r = nurt(n)
    m = n//2
    for i in range(1, m + 1):
        r -= nurt(i) * nurt(n-i)
    
    if n&1 == 0:
        r += (nurt(m) + 1)*nurt(m) // 2
    
    return r

def main():
    nurttab = [0, 1, 1, 2, 4, 9, 20, 48, 115, 286, 719, 1842, 4766, 12486, 32973, 87811, 235381, 634847, 1721159, 4688676, 12826228, 35221832, 97055181, 268282855, 743724984, 2067174645, 5759636510, 16083734329, 45007066269, 126186554308, 354426847597, 997171512998]

    treetab = [1, 1, 1, 1, 2, 3, 6, 11, 23, 47, 106, 235, 551, 1301, 3159, 7741, 19320, 48629, 123867, 317955, 823065, 2144505, 5623756, 14828074, 39299897, 104636890, 279793450, 751065460, 2023443032, 5469566585, 14830871802, 40330829030, 109972410221, 300628862480, 823779631721, 2262366343746, 6226306037178]

    for i in range(len(nurttab)):
        assert(nurt(i) == nurttab[i])

    for i in range(len(treetab)):
        assert(trees(i) == treetab[i])

main()
