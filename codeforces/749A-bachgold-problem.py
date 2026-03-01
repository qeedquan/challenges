#!/usr/bin/env python3

"""

Bachgold problem is very easy to formulate. Given a positive integer n represent it as a sum of maximum possible number of prime numbers. One can prove that such representation exists for any integer greater than 1.

Recall that integer k is called prime if it is greater than 1 and has exactly two positive integer divisors — 1 and k.

Input
The only line of the input contains a single integer n (2 ≤ n ≤ 100 000).

Output
The first line of the output contains a single integer k — maximum possible number of primes in representation.

The second line should contain k primes with their sum equal to n. You can print them in any order. If there are several optimal solution, print any of them.

Examples

input
5
output
2
2 3

input
6
output
3
2 2 2


"""

def decompose(n):
    o = n % 2
    n = n//2 - o
    p = [2] * n
    if o != 0:
        p.append(3)

    return p

def main():
    assert(decompose(5) == [2, 3])
    assert(decompose(6) == [2, 2, 2])

main()
