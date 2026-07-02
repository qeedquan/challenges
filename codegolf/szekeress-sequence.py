#!/usr/bin/env python3

"""

Definition
a(1)=1
a(2)=2
a(n) is smallest number k>a(n−1) which avoids any 3-term arithmetic progression in a(1),a(2),...,a(n−1),k.
In other words, a(n) is the smallest number k>a(n−1) such that there does not exist x,y where 0<x<y<n and a(y)−a(x)=k−a(y).

Worked out example
For n=5:

We have a(1),a(2),a(3),a(4)=1,2,4,5

If a(5)=6, then 2,4,6 form an arithmetic progression.

If a(5)=7, then 1,4,7 form an arithmetic progression.

If a(5)=8, then 2,5,8 form an arithmetic progression.

If a(5)=9, then 1,5,9 form an arithmetic progression.

If a(5)=10, no arithmetic progression can be found.

Therefore a(5)=10.

Task
Given n, output a(n).

Specs
n will be a positive integer.
You can use 0-indexed instead of 1-indexed, in which case n can be 0. Please state it in your answer if you are using 0-indexed.
Scoring
Since we are trying to avoid 3-term arithmetic progression, and 3 is a small number, your code should be as small (i.e. short) as possible, in terms of byte-count.

Testcases
The testcases are 1-indexed. You can use 0-indexed, but please specify it in your answer if you do so.

1     1
2     2
3     4
4     5
5     10
6     11
7     13
8     14
9     28
10    29
11    31
12    32
13    37
14    38
15    40
16    41
17    82
18    83
19    85
20    86
10000 1679657

References

WolframMathWorld
OEIS A003278

"""

# https://oeis.org/A003278
def szekeres(n):
    return int(format(n-1, 'b'), 3) + 1

def main():
    tab = [[1, 1], [2, 2], [3, 4], [4, 5], [5, 10], [6, 11], [7, 13], [8, 14], [9, 28], [10, 29], [11, 31], [12, 32], [13, 37], [14, 38], [15, 40], [16, 41], [17, 82], [18, 83], [19, 85], [20, 86], [10000, 1679657]]
    for v in tab:
        assert(szekeres(v[0]) == v[1])

main()
