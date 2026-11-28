#!/usr/bin/env python3

"""

Most everyone here is familiar with Pascal's Triangle. It's formed by successive rows, where each element is the sum of its two upper-left and upper-right neighbors. Here are the first 5 rows (borrowed from Generate Pascal's triangle):

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
  . . .
Collapse these rows to the left

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
. . .
Sort them in ascending order

1
1 1
1 1 2
1 1 3 3
1 1 4 4 6
. . .
Read this triangle by rows

[1, 1, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 4, 4, 6 ...]
Given an input n, output the nth number in this series. This is OEIS 107430.

Rules
You can choose either 0- or 1-based indexing. Please state which in your submission.
The input and output can be assumed to fit in your language's native integer type.
The input and output can be given by any convenient method.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

from math import comb

# https://oeis.org/A107430
def gen(n):
    r = []
    for i in range(n):
        for j in range(i + 1):
            if len(r) >= n:
                return r
            r.append(comb(i, j//2))

def main():
    tab = [1, 1, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 4, 4, 6, 1, 1, 5, 5, 10, 10, 1, 1, 6, 6, 15, 15, 20, 1, 1, 7, 7, 21, 21, 35, 35, 1, 1, 8, 8, 28, 28, 56, 56, 70, 1, 1, 9, 9, 36, 36, 84, 84, 126, 126, 1, 1, 10, 10, 45, 45, 120, 120, 210, 210, 252, 1, 1, 11, 11, 55, 55, 165, 165, 330, 330, 462, 462, 1]
    
    assert(gen(len(tab)) == tab)

main()
