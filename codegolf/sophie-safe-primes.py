#!/usr/bin/env python3

"""

Description
Write a program or function that takes in a positive integer n as input and outputs all Sophie Germain primes that are safe primes less than or equal to n.
A prime number p is a Sophie Germain prime if 2p+1 is also a prime. A prime number p is a safe prime if p=2q+1, where q is also a prime.
The output should be a list of the Sophie Germain primes that are also safe primes, in ascending order only.

Test Cases
[20] => 5, 11
[10000] => 5, 11, 23, 83, 179, 359, 719, 1019, 1439, 2039, 2063, 2459, 2819, 2903, 2963, 3023, 3623, 3779, 3803, 3863, 4919, 5399, 5639, 6899, 6983, 7079, 7643, 7823
[1000] => 5, 11, 23, 83, 179, 359, 719

Task and Criterion
Output primes p such that both (p-1)/2 and 2p+1 are prime less then, equal to a specific n given in input. Shortest bytes answer will win, in case if bytes are equated, a tie will occur.

"""

from sympy import *

# https://oeis.org/A059455
def ssgprimes(n):
    r = []
    for i in range(n+1):
        if isprime(i) and isprime(i//2) and isprime(2*i + 1):
            r.append(i)
    return r

def main():
    assert(ssgprimes(20) == [5, 11])
    assert(ssgprimes(10000) == [5, 11, 23, 83, 179, 359, 719, 1019, 1439, 2039, 2063, 2459, 2819, 2903, 2963, 3023, 3623, 3779, 3803, 3863, 4919, 5399, 5639, 6899, 6983, 7079, 7643, 7823])
    assert(ssgprimes(1000) == [5, 11, 23, 83, 179, 359, 719])

main()
