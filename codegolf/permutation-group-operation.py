#!/usr/bin/env python3

"""

There is a well-known bijection between the permutations of n elements and the numbers 0 to n!-1 such that the lexicographic ordering of the permutations and the corresponding numbers is the same.
For example, with n=3:

0 <-> (0, 1, 2)
1 <-> (0, 2, 1)
2 <-> (1, 0, 2)
3 <-> (1, 2, 0)
4 <-> (2, 0, 1)
5 <-> (2, 1, 0)

It is also well-known that the permutations of n elements form a group (the symmetric group of order n!) -
so, in particular, that one permutation of n elements applied to a second permutation of n elements yields a permutation of n elements.

For example, (1,0,2) applied to (a,b,c) yields (b,a,c), so (1,0,2) applied to (2,1,0) yields (1,2,0).

Write a program which takes three integer arguments: n, p1, and p2; interprets p1 and p2 as permutations of n elements via the bijection described above; applies the first to the second;
and outputs the corresponding integer, reapplying the above bijection. For example:

$ ./perm.sh 3 2 5
3
This is code-golf so the shortest code in bytes wins

"""

from itertools import *

# ported from @Keith Randall solution
def pgo(n, p1, p2):
    P = list(permutations(range(n)))
    t = tuple(P[p2][P[p1][i]] for i in range(n))
    return P.index(t)

def main():
    assert(pgo(3, 2, 5) == 3)

main()

