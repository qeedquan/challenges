#!/usr/bin/env python3

"""

 Do you know recursion?
This is a kata series that you can only solve using recursion.
##1 - Factorial

In mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n. For example,

5! = 5 * 4 * 3 * 2 * 1 = 120.

The value of 0! is 1.

#Your task

You have to create the function factorial that receives n and returns n!. You have to use recursion.

"""

from math import log2

# https://www.luschny.de/math/factorial/FastFactorialFunctions.htm
# https://oeis.org/A000142
class SplitRecursive:
    def __init__(self):
        self.x = 0

    def fact(self, n):
        if n < 2:
            return 1
        p = 1
        r = 1
        self.x = 1

        h = 0
        shift = 0
        high = 1
        log2n = int(log2(n))

        while h != n:
            shift += h
            h = n >> log2n
            log2n -= 1
            len = high
            high = (h - 1) | 1
            len = (high - len) // 2

            if len > 0:
                p *= self.prod(len)
                r *= p

        return r << shift

    def prod(self, n):
        m = n // 2
        if m == 0:
            self.x += 2
            return self.x
        if n == 2:
            x = self.x
            self.x += 4
            return (x + 2) * (x + 4)
        return self.prod(n - m) * self.prod(m)

def main():
    tab = [
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
        479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
        355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000,
        51090942171709440000, 1124000727777607680000
    ]

    sr = SplitRecursive()
    for i in range(len(tab)):
        assert(sr.fact(i) == tab[i])

main()
