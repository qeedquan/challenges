#!/usr/bin/env python3

"""

An integer partition of n is a weakly decreasing list of positive integers which sum to n.

For example, there are 7 integer partitions of 5:

[5], [4,1], [3,2], [3,1,1], [2,2,1], [2,1,1,1], [1,1,1,1,1].
Write a function which returns the number of integer partitions of n. The function should be able to find the number of integer partitions of n for n at least as large as 100.

"""

from sympy import partition

def main():
    # https://oeis.org/A000041
    tab = [
        1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176, 231, 297,
        385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565,
        5604, 6842, 8349, 10143, 12310, 14883, 17977, 21637, 26015, 31185, 37338,
        44583, 53174, 63261, 75175, 89134, 105558, 124754, 147273, 173525
    ]

    assert(partition(1) == 1)
    assert(partition(5) == 7)
    assert(partition(10) == 42)
    assert(partition(25) == 1958)

    for i in range(len(tab)):
        assert(partition(i) == tab[i])

main()
