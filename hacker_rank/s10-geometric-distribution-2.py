#!/usr/bin/env python3

"""

Task
The probability that a machine produces a defective product is 1/3. What is the probability that the 1st defect is found during the first 5 inspections?

Input Format

The first line contains the respective space-separated numerator and denominator for the probability of a defect, and the second line contains the inspection we want the probability of the first defect being discovered by:

1 3
5

If you do not wish to read this information from stdin, you can hard-code it into your program.

Output Format

Print a single line denoting the answer, rounded to a scale of 3 decimal places (i.e., 1.234 format).

"""

from scipy.stats import geom

"""

To get the probability of something happening in N inspections, sum the probability of it happening from 1 to N

"""

def solve(n, p):
    r = 0
    for i in range(1, n + 1):
        r += geom.pmf(i, p) 
    return r

def main():
    print(solve(5, 1/3))

main()
