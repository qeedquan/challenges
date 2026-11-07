#!/usr/bin/env python3

"""

Given some positive integer n generate all derangements of n objects.

Details
A derangement is a permutation with no fixed point. (This means in every derangement number i cannot be in the i-th entry).
The output should consist of derangements of the numbers  (1,2,…,n) (or alternatively  (0,1,2,…,n−1)).
You can alternatively always print derangements of  (n,n−1,…,1) (or  (n−1,n−2,…,1,0) respectively) but you have to specify so.
The output has to be deterministic, that is whenever the program is called with some given n as input, the output should be the same (which includes that the order of the derangements must remain the same), and the complete output must be done within a finite amount of time every time (it is not sufficient to do so with probability 1).

You can assume that  n⩾2

For some given n you can either generate all derangements or alternatively you can take another integer k that
serves as index and print the  k-th derangement (in the order you chose).

Examples
Note that the order of the derangements does not have to be the same as listed here:

n=2: (2,1)
n=3: (2,3,1),(3,1,2)
n=4: (2,1,4,3),(2,3,4,1),(2,4,1,3), (3,1,4,2),(3,4,1,2),(3,4,2,1), (4,1,2,3),(4,3,1,2),(4,3,2,1)

OEIS A000166 counts the number of derangements.

"""

from itertools import *

# https://oeis.org/A000166 (related)
def derangements(n):
    r = []
    for p in permutations(range(1, n + 1)):
        if all(i-j+1 for i, j in enumerate(p)):
               r.append(p)
    return r

def main():
    for i in range(2, 5):
        print(derangements(i))

main()
