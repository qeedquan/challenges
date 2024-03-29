/*

Your task: Print or return a conversion table with every byte from 00 to ff's value as an unsigned integer, to its value as a signed one (using two's complement).

For example:

0     0
1     1
2     2
3     3
4     4
5     5
6     6
7     7
8     8
9     9
10    10
11    11
12    12
13    13
14    14
15    15
16    16
17    17
18    18
19    19
20    20
21    21
22    22
23    23
24    24
25    25
26    26
27    27
28    28
29    29
30    30
31    31
32    32
33    33
34    34
35    35
36    36
37    37
38    38
39    39
40    40
41    41
42    42
43    43
44    44
45    45
46    46
47    47
48    48
49    49
50    50
51    51
52    52
53    53
54    54
55    55
56    56
57    57
58    58
59    59
60    60
61    61
62    62
63    63
64    64
65    65
66    66
67    67
68    68
69    69
70    70
71    71
72    72
73    73
74    74
75    75
76    76
77    77
78    78
79    79
80    80
81    81
82    82
83    83
84    84
85    85
86    86
87    87
88    88
89    89
90    90
91    91
92    92
93    93
94    94
95    95
96    96
97    97
98    98
99    99
100   100
101   101
102   102
103   103
104   104
105   105
106   106
107   107
108   108
109   109
110   110
111   111
112   112
113   113
114   114
115   115
116   116
117   117
118   118
119   119
120   120
121   121
122   122
123   123
124   124
125   125
126   126
127   127
128   -128
129   -127
130   -126
131   -125
132   -124
133   -123
134   -122
135   -121
136   -120
137   -119
138   -118
139   -117
140   -116
141   -115
142   -114
143   -113
144   -112
145   -111
146   -110
147   -109
148   -108
149   -107
150   -106
151   -105
152   -104
153   -103
154   -102
155   -101
156   -100
157   -99
158   -98
159   -97
160   -96
161   -95
162   -94
163   -93
164   -92
165   -91
166   -90
167   -89
168   -88
169   -87
170   -86
171   -85
172   -84
173   -83
174   -82
175   -81
176   -80
177   -79
178   -78
179   -77
180   -76
181   -75
182   -74
183   -73
184   -72
185   -71
186   -70
187   -69
188   -68
189   -67
190   -66
191   -65
192   -64
193   -63
194   -62
195   -61
196   -60
197   -59
198   -58
199   -57
200   -56
201   -55
202   -54
203   -53
204   -52
205   -51
206   -50
207   -49
208   -48
209   -47
210   -46
211   -45
212   -44
213   -43
214   -42
215   -41
216   -40
217   -39
218   -38
219   -37
220   -36
221   -35
222   -34
223   -33
224   -32
225   -31
226   -30
227   -29
228   -28
229   -27
230   -26
231   -25
232   -24
233   -23
234   -22
235   -21
236   -20
237   -19
238   -18
239   -17
240   -16
241   -15
242   -14
243   -13
244   -12
245   -11
246   -10
247   -9
248   -8
249   -7
250   -6
251   -5
252   -4
253   -3
254   -2
255   -1

Formatting:

    The output doesn't have to be padded to nicely line up like it does above (just a space in between would be fine)
    The separators can be any two strings which can't be confused for the data or each other
    Any base can be used (but if using binary, -1 would be -00000001, not 11111111)
    Trailing (and/or leading) whitespace and separators are allowed
    The output must be in the correct order
    The output must be textual; returning arrays/lists/dictionaries is not allowed

Valid outputs:

(using ... to skip over some repetitive chunks)

Zero-padded hexadecimal:

00 00
01 01
...
7f 7f
80 -80
81 -7f
...
fe -02
ff -01

Binary with , and ; for separators:

0,0;1,1;10,10;11,11;...;01111111,01111111;10000000,-10000000;10000001,-01111111;...;11111110,-00000010,11111111,00000001

Negadecimal with custom separators:

0 The HORSE is a noble animal. 0

1 The HORSE is a noble animal. 1

...

287 The HORSE is a noble animal. 287

288 The HORSE is a noble animal. 1932

289 The HORSE is a noble animal. 1933

...

354 The HORSE is a noble animal. 18

355 The HORSE is a noble animal. 19

Good luck!

*/

#include <stdio.h>

void
table(void)
{
	int i;

	for (i = 0; i < 256; i++)
		printf("%-3d %-3d\n", i, i - ((i & 0x80) << 1));
}

int
main(void)
{
	table();
	return 0;
}
