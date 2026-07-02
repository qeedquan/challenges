#!/usr/bin/env python3

"""

Minimum Scalar Product

The inspiration for this code golf problem is from Google's code jam competition. The premise behind the problem is, given the input of two vectors of varying lengths, find the minimum possible scalar. A scalar can be found using the following formula:

x1 * y1 + x2 * y2 + ... + xn * yn
The problem, however, is that multiple values for the scalar can be found depending on the order of the numerals in the input case (seen below). Your goal is to determine the minimum possible scalar integer solution by plugging in the input case numbers into the equation and solving for it. You may use every number in the input only once, and must use all of the numbers.

Allow me to provide an example with the following vectors.

Input

3
1 3 -5
-2 4 1

Output

-25

The first integer on the line represents the number of numbers, n, in each vector. In this case, we have three numbers in each vector.

The number n may vary with each test case, but there will always be two vectors.

In the example input, the minimum scalar product would be -25.

(-5 * 4) + (1 * 1) + (3 * -2) = 25

Rules

You may only use each integer in both vectors once.
You must use all integers in the vectors.
Your output must only include the final product
I'll select the solution with the least amount of code, which follows all of the specifications listed above, in any language!
Hint: You don't need to brute force this problem, unless it makes your code shorter. There is a specific method involved in finding the minimum spanning scalar :).

"""

def minscalar(a, b):
    a.sort()
    b.sort(reverse=True)

    n = min(len(a), len(b))
    r = 0
    for i in range(n):
        r += a[i] * b[i]
    return r

def main():
    assert(minscalar([1, 3, -5], [-2, 4, 1]) == -25)
    assert(minscalar([1, 2, 3, 4, 5], [1, 0, 1, 0, 1]) == 6)

main()
