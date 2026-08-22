#!/usr/bin/env python3

"""

In preparation for Emperor Palpatine's visit, it has been decided to update the droid lineup in hangar 32.
Due to the ongoing crisis, instead of purchasing new droids, a few older ones will be decommissioned.
Since Palpatine dislikes droids with low serial numbers, the task is to identify the two droids with the smallest serial numbers.

Input
The first line of the input contains an integer N — the number of droids (2≤N≤1000).
The second line contains N integers, each with an absolute value not exceeding 2⋅10^9, representing the droid serial numbers.

Output
Print two numbers: the first is the smallest droid serial number (this droid should be decommissioned first), and the second is the second smallest.

Examples
Input #1
5
49 100 23 -100 157

Answer #1
-100 23

"""

def solve(droids):
    if len(droids) < 2:
        return ()

    droids.sort()
    return (droids[0], droids[1])

def main():
    assert(solve([49, 100, 23, -100, 157]) == (-100, 23))

main()
