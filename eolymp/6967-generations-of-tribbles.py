#!/usr/bin/env python3

"""

Tribbles are the cute, fuzzy, cuddly animals that have voracious appetites and reproduction rates that rival any complex organism in the galaxy (tribbles are born pregnant!).
After being introduced to the Enterprise and its crew, it was quickly discovered what a nuisance tribbles could be.
In a very short amount of time, tribbles were everywhere on the ship.

Fortunately for the Enterprise, Engineer Scott was able to transport them to a nearby Klingon vessel.
The Klingons were unaware of the issues tribbles could cause and brought them into Klingon space, where the tribbles spread like locusts and devastated ecosystems of planets across the Klingon Empire.

Members of the United Federations of Planets (The Federation) found this extremely amusing and used the calculation of tribble reproduction as
an academic exercise for first year students at its academy.

The following sequence of numbers represents how tribbles reproduce. The first number represents generation 0, the second generation 1, and so on.

1,1,2,4,8,15,29,56

The following recurrence can be used to represent the above sequence, where n represents the generation number:

n<2:1

n=2:2

n=3:4

n>3:gen(n−1)+gen(n−2)+gen(n−3)+gen(n−4)

Those at the academy that know something about old Earth history have jokingly called the recurrence 'Tribblenacci'.

Your job as a first year student at the academy is to accurately and rapidly calculate how many tribbles there will be for a given 'Tribblenacci' number.
The fact is, evaluating the above recurrence recursively is slower than chemical propulsion for interstellar travel!
To do so for more than a handful of generations would clearly be illogical.

Input
The first line of input will be an integer t (0<t<69) representing the number of test cases.
Following this will be t integer values, one per line.
Each of these will represent a generation number g (0≤g≤67) to calculate.

Output
For each generation number read, display the corresponding 'Tribblenacci' value.

Examples

Input #1
8
0
1
2
3
4
5
30
67

Answer #1
1
1
2
4
8
15
201061985
7057305768232953720

"""

import numpy as np

# https://oeis.org/A000078
def tetranacci(n):
    if n < 0:
        return 0

    x = np.array([0, 0, 0, 1], dtype=object)
    if n > 4:
        A = np.array([[1, 1, 1, 1], [1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]], dtype=object)
        A = np.linalg.matrix_power(A, n - 4)
        x = np.dot(A, x)
    return x[0]

def solve(n):
    return tetranacci(n + 5)

def main():
    assert(solve(0) == 1)
    assert(solve(1) == 1)
    assert(solve(2) == 2)
    assert(solve(3) == 4)
    assert(solve(4) == 8)
    assert(solve(5) == 15)
    assert(solve(30) == 201061985)
    assert(solve(67) == 7057305768232953720)

main()
