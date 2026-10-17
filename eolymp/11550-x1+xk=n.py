#!/usr/bin/env python3

"""

Find the number of positive integer solutions to the equation

x1+x2+⋯+xk=n

Input
Two positive integers k and n (k≤n≤100).

Output
Print the number of positive integer solutions to the given equation.
It is known that the answer does not exceed 10^18.

Examples
There are 3 positive integer solutions to the equation x1+x2+x3=4:

(1,1,2)

(1,2,1)

(2,1,1)

Input #1
3 4
Answer #1
3

"""

from math import comb

"""

https://math.stackexchange.com/questions/2018957/number-of-solutions-to-x-1x-2-x-m-n

@N. F. Taussig

We wish to find the number of solutions to the equation

x1+x2+⋯+xm=n

where each xk, 1≤k≤m, is a positive integer.
As you observed, if we set yk=xk−1, then yk is a non-negative integer and

y1+y2+⋯+ym=n−m

which has the same number of solutions in the non-negative integers that equation 1 has in the positive integers.
A particular solution of equation 2 corresponds to the placement of m−1 addition signs in a row of n−m ones.

For example, if n=10 and m=3, then n−m=7, so 11 + +11111
corresponds to the solution y1=2, y2=0, and y3=5, while 1111+11+1 corresponds to the solution y1=4, y2=2, and y3=1.

Thus, the number of solutions of equation 2 is the number of ways we can select which m−1 of the (n−m)+(m−1)=n−1
symbols (n−m ones and m−1 addition signs) are addition signs, which is

binomial(n-1, m-1)

"""

def solve(k, n):
    return comb(n - 1, k - 1)

def main():
    assert(solve(3, 4) == 3)

main()
