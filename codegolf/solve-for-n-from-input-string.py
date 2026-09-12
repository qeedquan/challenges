#!/usr/bin/env python3

"""

Challenge :
Your job is to find the given number N.

Input :
You will be given a string in the following form:

dN ± Y = X
Where:

d, N, X, Y are all numbers with d , X , Y being integers (not decimals).
Output :
Solve the equation and output the value of N rounded. Round up if decimal is greater than or equal to 0.5 and round down if less than 0.5

Examples :
Input                  Output
 N + 1 = 3        ---> 2
 N - 1 = 5        ---> 6
2N + 1 = 3        ---> 1
2N + 1 = 4        ---> 2
Winning criteria :
This is code-golf so the shortest code in each language wins.

Notes :
Answer must be rounded it cannot be a float
Whitespace do not matter. You can have every element in the string separated by white space if you want or if you don't want leave it as it is.
You do not need to check for invalid input. i.e. All inputs will be strings in the given format.

"""

from sympy import *
from sympy.abc import *

def solution(eq):
    x = solve(eq, N)
    if len(x) == 0:
        return None
    return round(x[0])

def main():
    assert(solution(Eq(N + 1, 3)) == 2)
    assert(solution(Eq(N - 1, 5)) == 6)
    assert(solution(Eq(2*N + 1, 3)) == 1)
    assert(solution(Eq(2*N + 1, 4)) == 2)

main()
