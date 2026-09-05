#!/usr/bin/env python3

"""

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.


Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false


Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.

"""

def rotatable(a, b):
    return len(a) == len(b) and b in (a+a)

def main():
    assert(rotatable("abcde", "cdeab") == True)
    assert(rotatable("abcde", "abced") == False)
    assert(rotatable("lock", "cklo") == True)
    assert(rotatable("lock", "ckol") == False)

main()
