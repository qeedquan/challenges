#!/usr/bin/env python3

"""

By definition a string is said to be a palindrome if it does not change when get reversed. madam is a nice example of a palindrome.

Given a string S, you are allowed to insert any characters at any position of the string, find the minimum number of characters required to make the string a palindrome.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case contains a string of lowercase letters denoting the string for which we want to generate a palindrome. You may safely assume that the length of the string will be positive and no more than 100.

Output
For each case, print the case number and the minimum number of characters required to make string to a palindrome.

Sample
Input	Output
6
abcd
aaaa
abc
aab
abababaabababa
pqrsabcdpqrs

Case 1: 3
Case 2: 0
Case 3: 2
Case 4: 1
Case 5: 0
Case 6: 9

Notes
You can easily verify that for a string of length n, no more than (n - 1) characters are required to make it a palindrome. For example, abcd and its palindrome abcdcba.

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def find(s, i, j):
    if i >= j:
        return 0
    if s[i] == s[j]:
        return find(s, i + 1, j - 1)
    return 1 + min(find(s, i + 1, j), find(s, i, j - 1))

def solve(s):
    return find(s, 0, len(s) - 1)

def main():
    assert(solve("abcd") == 3)
    assert(solve("aaaa") == 0)
    assert(solve("abc") == 2)
    assert(solve("aab") == 1)
    assert(solve("abababaabababa") == 0)
    assert(solve("pqrsabcdpqrs") == 9)

main()
