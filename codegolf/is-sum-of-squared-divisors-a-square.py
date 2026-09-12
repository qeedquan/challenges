#!/usr/bin/env python3

"""

Let n=42 (Input)

Then divisors are : 1, 2, 3, 6, 7, 14, 21, 42

Squaring each divisor : 1, 4, 9, 36, 49, 196, 441, 1764

Taking sum (adding) : 2500

Since  50×50=2500 therefore we return a truthy value. If it is not a perfect square, return a falsy value.

Examples :
42  ---> true
1   ---> true
246 ---> true
10  ---> false
16  ---> false
This is code-golf so shortest code in bytes for each language wins

Thanks to @Arnauld for pointing out the sequence : A046655

"""

from math import sqrt

# https://oeis.org/A046655
def ss2(n):
    if n < 1:
        return False

    r = 0
    for i in range(1, n + 1):
        if n%i == 0:
            r += i**2
    s = int(sqrt(r))
    return s**2 == r

def main():
    truthy = [
        1, 42, 246, 287, 728, 1434, 1673, 1880, 4264, 6237, 9799, 9855, 18330,
        21352, 21385, 24856, 36531, 39990, 46655, 57270, 66815, 92664, 125255,
        156570, 182665, 208182, 212949, 242879, 273265, 380511, 391345, 411558,
        539560, 627215, 693160, 730145, 741096
    ]

    assert(ss2(42) == True)
    assert(ss2(1) == True)
    assert(ss2(246) == True)
    assert(ss2(10) == False)
    assert(ss2(16) == False)

    for i in truthy:
        assert(ss2(i) == True)

main()
