#!/usr/bin/env python3

"""

In a strange planet there are n races. They are completely different as well as their food habits. Each race has a feast period. Means that the ith race feasts after every xi de-sec (de-sec is the unit they use for counting time and it is used in both singular and plural forms). And at that particular de-sec, they spend the entire day feasting.

The planet declared the de-sec as 'Eid' in which all the races feast together.

Now given the feasting period for every race you have to find the number of de-sec between two consecutive Eids.

Input
Input starts with an integer T (≤ 225), denoting the number of test cases.

Each case of input will contain an integer n (2 ≤ n ≤ 1000) in a single line. The next line will contain n integers separated by spaces. The ith integer of this line will denote the eating period for the ith race. These integers will be between 1 and 10000.

Output
For each case of input you should print a line containing the case number and the number of de-sec between two consecutive Eids. Check the sample input and output for more details. The result can be big. So, use big integer calculations.

Sample
Input	Output
2
3
2 20 10
4
5 6 30 60

Case 1: 20
Case 2: 60

"""

from functools import reduce
from math import lcm

def solve(x):
    if len(x) == 0:
        return 0
    return reduce(lcm, x, 1)

def main():
    assert(solve([2, 20, 10]) == 20)
    assert(solve([5, 6, 30, 60]) == 60)
    assert(solve([138, 248975, 9247, 4852]) == 33511868684700)

main()
