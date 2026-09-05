#!/usr/bin/env python3

"""

The partition function:

In number theory, the partition function p(n) represents the number of possible partitions of a positive integer n into positive integers

For instance, p(4) = 5 because the integer 4 has five possible partitions:

1 + 1 + 1 + 1
1 + 1 + 2
1 + 3
2 + 2
4
Your task:

Accept an input (let's call it n). It will be a positive integer.
Find the sum of the partitions of the numbers from 1 to n and output it.
Example:

Given the input 5:

p(1) = 1
p(2) = 2
p(3) = 3
p(4) = 5
p(5) = 7
Sum = 18

As this is code-golf, the shortest answer in bytes wins.

I'll add my attempt as an answer, but it can probably be golfed down a bit.

"""

from sympy import partition

# https://oeis.org/A026905
def partition_sum(n):
    return sum(partition(k) for k in range(1, n+1))

def main():
    tab = [
        1, 3, 6, 11, 18, 29, 44, 66, 96, 138, 194, 271, 372, 507, 683, 914,
        1211, 1596, 2086, 2713, 3505, 4507, 5762, 7337, 9295, 11731, 14741,
        18459, 23024, 28628, 35470, 43819, 53962, 66272, 81155, 99132, 120769,
        146784, 177969, 215307, 259890, 313064, 376325, 451500
    ]

    for i in range(len(tab)):
        assert(partition_sum(i + 1) == tab[i])

main()
