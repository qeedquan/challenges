#!/usr/bin/env python3

"""

To celebrate the Lunar New Year of the Rat, Douglas decided to estimate the number of rats living in his neighborhood.
It is impossible to find all the rats, since they are usually well hidden.
However, on the first day of the new year, Douglas manages to catch n1 rats.
He marks each of them with an ear tag and then releases them.

On the second day of the new year, Douglas catches n2 rats and observes that n12 of them had already been marked on the first day.

Douglas asks you to help estimate the total number of rats in his neighborhood.
After consulting a statistics textbook, you suggest using the Chapman estimator N, which is computed by the formula

N = floor((n1 + 1)*(n2 + 1)/(n12 + 1) - 1)

Input
Three integers: n1,n2,n12 (0≤n1,n2≤10000,0≤n12≤min(n1,n2)).

Output
Print one integer — the value of the estimator N.

Examples

Input #1
15 18 11

Answer #1
24

"""

def solve(n1, n2, n12):
    return int((n1 + 1)*(n2 + 1)/(n12 + 1) - 1)

def main():
    assert(solve(15, 18, 11) == 24)

main()
