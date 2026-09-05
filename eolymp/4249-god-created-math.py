#!/usr/bin/env python3

"""

There is a saying: computer was the crystallization of men's intelligence, but math is from god. Today, god also sends us a problem.

sin(n! * floor(log(n)) * fibonacci(n) % 2012)

In sin(x), x is a radian.

0!=1, n!=(n−1)!⋅n (n≥1).

[x] is the integer part of a floating number.

fib(0)=fib(1)=1, and fib(n)=fib(n−1)+fib(n−2) (n≥2).

Your task is calculating the value with a given N.

Input
The first line contains a single integer T, indicating the number of test cases. Each test case contains one integer N (1≤N≤1000000000).

Output
For each test case, output the result rounded to three fractional digits.

Examples
Input #1
3
1
4
10

Answer #1
0.000
0.581
0.978

"""

from math import sin, log, floor
from sympy import factorial, fibonacci

"""

n! mod m is 0 if n > m because n! will contain m as one of the factors,
so the function will become sin(0) when n gets large enough.

"""

def solve(n):
    mod = 2012
    if n == 0 or n > mod:
        return 0
    return sin((factorial(n) * int(floor(log(n))) * fibonacci(n + 1)) % mod)

def main():
    print(solve(1))
    print(solve(4))
    print(solve(10))
    print(solve(2012))
    print(solve(1000000000))

main()
