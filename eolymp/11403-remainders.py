#!/usr/bin/env python3

"""

After Fuad got acquainted with the remainder operator, he thought about the next mathematical problem. He wonders how to compute (n mod 1)+(n mod 2)+…+(n mod m).

Here mod represents the remainder operator and (x mod y) represents the remainder obtained when x is divided by y. For example (8 mod 3)=2.

Find the value of the above expression for the given positive integers n and m.

Input
Two integers n and m (1≤n,m≤2⋅10^9).

Output
Print the value of the given expression.

Examples

Input #1
5 3

Answer #1
3

Input #2
3 3

Answer #2
1

Input #3
1 1

Answer #3
0

"""

# https://cp-algorithms.com/data_structures/sqrt_decomposition.html
# https://www.quora.com/How-do-I-calculate-the-sum-n-mod-1-n-mod-2-n-mod-3-n-mod-m
def solve(n, m):
    s = 0
    i = 1
    while i <= m and i <= n:
        k = n // i
        j = min(m, n // k)
        b = (j - i + 1) * (i + j) // 2
        s += b * k
        i = j + 1
    return m*n - s

def solvebf(n, m):
    r = 0
    for i in range(1, m + 1):
        r += n % i
    return r

def main():
    assert(solve(5, 3) == 3)
    assert(solve(3, 3) == 1)
    assert(solve(1, 1) == 0)

    for n in range(200):
        for m in range(200):
            assert(solve(n, m) == solvebf(n, m))

main()
