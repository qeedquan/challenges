#!/usr/bin/env python3

"""

Ok I've been on a bit of a triangle kick recently so here's another one.

Clark's Triangle is a triangle where the leftmost entry of each row is 1 and the rightmost entries are made up of multiples of 6 which increase as the row number increases. Here's a visualization

     1 6
    1 . 12
   1 . . 18
  1 . . . 24
 1 . . . . 30
1 . . . . . 36
Just like Pascal's Triangle all other entries are the sum of the numbers to their upper right and upper left.

Here are the first few rows filled in

          1   6
        1   7  12
      1   8  19  18
    1   9  27  37  24
  1  10  36  64  61  30
1  11  46  100 125 91  36

Task
Given a row number (starting from the top) and an column number (starting from the first non-zero item on that row) output the value at that particular cell. Both inputs may be either 1 or 0 indexed (you may mix and match if you desire). Out of the bounds of the triangle is undefined and you may do whatever you wish when queried for these values.

This is code-golf, the goal is to minimize the number of bytes in your solution.

OEIS A046902

"""

from math import *

# https://oeis.org/A046902
def clark(n, k):
    return 6*comb(n, k - 1) + comb(n - 1, k)

def gen(n):
    r = []
    i = 0
    while i < n and len(r) < n:
        r.append(1)
        j = 1
        while j <= i and len(r) < n:
            r.append(clark(i, j))
            j += 1
        i += 1

    if n > 0:
        r[0] = 0
    
    return r

def main():
    tab = [0, 1, 6, 1, 7, 12, 1, 8, 19, 18, 1, 9, 27, 37, 24, 1, 10, 36, 64, 61, 30, 1, 11, 46, 100, 125, 91, 36, 1, 12, 57, 146, 225, 216, 127, 42, 1, 13, 69, 203, 371, 441, 343, 169, 48, 1, 14, 82, 272, 574, 812, 784, 512, 217, 54, 1, 15, 96, 354, 846, 1386, 1596, 1296, 729, 271]

    assert(gen(len(tab)) == tab)

main()
