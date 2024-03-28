#!/usr/bin/env python3

"""

Objective
In this challenge, we practice solving problems based on the Central Limit Theorem.

Task
A large elevator can transport a maximum of 9800 pounds. Suppose a load of cargo containing 49 boxes must be transported via the elevator.
The box weight of this type of cargo follows a distribution with a mean of µ=205 pounds and a standard deviation of o=15 pounds.
Based on this information, what is the probability that all  boxes can be safely loaded onto the freight elevator and transported?

Output Format

Your output must be a floating point/decimal number, correct to a scale of 4 decimal places. You can submit solutions in either of the 2 following ways:

Solve the problem manually and submit your result as Plain Text. In the text box below, enter a single floating point/decimal number.

Submit an R or Python program, which uses the above parameters (hard-coded), and computes the answer.

Your answer should resemble something like:

0.1234

(This is NOT the answer, just a demonstration of the answering format.)

"""

import scipy.stats
from math import *

def solve(max_pounds, sample_size, pop_mean=205, pop_sd=15):
    x = max_pounds / sample_size
    sample_sd = pop_sd / sqrt(sample_size)
    z_score = (x - pop_mean) / sample_sd
    return scipy.stats.norm.cdf(z_score)

def main():
    print('{:0.4f}'.format(solve(9800, 49)))

main()
