#!/usr/bin/env python3

"""

A 3-smooth number is a positive integer whose prime factors are all among 2 and 3. Equivalently, it is a number of the form

2^i*3^j, i, j∈Z≥0.

All 3-smooth numbers in increasing order begins:

1,2,3,4,6,8,9,12,16,18,24,…

It is A003586 on OEIS.

If all 3-smooth numbers less than N are sorted, they can be used directly as a gap sequence for Shell sort. According to Wikipedia, to sort an array of  N elements, this gives the algorithm a worst-case time complexity of  Θ(N*log^2(N)).

Challenge
Given N, output every 3-smooth number strictly less than N, exactly once, in any order.

Equivalently, output the set

{2^i 3^j ∣ i,j ∈ Z≥0, 2^i 3^j < N}.

You may assume that

N∈Z, 1≤N≤1000.

Rules
Input and output may be in any convenient format.
This is code-golf. Shortest answer in bytes wins.
Test cases
1   -> []
2   -> [1]
7   -> [1, 2, 3, 4, 6]
10  -> [1, 2, 3, 4, 6, 8, 9]
20  -> [1, 2, 3, 4, 6, 8, 9, 12, 16, 18]
100 -> [1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, 32, 36, 48, 54, 64, 72, 81, 96]
The order of the output is not significant.

"""

from itertools import count, takewhile

# https://oeis.org/A003586
def upto(n):
    pows2 = list(takewhile(lambda x: x < n, (2**i for i in count(0))))
    pows3 = list(takewhile(lambda x: x < n, (3**i for i in count(0))))
    return sorted(c*d for c in pows2 for d in pows3 if c*d <= n)

def main():
    tab = [
        1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, 32, 36, 48, 54, 64, 72, 81,
        96, 108, 128, 144, 162, 192, 216, 243, 256, 288, 324, 384, 432, 486,
        512, 576, 648, 729, 768, 864, 972, 1024, 1152, 1296, 1458, 1536, 1728,
        1944, 2048, 2187, 2304, 2592, 2916, 3072, 3456, 3888
    ]

    assert(upto(1) == [])
    assert(upto(2) == [1])
    assert(upto(7) == [1, 2, 3, 4, 6])
    assert(upto(10) == [1, 2, 3, 4, 6, 8, 9])
    assert(upto(20) == [1, 2, 3, 4, 6, 8, 9, 12, 16, 18])
    assert(upto(100) == [1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, 32, 36, 48, 54, 64, 72, 81, 96])
    assert(upto(tab[-1]) == tab)

main()
