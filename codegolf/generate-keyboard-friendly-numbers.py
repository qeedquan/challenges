#!/usr/bin/env python3

"""

Most common computer keyboard layouts have the decimal digit keys

1234567890

running along at their top, above the keys for letters.

Let a decimal digit's neighborhood be the set of digits from its own digit key and from the digit keys immediately to the left and right, if they exist.

For example, the neighborhood of 0 is {0, 9}, and the neighborhood of 5 is {4, 5, 6}.

Now, define a keyboard friendly number as a positive integer (in decimal form with no leading zeros) that can be typed on the layout above such that every consecutive digit in the number after the first digit is in the neighborhood of the preceding digit.

All single digit numbers (1-9) are trivially keyboard friendly.

A number such as 22321 is keyboard friendly because every digit (not counting the first) is in the neighborhood of the digit just before.

A number such as 1245 is not keyboard friendly because 4 is not in the neighborhood of 2 (nor vice versa).

A number such as 109 is not keyboard friendly because 0 is not in the neighborhood of 1. The ends do not loop around.

By putting the keyboard friendly numbers in order from smallest to largest, we can create an integer sequence.

Here are the first 200 terms of the keyboard friendly numbers sequence:

N KFN(N)
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 11
11 12
12 21
13 22
14 23
15 32
16 33
17 34
18 43
19 44
20 45
21 54
22 55
23 56
24 65
25 66
26 67
27 76
28 77
29 78
30 87
31 88
32 89
33 90
34 98
35 99
36 111
37 112
38 121
39 122
40 123
41 211
42 212
43 221
44 222
45 223
46 232
47 233
48 234
49 321
50 322
51 323
52 332
53 333
54 334
55 343
56 344
57 345
58 432
59 433
60 434
61 443
62 444
63 445
64 454
65 455
66 456
67 543
68 544
69 545
70 554
71 555
72 556
73 565
74 566
75 567
76 654
77 655
78 656
79 665
80 666
81 667
82 676
83 677
84 678
85 765
86 766
87 767
88 776
89 777
90 778
91 787
92 788
93 789
94 876
95 877
96 878
97 887
98 888
99 889
100 890
101 898
102 899
103 900
104 909
105 987
106 988
107 989
108 990
109 998
110 999
111 1111
112 1112
113 1121
114 1122
115 1123
116 1211
117 1212
118 1221
119 1222
120 1223
121 1232
122 1233
123 1234
124 2111
125 2112
126 2121
127 2122
128 2123
129 2211
130 2212
131 2221
132 2222
133 2223
134 2232
135 2233
136 2234
137 2321
138 2322
139 2323
140 2332
141 2333
142 2334
143 2343
144 2344
145 2345
146 3211
147 3212
148 3221
149 3222
150 3223
151 3232
152 3233
153 3234
154 3321
155 3322
156 3323
157 3332
158 3333
159 3334
160 3343
161 3344
162 3345
163 3432
164 3433
165 3434
166 3443
167 3444
168 3445
169 3454
170 3455
171 3456
172 4321
173 4322
174 4323
175 4332
176 4333
177 4334
178 4343
179 4344
180 4345
181 4432
182 4433
183 4434
184 4443
185 4444
186 4445
187 4454
188 4455
189 4456
190 4543
191 4544
192 4545
193 4554
194 4555
195 4556
196 4565
197 4566
198 4567
199 5432
200 5433

Challenge
Write a program or function that takes a positive integer N (via stdin/command line/function arg) and prints (to stdout) or returns the Nth term in the keyboard friendly numbers sequence.

For example, if the input is 191, the output should be 4544.

The output may optionally have a single trailing newline.

The shortest submission in bytes wins.

"""

# Ported from @Οurous solution
def kbf(n):
    i = 0
    while n != 0:
        i += 1
        s = str(i)
        for x in range(len(s) - 1):
            k = (int(s[x]) + 9) % 10
            if s[x + 1] not in ' 1234567890'[k : k + 3]:
                break
        else:
            n -= 1
    return i

def main():
    tab = [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 21, 22, 23, 32, 33, 34, 43, 44, 45, 54, 55, 56, 65, 66, 67, 76, 77, 78, 87, 88, 89, 90, 98, 99, 111, 112, 121, 122, 123, 211, 212, 221, 222, 223, 232, 233, 234, 321, 322, 323, 332, 333, 334, 343, 344, 345, 432, 433, 434, 443, 444, 445, 454, 455, 456, 543, 544, 545, 554, 555, 556, 565, 566, 567, 654, 655, 656, 665, 666, 667, 676, 677, 678, 765, 766, 767, 776, 777, 778, 787, 788, 789, 876, 877, 878, 887, 888, 889, 890, 898, 899, 900, 909, 987, 988, 989, 990, 998, 999, 1111, 1112, 1121, 1122, 1123, 1211, 1212, 1221, 1222, 1223, 1232, 1233, 1234, 2111, 2112, 2121, 2122, 2123, 2211, 2212, 2221, 2222, 2223, 2232, 2233, 2234, 2321, 2322, 2323, 2332, 2333, 2334, 2343, 2344, 2345, 3211, 3212, 3221, 3222, 3223, 3232, 3233, 3234, 3321, 3322, 3323, 3332, 3333, 3334, 3343, 3344, 3345, 3432, 3433, 3434, 3443, 3444, 3445, 3454, 3455, 3456, 4321, 4322, 4323, 4332, 4333, 4334, 4343, 4344, 4345, 4432, 4433, 4434, 4443, 4444, 4445, 4454, 4455, 4456, 4543, 4544, 4545, 4554, 4555, 4556, 4565, 4566, 4567, 5432, 5433]

    for i in range(len(tab)):
        assert(kbf(i + 1) == tab[i])

main()
