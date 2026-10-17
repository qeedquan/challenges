#!/usr/bin/env python3

"""

Input
A positive integer N representing the size of the problem and four positive integers v, x, y, z.

Output
This is what your code should compute. Consider a set of N distinct integers and consider all ways of choosing 3 subsets (which can overlap) from the set. There are 23N
 different possible ways of choosing the three subsets. Call the three subsets A, B and C.

Your code must count the number of possible choices of subsets A, B, C such that |A∩B∩C| = v, |A∩B| = x, |B∩C| = y, |C∩A| = z for non-negative integers v, x,y, z.

Scoring
I will generate a set of 5 valid inputs for each N and the time for your code will be the longest running time for a given problem size for any of the 5 inputs. Each answer will be tested on the same set of inputs, and your score is the highest N your code reaches on my PC in 60 seconds (spec details below). This means you need to give me simple and complete instructions on how to compile and run your code in Linux.

Examples
Answers for different values of N, v, x, y, z.

2, 0, 1, 1, 1 gives 0
2, 1, 1, 1, 1 gives 8
2, 2, 1, 1, 1 gives 0
8, 0, 2, 3, 3 gives 560
8, 1, 2, 3, 3 gives 80640
8, 2, 2, 3, 3 gives 215040
8, 3, 2, 3, 3 gives 0
My PC
I have an AMD Ryzen 5 3400G running Ubuntu 20.04.

Notes
This challenge is run per language so the fastest in Python is not competing with the fastest in C directly. I will maintain a league table per language once the first answer is given.

"""

from math import *

def combine(n, k):
    if n >= 0 and k >= 0:
        return comb(n, k)
    return 0

"""

@ngn

We fill the Venn diagram's compartments one by one, and we multiply the numbers of options we have at each step:

C(v,n) - to fill the common intersection A∩B∩C, we need to choose v elements out of a total of n. After making that choice, we are left with n-v elements.

C(n-v,x-v) - we fill the x-v compartment from those n-v, and we're left with n-v-(x-v) = n-x elements

C(n-x,y-v) - we fill y-v, with n-x-y+v left

C(n-x-y+v,z-v) - we fill z-v

For each of the remaining n-x-y-z+2*v elements, there are four possibilities - either belong to exactly one of A, B, or C, or to none of them. Those choices are independent, so we multiply by 4**(n-x-y-z+2*v).

"""

def intersections(n, v, x, y, z):
    return combine(n, v) * combine(n - v, x - v) * combine(n - x, y - v) * combine(n - x - y + v, z - v) * 4**(n-x-y-z + 2*v)

def main():
    assert(intersections(2, 0, 1, 1, 1) == 0)
    assert(intersections(2, 1, 1, 1, 1) == 8)
    assert(intersections(2, 2, 1, 1, 1) == 0)
    assert(intersections(8, 0, 2, 3, 3) == 560)
    assert(intersections(8, 1, 2, 3, 3) == 80640)
    assert(intersections(8, 2, 2, 3, 3) == 215040)
    assert(intersections(8, 3, 2, 3, 3) == 0)

main()
