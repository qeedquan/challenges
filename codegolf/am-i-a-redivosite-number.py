#!/usr/bin/env python3

"""

Redivosite is a portmanteau word invented for the sole purpose of this challenge. It's a mix of Reduction, Division and Composite.

Definition
Given an integer N > 6:

If N is prime, N is not a Redivosite Number.
If N is composite:
repeatedly compute N' = N / d + d + 1 until N' is prime, where d is the smallest divisor of N greater than 1
N is a Redivosite Number if and only if the final value of N' is a divisor of N
Below are the 100 first Redivosite Numbers (no OEIS entry at the time of posting):

14,42,44,49,66,70,143,153,168,169,176,195,204,260,287,294,322,350,414,462,518,553,572,575,592,629,651,702,726,735,775,806,850,869,889,891,913,950,1014,1023,1027,1071,1118,1173,1177,1197,1221,1235,1254,1260,1302,1364,1403,1430,1441,1554,1598,1610,1615,1628,1650,1673,1683,1687,1690,1703,1710,1736,1771,1840,1957,1974,2046,2067,2139,2196,2231,2254,2257,2288,2310,2318,2353,2392,2409,2432,2480,2522,2544,2635,2640,2650,2652,2684,2717,2758,2760,2784,2822,2835

Examples
N = 13: 13 is prime, so 13 is not a Redivosite Number
N = 32: 32 / 2 + 3 = 19; 19 is not a divisor or 32, so 32 is not a Redivosite Number
N = 260: 260 / 2 + 3 = 133, 133 / 7 + 8 = 27, 27 / 3 + 4 = 13; 13 is a divisor or 260, so 260 is a Redivosite Number

Your task
Given an integer N, return a truthy value if it's a Redivosite Number or a falsy value otherwise. (You may also output any two distinct values, as long as they're consistent.)
The input is guaranteed to be larger than 6.
This is code-golf, so the shortest answer in bytes wins!

"""

from sympy import *

def redivosite(n):
    if n <= 6 or isprime(n):
        return False

    m = n
    while True:
        d = min(factorint(m))
        m = m//d + d + 1
        if isprime(m):
            break
    return n%m == 0

def gen(n):
    r = []
    i = 7
    while len(r) < n:
        if redivosite(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [14, 42, 44, 49, 66, 70, 143, 153, 168, 169, 176, 195, 204, 260, 287, 294, 322, 350, 414, 462, 518, 553, 572, 575, 592, 629, 651, 702, 726, 735, 775, 806, 850, 869, 889, 891, 913, 950, 1014, 1023, 1027, 1071, 1118, 1173, 1177, 1197, 1221, 1235, 1254, 1260, 1302, 1364, 1403, 1430, 1441, 1554, 1598, 1610, 1615, 1628, 1650, 1673, 1683, 1687, 1690, 1703, 1710, 1736, 1771, 1840, 1957, 1974, 2046, 2067, 2139, 2196, 2231, 2254, 2257, 2288, 2310, 2318, 2353, 2392, 2409, 2432, 2480, 2522, 2544, 2635, 2640, 2650, 2652, 2684, 2717, 2758, 2760, 2784, 2822, 2835]

    assert(gen(len(tab)) == tab)

main()
