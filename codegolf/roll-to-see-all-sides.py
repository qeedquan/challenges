#!/usr/bin/env python3

"""

Let's say you have a 20-sided die. You start rolling that die and have to roll it a few dozen times before you finally roll all 20 values. You wonder, how many rolls do I need before I get a 50% chance of seeing all 20 values? And how many rolls of an n-sided die do I need to roll before I roll all n sides?

After some research, you find out that a formula exists for calculating the chance of rolling all n values after r rolls.

P(r, n) = n! * S(r, n) / n**r
where S(a, b) denotes Stirling numbers of the second kind, the number of ways to partition a set of n objects (each roll) into k non-empty subsets (each side).

You also find the OEIS sequence, which we'll call R(n), that corresponds to the smallest r where P(r, n) is at least 50%. The challenge is to calculate the nth term of this sequence as fast as possible.

The challenge

Given an n, find the smallest r where P(r, n) is greater than or equal to 0.5 or 50%.
Your code should theoretically handle any non-negative integer n as input, but we will only be testing your code in the range of 1 <= n <= 1000000.
For scoring, we will be take the total time required to run R(n) on inputs 1 through 10000.
We will check if your solutions are correct by running our version of R(n) on your output to see if P(your_output, n) >= 0.5 and P(your_output - 1, n) < 0.5, i.e. that your output is actually the smallest r for a given n.
You may use any definition for S(a, b) in your solution. Wikipedia has several definitions that may be helpful here.
You may use built-ins in your solutions, including those that calculate S(a, b), or even those that calculate P(r, n) directly.
You can hardcode up to 1000 values of R(n) and a million Stirling numbers, though neither of these are hard limits, and can be changed if you can make a convincing argument for raising or lowering them.
You don't need to check every possible r between n and the r we're looking for, but you do need to find the smallest r and not just any r where P(r, n) >= 0.5.
Your program must use a language that is freely runnable on Windows 10.
The specifications of the computer that will test your solutions are i7 4790k, 8 GB RAM. Thanks to @DJMcMayhem for providing his computer for the testing. Feel free to add your own unofficial timing for reference, but the official timing will be provided later once DJ can test it.

Test cases

n       R(n)
1       1
2       2
3       5
4       7
5       10
6       13
20      67       # our 20-sided die
52      225      # how many cards from a huge uniformly random pile until we get a full deck
100     497
366     2294     # number of people for to get 366 distinct birthdays
1000    7274
2000    15934
5000    44418
10000   95768
100000  1187943
1000000 14182022
Let me know if you have any questions or suggestions. Good luck and good optimizing!

"""

import numpy as np

"""

Ported from @Anders Kaseorg solution

How it works
This uses the closed-form series for P(r, n), and its derivative with respect to r,
rearranged for numerical stability and vectorization, to do a Newton’s method search for r such that P(r, n) = 0.5,
rounding r to an integer before each step, until the step moves r by less than 3/4.
With a good initial guess, this usually takes just one or two iterations.

xi = log(1 − i/n) = log((n − i)/n)
cxi = log(n!/((n − i − 1)! ⋅ ni + 1)
yi = cxi + cxn − i − 2 − cxn − 1 = log binom(n, i + 1)
zi = (-1)i + 1 ⋅ binom(n, i + 1) ⋅ ((n − i − 1)/n)r
1 + ∑zi = n! ⋅ S(r, n)/nr = P(r, n)
zi ⋅ xi + 1 = (-1)i + 1 ⋅ binom(n, i + 1) ⋅ ((n − i − 1)/n)r log((n − i − 1)/n)
∑zi ⋅ xi + 1 = d/dr P(r, n)

"""
def rolls(n):
    if n == 1:
        return 1
    r = n * (np.log(n) - np.log(np.log(2)))
    x = np.log1p(np.arange(n) / -n)
    cx = x.cumsum()
    y = cx[:-1] + cx[-2::-1] - cx[-1]
    while True:
        r0 = np.round(r)
        z = np.exp(y + r0 * x[1:])
        z[::2] *= -1
        r = r0 - (z.sum() + 0.5) / z.dot(x[1:])
        if abs(r - r0) < 0.75:
            return np.ceil(r).astype(int)

def main():
    assert(rolls(1) == 1)
    assert(rolls(2) == 2)
    assert(rolls(3) == 5)
    assert(rolls(4) == 7)
    assert(rolls(5) == 10)
    assert(rolls(6) == 13)
    assert(rolls(20) == 67)
    assert(rolls(52) == 225)
    assert(rolls(100) == 497)
    assert(rolls(366) == 2294)
    assert(rolls(1000) == 7274)
    assert(rolls(2000) == 15934)
    assert(rolls(5000) == 44418)
    assert(rolls(10000) == 95768)
    assert(rolls(100000) == 1187943)
    assert(rolls(1000000) == 14182022)

main()
