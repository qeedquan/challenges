#!/usr/bin/env python3

"""

Task
Given two n-element data sets, X and Y, calculate the value of Spearman's rank correlation coefficient.

Input Format

The first line contains an integer, n, denoting the number of values in data sets X and Y.
The second line contains n space-separated real numbers (scaled to at most one decimal place) denoting data set X.
The third line contains n space-separated real numbers (scaled to at most one decimal place) denoting data set Y.

Constraints

10 <= n <= 100
1 <= x[i] <= 500, where x[i] is the ith value of data set X.
1 <= y[i] <= 500, where y[i] is the ith value of data set Y.
Data set X contains unique values.
Data set Y contains unique values.

Output Format

Print the value of the Spearman's rank correlation coefficient, rounded to a scale of 3 decimal places.

Sample Input

10
10 9.8 8 7.8 7.7 1.7 6 5 1.4 2
200 44 32 24 22 17 15 12 8 4

Sample Output

0.903

"""

from scipy.stats import spearmanr

"""

The Spearman rank-order correlation coefficient is a nonparametric measure of the monotonicity of the relationship between two datasets.
Like other correlation coefficients, this one varies between -1 and +1 with 0 implying no correlation.
Correlations of -1 or +1 imply an exact monotonic relationship.
Positive correlations imply that as x increases, so does y.
Negative correlations imply that as x increases, y decreases.

"""

def main():
    print(spearmanr([10, 9.8, 8, 7.8, 7.7, 1.7, 6, 5, 1.4, 2], [200, 44, 32, 24, 22, 17, 15, 12, 8, 4]))

main()

