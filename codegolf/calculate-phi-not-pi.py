#!/usr/bin/env python3

"""

No, I don't mean ϕ=1.618... and π=3.14159.... I mean the functions.

ϕ(x) is the number of integers less than or equal to x that are relatively prime to x.
π(x) is the number of primes less than or equal to x.
Let's say that "not pi" is then π¯(x) and define it to be the number of composites less than or equal to x.

Task
Given a strictly positive integer x, calculate ϕ(π¯(x)). Scoring is in bytes.

Examples
Each line consists of the input (from 1 to 100, inclusive) and the corresponding output separated by a space.

1 0
2 0
3 0
4 1
5 1
6 1
7 1
8 2
9 2
10 4
11 4
12 2
13 2
14 6
15 4
16 6
17 6
18 4
19 4
20 10
21 4
22 12
23 12
24 6
25 8
26 8
27 16
28 6
29 6
30 18
31 18
32 8
33 12
34 10
35 22
36 8
37 8
38 20
39 12
40 18
41 18
42 12
43 12
44 28
45 8
46 30
47 30
48 16
49 20
50 16
51 24
52 12
53 12
54 36
55 18
56 24
57 16
58 40
59 40
60 12
61 12
62 42
63 20
64 24
65 22
66 46
67 46
68 16
69 42
70 20
71 20
72 32
73 32
74 24
75 52
76 18
77 40
78 24
79 24
80 36
81 28
82 58
83 58
84 16
85 60
86 30
87 36
88 32
89 32
90 48
91 20
92 66
93 32
94 44
95 24
96 70
97 70
98 24
99 72
100 36
Use this link to calculate the expected output for any input. Also, a list of inputs and outputs for x≤1000 is provided here on pastebin. (Generated with this Minkolang program.)

"""

from sympy import *

def phinotpi(n):
    if n < 4:
        return 0
    return totient(n - 1 - primepi(n))

def main():
    tab = [0, 0, 0, 1, 1, 1, 1, 2, 2, 4, 4, 2, 2, 6, 4, 6, 6, 4, 4, 10, 4, 12, 12, 6, 8, 8, 16, 6, 6, 18, 18, 8, 12, 10, 22, 8, 8, 20, 12, 18, 18, 12, 12, 28, 8, 30, 30, 16, 20, 16, 24, 12, 12, 36, 18, 24, 16, 40, 40, 12, 12, 42, 20, 24, 22, 46, 46, 16, 42, 20, 20, 32, 32, 24, 52, 18, 40, 24, 24, 36, 28, 58, 58, 16, 60, 30, 36, 32, 32, 48, 20, 66, 32, 44, 24, 70, 70, 24, 72, 36]

    for i in range(len(tab)):
        assert(phinotpi(i + 1) == tab[i])

main()
