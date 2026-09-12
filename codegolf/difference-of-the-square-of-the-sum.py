#!/usr/bin/env python3

"""

Find the difference between the square of the sums and sum of the squares.

This is the mathematical representation:

(∑n)^2 - ∑(n^2)

Your program/method should take two inputs, these are your lower and upper limits of the range, and are inclusive. Limits will be whole integers above 0.

Your program/method should return the answer.

You may use whichever base you would like to, but please state in your answer which base you have used.

Test case (Base 10)

5,9      970
91,123   12087152
1,10     2640
This is usual code-golf, so the shorter the answer the better.

"""

def pyramidal(n):
    return (2*n**3 + 3*n**2 + n) // 6

def triangular(n):
    return n*(n + 1) // 2

"""

@Sp3000

Explanation
Let p(n) be the nth square pyramidal number, and t(n) be the nth triangular number. Then, for n over the range a, ..., b:

∑n = t(b)-t(a-1), and
∑n² = p(b) - p(a-1)
So (∑n)²-∑n² = (t(b)-t(a-1))² - (p(b) - p(a-1)).

"""
def difference(a, b):
    return (triangular(b) - triangular(a - 1))**2 - (pyramidal(b) - pyramidal(a - 1))

def main():
    assert(difference(5, 9) == 970)
    assert(difference(91, 123) == 12087152)
    assert(difference(1, 10) == 2640)

main()
