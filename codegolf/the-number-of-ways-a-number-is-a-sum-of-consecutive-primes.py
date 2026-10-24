#!/usr/bin/env python3

"""

Given an integer greater than 1, output the number of ways it can be expressed as the sum of one or more consecutive primes.

Order of summands doesn't matter. A sum can consist of a single number (so the output for any prime will be at least 1.)

This is code-golf. Standard rules apply.

See this OEIS wiki for related information and sequences, including the sequence itself OEIS A054845.

Test cases
2 => 1
3 => 1
4 => 0
5 => 2
6 => 0
7 => 1
8 => 1
10 => 1
36 => 2
41 => 3
42 => 1
43 => 1
44 => 0
311 => 5
1151 => 4
34421 => 6

"""

from sympy import primerange

# https://oeis.org/A054845
def upto(n):
    p = [0 for n in range(n + 1)]
    for x in primerange(2, n + 1):
        s = x
        p[s] += 1
        for y in primerange(x + 1, n + 1):
            s += y
            if s <= n:
                p[s] += 1
            else:
                break
    return p

def main():
    tab = [
        0, 0, 1, 1, 0, 2, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 2, 1, 1, 0, 0, 0, 2,
        1, 0, 1, 0, 1, 1, 1, 2, 0, 0, 0, 0, 2, 1, 0, 1, 0, 3, 1, 1, 0, 0, 0, 1,
        1, 1, 0, 0, 1, 2, 0, 0, 1, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 2, 1, 0, 0, 2,
        2, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 3, 1, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 1,
        0, 2, 1, 0, 2, 2
    ]

    p = upto(34421)

    assert(p[2] == 1)
    assert(p[3] == 1)
    assert(p[4] == 0)
    assert(p[5] == 2)
    assert(p[6] == 0)
    assert(p[7] == 1)
    assert(p[8] == 1)
    assert(p[10] == 1)
    assert(p[36] == 2)
    assert(p[41] == 3)
    assert(p[42] == 1)
    assert(p[43] == 1)
    assert(p[44] == 0)
    assert(p[311] == 5)
    assert(p[1151] == 4)
    assert(p[34421] == 6)
    assert(p[:len(tab)] == tab)

main()
