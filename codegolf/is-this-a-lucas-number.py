#!/usr/bin/env python3

"""

Write a program or function that takes an input greater than or equal to 2.
It should output a truthy or falsy value corresponding to whether the input is a Lucas number or not.
You may take input from STDIN, or whichever source is most suitable to you.

This question is different to this one because this question is specifically for Lucas numbers only, and not Fibonacci numbers at all,
whereas that question was Lucas number, Fibonacci numbers and both possible combinations of them.
This question was, however, inspired by that question and is similar in some regards.

Lucas numbers are the numbers that result from the rules following: the first Lucas number is a 2,
the second is a 1, and each term after that is the sum of the previous two.
Yes, it is very similar to the Fibonacci sequence,
but this has the added advantage of converging closer to the golden ratio, phi, faster than Fibonacci numbers do.

Example inputs/outputs
Input   Output
--------------
3       True
4       True
7       True
8      False
10     False
3421   False
9349    True
etc.

Some limitations
Your program/function must run in a reasonable amount of time. It should terminate within seconds and minutes, not hours and days.
Your program must not calculate all the Lucas numbers up to the input number
This is code golf, so the shortest code in bytes wins.

"""

from math import isqrt

def ispsq(n):
    if n < 0:
        return False
    s = isqrt(n)
    return s*s == n

"""

https://oeis.org/A000032

@mriklojn

n is a Lucas number if either 5n^2+20 or 5n^2-20 is a perfect square.

"""

def islucas(n):
    return ispsq(5*n*n + 20) or ispsq(5*n*n - 20)

def main():
    tab = [
        2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, 322, 521, 843, 1364, 2207,
        3571, 5778, 9349, 15127, 24476, 39603, 64079, 103682, 167761,
        271443, 439204, 710647
    ]

    assert(islucas(3) == True)
    assert(islucas(4) == True)
    assert(islucas(7) == True)
    assert(islucas(8) == False)
    assert(islucas(10) == False)
    assert(islucas(3421) == False)
    assert(islucas(9349) == True)

    for i in range(max(tab) + 1):
        if i in tab:
            assert(islucas(i) == True)
        else:
            assert(islucas(i) == False)

main()
