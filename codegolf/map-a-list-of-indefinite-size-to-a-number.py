#!/usr/bin/env python3

"""

It is well known, in the field of Mathematics studying infinity, that the Cartesian product of any finite amount of countable sets is also countable.

Your task is to write two programs to implement this, one to map from list to integer, one to map from integer to list.

Your function must be bijective and deterministic, meaning that 1 will always map to a certain list, and 2 will always map to another certain list, etc...

Earlier, we mapped integers to a list consisting only of 0 and 1.

However, now the list will consist of non-negative numbers.

Specs
Program/function, reasonable input/output format.
Whether the mapped integers start from 1 or starts from 0 is your choice, meaning that 0 doesn't have to (but may) map to anything.
The empty array [] must be encoded.
Input/output may be in any base.
Sharing code between the two functions is allowed.

Scoring
This is code-golf. Lowest score wins.

Score is the sum of lengths (in bytes) of the two programs/functions.

"""

from sympy import *

"""

@Dennis

Background
Let p0, p1, p2, ⋯ be the sequence of prime numbers in ascending order.

For each list of non-negative integers A := [a1, ⋯, an], we map A to p0^z(A)*p1^a1⋯pn*^an, where z(A) is the number of trailing zeroes of A.

Reversing the above map in straightforward. For a positive integer k, we factorize it uniquely as the product of consecutive prime powers
n = p0^α0*p1^α1⋯pn^αn, where αn > 0, then reconstruct the list as [α1, ⋯, αn], appending α0 zeroes.

"""

def encode(n):
    if n < 2:
        return []

    f = factorint(n)
    p = list(primerange(0, max(f.keys()) + 1))
    r = []
    for x in p:
        r.append(f.get(x, 0))
    
    for i in range(r[0]):
        r.append(0)
    
    return r[1:]

def decode(a):
    n = len(a)
    if n == 0:
        return 1
    
    z = -1
    for i in range(n - 1, -1, -1):
        if a[i] != 0:
            a = a[:i + 1]
            z = n - i - 1
            break
    
    if z < 0:
        z = len(a)
    
    p = list([prime(x + 1) for x in range(len(a) + 1)])
    
    r = p[0]**z
    for i in range(1, len(p)):
        r *= p[i]**a[i-1]
    return r

def main():
    for i in range(1, 101):
        assert(i == decode(encode(i)))

main()

