#!/usr/bin/env python3

"""

Task
Below we will define what and n-interesting polygon is and your task is to find its area for a given n.

A 1-interesting polygon is just a square with a side of length 1. An n-interesting polygon is obtained by taking the n - 1-interesting polygon and appending 1-interesting polygons to its rim side by side. You can see the 1-, 2- and 3-interesting polygons in the picture below.


                                                                 _
                                                               _|_|_
                            _              _ _               _|_|_|_|_
                          _|_|_          _|_|_|_           _|_|_|_|_|_|_
              _ _       _|_|_|_|_      _|_|_|_|_|_       _|_|_|_|_|_|_|_|_
    _        |_|_|     |_|_|_|_|_|    |_|_|_|_|_|_|     |_|_|_|_|_|_|_|_|_|
   |_|       |_|_|       |_|_|_|      |_|_|_|_|_|_|       |_|_|_|_|_|_|_|
                           |_|          |_|_|_|_|           |_|_|_|_|_|
                                          |_|_|               |_|_|_|
                                                                |_|
   n=1        n=2          n=3             n=4                  n=5

Example
For n = 1, the output should be 1;

For n = 2, the output should be 5;

For n = 3, the output should be 13.

Input/Output
[input] integer n

Constraints: 1 ≤ n < 10000.

[output] an integer

The area of the n-interesting polygon.

"""

# https://oeis.org/A255840
def shape_area(n):
    return (4*n**2 - 4*n + 1 - (-1)**n) // 2

def main():
    tab = [
        0, 1, 4, 13, 24, 41, 60, 85, 112, 145, 180, 221, 264, 313, 364, 421,
        480, 545, 612, 685, 760, 841, 924, 1013, 1104, 1201, 1300, 1405, 1512,
        1625, 1740, 1861, 1984, 2113, 2244, 2381, 2520, 2665, 2812, 2965, 3120,
        3281, 3444, 3613, 3784, 3961, 4140, 4325, 4512
    ]

    for i in range(len(tab)):
        assert(shape_area(i) == tab[i])

main()
