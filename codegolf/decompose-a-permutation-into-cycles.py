#!/usr/bin/env python3

"""

There is a well-known theorem that any permutation can be decomposed into a set of cycles. Your job is to write the shortest possible program to do so.

Input:
Two lines. The first contains a number N, the second contains N distinct integers in the range [0,N-1] separated by spaces. These integers represent a permutation of N elements.

Output:
One line for each cycle in the permutation. Each line should be a space-separated list of integers in cycle order.

Cycles can be output in any order, and each cycle can be output starting at any position.

Example 1:
8
2 3 4 5 6 7 0 1
This input encodes the permutation 0->2, 1->3, 2->4, 3->5, 4->6, 5->7, 6->0, 7->1. This decomposes into cycles like this:

0 2 4 6
1 3 5 7
An equally valid output would be

5 7 1 3
2 4 6 0
Example 2:
8
0 1 3 4 5 6 7 2
valid output:

0
1
4 5 6 7 2 3

"""

def decompose(array):
    lookup = {}
    for index, value in enumerate(array):
        lookup[index] = value

    result = []
    while lookup:
        cycles = []
        value = list(lookup)[0]
        while value in lookup:
            cycles.append(value)
            value = lookup.pop(value)
        result.append(cycles)
    return result

def main():
    print(decompose([2, 3, 4, 5, 6, 7, 0, 1]))
    print(decompose([0, 1, 3, 4, 5, 6, 7, 2]))

main()
