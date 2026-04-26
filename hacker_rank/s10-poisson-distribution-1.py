#!/usr/bin/env python3

from scipy.stats import poisson

"""

Task
A random variable, X, follows Poisson distribution with mean of 2.5. Find the probability with which the random variable X is equal to 5.

Input Format

The first line contains X's mean. The second line contains the value we want the probability for:

2.5
5

If you do not wish to read this information from stdin, you can hard-code it into your program.

Output Format

Print a single line denoting the answer, rounded to a scale of 3 decimal places (i.e., 1.234 format).

"""

def main():
    print(poisson.pmf(5, 2.5))

main()
