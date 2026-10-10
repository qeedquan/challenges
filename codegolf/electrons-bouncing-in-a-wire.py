#!/usr/bin/env python3

"""

Imagine a "wire" that has n spaces. Imagine further that there are "electrons" in that wire. These electrons only live for one unit of time. Any spaces in the wire that are adjacent to exactly one electron become an electron. In Game of Life terminology, this is B1/S.

For example, this is a wire of length 10, with period 62.

enter image description here

Rules
Input, n, is a single, positive integer.
Output must be a single integer denoting the period of a wire of length n.
The starting state is a single electron at one end of the wire.
The period does not necessarily include the starting state. Some lengths never return to the starting state, but all of them are periodic.
A static wire (i.e., one without electrons) has period 1.
Boundary conditions are not periodic. That is, the wire is not toroidal in any way.

Test cases
Special thanks to orlp for producing this list. (I have verified it up to n=27.)

1 1
2 2
3 1
4 6
5 4
6 14
7 1
8 14
9 12
10 62
11 8
12 126
13 28
14 30
15 1
16 30
17 28
18 1022
19 24
20 126
21 124
22 4094
23 16
24 2046
25 252
26 1022
27 56
28 32766
29 60
30 62
31 1
32 62
33 60
34 8190
35 56
36 174762
37 2044
38 8190
39 48
40 2046
41 252
42 254
43 248
44 8190
45 8188
You can see test cases for n=2 through 21 here with my Game-of-Life-esque simulator: Variations of Life.

EDIT: the sequence here has been published as A268754!

"""

# https://oeis.org/A268754
def electron_period(n):
    wire_mask = (1 << n) - 1
    power = lam = 1
    tortoise, hare = 1, 2
    while tortoise != hare:
        if power == lam:
            tortoise = hare
            power *= 2
            lam = 0
        hare = ((hare << 1) ^ (hare >> 1)) & wire_mask
        lam += 1
    return lam

def main():
    tab = [1, 2, 1, 6, 4, 14, 1, 14, 12, 62, 8, 126, 28, 30, 1, 30, 28, 1022, 24, 126, 124, 4094, 16, 2046, 252, 1022, 56, 32766, 60, 62, 1, 62, 60, 8190, 56, 174762, 2044, 8190, 48, 2046, 252, 254, 248, 8190, 8188]

    for i in range(len(tab)):
        assert(electron_period(i + 1) == tab[i])

main()
