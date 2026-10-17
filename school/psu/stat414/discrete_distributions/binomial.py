#!/usr/bin/env python3

"""

Binomial Random Variable
A discrete random variable X is a binomial random variable if:

An experiment, or trial, is performed in exactly the same way n times.
Each of the n trials has only two possible outcomes. One of the outcomes is called a "success," while the other is called a "failure." Such a trial is called a Bernoulli trial.
The n trials are independent.
The probability of success, denoted p, is the same for each trial. The probability of failure is q = 1 - p.
The random variable X=the number of successes in the trials.

"""

from math import *
import scipy

"""

The binomial distribution is parameterized by:

n - total number of possible outcomes for p
p - probability of an event happening
x - ranges from [0, n] that

pmf(x) gives the probablity that x occurs out of (n, p)

"""

def binomial_pmf(x, n, p):
    return comb(n, x) * p**x * (1 - p)**(n - x)

"""

P = Penn State fan
N = Notre Dame fan
S = {PPP, PPN, PNP, NPP, NNP, NPN, PNN, NNN}

Since we have two outcomes this can be modeled by a binomial distribution with the following:

B(X=0) = B(NNN)
B(X=1) = B(NNP) + B(NPN) + B(PNN)
B(X=2) = B(PPN) + B(PNP) + B(NPP)
B(X=3) = B(PPP)

"""

def problem1():
    for x in range(4):
        print(x, binomial_pmf(x, 3, 0.8), scipy.stats.binom.pmf(x, 3, 0.8))

def main():
    problem1()

main()
