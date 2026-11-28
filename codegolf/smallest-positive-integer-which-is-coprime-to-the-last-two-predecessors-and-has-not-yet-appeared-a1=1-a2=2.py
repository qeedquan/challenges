#!/usr/bin/env python3

"""

Definition
Two integers are coprime if they share no positive common divisors other than 1.
a(1) = 1
a(2) = 2
a(n) is the smallest positive integer which is coprime to the a(n-1) and a(n-2) and has not yet appeared, for integer n >= 3.

Task
Given positive integer n, output/print a(n).

Example
a(11) = 6 because 6 is coprime with the last two predecessors (namely, 11 and 13) and 6 has not appeared before.

Notes
Note that the sequence is not ascending, meaning that an element can be smaller than its predecessor.

Specs
You must use 1-indexed.

Testcases
n      a(n)
1      1
2      2
3      3
4      5
5      4
6      7
7      9
8      8
9      11
10     13
11     6
12     17
13     19
14     10
15     21
16     23
17     16
18     15
19     29
20     14
100    139
1000   1355
10000  13387
100000 133361

Scoring
Since coprime means that the two numbers share only one divisor (1), and 1 is a small number, your code should be as small as possible in terms of byte-count.

References
OEIS A084937

"""

from math import gcd

# https://oeis.org/A084937
def gen(n):
    r, l1, l2, s, b = [1, 2], 2, 1, 3, set()
    while True:
        i = s
        while True:
            if not i in b and gcd(i, l1) == 1 and gcd(i, l2) == 1:
                r.append(i)
                if len(r) > n:
                    return r[:n]
                l2, l1 = l1, i
                b.add(i)
                while s in b:
                    b.remove(s)
                    s += 1
                break
            i += 1

def main():
    tab = [
        1, 2, 3, 5, 4, 7, 9, 8, 11, 13, 6, 17, 19, 10, 21, 23, 16, 15, 29, 14,
        25, 27, 22, 31, 35, 12, 37, 41, 18, 43, 47, 20, 33, 49, 26, 45, 53, 28,
        39, 55, 32, 51, 59, 38, 61, 63, 34, 65, 57, 44, 67, 69, 40, 71, 73, 24,
        77, 79, 30, 83, 89, 36, 85, 91, 46, 75, 97, 52, 81
    ]

    assert(gen(len(tab)) == tab)

main()
