#!/usr/bin/env python3

"""

Task
The number of tickets purchased by each student for the University X vs. University Y football game follows a distribution that has a mean of µ=2.4 and a standard deviation of σ=2.0.

Suppose that a few hours before the game starts, there are 100 eager students standing in line to purchase tickets.
If there are only 250 tickets left, what is the probability that all 100 students will be able to purchase the tickets they want?

Output Format

Your output must be a floating point/decimal number, correct to a scale of 4 decimal places. You can submit solutions in either of the 2 following ways:

Solve the problem manually and submit your result as Plain Text. In the text box below, enter a single floating point/decimal number.

Submit an R or Python program, which uses the above parameters (hard-coded), and computes the answer.

Your answer should resemble something like:

0.1234
(This is NOT the answer, just a demonstration of the answering format.)

"""

from scipy.stats import norm
from math import sqrt

def solve(tickets, students, mean, stddev):
    loc = students * mean
    scale = sqrt(100) * stddev
    return norm.cdf(tickets, loc=loc, scale=scale)

def main():
    print("%.4f" % (solve(250, 100, 2.4, 2)))

main()
