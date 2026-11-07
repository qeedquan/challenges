#!/usr/bin/env python3

"""

Given an array a1,a2,...,an of n integers. Sort it in ascending order.

Then answer q queries: for each input value k print ak.

Input
The first line contains the size n (n≤10^6) of array and the number of queries q (q≤10^5).

The second line contains the array elements a1,a2,...,an.

Each of the following q lines contains a query: one integer k (1≤k≤n).

Output
For each query print ak on a separate line: the k-th number in the sorted array.

Examples
Sort the numbers in the given sample:


The answers to the queries are: a4=5,a5=6,a1=1,a7=7,a2=1.

Input #1
10 5
10 1 7 5 9 6 8 2 1 6
4
5
1
7
2
Answer #1
5
6
1
7
1

"""

def solve(a, q):
    a.sort()
    for i in q:
        print(a[i - 1])

def main():
    solve([10, 1, 7, 5, 9, 6, 8, 2, 1, 6], [4, 5, 1, 7, 2])

main()
