#!/usr/bin/env python3

"""

You are given an integer n. You can perform the following three types of operations:

Decrease n by 1.

Increase n by 1.

If n is divisible by 3, divide n by 3.

Determine the minimum number of operations needed to transform the number n into 1.

Input
The input consists of a single integer n (1≤n≤10^18).

Output
Output a single integer representing the minimum number of operations required to make the number n equal to 1.

Examples

Input #1
3

Answer #1
1

Input #2
5

Answer #2
3

Input #5
70109

Answer #5
18

Note
In the first example, you can divide by 3 once to reach 1.

In the second example, you can decrease n by 1 twice, and then divide by 3.

Scoring
Solutions that correctly handle the constraints 1≤n≤10^5 will earn 40% of the total points.

"""

from functools import lru_cache

# https://oeis.org/A061295 (related)
@lru_cache(maxsize=None)
def f(n):
    if n < 2:
        return 0
    if n == 2:
        return 1
    if n%3 == 0:
        return f(n//3) + 1
    if (n-1)%3 == 0:
        return min(f(n-1) + 1, f(n+2) + 2)
    if (n+1)%3 == 0:
        return min(f(n+1) + 1, f(n-2) + 2)
    return 0

def solve(n):
    return f(n)

def main():
    assert(solve(3) == 1)
    assert(solve(5) == 3)
    assert(solve(70109) == 18)

main()

