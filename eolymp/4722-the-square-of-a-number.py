#!/usr/bin/env python3

"""

The number n is written k times consecutively. The resulting number is multiplied by itself. What is the result?

Input
The first line contains nonnegative integer n (n≤777). The second line contains positive integer k (k≤777).

Output
Print the resulting number.

Examples

Input #1
1
2

Answer #1
121

Input #2
12
3

Answer #2
14692348944

"""

import sys

def solve(n, k):
    return int(str(n)*k)**2

def main():
    sys.set_int_max_str_digits(100000)
    assert(solve(1, 2) == 121)
    assert(solve(12, 3) == 14692348944)

main()
