#!/usr/bin/env python3

"""

OEIS has a variation (A111439) on Golomb's sequence. As in Golomb's sequence, A(n) describes how often n appears in the sequence. But in addition, no two consecutive numbers may be identical. While building up the sequence, A(n) is always chosen as the smallest positive integer that doesn't violate these two properties. Due to disallowed consecutive identical numbers, the series wobbles slightly up and down as it grows. Here are the first 100 terms:

1, 2, 3, 2, 3, 4, 3, 4, 5, 6, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8, 9, 8, 9, 8, 9,
10, 9, 10, 9, 10, 11, 10, 11, 10, 11, 10, 11, 12, 11, 12, 13, 12, 13, 12,
13, 12, 13, 12, 13, 14, 15, 14, 15, 14, 15, 14, 15, 14, 15, 14, 15, 16, 15,
16, 17, 16, 17, 16, 17, 16, 17, 16, 17, 18, 17, 18, 17, 18, 19, 18, 19, 18,
19, 18, 19, 18, 19, 18, 19, 20, 19, 20, 21, 20, 21, 20, 21, 20, 21, 20
The full list of the first 10,000 numbers can be found on OEIS.

The challenge is to write a program or function which computes A(n), given n. n is 1-based to ensure that the self-describing property works.

Rules
You may write a program or a function and use any of the our standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
n     A(n)
1     1
4     2
10    6
26    10
100   20
1000  86
1257  100
10000 358

"""

# https://oeis.org/A111439
def wobbly(n):
    L = [1, 2, 3]
    while len(L) < n:
        for i in range(2, n):
            if L.count(i) < L[i - 1] and L[-1] != i:
                L += [i]
                break
    return L[n - 1]

def main():
    tab = [1, 2, 3, 2, 3, 4, 3, 4, 5, 6, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8, 9, 8, 9, 8, 9, 10, 9, 10, 9, 10, 11, 10, 11, 10, 11, 10, 11, 12, 11, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 14, 15, 14, 15, 14, 15, 14, 15, 14, 15, 14, 15, 16, 15, 16, 17, 16, 17, 16, 17, 16, 17, 16, 17, 18, 17, 18, 17, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 20, 19, 20, 21, 20, 21, 20, 21, 20, 21, 20]

    assert(wobbly(1) == 1)
    assert(wobbly(4) == 2)
    assert(wobbly(10) == 6)
    assert(wobbly(26) == 10)
    assert(wobbly(100) == 20)
    assert(wobbly(1000) == 86)
    assert(wobbly(1257) == 100)

    for i in range(len(tab)):
        assert(wobbly(i + 1) == tab[i])

main()
