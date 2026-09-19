#!/usr/bin/env python3

"""

Help Shashank in calculating the value of S, which is given as follows. Since the value of S can be very large, he only wants the last 2 digits of S.

Input Format
The first line contains an integer T i.e. number of the test cases.
The next T lines will each contain a pair of integers, i.e. K and N.

Output Format
Print the last two digits of S for each test case in separate lines.

Constraints

Sample Input#00
3
2 2
2 3
3 3

Sample Output#00
05
09
36

Sample Input#01
3
5 2
3 4
3 3

Sample Output#01
55
98
36

Explanation

For the first test case,
1^2 + 2^2 + 3^2 + 4^2 + 5^2 = 55

"""

def solve(k, n):
    m = 100
    r = 0
    for i in range(1, k + 1):
        r = (r + pow(i, n, m)) % m
    return r

def main():
    assert(solve(2, 2) == 5)
    assert(solve(2, 3) == 9)
    assert(solve(3, 3) == 36)
    assert(solve(5, 2) == 55)
    assert(solve(3, 4) == 98)

main()
