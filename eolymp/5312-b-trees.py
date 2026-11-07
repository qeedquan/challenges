#!/usr/bin/env python3

"""

If a tree could speak...

A B-tree is a data structure used for storing data in secondary memory, such as on a hard disk. It has the following properties:

Each non-leaf node has at least t children and at most 2t children, where t is a parameter known as the branching factor.

Each leaf node contains a number of keys, from t−1 to 2t−1.

The length of the path from the root to any leaf is the same for all leaves.

Note that the root node can also be a leaf.

Two B-trees are considered different if they differ as graphs with labeled vertices, or if a vertex with the same labels contains a different number of keys. For instance, there are 8 distinct B-trees with 4 keys and a branching factor of 2:

https://static.e-olymp.com/content/04/04b06bb3f704c6815cac293ed81490510019fef8.jpg

Determine the number of distinct B-trees that can be formed with n keys in the leaves and a branching factor of t.

Input
The first line contains two natural numbers n and t —
the number of keys in the leaves and the branching factor, respectively (1≤n≤500, 2≤t≤10^9).

Output
Print a single number on the first line, without leading zeros: the number of B-trees with n keys in the leaves and a branching factor of t.

Examples
Input #1
4 2

Answer #1
8

"""


def solve(n, t):
    # If the root is a single leaf node (Height = 0)
    ans = 1 if (t - 1 <= n <= 2 * t - 1) else 0

    # dp[k] stores the number of valid subtrees at current height with k leaf keys
    dp = [0] * (n + 1)
    for k in range(t - 1, min(2 * t - 1, n) + 1):
        dp[k] = 1

    # Max height a B-tree can reach with n keys is bounded
    # Loop over internal heights
    while any(dp):
        # We need to find the distribution for the root node (2 to 2t children)
        # and for the next level internal nodes (t to 2t children)

        # Helper to compute polynomial powers (combinations of child distributions)
        # poly_power[c][k] = ways to get k total leaf keys using exactly c children
        poly_power = [[0] * (n + 1) for _ in range(2 * t + 1)]
        poly_power[0][0] = 1

        # Compute combinations iteratively up to maximum children 2*t
        for c in range(1, 2 * t + 1):
            for i in range(n + 1):
                if poly_power[c-1][i] == 0:
                    continue
                for j in range(n + 1 - i):
                    if dp[j] == 0:
                        continue
                    poly_power[c][i + j] += poly_power[c-1][i] * dp[j]

        # 1. Add valid root choices for this height to the total answer
        # The root must have between 2 and 2*t children
        for c in range(2, min(2 * t, n) + 1):
            ans += poly_power[c][n]

        # 2. Transition dp to the next internal node level
        # Internal nodes must have between t and 2*t children
        next_dp = [0] * (n + 1)
        for k in range(n + 1):
            for c in range(t, min(2 * t, n) + 1):
                next_dp[k] += poly_power[c][k]

        dp = next_dp

    return ans

def main():
    assert(solve(4, 2) == 8)

main()
