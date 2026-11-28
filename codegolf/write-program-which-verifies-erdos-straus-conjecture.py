#!/usr/bin/env python3

"""

Write program, which verifies Erdős–Straus conjecture.
Program should take as input one integern (3 <= n <= 1 000 000) and print triple of integers satisfying identity 4/n = 1/x + 1/y + 1/z, 0 < x < y < z.

Shortest code wins.

Some examples:

3 => {1, 4, 12}
4 => {2, 3, 6}
5 => {2, 4, 20}
1009 => {253, 85096, 1974822872}
999983 => {249996, 249991750069, 62495875102311369754692}
1000000 => {500000, 750000, 1500000}
Note that your program may print other results for these numbers because there are multiple solutions.

"""

from sympy import divisors

"""

Ported from @Anders Kaseorg solution

How it works
Rewrite 4/n = 1/x + 1/y + 1/z as z = n·x·y/d, where d = 4·x·y − n·x − n·y.
Then we can factor 4·d + n2 = (4·x − n)·(4·y − n), which gives us a much faster way to search for x and y as long as d is small.
Given x < y < z, we can at least prove d < 3·n2/4 (hence the bound on the outer loop),
although in practice it tends to be much smaller—95% of the time, we can use d = 1, 2, or 3.
The worst case is n = 769129, for which the smallest d is 1754 (this case takes about 1 second).

"""

def find(n):
    for d in range(1, n*n):
        v = 4*d + n*n
        for p in divisors(v):
            q = v // p
            x = (n + p) >> 2
            y = (n + q) >> 2
            r = (((n + p) & 3) | ((n + q) & 3) | ((n * x * y) % d))
            if r < 1:
                return x, y, (n*x*y)//d
    return -1, -1, -1

def main():
    for n in [3, 4, 5, 1009, 999983, 1000000, 769129]:
        print(n, find(n))

main()
