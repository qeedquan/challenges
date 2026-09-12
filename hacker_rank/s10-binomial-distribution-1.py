#!/usr/bin/env python3

"""

Task
The ratio of boys to girls for babies born in Russia is 1.09:1. If there is 1 child born per birth, what proportion of Russian families with exactly 6 children will have at least 3 boys?

Write a program to compute the answer using the above parameters. Then print your result, rounded to a scale of 3 decimal places (i.e., 1.234 format).

Input Format

A single line containing the following values:

1.09 1
If you do not wish to read this information from stdin, you can hard-code it into your program.

Output Format

Print a single line denoting the answer, rounded to a scale of 3 decimal places (i.e., 1.234 format).

"""

from scipy.stats import binom

def solve(ratio, children=6, boys=3):
    prob = 0
    for i in range(boys, children + 1):
        prob += binom.pmf(i, children, ratio / (1 + ratio))
    return prob

def main():
    print("%.3f" % (solve(1.09/1)))

main()
