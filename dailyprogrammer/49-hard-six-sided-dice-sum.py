#!/usr/bin/env python3

"""

When you roll two regular six-sided dice, the total number of pips that can come up ranges from 2 (if both dice show 1) to 12 (if both dice show 6), but as all experienced gamblers know, some numbers are more likely than others. In fact, the most likely number to come up is 7, with a probability of 1/6. By contrast, the probability of 12 showing is only 1/36, so it is six times more likely that the dice will show 7 than it is that they will show 12.

The reason for this is of course that there are more ways that two dice can sum to 7. In fact, there are exactly six ways two dice can sum to 7: the first die can show 1 and the second 6, the first 2 and the second 5, the first 3 and the second 4, the first 4 and the second 3, the first 5 and the second 2, and finally the first die can show 6 and the second 1. Given that there are a total of 6*6 = 36 different ways the dice can land, this gives us the probability: 6/36 = 1/6. In contrast, there is only one way two dice can form 12, by throwing two sixes.

Define a function f(d, n) that gives the number of ways d six-sided dice can be thrown to show the number n. So, in the previous example, f(2,7) = 6. Here are a few other values of that function:

f(1,n) = 1 (for 1≤n≤6, 0 otherwise)
f(2,7) = 6
f(2,10) = 3
f(2,12) = 1
f(3,10) = 27
f(5,20) = 651
f(7,30) = 12117
f(10,50) = 85228

Find f(20, 100)

Note: the answer fits into a 64-bit integer

Bonus: Find f(1100, 5000) mod 10^7

"""

from math import comb

def binom(n, k):
    try:
        return comb(n, k)
    except:
        return 0

"""

@eruonna

The alternating sum is an inclusion-exclusion formula: binom (n-1) (k-1) counts the number of ways to write n as a sum of k positive integers.
We need those summands to be at most d.
There are k * binom (n-d-1) (k-1) ways to have at least one greater than d; just take a sum that gives n-d and add d to one of the summands.
But then you've doubly subtracted anything with two summands greater than d, so you do the inclusion-exclusion thing.

"""

def ways(d, n, k):
    r = 0
    for i in range(min(k, n // d) + 1):
        r += (-1)**i * binom(k, i) * binom(n - d*i - 1, k - 1)
    return r

def solve(d, n):
    return ways(6, n, d)

def main():
    for i in range(1, 7):
        assert(solve(1, i) == 1)

    assert(solve(2, 7) == 6)
    assert(solve(2, 10) == 3)
    assert(solve(2, 12) == 1)
    assert(solve(3, 10) == 27)
    assert(solve(5, 20) == 651)
    assert(solve(7, 30) == 12117)
    assert(solve(10, 50) == 85228)
    assert(solve(1100, 5000)%10**7 == 6647080)

main()
