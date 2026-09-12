#!/usr/bin/env python3

"""

In 1960, Donald Wall of IBM, in White Plains, NY, proved that the series obtained by taking each element of the Fibonacci series modulo m was periodic.

For example, the first ten elements of the Fibonacci sequence, as well as their remainders modulo 11, are:

The sequence made up of the remainders then repeats. Let k(m) be the length of the repeating subsequence; in this example, we see k(11)=10.

Wall proved several other properties, some of which you may find interesting:

If m>2, k(m) is even.

For any even integer n>2, there exists m such that k(m)=n.
k(m)≤m^2−1
k(2n)≤3⋅2^(n−1)
k(5n)=4⋅5^n
k(2⋅5^n)=6n
If n>2, k(10n)=15⋅10^(n−1)

For this problem, you must write a program that calculates the length of the repeating subsequence k(m) for different modulo values m.

Input
The first line contains the number of data sets p (1≤p≤1000) that follow.
Each data set is a single line that consists of two space separated integer values n and m,
where n is the data set number and m (2≤m≤1000000) is the modulo value.

Output
For each data set there is one line of output. It contains the data set number n followed by a single space,
followed by the length of the repeating subsequence for m - the value of k(m).

Examples
Input #1
5
1 4
2 5
3 11
4 123456
5 987654

Answer #1
1 6
2 20
3 10
4 15456
5 332808

"""

from functools import *
from sympy import *

# https://oeis.org/A001175
def pisano(n):
    if n < 1:
        return 0
    if n == 1:
        return 1

    f = factorint(n)
    if len(f) > 1:
        return reduce(lcm, (pisano(a**f[a]) for a in f))

    k, x = 1, [1, 1]
    while x != [0, 1]:
        k += 1
        x = [x[1], (x[0] + x[1]) % n]
    return k

def main():
    tab = [
        1, 3, 8, 6, 20, 24, 16, 12, 24, 60, 10, 24, 28, 48, 40, 24, 36, 24, 18,
        60, 16, 30, 48, 24, 100, 84, 72, 48, 14, 120, 30, 48, 40, 36, 80, 24,
        76, 18, 56, 60, 40, 48, 88, 30, 120, 48, 32, 24, 112, 300, 72, 84, 108,
        72, 20, 48, 72, 42, 58, 120, 60, 30, 48, 96, 140, 120, 136
    ]

    assert(pisano(4) == 6)
    assert(pisano(5) == 20)
    assert(pisano(11) == 10)
    assert(pisano(123456) == 15456)
    assert(pisano(987654) == 332808)

    for i in range(len(tab)):
        assert(pisano(i + 1) == tab[i])

main()
