#!/usr/bin/env python3

"""

A hypergeometric distribution is associated with sampling without replacement.

Select n items without replacement from a set of N items of which:
m of the items are of one type and N-m of the items are of a second type

The PMF for it is then:

P(X = x) = f(x) = binomial(m, x)*binomial(N-m, n-x) / binomial(N, n)

The support bounds are:
x <= n*x <= m*n - x <= N - m

Intuitively the formula says the following:

The total number of things we can pick out is binomial(N, n)
The subset binomial(m, x) is the combinations of item of one type that we can pick out
The subset binomial(N-m, n-x) is the combinations of item of the other type that we can pick out

Multiplying the two subsets gives the count of how many items that is of that first type in the subset
Divide that by the total combinations of items to get the probability

"""

from scipy.stats import hypergeom

"""

A crate contains 50 light bulbs of which 5 are defective and 45 are not. A Quality Control Inspector randomly samples 4 bulbs without replacement.
Let X = the number of defective bulbs selected.
Find the probability mass function, f(x), of the discrete random variable X.

"""

def problem1():
    return hypergeom.pmf(4, 50, 5, 4)

"""

Let the random variable X denote the number of aces in a five-card hand dealt from a standard 52-card deck. Find a formula for the probability mass function of X.

"""

def problem2(x):
    return hypergeom.pmf(x, 52, 5, 4)

def main():
    print(problem1())
    print(problem2(0))
    print(problem2(1))

main()
