#!/usr/bin/env python3

"""

In the Euclidean algorithm, two integers x and y with x>=y are replaced with y and x mod y until y becomes 0. For example:

(x, y) = (9, 7) is replaced with (7, 2),
which then is replaced with (2, 1),
which then is replace with (1, 0), and the algorithm terminates.
Overall, the algorithm took three steps.

Your task is to find integer pairs for which the Euclidean algorithm runs exactly n steps.

Input: The first line contains the number t of test cases.
The second line contains t integer values – each is the count of target steps for the Euclidean algorithm.

Output: A single line of t space-separated integer pairs x and y with x >= y >=1 so that the Euclidean algorithm for the i-th pair takes exactly the i-th target number of steps.

Example:

input:
2
1 3

answer:
111 111 9 7

"""

from sympy import fibonacci

def gcdstep(a, b):
    c = 0
    while b:
        a, b = b, a % b
        c += 1
    return c

"""

https://en.wikipedia.org/wiki/Lam%C3%A9%27s_theorem
https://www.techchorus.net/posts/euclids-algorithm-gcd/

Here’s an intuition to understand why Fibonacci numbers represent the worst case:

Reduction Rate: In each step, the algorithm reduces the problem size by subtracting the smaller number from the larger one and taking the modulus. For Fibonacci numbers, the remainder is maximized because
Fk+1 mod Fk = Fk−1 is nearly as large as
Fk itself, leading to the slowest possible reduction.

"""
def solve(n):
    if n < 1:
        return (0, 0)
    return (fibonacci(n), fibonacci(n + 1))

def test(n):
    a, b = solve(n)
    assert(gcdstep(a, b) == n)

def main():
    assert(gcdstep(9, 7) == 3)
    assert(gcdstep(111, 111) == 1)

    for i in range(1000):
        test(i)

main()
