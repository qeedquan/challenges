#!/usr/bin/env python3

"""

Definition
Define the nth term of the CRAU sequence as follows.

Begin with the singleton array A = [n].

Do the following n times:

For each integer k in A, replace the entry k with k natural numbers, counting from 1 to k.

Compute the sum of all integers in A.

For example, if n = 3, we start with the list [3].

We replace 3 with 1, 2, 3, yielding [1, 2, 3].

We now replace 1, 2, and 3 with 1, 1, 2 and 1, 2, 3 (resp.), yielding [1, 1, 2, 1, 2, 3].

Finally, we perform the same replacements as in the previous step for all six integers in the array, yielding [1, 1, 1, 2, 1, 1, 2, 1, 2, 3].

The sum of the resulting integers is 15, so this is the third CRAU number.

Task
Write a program of a function that, given a strictly positive integer n as input, computes the nth term of the CRAU sequence.

This is code-golf. May the shortest code in bytes win!

Test cases
 1 ->       1
 2 ->       4
 3 ->      15
 4 ->      56
 5 ->     210
 6 ->     792
 7 ->    3003
 8 ->   11440
 9 ->   43758
10 ->  167960
11 ->  646646
12 -> 2496144
13 -> 9657700

Related
Simplicial polytopic numbers

OEIS A001791: Binomial coefficients C(2n,n-1)

"""

from math import *

# https://oeis.org/A001791
def crau(n):
    if n < 1:
        return 0
    return comb(2 * n, n - 1)

def main():
    tab = [0, 1, 4, 15, 56, 210, 792, 3003, 11440, 43758, 167960, 646646, 2496144, 9657700, 37442160, 145422675, 565722720, 2203961430, 8597496600, 33578000610, 131282408400, 513791607420, 2012616400080, 7890371113950, 30957699535776, 121548660036300, 477551179875952]

    for i in range(len(tab)):
        assert(crau(i) == tab[i])

main()
