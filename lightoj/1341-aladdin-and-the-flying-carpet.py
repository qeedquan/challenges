#!/usr/bin/env python3

"""

It's said that Aladdin had to solve seven mysteries before getting the Magical Lamp which summons a powerful Genie. Here we are concerned about the first mystery.

Aladdin was about to enter to a magical cave, led by the evil sorcerer who disguised himself as Aladdin's uncle, found a strange magical flying carpet at the entrance. There were some strange creatures guarding the entrance of the cave. Aladdin could run, but he knew that there was a high chance of getting caught. So, he decided to use the magical flying carpet. The carpet was rectangular shaped, but not square shaped. Aladdin took the carpet and with the help of it he passed the entrance.

Now you are given the area of the carpet and the length of the minimum possible side of the carpet, your task is to find how many types of carpets are possible. For example, the area of the carpet 12, and the minimum possible side of the carpet is 2, then there can be two types of carpets and their sides are: {2, 6} and {3, 4}.

Input
Input starts with an integer T (≤ 4000), denoting the number of test cases.

Each case starts with a line containing two integers: a b (1 ≤ b ≤ a ≤ 10^12)
where a denotes the area of the carpet and b denotes the minimum possible side of the carpet.

Output
For each case, print the case number and the number of possible carpets.

Sample
Input	Output
2
10 2
12 2

Case 1: 1
Case 2: 2

"""

from sympy import divisors
from math import isqrt

def solve(a, b):
    if b*b == a or isqrt(a) < b:
        return 0
    
    d = divisors(a)
    r = len(d) // 2
    for x in d:
        if x < b:
            r -= 1
    return r

def main():
    assert(solve(10, 2) == 1)
    assert(solve(12, 2) == 2)
    assert(solve(15, 2) == 1)
    assert(solve(30, 4) == 1)
    assert(solve(84, 2) == 5)
    assert(solve(18, 2) == 2)
    assert(solve(669, 3) == 1)
    assert(solve(248975, 9631) == 0)

main()
