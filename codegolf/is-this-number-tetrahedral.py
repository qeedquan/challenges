#!/usr/bin/env python3

"""

Happy New Year 2024!

2024 is a tetrahedral number. A tetrahedral number is a number that can be represented in the form n(n+1)(n+2)/6 for some positive integer n.
Or, equivalently, they are the sum of the first n triangular numbers.
They are also the number of objects in a triangular pyramid which has n objects on each of its edges.

For example, 10 is a tetrahedral number because 10=3×4×56.

Here are the first few tetrahedral numbers:

1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 286, 364, 455, 560, 680, 816, 969, 1140, 1330, 1540, 1771, 2024, ...
This is sequence A000292 in the OEIS.

Task
Given a positive integer n, determine whether n is a tetrahedral number.

This is code-golf, so the shortest code in bytes in each language wins.

This is also a decision-problem, so you may use your language's convention for truthy/falsy (swapping truthy and falsy is allowed), or use two distinct, fixed values to represent true or false.

"""

from math import floor, cbrt

"""

@Arnauld

If n is a tetrahedral number, then the following holds:

k = floor( (6 * n) ^ (1/3) )
(k + 1)^3 - k - 1 = 6*n

"""

def istetra(n):
    k = floor(cbrt(6*n))
    return (k+1)**3 - k - 1 == 6*n

def main():
    for i in range(5000):
        if istetra(i):
            print(i)

main()

