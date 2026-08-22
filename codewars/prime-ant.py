#!/usr/bin/env python3

"""

The Prime ( https://codegolf.stackexchange.com/questions/144695/the-prime-ant ) ant ( https://math.stackexchange.com/questions/2487116/does-the-prime-ant-ever-backtrack ) (A293689 ( http://oeis.org/A293689 )) is an obstinate animal that navigates the integers and divides them until there are only primes left, according to the following procedure:

An infinite array/list A is initialized to contain all the integers greater than 1: [2, 3, 4, 5, 6, …]
Let p be the position of the ant on the array/list. Initially p = 0, so the ant is at A[0] = 2
At each turn, the ant moves as follows:

If A[p] is prime, move the ant one position forward, so p ← p + 1
Otherwise (if A[p] is composite):

Let q be its smallest divisor greater than 1
Replace A[p] with A[p] / q
Replace A[p−1] with A[p−1] + q
Move the ant one position backward, so p ← p − 1

Your task is to comlete the function that computes the position of the prime ant after n turns.

Examples
primeAnt(2)   // => 2
primeAnt(11)  // => 5
primeAnt(47)  // => 9

"""

from sympy import isprime

# https://oeis.org/A293689
def primeant(n):
    a = [(i + 2) for i in range(n * 2)]
    p = 0
    for _ in range(n):
        if isprime(a[p]):
            p += 1
            continue

        q = 2
        while a[p]%q != 0:
            q += 1
        a[p - 1] += q
        a[p] //= q
        p -= 1

    return p

def main():
    tab = [
        0, 1, 2, 1, 2, 3, 4, 3, 4, 5, 6, 5, 4, 3, 2, 3, 4, 5, 6, 5, 6, 7, 6, 7,
        8, 7, 8, 9, 10, 9, 10, 9, 8, 7, 8, 7, 6, 5, 6, 5, 4, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 11, 10, 9, 10, 11, 12, 13, 12, 11, 12, 13, 14, 13, 14,
        13, 12, 11, 10, 9, 8, 9, 10, 11, 12, 11, 12, 13
    ]

    for i in range(len(tab)):
        assert(primeant(i) == tab[i])

main()
