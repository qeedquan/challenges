#!/usr/bin/env python3

"""

Vasiliy Pupkin decided to replace the wallpaper on a wall measuring n meters in height and m meters in width.
The wallpaper is sold in rolls with a width of 1 meter and a length of k meters.
The wallpaper is to be applied vertically—from ceiling to floor.
Vasiliy wants to apply the wallpaper so that there are no horizontal seams, using continuous strips (i.e., each strip is a single piece from ceiling to floor).
It is possible to cut a piece of the required length from the roll.
Of course, if a shorter piece remains, it will be wasted.
What is the minimum number of rolls Vasiliy should buy, and how many meters of wallpaper will be wasted?

Input
Three integers n, m, and k (1≤n≤100, 1≤m≤100, n≤k≤100).

Output
Output two numbers: the minimum number of rolls and the total length of wallpaper wasted.

Examples
Input #1
6 7 20

Answer #1
3 18

Input #9
2 5 5

Answer #9
3 5

"""

from math import ceil

def solve(n, m, k):
    p = k // n
    r = ceil(m / p)
    return (r, r*k - m*n)

def main():
    assert(solve(6, 7, 20) == (3, 18))
    assert(solve(2, 5, 5) == (3, 5))

main()
