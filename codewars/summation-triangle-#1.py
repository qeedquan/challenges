#!/usr/bin/env python3

r"""

The task
You have to make a program capable of returning the sum of all the elements of a triangle with side of size n + 1.


The problem
Your solution has to support 0 ≤ n ≤ 10^6. Brute-forcing will not work!

The definition
A triangle element a[i][j] where i is the column and j is the row can be defined as a[i][j] = 2*j + i + 1 where 0 <= j <= i <= n

Examples
For n = 2:

1  2  3      \
   4  5       \__ 1+2+3+4+5+7 sums to: 22
      7       /
sum(2) = 22
For n = 3:

1  2  3  4   \
   4  5  6    \__ 1+2+3+4+4+5+6+7+8+10 sums to: 50
      7  8    /
        10   /
sum(3) = 50
Hints
Euler transform (Optional)
Sums of powers

"""

from math import comb

# https://oeis.org/A002412
def getsum(n):
    n += 1
    return (4*n - 1) * comb(n + 1, 2) // 3

def main():
    tab = [
        0, 1, 7, 22, 50, 95, 161, 252, 372, 525, 715, 946, 1222, 1547, 1925,
        2360, 2856, 3417, 4047, 4750, 5530, 6391, 7337, 8372, 9500, 10725, 12051,
        13482, 15022, 16675, 18445, 20336, 22352, 24497, 26775, 29190, 31746,
        34447, 37297, 40300
    ]

    for i in range(len(tab)):
        assert(getsum(i - 1) == tab[i])

    assert(getsum(0) == 1)
    assert(getsum(1) == 7)
    assert(getsum(2) == 22)
    assert(getsum(3) == 50)
    assert(getsum(100) == 691951)
    assert(getsum(1000) == 669169501)

main()
