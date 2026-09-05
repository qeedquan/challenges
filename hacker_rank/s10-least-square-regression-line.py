#!/usr/bin/env python3

"""

Task
You are given the Math aptitude test (x) scores for a set of students, as well as their respective scores for a Statistics course (y). The students enrolled in Statistics immediately after taking the math aptitude test.

The scores (x, y) for each student are:

(95, 85) (85, 95) (80, 70) (70, 65) (60, 70)

If a student scored an 80 on the Math aptitude test, what score would we expect her to achieve in Statistics? Determine the equation of the best-fit line using the least squares method, and then compute the value of y when x=80.

Output Format

You can submit solutions in either of the 2 following ways:

Solve the problem manually and submit your result as Plain Text. In the text box below, enter a single floating point/decimal number denoting the score.
Submit an R or Python program, which uses the above parameters (hard-coded), then computes and prints the score.
Your answer should follow the format below, and must not contain any extra white space or newline characters:

60.5

"""

import numpy as np

def solve():
    x = np.array([95, 85, 80, 70, 60])
    y = np.array([85, 95, 70, 65, 70])
    A = np.vstack([x, np.ones(len(x))]).T
    m, c = np.linalg.lstsq(A, y, rcond=None)[0]
    print("%.1f" % (m*80 + c))

def main():
    solve()

main()
