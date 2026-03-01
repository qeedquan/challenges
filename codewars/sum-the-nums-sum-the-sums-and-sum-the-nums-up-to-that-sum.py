#!/usr/bin/env python3

"""

Let's define two functions:

S(N) — sum of all positive numbers not more than N
S(N) = 1 + 2 + 3 + ... + N

Z(N) — sum of all S(i), where 1 <= i <= N
Z(N) = S(1) + S(2) + S(3) + ... + S(N)
You will be given an integer N as input; your task is to return the value of S(Z(N)).

For example, let N = 3:

Z(3) = 1 + 3 + 6 = 10
S(Z(3)) = S(10) = 55
The input range is 1 <= N <= 10^9 and there are 80 ( 40 in LC ) test cases, of which most are random.

This is my first kata and I hope you'll enjoy it :).
Best of luck!

"""

from math import comb

# https://oeis.org/A373733
def sumofsums(n):
    return comb(comb(n + 2, 3) + 1, 2)

def main():
    assert(sumofsums(3) == 55)
    assert(sumofsums(5) == 630)
    assert(sumofsums(100) == 14740530850)

main()
