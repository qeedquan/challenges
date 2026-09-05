#!/usr/bin/env python3

"""

The prime cluster of an integer N higher than 2 is defined as the pair formed by the highest prime strictly lower than N and the lowest prime strictly higher than N.

Note that following the definition above, if the integer is a prime itself, then its prime cluster is the pair of the primes preceding and succeeding it.

Task
Given two integers N, M (N, M ≥ 3), output a truthy / falsy value based on whether N and M have the same prime cluster.

This is code-golf, so the aim is to reduce your byte count as much as possible. Thus, the shortest code in every programming language wins.

Test cases / Examples
For instance, the prime cluster of 9 is [7, 11], because:

7 is the highest prime strictly lower than 9, and
11 is the lowest prime strictly higher than 9.
Similarly, the the prime cluster of 67 is [61, 71] (note that 67 is a prime).

Truthy pairs

8, 10
20, 22
65, 65
73, 73
86, 84
326, 318
513, 518
Falsy pairs

4, 5
6, 8
409, 401
348, 347
419, 418
311, 313
326, 305

"""

from sympy import isprime

"""

@ETHproductions

Works because two numbers have different prime clusters iff there is a prime between them, or either number is itself prime; unless both numbers are the same, in which case E returns 1 anyway (all items in a single-item array are equal).

"""

def prime_cluster(n, m):
    if m < n:
        n, m = m, n
    if n == m:
        return True

    for i in range(n, m + 1):
        if isprime(i):
            return False
    return True

def main():
    assert(prime_cluster(8, 10) == True)
    assert(prime_cluster(20, 22) == True)
    assert(prime_cluster(65, 65) == True)
    assert(prime_cluster(73, 73) == True)
    assert(prime_cluster(86, 84) == True)
    assert(prime_cluster(326, 318) == True)
    assert(prime_cluster(513, 518) == True)

    assert(prime_cluster(4, 5) == False)
    assert(prime_cluster(6, 8) == False)
    assert(prime_cluster(409, 401) == False)
    assert(prime_cluster(348, 347) == False)
    assert(prime_cluster(419, 418) == False)
    assert(prime_cluster(311, 313) == False)
    assert(prime_cluster(326, 305) == False)

main()
