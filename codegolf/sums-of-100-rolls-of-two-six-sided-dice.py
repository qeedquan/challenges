#!/usr/bin/env python3

"""

Suppose you have two six-sided dice. Roll the pair 100 times, calculating the sum of each pair. Print out the number of times each sum occurred. If a sum was never rolled, you must include a zero or some way to identify that that particular sum was never rolled.

Example Output: [3, 3, 9, 11, 15, 15, 11, 15, 7, 8, 3]

The number of times a sum was rolled is represented in the sums index - 2

In this example, a sum of two was rolled 3 times ([2-2]), a sum of three 3 times ([3-2]), a sum of four 9 times ([4-2]), and so on. It does not matter the individual dice rolls to arrive at a sum (5 and 2 would be counted as the same sum as 6 and 1)

"Ugly" outputs are fine (loads of trailing zeros, extra output, strange ways of representing data, etc.) as long as you explain how the data should be read.

"""

from random import *

def rolls(s, n):
    m = {}
    for i in range(n):
        k = randint(1, s) + randint(1, s)
        if k not in m:
            m[k] = 0
        m[k] += 1
    return m

def main():
    print(rolls(6, 100))

main()
