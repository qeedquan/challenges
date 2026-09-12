#!/usr/bin/env python3

"""

Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "0110", n = 3
Output: true

Example 2:

Input: s = "0110", n = 4
Output: false

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= n <= 10^9

Hint 1
We only need to check substrings of length at most 30, because 10^9 has 30 bits.

"""

def query(s, n):
    for i in reversed(range(n // 2, n + 1)):
        if not bin(i)[2:] in s:
            return False
    return True

def main():
    assert(query("0110", 3) == True)
    assert(query("0110", 4) == False)

main()
