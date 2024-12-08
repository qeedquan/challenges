#!/usr/bin/env python3

"""

You are given two sets, A and B.
Your job is to find whether set A is a subset of set B.

If set A is subset of set B, print True.
If set A is not a subset of set B, print False.

Input Format

The first line will contain the number of test cases, T.
The first line of each test case contains the number of elements in set A.
The second line of each test case contains the space separated elements of set A.
The third line of each test case contains the number of elements in set B.
The fourth line of each test case contains the space separated elements of set B.

Constraints
0 < T < 21
0 < Number of elements in each set < 1001

Output Format
Output True or False for each test case on separate lines.

Sample Input
3
5
1 2 3 5 6
9
9 8 5 6 3 2 1 4 7
1
2
5
3 6 5 4 1
7
1 2 3 5 6 8 9
3
9 8 2

Sample Output
True
False
False

"""

def subset(a, b):
    return a&b == a

def main():
    assert(subset({1, 2, 3, 4, 5, 6}, {9, 8, 5, 6, 3, 2, 1, 4, 7}) == True)
    assert(subset({2}, {3, 6, 5, 4, 1}) == False)
    assert(subset({1, 2, 3, 5, 6, 8, 9}, {9, 8, 2}) == False)

main()
