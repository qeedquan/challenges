#!/usr/bin/env sage

"""

Let p(n) represent the number of different ways in which coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5) = 7.

OOOOO
OOOO   O
OOO   OO
OOO   O   O
OO   OO   O
OO   O   O   O
O   O   O   O   O

Find the least value of n for which p(n) is divisible by one million.

"""

# https://oeis.org/A000041
@CachedFunction
def npartitions(n):
    if n == 0:
        return 1
    S = 0
    J = n - 1
    k = 2
    while 0 <= J:
        T = npartitions(J)
        S = S+T if is_odd(k//2) else S-T
        J -= k if is_odd(k) else k//2
        k += 1
    return S

def solve(m):
    i = 0
    while npartitions(i)%m != 0:
        i += 1
    return i

def main():
    print(solve(1000000))

main()
