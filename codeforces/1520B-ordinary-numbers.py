#!/usr/bin/env python3

"""

Let's call a positive integer n ordinary if in the decimal notation all its digits are the same. For example, 1, 2 and 99 are ordinary numbers, but 719 and 2021 are not ordinary numbers.

For a given number n, find the number of ordinary numbers among the numbers from 1 to n.

Input
The first line contains one integer t (1≤t≤10^4). Then t test cases follow.

Each test case is characterized by one integer n (1≤n≤10^9).

Output
For each test case output the number of ordinary numbers among numbers from 1 to n.

Example

input
6
1
2
3
4
5
100

output
1
2
3
4
5
18

"""

# https://oeis.org/A010785
def repdigit(n):
    if n < 1:
        return 0
    return int(str((n-1)%9 + 1) * ((n-1)//9 + 1))

def ordinaries(n):
    if n < 1:
        return 0

    i = 0
    while repdigit(i) <= n:
        i += 1
    return i - 1

def main():
    assert(ordinaries(1) == 1)
    assert(ordinaries(2) == 2)
    assert(ordinaries(3) == 3)
    assert(ordinaries(4) == 4)
    assert(ordinaries(5) == 5)
    assert(ordinaries(100) == 18)

main()
