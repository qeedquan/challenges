#!/usr/bin/env python3

"""

The problem is defined as follows:

Create a function that takes an integer and returns a list of integers, with the following properties:

Given a positive integer input, n, it produces a list containing n integers ≥ 1.
Any sublist of the output must contain at least one unique element, which is different from all other elements from the same sublist. Sublist refers to a contiguous section of the original list; for example, [1,2,3] has sublists [1], [2], [3], [1,2], [2,3], and [1,2,3].
The list returned must be the lexicographically smallest list possible.
There is only one valid such list for every input. The first few are:

f(2) = [1,2]         2 numbers used
f(3) = [1,2,1]       2 numbers used
f(4) = [1,2,1,3]     3 numbers used

"""

def gen(n):
    return [len(bin(i & ~(i - 1))) - 2 for i in range(1, n + 1)]

def main():
    for i in range(10):
        print(i, gen(i))

main()
