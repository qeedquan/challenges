#!/usr/bin/env python3

"""

Imagine a triangle of numbers which follows this pattern:

Starting with the number "1", "1" is positioned at the top of the triangle. As this is the 1st row, it can only support a single number.
The 2nd row can support the next 2 numbers: "2" and "3"
Likewise, the 3rd row, can only support the next 3 numbers: "4", "5", "6"
And so on; this pattern continues.
    1
   2 3
  4 5 6
 7 8 9 10
...
Given N, return the sum of all numbers on the Nth Row:

1 <= N <= 10,000

"""

# https://oeis.org/A006003
def cumulative(n):
    return (n**3 + n)//2

def main():
    tab = [
        0, 1, 5, 15, 34, 65, 111, 175, 260, 369, 505, 671, 870, 1105,
        1379, 1695, 2056, 2465, 2925, 3439, 4010, 4641, 5335, 6095,
        6924, 7825, 8801, 9855, 10990, 12209, 13515, 14911, 16400,
        17985, 19669, 21455, 23346, 25345, 27455, 29679, 32020,
        34481, 37065, 39775
    ]

    for i in range(len(tab)):
        assert(cumulative(i) == tab[i])

main()
