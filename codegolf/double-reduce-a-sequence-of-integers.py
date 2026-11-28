#!/usr/bin/env python3

"""

Consider a function r where

r(i, k) = L[i+1] - L[i]                                     if k=0 (1st reduction)
          r(i, 0) - r(floor(log2(k)), k - 2^floor(log2(k))) if k >= 1 (2nd reduction)

where k<2^i and L is a finite sequence of integers.

For example, assuming that  L={0,1,1,2,3,5},

for i=0,
r(0,0)=L1−L0=1−0=1.

for i=1,
r(1,0)=L2−L1=1−1=0.
r(1,1)=r(1,0)−r(0,0)=0−1=−1.

for i=2,
r(2,0)=L3−L2=2−1=1.
r(2,1)=r(2,0)−r(0,0)=1−1=0.
r(2,2)=r(2,0)−r(1,0)=1−0=1.
r(2,3)=r(2,0)−r(1,1)=1+1=2.

The double-reduction of L is created by concatenating results from  i=0, i=1, ...,
until every consecutive pair of elements of  L are visited.

In layperson's terms, this function subtracts two consecutive terms of L,
and then subtract every previous-calculated subtraction from that result.
Note that every call of  r(i,k), for i>0 and k>0, is already computed.

Input
A list of integers L. You can assume its size will be always greater or equal to 3.

Output
A sequence representing the double-reduction of L.

Indexing: Both 0- and  1-based indexing are allowed, and the following rules can be applied with both these types of indexing.
Format: The answers can use one of the following output methods:
Given some index n, it can return the n-th entry of the list.
Given some index n, it can return all entries up to the n-th one in the sequence.
Without taking any index, it can output all entries by printing them one by one or by returning a list.
Test cases
Here's the test cases for positive numbers, even numbers, prime numbers, Fibonacci numbers, power-of-2 numbers, lucky numbers and signed Fibonacci numbers, respectively:

[1, 2, 3] -> [1, 1, 0]
[2, 4, 6, 8] -> [2, 2, 0, 2, 0, 0, 2]
[2, 3, 5, 7, 11] -> [1, 2, 1, 2, 1, 0, 1, 4, 3, 2, 3, 2, 3, 4, 3]
[0, 1, 1, 2, 3, 5] -> [1, 0, -1, 1, 0, 1, 2, 1, 0, 1, 2, 0, 1, 0, -1, 2, 1, 2, 3, 1, 2, 1, 0, 1, 2, 1, 0, 2, 1, 2, 3]
[1, 2, 4, 8, 16, 32] -> [1, 2, 1, 4, 3, 2, 3, 8, 7, 6, 7, 4, 5, 6, 5, 16, 15, 14, 15, 12, 13, 14, 13, 8, 9, 10, 9, 12, 11, 10, 11]
[1, 3, 7, 9, 13, 15, 21] -> [2, 4, 2, 2, 0, -2, 0, 4, 2, 0, 2, 2, 4, 6, 4, 2, 0, -2, 0, 0, 2, 4, 2, -2, 0, 2, 0, 0, -2, -4, -2, 6, 4, 2, 4, 4, 6, 8, 6, 2, 4, 6, 4, 4, 2, 0, 2, 4, 6, 8, 6, 6, 4, 2, 4, 8, 6, 4, 6, 6, 8, 10, 8]
[0, 1, -1, 2, -3, 5, -8] -> [1, -2, -3, 3, 2, 5, 6, -5, -6, -3, -2, -8, -7, -10, -11, 8, 7, 10, 11, 5, 6, 3, 2, 13, 14, 11, 10, 16, 15, 18, 19, -13, -14, -11, -10, -16, -15, -18, -19, -8, -7, -10, -11, -5, -6, -3, -2, -21, -20, -23, -24, -18, -19, -16, -15, -26, -27, -24, -23, -29, -28, -31, -32]

Your solution should be implemented with fewest bytes as possible.

Brownie points for beating or matching my 70-bytes Python answer.

"""

"""

Ported from @loopy walt solution

How?
Once one all but ignores the confusing double indexing there is an obvious rather simple recursion.

"""

def reduction(first, *rest):
    results = []
    for value in rest:
        difference = value - first
        results.extend(difference - previous for previous in [0, *results])
        first = value
    return results

def solve(array):
    return reduction(*array)

def main():
    assert(solve([1, 2, 3]) == [1, 1, 0])
    assert(solve([2, 4, 6, 8]) == [2, 2, 0, 2, 0, 0, 2])
    assert(solve([2, 3, 5, 7, 11]) == [1, 2, 1, 2, 1, 0, 1, 4, 3, 2, 3, 2, 3, 4, 3])
    assert(solve([0, 1, 1, 2, 3, 5]) == [1, 0, -1, 1, 0, 1, 2, 1, 0, 1, 2, 0, 1, 0, -1, 2, 1, 2, 3, 1, 2, 1, 0, 1, 2, 1, 0, 2, 1, 2, 3])
    assert(solve([1, 2, 4, 8, 16, 32]) == [1, 2, 1, 4, 3, 2, 3, 8, 7, 6, 7, 4, 5, 6, 5, 16, 15, 14, 15, 12, 13, 14, 13, 8, 9, 10, 9, 12, 11, 10, 11])
    assert(solve([1, 3, 7, 9, 13, 15, 21]) == [2, 4, 2, 2, 0, -2, 0, 4, 2, 0, 2, 2, 4, 6, 4, 2, 0, -2, 0, 0, 2, 4, 2, -2, 0, 2, 0, 0, -2, -4, -2, 6, 4, 2, 4, 4, 6, 8, 6, 2, 4, 6, 4, 4, 2, 0, 2, 4, 6, 8, 6, 6, 4, 2, 4, 8, 6, 4, 6, 6, 8, 10, 8])
    assert(solve([0, 1, -1, 2, -3, 5, -8]) == [1, -2, -3, 3, 2, 5, 6, -5, -6, -3, -2, -8, -7, -10, -11, 8, 7, 10, 11, 5, 6, 3, 2, 13, 14, 11, 10, 16, 15, 18, 19, -13, -14, -11, -10, -16, -15, -18, -19, -8, -7, -10, -11, -5, -6, -3, -2, -21, -20, -23, -24, -18, -19, -16, -15, -26, -27, -24, -23, -29, -28, -31, -32])

main()
