#!/usr/bin/env python3

"""

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime.
However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303

Constraints:

1 <= n <= 10^15

Hint 1
Is there a formula we can use to find the count of all the good numbers?

Hint 2
Exponentiation can be done very fast if we looked at the binary bits of n.

"""

"""

https://algo.monster/liteproblems/1922

When we look at this problem, we need to count valid combinations, not generate them. This is a classic combinatorics problem.

Let's think about building a good string position by position. For each position, we have independent choices that don't affect other positions:

At position 0 (even index): We can choose from 5 even digits (0, 2, 4, 6, 8)
At position 1 (odd index): We can choose from 4 prime digits (2, 3, 5, 7)
At position 2 (even index): Again 5 choices
At position 3 (odd index): Again 4 choices
And so on...
Since each position's choice is independent, we can use the multiplication principle. If we have a string of length 4, the total number of good strings would be 5 × 4 × 5 × 4.

We can see a pattern emerging:

For length 1: 5 (only one even-indexed position)
For length 2: 5 × 4
For length 3: 5 × 4 × 5 = 5² × 4
For length 4: 5 × 4 × 5 × 4 = 5² × 4²
For length 5: 5 × 4 × 5 × 4 × 5 = 5³ × 4²
The pattern shows that for a string of length n:

Number of even-indexed positions = ⌈n/2⌉ (ceiling of n/2)
Number of odd-indexed positions = ⌊n/2⌋ (floor of n/2)
Therefore, the total count becomes 5^(number of even positions) × 4^(number of odd positions).

"""

def count(n):
    mod = 1_000_000_007
    return pow(5, (n + 1)//2, mod) * pow(4, n//2, mod) % mod

def main():
    assert(count(1) == 5)
    assert(count(4) == 400)
    assert(count(50) == 564908303)

main()

