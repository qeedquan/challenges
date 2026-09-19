#!/usr/bin/env python3

"""

You are in a maze; seeing n doors in front of you in the beginning. You can choose any door you would like. The probability for choosing a door is equal for all the doors.

If you choose the ith door, it can either take you back to the same position where you began in xi minutes, or can take you out of the maze after xi minutes. If you come back to the same position, you can't remember anything. So, every time you come to the beginning position, you have no past experience.

Now, you want to find the expected time to get out of the maze.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case contains a blank line and an integer n (1 ≤ n ≤ 100) denoting the number of doors. The next line contains n space separated integers. If the ith integer (xi) is positive, you can assume that the ith door will take you out of the maze after xi minutes. If it's negative, then the ith door will take you back to the beginning position after abs(xi) minutes. You can safely assume that 1 ≤ abs(xi) ≤ 10000.

Output
For each case, print the case number and the expected time to get out of the maze. If it's impossible to get out of the maze, print inf. Print the result in p/q format. Where p is the numerator and q is the denominator of the result respectively. p and q should be relatively prime. See the samples for details.

Sample
Input	Output
3

1
1

2
-10 -3

3
3 -6 -9

Case 1: 1/1
Case 2: inf
Case 3: 18/1

"""

from math import gcd

def solve(values):
    total = 0
    negatives = 0
    for value in values:
        total += abs(value)
        if value < 0:
            negatives += 1
    
    if negatives == len(values):
        return "inf"
    
    numerator = total
    denominator = len(values) - negatives
    multiple = gcd(numerator, denominator)
    
    numerator //= multiple
    denominator //= multiple
    return (numerator, denominator)

def main():
    assert(solve([1]) == (1, 1))
    assert(solve([-10, -3]) == "inf")
    assert(solve([3, -6, -9]) == (18, 1))

main()
