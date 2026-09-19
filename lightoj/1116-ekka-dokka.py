#!/usr/bin/env python3

"""

Ekka and his friend Dokka decided to buy a cake. They both love cakes and that's why they want to share the cake after buying it. As the name suggested that Ekka is very fond of odd numbers and Dokka is very fond of even numbers, they want to divide the cake such that Ekka gets a share of N square centimeters and Dokka gets a share of M square centimeters where N is odd and M is even. Both N and M are positive integers.

They want to divide the cake such that N * M = W, where W is the dashing factor set by them. Now you know their dashing factor, you have to find whether they can buy the desired cake or not.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains an integer W (2 ≤ W < 2^63). And W will not be a power of 2.

Output
For each case, print the case number first. After that print Impossible if they can't buy their desired cake. If they can buy such a cake, you have to print N and M. If there are multiple solutions, then print the result where M is as small as possible.

Sample
Input	Output
3
10
5
12

Case 1: 5 2
Case 2: Impossible
Case 3: 3 4

"""

def solve(n):
    if n%2 == 1:
        return "Impossible"
    
    m = 1
    while n%2 == 0:
        m *= 2
        n //= 2
    return (n, m)

def main():
    assert(solve(10) == (5, 2))
    assert(solve(5) == "Impossible")
    assert(solve(12) == (3, 4))

main()
