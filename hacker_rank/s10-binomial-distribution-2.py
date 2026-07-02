#!/usr/bin/env python3

"""

Task
A manufacturer of metal pistons finds that, on average, 12% of the pistons they manufacture are rejected because they are incorrectly sized. What is the probability that a batch of 10 pistons will contain:

No more than 2 rejects?
At least 2 rejects?

Input Format

A single line containing the following values (denoting the respective percentage of defective pistons and the size of the current batch of pistons):

12 10
If you do not wish to read this information from stdin, you can hard-code it into your program.

Output Format

Print the answer to each question on its own line:

The first line should contain the probability that a batch of 10 pistons will contain no more than 2 rejects.
The second line should contain the probability that a batch of 10 pistons will contain at least 2 rejects.
Round both of your answers to a scale of 3 decimal places (i.e., 1.234  format).

"""

from scipy.stats import binom

def solve(rejects, total, prob):
    prob0 = binom.cdf(rejects, total, prob)
    prob1 = binom.cdf(total, total, prob) - binom.cdf(rejects - 1, total, prob)
    return (prob0, prob1)

def main():
    print("%.3f %.3f" % (solve(2, 10, 0.12)))

main()
