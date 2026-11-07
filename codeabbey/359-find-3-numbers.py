#!/usr/bin/env python3

"""

You are given a positive integer N and must find 3 positive integers X, Y and Z which satisfy all of the following conditions.

The 3 numbers X, Y and Z are all different and are all greater than 1.
The products X*Y, X*Z and Y*Z are all divisors of N.
The product X*Y*Z is a multiple of N.
For example, if N = 100 we find that X = 2, Y = 5 and Z = 10 satisfies these 3 conditions. The products X*Y, X*Z and Y*Z are 10, 20 and 50 respectively. All of these are divisors of N = 100. The product X*Y*Z = 2*5*10 = 100 = 1 x 100. So this is a multiple of N as required.

If we consider N = 35 we soon find that there is no combination of integers X, Y and Z which satisfy the requirements.

For each solution you must give the 3 values of X, Y and Z in ascending size order, separated by single spaces. If there is no solution for a particular value of N, you indicate this with a single 0 in place of the 3 values for X, Y and Z.

Input/Output description: The first line of the input data will contain a single integer M, the number of different values of N to consider. M lines will follow. Each line contains a single value of N. Find the corresponding values of X, Y and Z (in ascending order) or report 0 if there is no solution. Combine all answers into a single string, separated by spaces.

Example:

input:
3
100
35
3485

answer:
2 5 10 0 5 17 41

"""

import sympy

def solve(n):
    if n < 1:
        return (0, 0, 0)

    d = sympy.divisors(n)[1:]
    for i in range(len(d)):
        x = d[i]
        for j in range(i+1, len(d)):
            y = d[j]
            if n%(x*y) != 0:
                continue
            for k in range(j+1, len(d)):
                z = d[k]
                if n%(x*z) == 0 and n%(y*z) == 0:
                    if (x*y*z)%n == 0:
                        return (x, y, z)
    return (0, 0, 0)

def main():
    assert(solve(100) == (2, 5, 10))
    assert(solve(35) == (0, 0, 0))
    assert(solve(3485) == (5, 17, 41))

main()
