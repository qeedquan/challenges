#!/usr/bin/env python3

"""

Objective
In this challenge, we practice calculating the mean, median, and mode. Check out the Tutorial tab for learning materials and an instructional video!

Task
Given an array, X, of N integers, calculate and print the respective mean, median, and mode on separate lines. If your array contains more than one modal value, choose the numerically smallest one.

Note: Other than the modal value (which will always be an integer), your answers should be in decimal form, rounded to a scale of 1 decimal place (i.e., 12.3, 7.0 format).

Example

N = 6
X = [1, 2, 3, 4, 5, 5]

The mean is 20/6 = 3.3.
The median is (3+4)/2 = 3.5.
The mode is 5 because 5 occurs most frequently.

Input Format

The first line contains an integer, N, the number of elements in the array.
The second line contains N space-separated integers that describe the array's elements.

Constraints

10 <= N <= 2500
0 < x[i] <= 10^5, where x[i] is the ith element of the array.
Output Format

Print 3 lines of output in the following order:

Print the mean on the first line to a scale of 1 decimal place (i.e., 12.3, 7.0).
Print the median on a new line, to a scale of 1 decimal place (i.e., 12.3, 7.0).
Print the mode on a new line. If more than one such value exists, print the numerically smallest one.

Sample Input

10
64630 11735 14216 99233 14470 4978 73429 38120 51135 67060

Sample Output

43900.6
44627.5
4978

"""

import scipy
import numpy as np

def solve(a):
    mode = scipy.stats.mode(a, keepdims=False)[0]
    print(a)
    print("Mean:   %.1f" % (np.mean(a)))
    print("Median: %.1f" % (np.median(a)))
    print("Mode:   %d" % (mode))
    print()

def main():
    solve([1, 2, 3, 4, 5, 5])
    solve([64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060])

main()
