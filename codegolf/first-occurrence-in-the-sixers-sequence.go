/*

The Sixers sequence is a name that can be given to sequence A087409. I learned about this sequence in a Numberphile video, and it can be constructed as follows:

First, take the multiples of 6, written in base 10:

6, 12, 18, 24, 30, 36, ...

Next, concatenate the numbers into a stream of digits:

61218243036...

Finally, regroup the stream into pairs and interpret each as an integer:

61, 21, 82, 43, 3, ...

As we're grouping the numbers into pairs, the maximum number in the sequence will be 99, and it turns out that all non-negative integers less than 100 are represented in the sequence. This challenge is to find the index of the first instance of a number in the Sixers sequence.

Input
An integer in the range [0-99]. You do not need to account for numbers outside this range, and your solution can have any behaviour if such an input is given.

Output
The index of the first occurrence of the input number in the Sixers sequence. This may be 0- or 1-indexed; please say which you are using in your answer.

Rules
The procedure to generate the sequence noted in the introduction is for illustrative purposes only, you can use any method you like as long as the results are the same.
You can submit full programs or functions.
Any sensible methods of input and output are allowed.
Standard loopholes are disallowed.
Links to test your code online are recommended!
This is code-golf, so shortest answer in each language wins!
Test cases
Here is a list of all input and outputs, in the format input, 0-indexed output, 1-indexed output.

0   241 242
1   21  22
2   16  17
3   4   5
4   96  97
5   126 127
6   9   10
7   171 172
8   201 202
9   14  15
10  17  18
11  277 278
12  20  21
13  23  24
14  19  20
15  29  30
16  32  33
17  297 298
18  35  36
19  38  39
20  41  42
21  1   2
22  46  47
23  69  70
24  6   7
25  53  54
26  22  23
27  11  12
28  62  63
29  219 220
30  65  66
31  68  69
32  71  72
33  74  75
34  49  50
35  357 358
36  80  81
37  83  84
38  25  26
39  89  90
40  92  93
41  27  28
42  42  43
43  3   4
44  101 102
45  104 105
46  8   9
47  177 178
48  110 111
49  13  14
50  28  29
51  119 120
52  122 123
53  417 418
54  79  80
55  128 129
56  131 132
57  134 135
58  55  56
59  437 438
60  140 141
61  0   1
62  31  32
63  75  76
64  5   6
65  120 121
66  82  83
67  10  11
68  161 162
69  164 165
70  58  59
71  477 478
72  170 171
73  173 174
74  34  35
75  179 180
76  182 183
77  497 498
78  85  86
79  188 189
80  191 192
81  18  19
82  2   3
83  78  79
84  93  94
85  7   8
86  37  38
87  168 169
88  12  13
89  228 229
90  88  89
91  218 219
92  221 222
93  224 225
94  64  65
95  557 558
96  230 231
97  233 234
98  40  41
99  239 240

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	tab := []int{
		241, 21, 16, 4, 96, 126, 9, 171, 201, 14, 17, 277, 20, 23, 19, 29, 32,
		297, 35, 38, 41, 1, 46, 69, 6, 53, 22, 11, 62, 219, 65, 68, 71, 74, 49,
		357, 80, 83, 25, 89, 92, 27, 42, 3, 101, 104, 8, 177, 110, 13, 28, 119,
		122, 417, 79, 128, 131, 134, 55, 437, 140, 0, 31, 75, 5, 120, 82, 10,
		161, 164, 58, 477, 170, 173, 34, 179, 182, 497, 85, 188, 191, 18, 2,
		78, 93, 7, 37, 168, 12, 228, 88, 218, 221, 224, 64, 557, 230, 233, 40, 239,
	}

	for i := range tab {
		assert(sixer(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Arnauld

How?
Using a recursive function, we either 'consume' the first 2 characters of the string of concatenated multiples of 6,
or append new characters if we have less than 2 of them.

Example for  n=3:

 string | operation                          | result
--------+------------------------------------+--------
 ''     | not enough characters: append '6'  |   0
 '6'    | not enough characters: append '12' |   0
 '612'  | consume '61', increment the result |   1
 '2'    | not enough characters: append '18' |   1
 '218'  | consume '21', increment the result |   2
 '8'    | not enough characters: append '24' |   2
 '824'  | consume '82', increment the result |   3
 '4'    | not enough characters: append '30' |   3
 '430'  | consume '43', increment the result |   4
 '0'    | not enough characters: append '36' |   4
 '036'  | consume '03': success              |   4

*/

func sixer(n int) int {
	if n < 0 || n > 99 {
		return -1
	}

	s := ""
	c := 0
	i := 0
	for {
		if len(s) < 2 {
			i += 6
			s += fmt.Sprint(i)
		} else {
			v, _ := strconv.Atoi(s[:2])
			if v == n {
				break
			}
			s = s[2:]
			c += 1
		}
	}
	return c
}
