#!/usr/bin/env python3

"""

Description

Superbowl Sunday is nearly here. In order to pass the time waiting for the half-time commercials and wardrobe malfunctions, the local hackers have organized a betting pool on the game. Members place their bets on the sum of the two final scores, or on the absolute difference between the two scores.
Given the winning numbers for each type of bet, can you deduce the final scores?

Input

The first line of input contains n, the number of test cases. n lines follow, each representing a test case. Each test case gives s and d, non-negative integers representing the sum and (absolute) difference between the two final scores.

Output

For each test case, output a line giving the two final scores, largest first. If there are no such scores, output a line containing "impossible". Recall that football scores are always non-negative integers.

Sample Input

2
40 20
20 40

Sample Output

30 10
impossible

Source

Waterloo local 2005.02.05

"""

def score(s, d):
    if (s+d)%2 != 0 or d > s:
        return "impossible"
    return ((s+d)//2, (s-d)//2)

def main():
    assert(score(40, 20) == (30, 10))
    assert(score(20, 40) == "impossible")

main()
