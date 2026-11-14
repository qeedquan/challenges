#!/usr/bin/env python3

"""

Statement of problem
Given a set of unique, consecutive primes (not necessarily including 2), generate the products of all combinations of first powers of these primes — e.g., no repeats — and also 1. For example, given the set { 2, 3, 5, 7 }, you produce { 1, 2, 3, 5, 6, 7, 10, 14, 15, 21, 30, 35, 42, 70, 105, 210 } because:

  1  =  1
  2  =  2
  3  =  3
  5  =  5
  6  =  2 x 3
  7  =  7
 10  =  2 x 5
 14  =  2 x 7
 15  =  3 x 5
 21  =  3 x 7
 30  =  2 x 3 x 5
 35  =  5 x 7
 42  =  2 x 3 x 7
 70  =  2 x 5 x 7
105  =  3 x 5 x 7
210  =  2 x 3 x 5 x 7
Note that if the cardinality of your input set is k, this will give you 2^k members in your output set.

Rules/Conditions
You can use any language. Aim for the smallest character count of source code.
Your solution must be either a complete program or a complete function. The function can be anonymous (if your language supports anonymous functions).
Your solution should be able to support products up to at least 2^31. Don't worry about detecting or handling integer overflow if you are passed numbers whose product is too great to represent. However, please state the limits of your calculations.
You may accept either a list or a set and produce either a list or a set. You may assume the input is sorted but you are not required to produce sorted output.
Background
When or why is this useful? One place it is very useful is in generating a table of multipliers to race in parallel in an integer factoring algorithm known as Square Forms Factorization. There, each odd multiplier you try decreases the probability of the algorithm failing (to find a factor) by approximately 50% on hard semiprimes. So with the set of generating primes { 3, 5, 7, 11 }, which produces a set of 16 trial multipliers to race in parallel, the algorithm fails approximately 2^–16 of the time on hard semiprimes. Adding 13 to the primes list produces a set of 32 trial multipliers, reducing the chance of failure to approximately 2^–32, giving a drastic improvement in outcome at no additional computational expense (because even with twice as many multipliers racing in parallel, on average it still finds the answer in the same total number of steps).

"""

from itertools import combinations
from math import prod

def generate(primes):
    print(1, [1])
    for size in range(1, len(primes) + 1):
        for numbers in combinations(primes, size):
            print(prod(numbers), list(numbers))

def main():
    generate([2, 3, 5, 7])

main()
