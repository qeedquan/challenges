#!/usr/bin/env python3

"""

Given a series of numbers for events X and Y, calculate Pearson's correlation coefficient. The probability of each event is equal, so expected values can be calculated by simply summing each series and dividing by the number of trials.

Input
1   6.86
2   5.92
3   6.08
4   8.34
5   8.7
6   8.16
7   8.22
8   7.68
9   12.04
10  8.6
11  10.96
Output
0.769
Shortest code wins. Input can be by stdin or arg. Output will be by stdout.

Edit: Builtin functions should not be allowed (ie calculated expected value, variance, deviation, etc) to allow more diversity in solutions. However, feel free to demonstrate a language that is well suited for the task using builtins (for exhibition).

Based on David's idea for input for Mathematica (86 char using builtin mean)

m=Mean;x=d[[All,1]];y=d[[All,2]];(m@(x*y)-m@x*m@y)/Sqrt[(m@(x^2)-m@x^2)(m@(y^2)-m@y^2)]

m = Mean;
x = d[[All,1]];
y = d[[All,2]];
(m@(x*y) - m@x*m@y)/((m@(x^2) - m@x^2)(m@(y^2) - m@y^2))^.5
Skirting by using our own mean (101 char)

m=Total[#]/Length[#]&;x=d[[All,1]];y=d[[All,2]];(m@(x*y)-m@x*m@y)/((m@(x^2)-m@x^2)(m@(y^2)-m@y^2))^.5

m = Total[#]/Length[#]&;
x = d[[All,1]];
y = d[[All,2]];
(m@(x*y)-m@x*m@y)/((m@(x^2)-m@x^2)(m@(y^2)-m@y^2))^.5

"""

import numpy as np
from scipy import stats

def correlation(x, y):
    p = stats.pearsonr(x, y)
    return p.statistic

def main():
    print(correlation([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], [6.86, 5.92, 6.08, 8.34, 8.7, 8.16, 8.22, 7.68, 12.04, 8.6, 10.96]))

main()
