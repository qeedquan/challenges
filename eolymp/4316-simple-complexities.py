#!/usr/bin/env python3

"""

In life, not everything is straightforward, especially when it comes to numbers.

You are provided with a set of numbers. Your task is to determine whether each number is a prime number.

Input
The first line of input contains a single integer 1≤T≤5000, representing the number of numbers you need to check for primality.
The next T lines each contain a positive integer, with each number not exceeding 10^18.

Output
For each number, output "YES" on a new line if the number is prime, and "NO" if it is not.

Examples

Input #1
2
3
4

Answer #1
YES
NO

"""

from sympy import isprime

def solve(a):
    r = []
    for x in a:
        if isprime(x):
            r.append("YES")
        else:
            r.append("NO")
    return r

def main():
    print(solve([3, 4]))

main()

