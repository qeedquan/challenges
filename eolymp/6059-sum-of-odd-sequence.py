#!/usr/bin/env python3

"""

Given an odd integer N, calculate the sum of all the odd integers between 1 and N inclusive.

Input
First line of the input contains T, the number of test cases. Each test case contains a single integer N. N is between 1 and 100.

Output
For each test case output the value 1+3+…+N.

Examples

Input #1
10
1
3
5
7
9
11
13
15
17
19

Answer #1
1
4
9
16
25
36
49
64
81
100

"""

def solve(n):
    if n < 1:
        return 0
    
    k = (n + 1) // 2
    return 2*k*k // 2

def main():
    assert(solve(1) == 1)
    assert(solve(3) == 4)
    assert(solve(5) == 9)
    assert(solve(7) == 16)
    assert(solve(9) == 25)
    assert(solve(11) == 36)
    assert(solve(13) == 49)
    assert(solve(15) == 64)
    assert(solve(17) == 81)
    assert(solve(19) == 100)

main()
