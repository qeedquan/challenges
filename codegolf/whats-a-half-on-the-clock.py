#!/usr/bin/env python3

"""

In my room, I have this geeky clock (click for full size):

https://i.stack.imgur.com/lx2F2.jpg

Most of these are not difficult to figure out, but the one for 4-o-clock is particularly tricky:

2^-1 (mod 7)

Normally, a fraction like 1/2 doesn't make sense in modular arithmetic since only integers are involved. The correct way, then, is to see this as the inverse of 2, or to put it another way, two to the power of negative one is that number x where two times x equals one. Put this way, a moment's thought will reveal that x equals four because two x equals two times four equals eight which is equivalent to one modulo seven.

However, simply finding the multiplicative inverse would be far too easy as a challenge. So let's bump up the difficulty to exponentiation, or in other words, finding the modular logarithm or discrete logarithm of 2. In this case, 3 is the modular logarithm of 2 with respect to 7. For those of you with number theory/abstract algebra background, this means calculating the multiplicative order of 2 modulo n.

The Challenge
Given a positive odd integer n greater than 1, output the smallest positive integer x where enter image description here.

Examples
n x
3 2
5 4
7 3
9 6
11 10
13 12
15 4
17 8
19 18
21 6
23 11
25 20
27 18
29 28
31 5
33 10
35 12
37 36
39 12
41 20
43 14
45 12
47 23
49 21
51 8
53 52
55 20
57 18
59 58
61 60
63 6
65 12
67 66
69 22
71 35
73 9
75 20
77 30
79 39
81 54
83 82
85 8
87 28
89 11
91 12
93 10
95 36
97 48
99 30
101 100
103 51
105 12
107 106
109 36
111 36
113 28
115 44
117 12
119 24
121 110
123 20
125 100
127 7
129 14
131 130
133 18
135 36
137 68
139 138
141 46
143 60
145 28
147 42
149 148
151 15
153 24
155 20
157 52
159 52
161 33
163 162
165 20
167 83
169 156
171 18
173 172
175 60
177 58
179 178
181 180
183 60
185 36
187 40
189 18
191 95
193 96
195 12
197 196
199 99
201 66

"""

def multiplicative_order(n):
    for i in range(1, n + 1):
        if (2**i)%n == 1:
            return i
    return 0

def main():
    tab = [[3, 2],
           [5, 4],
           [7, 3],
           [9, 6],
           [11, 10],
           [13, 12],
           [15, 4],
           [17, 8],
           [19, 18],
           [21, 6],
           [23, 11],
           [25, 20],
           [27, 18],
           [29, 28],
           [31, 5],
           [33, 10],
           [35, 12],
           [37, 36],
           [39, 12],
           [41, 20],
           [43, 14],
           [45, 12],
           [47, 23],
           [49, 21],
           [51, 8],
           [53, 52],
           [55, 20],
           [57, 18],
           [59, 58],
           [61, 60],
           [63, 6],
           [65, 12],
           [67, 66],
           [69, 22],
           [71, 35],
           [73, 9],
           [75, 20],
           [77, 30],
           [79, 39],
           [81, 54],
           [83, 82],
           [85, 8],
           [87, 28],
           [89, 11],
           [91, 12],
           [93, 10],
           [95, 36],
           [97, 48],
           [99, 30],
           [101, 100],
           [103, 51],
           [105, 12],
           [107, 106],
           [109, 36],
           [111, 36],
           [113, 28],
           [115, 44],
           [117, 12],
           [119, 24],
           [121, 110],
           [123, 20],
           [125, 100],
           [127, 7],
           [129, 14],
           [131, 130],
           [133, 18],
           [135, 36],
           [137, 68],
           [139, 138],
           [141, 46],
           [143, 60],
           [145, 28],
           [147, 42],
           [149, 148],
           [151, 15],
           [153, 24],
           [155, 20],
           [157, 52],
           [159, 52],
           [161, 33],
           [163, 162],
           [165, 20],
           [167, 83],
           [169, 156],
           [171, 18],
           [173, 172],
           [175, 60],
           [177, 58],
           [179, 178],
           [181, 180],
           [183, 60],
           [185, 36],
           [187, 40],
           [189, 18],
           [191, 95],
           [193, 96],
           [195, 12]]

    for v in tab:
        assert(multiplicative_order(v[0]) == v[1])

main()
