#!/usr/bin/env python3

"""

Feuzem is an unemployed computer scientist who spends his days working at odd-jobs. While on the job he always manages to find algorithmic problems within mundane aspects of everyday life.

Today, while writing down the specials menu at the restaurant he's working at, he felt irritated by the lack of palindromes (strings which stay the same when reversed) on the menu. Feuzem is a big fan of palindromic problems, and started thinking about the number of ways he could remove letters from a particular word so that it would become a palindrome.

Two ways that differ due to order of removing letters are considered the same. And it can also be the case that no letters have to be removed to form a palindrome.

Input
nput starts with an integer T (≤ 200), denoting the number of test cases.

Each case contains a single word W (1 ≤ length(W) ≤ 60).

Output
For each case, print the case number and the total number of ways to remove letters from W such that it becomes a palindrome.

Sample
Input	Output
3
SALADS
PASTA
YUMMY

Case 1: 15
Case 2: 8
Case 3: 11

Notes
For the case PASTA, there are 8 ways -
#	Removed Characters	Remaining Palindrome
1	PAST_	A
2	PAS_A	T
3	PA_TA	S
4	P_STA	A
5	_ASTA	P
6	P_ST_	AA
7	P__T_	ASA
8	P_S__	ATA

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def calc(s, i, j):
    if i > j:
        return 0
    if i == j:
        return 1
    if s[i] == s[j]:
        return 1 + calc(s, i + 1, j) + calc(s, i, j - 1)
    return calc(s, i + 1, j) + calc(s, i, j - 1) - calc(s, i + 1, j - 1)

def solve(s):
    return calc(s, 0, len(s) - 1)

def main():
    assert(solve("SALADS") == 15)
    assert(solve("PASTA") == 8)
    assert(solve("YUMMY") == 11)

main()
