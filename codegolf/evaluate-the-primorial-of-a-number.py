#!/usr/bin/env python3

"""

The primorial of a number is the product of all the primes until that number, itself included.

Take a number from STDIN as the input and evaluate its primorial, also known as the prime factorial.

Don't use libraries. Shortest code wins.

Test cases:

1 1
2 2
3 6
4 6
5 30
6 30
7 210
8 210
9 210
10 210
11 2310
12 2310
13 30030
14 30030
15 30030
16 30030
17 510510
18 510510
19 9699690

"""

import sympy

# https://oeis.org/A034386
def primorial(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return sympy.primorial(n, nth=False)

def main():
    tab = [1, 1, 2, 6, 6, 30, 30, 210, 210, 210, 210, 2310, 2310, 30030, 30030, 30030, 30030, 510510, 510510, 9699690, 9699690, 9699690, 9699690, 223092870, 223092870, 223092870, 223092870, 223092870, 223092870, 6469693230, 6469693230, 200560490130, 200560490130]

    for i in range(len(tab)):
        assert(primorial(i) == tab[i])

main()
