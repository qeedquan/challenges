#!/usr/bin/env python3

"""

You are given two positive integers `a` and `b` (`a < b <= 20000`). Complete the function which returns a list of all those numbers in the interval `[a, b)` whose digits are made up of prime numbers (`2, 3, 5, 7`) but which are not primes themselves.

Be careful about your timing!

"""

from sympy import isprime

def valid(n):
    s = str(n)
    for c in s:
        if c != '2' and c != '3' and c != '5' and c != '7':
            return False
    return not isprime(n)

# https://oeis.org/A061371
def notprimes(a, b):
    r = []
    for i in range(a, b):
        if valid(i):
            r.append(i)
    return r

def main():
    assert(notprimes(2, 222) == [22, 25, 27, 32, 33, 35, 52, 55, 57, 72, 75, 77])
    assert(notprimes(2700, 3000) == [2722, 2723, 2725, 2727, 2732, 2733, 2735, 2737, 2752, 2755, 2757, 2772, 2773, 2775])
    assert(notprimes(500, 999) == [522, 525, 527, 532, 533, 535, 537, 552, 553, 555, 572, 573, 575, 722, 723, 725, 732, 735, 737, 752, 753, 755, 772, 775, 777])
    assert(notprimes(999, 2500) == [2222, 2223, 2225, 2227, 2232, 2233, 2235, 2252, 2253, 2255, 2257, 2272, 2275, 2277, 2322, 2323, 2325, 2327, 2332, 2335, 2337, 2352, 2353, 2355, 2372, 2373, 2375])
    assert(notprimes(2, 736) == [22, 25, 27, 32, 33, 35, 52, 55, 57, 72, 75, 77, 222, 225, 232, 235, 237, 252, 253, 255, 272, 273, 275, 322, 323, 325, 327, 332, 333, 335, 352, 355, 357, 372, 375, 377, 522, 525, 527, 532, 533, 535, 537, 552, 553, 555, 572, 573, 575, 722, 723, 725, 732, 735])

main()
