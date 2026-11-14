#!/usr/bin/env python3

"""

https://www.mathblog.dk/project-euler-30-sum-numbers-that-can-be-written-as-the-sum-fifth-powers-digits/

So lets determine the upper bound. We need to find a number x9^5 which gives us an x digit number.
We can do this by hand. Since 9^5 = 59049, we need at least 5 digits. 5*9^5 = 295245, so with 5 digits we can make a 6 digit number. 6*9^5 = 354294.
So 355000 seems like a reasonable upper bound to use. We could probably tighten is even further if we wanted.

"""

def dfp(n):
    r = 0
    x = n
    while x > 0:
        r += (x%10)**5
        x //= 10
    return r == n

def solve():
    r = 0
    for i in range(2, 355000):
        if dfp(i):
            r += i
    return r

def main():
    print(solve())

main()
