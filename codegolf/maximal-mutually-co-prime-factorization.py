#!/usr/bin/env python3

"""

Definitions
Two numbers are co-prime if their only positive common divisor is 1.
A list of numbers is mutually co-prime if every pair of numbers within that list are co-prime with each other.
A factorization of number n is a list of numbers whose product is n.

Task
Given a positive number n, output the mutually co-prime factorization of n with the maximum length that does not include 1.

Example
For n=60, the answer is [3,4,5], because 3*4*5=60 and no other mutually co-prime factorization without
1 has length greater than or equal to 3, the length of the factorization.

Rules and freedoms
You can use any reasonable input/output format.
The entries in the output list do not need to be sorted.
Testcases
n   output
1   []
2   [2]
3   [3]
4   [4]
5   [5]
6   [2, 3]
7   [7]
8   [8]
9   [9]
10  [2, 5]
11  [11]
12  [3, 4]
13  [13]
14  [2, 7]
15  [3, 5]
16  [16]
17  [17]
18  [2, 9]
19  [19]
20  [4, 5]
21  [3, 7]
22  [2, 11]
23  [23]
24  [3, 8]
25  [25]
26  [2, 13]
27  [27]
28  [4, 7]
29  [29]
30  [2, 3, 5]
31  [31]
32  [32]
33  [3, 11]
34  [2, 17]
35  [5, 7]
36  [4, 9]
37  [37]
38  [2, 19]
39  [3, 13]
40  [5, 8]
41  [41]
42  [2, 3, 7]
43  [43]
44  [4, 11]
45  [5, 9]
46  [2, 23]
47  [47]
48  [3, 16]
49  [49]
50  [2, 25]
51  [3, 17]
52  [4, 13]
53  [53]
54  [2, 27]
55  [5, 11]
56  [7, 8]
57  [3, 19]
58  [2, 29]
59  [59]
60  [3, 4, 5]
61  [61]
62  [2, 31]
63  [7, 9]
64  [64]
65  [5, 13]
66  [2, 3, 11]
67  [67]
68  [4, 17]
69  [3, 23]
70  [2, 5, 7]
71  [71]
72  [8, 9]
73  [73]
74  [2, 37]
75  [3, 25]
76  [4, 19]
77  [7, 11]
78  [2, 3, 13]
79  [79]
80  [5, 16]
81  [81]
82  [2, 41]
83  [83]
84  [3, 4, 7]
85  [5, 17]
86  [2, 43]
87  [3, 29]
88  [8, 11]
89  [89]
90  [2, 5, 9]
91  [7, 13]
92  [4, 23]
93  [3, 31]
94  [2, 47]
95  [5, 19]
96  [3, 32]
97  [97]
98  [2, 49]
99  [9, 11]

Scoring
This is code-golf. Shortest answer in bytes wins.

"""

from sympy import factorint

def solve(n):
    r = []
    f = factorint(n)
    for p in f:
        r.append(p**f[p])
    return sorted(r)

def main():
    for i in range(1, 100):
        print(i, solve(i))

main()
