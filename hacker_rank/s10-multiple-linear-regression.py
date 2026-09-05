#!/usr/bin/env python3

"""

Task
Andrea has a simple equation:

Y = a + b1*f1 + b2*f2 + ... + bm*fm

for (m+1) real constants (a, f1, f2, f3, ..., fm). We can say that the value of Y depends on m features.
Andrea studies this equation for n different feature sets (f1, f2, ..., fm)  and records each respective value of Y.
If she has q new feature sets, can you help Andrea find the value of Y for each of the sets?

Note: You are not expected to account for bias and variance trade-offs.

Input Format

The first line contains 2 space-separated integers, m (the number of observed features) and n (the number of feature sets Andrea studied), respectively.
Each of the n subsequent lines contain m+1 space-separated decimals; the first m elements are features (f1, f2, ..., fm), and the last element is the value of Y for the line's feature set.
The next line contains a single integer, q, denoting the number of feature sets Andrea wants to query for.
Each of the q subsequent lines contains m space-separated decimals describing the feature sets.

Constraints
1 <= m <= 10
5 <= n <= 100
0 <= x[i] <= 1
0 <= Y <= 10^6
1 <= q <= 100

Scoring
For each feature set in one test case, we will compute the following:

d'[i] = |Computed value of Y - Expected Value of Y|/(Expected Value of Y). 
d[i] = max(d'[i] - 0.1, 0). We will permit up to a 10% margin of error.
s[i] = max(1.0 - d[i], 0.0)

The normalized score for each test case will be: S = (Sum[i=1, q] s[i])/q . If the challenge is worth C points, then your score will be S*C.

Output Format

For each of the  feature sets, print the value of  on a new line (i.e., you must print a total of  lines).

Sample Input

2 7
0.18 0.89 109.85
1.0 0.26 155.72
0.92 0.11 137.66
0.07 0.37 76.17
0.85 0.16 139.75
0.99 0.41 162.6
0.87 0.47 151.77
4
0.49 0.18
0.57 0.83
0.56 0.64
0.76 0.18

Sample Output

105.22
142.68
132.94
129.71

"""

from sklearn import linear_model

"""

The idea is to use least squares for:

Y = a + b1*X1 + b2*X2 + ... + bm*Xm

which just generalizes the one variable regression case of

Y = a + b*X

Once we have the coefficients a and b, we can use it to predict the outcome a new feature given by F

"""

def predict(X, Y, F):
    LM = linear_model.LinearRegression()
    LM.fit(X, Y)

    A = LM.intercept_
    B = LM.coef_

    r = A
    for i in range(len(F)):
        r += B[i]*F[i]
    return r

def main():
    X = [[0.18, 0.89], [1.0, 0.26], [0.92, 0.11], [0.07, 0.37], [0.85, 0.16], [0.99, 0.41], [0.87, 0.47]]
    Y = [109.85, 155.72, 137.66, 76.17, 139.75, 162.6, 151.77]
    F1 = [0.49, 0.18]
    F2 = [0.57, 0.83]
    F3 = [0.56, 0.64]
    F4 = [0.76, 0.18]

    print(predict(X, Y, F1))
    print(predict(X, Y, F2))
    print(predict(X, Y, F3))
    print(predict(X, Y, F4))

main()
