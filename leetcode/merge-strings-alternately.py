#!/usr/bin/env python3

"""

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.


Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d


Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

"""

def altmerge(a, b):
    s = ""
    f = 0
    i = 0
    j = 0
    while i < len(a) or j < len(b):
        if i >= len(a) or (f == 1 and j < len(b)):
            s += b[j]
            j += 1
        elif j >= len(b) or (f == 0 and i < len(a)):
            s += a[i]
            i += 1
        f = 1 - f
    return s

def main():
    assert(altmerge("abc", "pqr") == "apbqcr")
    assert(altmerge("ab", "pqrs") == "apbqrs")
    assert(altmerge("abcd", "pq") == "apbqcd")

main()
