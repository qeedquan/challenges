#!/usr/bin/env python3

"""

Your function takes a natural number and returns the smallest natural number that has exactly that amount of divisors, including itself.

Examples:

f(1) =  1 [1]
f(2) =  2 [1, 2]
f(3) =  4 [1, 2, 4]
f(4) =  6 [1, 2, 3, 6]
f(5) = 16 [1, 2, 4, 8, 16]
f(6) = 12 [1, 2, 3, 4, 6, 12]
 ...
The function doesn't have to return the list of divisors, they are only here for the examples.

"""

from sympy import *

"""

https://oeis.org/A005179
https://math.stackexchange.com/questions/1551959/why-does-a005179-smallest-number-with-n-factors-have-spikes-at-prime-numbers

If n is prime the first number which has n divisors is 2^(n-1), otherwise the number is small enough to brute force for small n.

An approximate method by @Ray

The idea is first to find the prime factors of k=p1*p2*...*pm, where p1 <= p2 <= ... <= pm. Then the answer is n = 2^(pm-1) * 3^(p(m-1)-1) * 5^(p(m-2)-1) ....
For example, factorizing k=18, we get 18 = 2 * 3 * 3. The first 3 primes is 2, 3, 5. So the answer n = 2^(3-1) * 3^(3-1) * 5^(2-1) = 4 * 9 * 5 = 180
This will not give the right answer if the specified number of divisors contain a high power of small prime.

"""
def ndivisors(n):
    if n < 1:
        return 0

    if isprime(n):
        return 2**(n - 1)

    i = 1
    while len(divisors(i)) != n:
        i += 1
    return i

def main():
    tab = [1, 2, 4, 6, 16, 12, 64, 24, 36, 48, 1024, 60, 4096, 192, 144, 120, 65536, 180, 262144, 240, 576, 3072, 4194304, 360, 1296, 12288, 900, 960, 268435456, 720, 1073741824, 840, 9216, 196608, 5184, 1260, 68719476736, 786432, 36864, 1680, 1099511627776, 2880]

    for i in range(len(tab)):
        assert(ndivisors(i + 1) == tab[i])

main()
