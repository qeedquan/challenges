#!/usr/bin/env python3

"""

Most of the times, the students of Computer Science & Engineering of BUET deal with bogus, tough and
very complex formulae. That is why, sometimes, even for a easy problem they think very hard and make
the problem much complex to solve. But, the team members of the team “BUET PESSIMISTIC”
are the only exceptions. Just like the opposite manner, they treat every hard problem as easy and so
cannot do well in any contest. Today, they try to solve a series but fail for treating it as hard. Let
them help.

Input
Just try to determine the answer for the following series
Sum[i=1, N] i*A^i

You are given the value of integers N and A (1 ≤ N ≤ 150, 0 ≤ A ≤ 15).

Output
For each line of the input, your correct program should output the integer value of the sum in separate
lines for each pair of values of N and A.

Sample Input
3 3
4 4

Sample Output
102
1252

"""

def solve(n, a):
    r = 0
    for i in range(1, n+1):
        r += i * a**i
    return r

def main():
    assert(solve(3, 3) == 102)
    assert(solve(4, 4) == 1252)

main()

