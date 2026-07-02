#!/usr/bin/env python3

"""

Prime number n is given. The inverse number to i (1≤i<n) is such number j that i⋅j≡1(modn).
It's possible to prove that for each i there exists only one inverse.

For all possible values of i find the inverse numbers.

Input
One prime number n (2≤n≤10^6).

Output
Print n−1 numbers. The i-th printed number should be the inverse to i.

Examples
Input #1
5

Answer #1
1 3 2 4

"""

"""

Fermat's Little Theorem

Since n is prime and (1 <= i < n), the greatest common divisor gcd(i, n) = 1.
According to Fermat's Little Theorem:

i^(n-1) = 1 (mod n)

By splitting the exponent, we get

i*i^(n-1) = 1 (mod n).

Therefore, the inverse is:

j = i^(n-2) (mod n)

"""

def solve(n):
    r = [0] * n
    for i in range(1, n):
        r[i] = pow(i, n-2, n)
    return r[1:]

def main():
    print(solve(5))
    print(solve(7))
    print(solve(13))

main()
