#!/usr/bin/env python3

"""

Alice has quarreled with Berta recently. Now she doesn't want to have anything in common with her!

Recently, they've received two collections of positive integers. The Alice's integers were A1, A2, ..., AN, while Berta's were B1, B2, ..., BM.

Now Alice wants to throw away the minimal amount of number from her collection so that their collections would have no common numbers, i.e. there won't be any number which is present in both collections.
Please help Alice to find the minimal amount of numbers she would need to throw away.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space-separated integer numbers N and M denoting the amount of numbers in Alice's and Berta's collections respectively.

The second line contains N space-separated integers A1, A2, ..., AN denoting the numbers of Alice.

The third line contains M space-separated integers B1, B2, ..., BM denoting the numbers of Berta.

Output

For each test case, output a single line containing the minimal amount of numbers Alice needs to throw away from her collection so that she wouldn't have any numbers in common with Berta.

Constraints
1 ≤ Ai, Bi ≤ 10^6
All numbers are distinct within a single girl's collection.

"""

def common(a, b):
    m = {}
    for v in b:
        m[v] = 1

    c = 0
    for v in a:
        try:
            c += m[v]
        except:
            pass

    return c

def main():
    assert(common([1, 2, 3], [3, 4, 5, 6]) == 1)
    assert(common([1, 2, 3], [4, 5, 6]) == 0)

main()
