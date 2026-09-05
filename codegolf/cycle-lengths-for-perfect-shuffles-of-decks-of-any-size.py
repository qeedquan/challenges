#!/usr/bin/env python3

"""

Challenge
In the shortest amount of code:

Compute the length of the permutation cycle of a perfect shuffle on a deck of cards of any size n (where n ≥ 2 and n is even).
Output a table of all cycle lengths for 2 ≤ n ≤ 1000 (n even).
Note that there are two basic ways of defining a perfect shuffle.
There is the out-shuffle, which keeps the first card on top and the last card on bottom, and there is the in-shuffle, which moves the first and last cards one position toward the center.
You may choose whether you are doing an out-shuffle or an in-shuffle; the algorithm is almost identical between the two.

out-shuffle of 10-card deck: [1,2,3,4,5,6,7,8,9,10] ↦ [1,6,2,7,3,8,4,9,5,10].
in-shuffle of 10-card deck: [1,2,3,4,5,6,7,8,9,10] ↦ [6,1,7,2,8,3,9,4,10,5].
Graphical example
Here, we see that an out-shuffle on a 20-card deck has a cycle length of 18 steps. (This is for illustration only; your solution is not required to output cycles graphically.) The classic 52-card deck, on the other hand, has an out-shuffle cycle length of only 8 steps (not shown).

https://i.sstatic.net/qd3ie.png

An in-shuffle on a 20-card deck has a cycle length of only 6 steps.

https://i.sstatic.net/ZgCOZ.png

Tabular example of output
Your program should output something similar to this, although you may choose any tabular format that you like best. This is for an out-shuffle:

2 1
4 2
6 4
8 3
10 6
12 10
14 12
16 4
18 8
20 18
22 6
24 11
26 20
28 18
30 28
32 5
34 10
36 12
38 36
40 12
...many lines omitted...
1000 36
Questions
Does there seem to be any connection between the number input n and its cycle count, when n is a power of 2?
How about when n is not a power of 2?
Curiously, a 1000-card deck has an out-shuffle cycle count of only 36, while a 500-card deck has an out-shuffle cycle count of 166. Why might this be?
What is the largest number you can find whose cycle count c is vastly smaller than n, meaning that ratio n/c is maximized?

"""

from sympy import n_order

# https://oeis.org/A002326
def main():
    for n in range(1, 501):
        print(2*n, n_order(2, 2*n + 1))

main()
