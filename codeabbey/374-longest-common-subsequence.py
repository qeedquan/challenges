#!/usr/bin/env python3

"""

It is a classic exercise - no idea why we were lacking it until now!

Common subsequence is like common substring, but letters don't need to be adjacent, though order should be kept. For example words banana and atanek have common substring an but common subsequence is aan.

Input data provides a T - number of testcases in the first line.
Then T lines follow, each containing some string of small latin letters.

Answer should for every test string give the length of the longest common subsequence between this string and its reverse.

Example

input data:
5
afzqo
wmfafmhu
bnkdqkdefjp
doambxhttgbofe
uqoydupcewmprbjw

answer:
1 5 3 6 3

"""

def lcs(s, t):
    m = len(s)
    n = len(t)
    L = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif s[i-1] == t[j-1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])

    r, i, j = "", m, n
    while i > 0 and j > 0:
        if s[i-1] == t[j-1]:
            r += s[i-1]
            i -= 1
            j -= 1
        elif L[i-1][j] > L[i][j-1]:
            i -= 1
        else:
            j -= 1
    return r[::-1]

def solve(s):
    return len(lcs(s, s[::-1]))

def main():
    assert(solve("afzqo") == 1)
    assert(solve("wmfafmhu") == 5)
    assert(solve("bnkdqkdefjp") == 3)
    assert(solve("doambxhttgbofe") == 6)
    assert(solve("uqoydupcewmprbjw") == 3)

main()

