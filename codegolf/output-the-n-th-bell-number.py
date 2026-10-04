#!/usr/bin/env python3

"""

A Bell number (OEIS A000110) is the number of ways to partition a set of n labeled (distinct) elements. The 0th Bell number is defined as 1.

Let's look at some examples (I use brackets to denote the subsets and braces for the partitions):

1: {1}
2: {[1,2]}, {[1],[2]}
3: {[1,2,3]}, {[1,2],[3]}, {[1,3],[2]}, {[2,3],[1]}, {[1],[2],[3]}
There are many ways to compute Bell numbers, and you are free to use any of them. One way will be described here:

The easiest way to compute Bell numbers is to use a number triangle resembling Pascal's triangle for the binomial coefficients. The Bell numbers appear on the edges of the triangle. Starting with 1, each new row in the triangle is constructed by taking the last entry in the previous row as the first entry, and then setting each new entry to its left neighbor plus its upper left neighbor:

1
1    2
2    3    5
5    7   10   15
15  20   27   37   52
You may use 0-indexing or 1-indexing. If you use 0-indexing, an input of 3 should output 5, but should output 2 if you use 1-indexing.

Your program must work up to the 15th Bell number, outputting 1382958545. In theory, your program should be able to handle larger numbers (in other words, don't hardcode the solutions). EDIT: You are not required to handle an input of 0 (for 0-indexing) or 1(for 1-indexing) because it is not computed by the triangle method.

Test cases (assuming 0-indexing):

0 ->  1 (OPTIONAL)
1 ->  1
2 ->  2
3 ->  5
4 ->  15
5 ->  52
6 ->  203
7 ->  877
8 ->  4140
9 ->  21147
10 -> 115975
11 -> 678570
12 -> 4213597
13 -> 27644437
14 -> 190899322
15 -> 1382958545
Answers using a built-in method (such as BellB[n] in the Wolfram Language) that directly produces Bell numbers will be noncompetitive.

Shortest code (in bytes) wins.

"""

from sympy import *

# https://oeis.org/A000110
def main():
    tab = [1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570, 4213597, 27644437, 190899322, 1382958545, 10480142147, 82864869804, 682076806159, 5832742205057, 51724158235372, 474869816156751, 4506715738447323, 44152005855084346, 445958869294805289, 4638590332229999353, 49631246523618756274]

    for i in range(len(tab)):
        assert(bell(i) == tab[i])

main()
