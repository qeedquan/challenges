#!/usr/bin/env python3

"""

Just as the title suggestes :D . For example ->

largest(1); //Should return 7
largest(2); //Should return 97
....

Do not mind the pattern as it is just an incident ! And make sure to return false if the input is not an integer :D This might seem simple at first, it is, but keep an eye on the performance. Go for it !

"""

from sympy import isprime

# https://oeis.org/A003618
def largest(n):
    if n < 1:
        return -1

    x = int('9'*(n - 1) + '7')
    while x > 0 and not isprime(x):
        x -= 2
    return x

def main():
    tab = [
        7, 97, 997, 9973, 99991, 999983, 9999991, 99999989, 999999937, 9999999967,
        99999999977, 999999999989, 9999999999971, 99999999999973, 999999999999989,
        9999999999999937, 99999999999999997, 999999999999999989, 9999999999999999961,
        99999999999999999989
    ]

    for i in range(len(tab)):
        assert(largest(i + 1) == tab[i])

main()
