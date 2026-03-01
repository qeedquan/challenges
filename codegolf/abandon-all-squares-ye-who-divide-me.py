#!/usr/bin/env python3

"""

Definitions
A perfect square is an integer which can be expressed as the square of another integer. For example, 36 is a perfect square because 6^2 = 36.
A squarefree number is an integer which is not divisible by any perfect square, except by 1. For example, 10 is a squarefree number. However, 12 is not a squarefree number, because 12 is divisible by 4 and 4 is a perfect square.
Task
Given a positive integer n, output the largest squarefree number which divides n.

Testcases
n   output
1   1
2   2
3   3
4   2
5   5
6   6
7   7
8   2
9   3
10  10
11  11
12  6
13  13
14  14
15  15
16  2
17  17
18  6
19  19
20  10
21  21
22  22
23  23
24  6
25  5
26  26
27  3
28  14
29  29
30  30
31  31
32  2
33  33
34  34
35  35
36  6
37  37
38  38
39  39
40  10
41  41
42  42
43  43
44  22
45  15
46  46
47  47
48  6
49  7
50  10
Scoring
This is code-golf. Shortest answer in bytes wins.

Standard loopholes apply.

Reference
OEIS A007947

"""

# https://oeis.org/A007947
def radical(n):
    r = 0
    for k in range(1, n + 1):
        r += k**n//n - ((k**n - 1)//n)
    
    if r == 0:
        return 0
    return n//r

def main():
    tab = [1, 2, 3, 2, 5, 6, 7, 2, 3, 10, 11, 6, 13, 14, 15, 2, 17, 6, 19, 10, 21, 22, 23, 6, 5, 26, 3, 14, 29, 30, 31, 2, 33, 34, 35, 6, 37, 38, 39, 10, 41, 42, 43, 22, 15, 46, 47, 6, 7, 10, 51, 26, 53, 6, 55, 14, 57, 58, 59, 30, 61, 62, 21, 2, 65, 66, 67, 34, 69, 70, 71, 6, 73, 74, 15, 38, 77, 78]
    
    for i in range(len(tab)):
        assert(radical(i + 1) == tab[i])

main()
