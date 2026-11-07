/*

Question
Given the atomic number of an element in the range [1-118] output the group and period, of that element as given by the following Periodic Table Of Elements.

For elements in the Lanthanide and Actinide series, (ranges [57-71] and [89-103]), you should instead return L for the Lanthanides and A for the Actinides

You may write a program or a function and use any of the our standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

https://i.stack.imgur.com/nJm2q.png

Since there are only 118 possible inputs, a full list of the expected inputs and outputs is given below.

Created by hand, let me know if there's a mistake!

1,1,1
2,18,1
3,1,2
4,2,2
5,13,2
6,14,2
7,15,2
8,16,2
9,17,2
10,18,2
11,1,3
12,2,3
13,13,3
14,14,3
15,15,3
16,16,3
17,17,3
18,18,3
19,1,4
20,2,4
21,3,4
22,4,4
23,5,4
24,6,4
25,7,4
26,8,4
27,9,4
28,10,4
29,11,4
30,12,4
31,13,4
32,14,4
33,15,4
34,16,4
35,17,4
36,18,4
37,1,5
38,2,5
39,3,5
40,4,5
41,5,5
42,6,5
43,7,5
44,8,5
45,9,5
46,10,5
47,11,5
48,12,5
49,13,5
50,14,5
51,15,5
52,16,5
53,17,5
54,18,5
55,1,6
56,2,6
57,L,
58,L,
59,L,
60,L,
61,L,
62,L,
63,L,
64,L,
65,L,
66,L,
67,L,
68,L,
69,L,
70,L,
71,L,
72,4,6
73,5,6
74,6,6
75,7,6
76,8,6
77,9,6
78,10,6
79,11,6
80,12,6
81,13,6
82,14,6
83,15,6
84,16,6
85,17,6
86,18,6
87,1,7
88,2,7
89,A,
90,A,
91,A,
92,A,
93,A,
94,A,
95,A,
96,A,
97,A,
98,A,
99,A,
100,A,
101,A,
102,A,
103,A,
104,4,7
105,5,7
106,6,7
107,7,7
108,8,7
109,9,7
110,10,7
111,11,7
112,12,7
113,13,7
114,14,7
115,15,7
116,16,7
117,17,7
118,18,7

Scoring
Simple code-golf. Shortest number of bytes wins

*/

package main

import "fmt"

func main() {
	fmt.Println(lookup(118))
}

func lookup(atomic int) (group, period int) {
	lut := [][2]int{
		1:   [2]int{1, 1},
		2:   [2]int{18, 1},
		3:   [2]int{1, 2},
		4:   [2]int{2, 2},
		5:   [2]int{13, 2},
		6:   [2]int{14, 2},
		7:   [2]int{15, 2},
		8:   [2]int{16, 2},
		9:   [2]int{17, 2},
		10:  [2]int{18, 2},
		11:  [2]int{1, 3},
		12:  [2]int{2, 3},
		13:  [2]int{13, 3},
		14:  [2]int{14, 3},
		15:  [2]int{15, 3},
		16:  [2]int{16, 3},
		17:  [2]int{17, 3},
		18:  [2]int{18, 3},
		19:  [2]int{1, 4},
		20:  [2]int{2, 4},
		21:  [2]int{3, 4},
		22:  [2]int{4, 4},
		23:  [2]int{5, 4},
		24:  [2]int{6, 4},
		25:  [2]int{7, 4},
		26:  [2]int{8, 4},
		27:  [2]int{9, 4},
		28:  [2]int{10, 4},
		29:  [2]int{11, 4},
		30:  [2]int{12, 4},
		31:  [2]int{13, 4},
		32:  [2]int{14, 4},
		33:  [2]int{15, 4},
		34:  [2]int{16, 4},
		35:  [2]int{17, 4},
		36:  [2]int{18, 4},
		37:  [2]int{1, 5},
		38:  [2]int{2, 5},
		39:  [2]int{3, 5},
		40:  [2]int{4, 5},
		41:  [2]int{5, 5},
		42:  [2]int{6, 5},
		43:  [2]int{7, 5},
		44:  [2]int{8, 5},
		45:  [2]int{9, 5},
		46:  [2]int{10, 5},
		47:  [2]int{11, 5},
		48:  [2]int{12, 5},
		49:  [2]int{13, 5},
		50:  [2]int{14, 5},
		51:  [2]int{15, 5},
		52:  [2]int{16, 5},
		53:  [2]int{17, 5},
		54:  [2]int{18, 5},
		55:  [2]int{1, 6},
		56:  [2]int{2, 6},
		57:  [2]int{'L', 0},
		58:  [2]int{'L', 0},
		59:  [2]int{'L', 0},
		60:  [2]int{'L', 0},
		61:  [2]int{'L', 0},
		62:  [2]int{'L', 0},
		63:  [2]int{'L', 0},
		64:  [2]int{'L', 0},
		65:  [2]int{'L', 0},
		66:  [2]int{'L', 0},
		67:  [2]int{'L', 0},
		68:  [2]int{'L', 0},
		69:  [2]int{'L', 0},
		70:  [2]int{'L', 0},
		71:  [2]int{'L', 0},
		72:  [2]int{4, 6},
		73:  [2]int{5, 6},
		74:  [2]int{6, 6},
		75:  [2]int{7, 6},
		76:  [2]int{8, 6},
		77:  [2]int{9, 6},
		78:  [2]int{10, 6},
		79:  [2]int{11, 6},
		80:  [2]int{12, 6},
		81:  [2]int{13, 6},
		82:  [2]int{14, 6},
		83:  [2]int{15, 6},
		84:  [2]int{16, 6},
		85:  [2]int{17, 6},
		86:  [2]int{18, 6},
		87:  [2]int{1, 7},
		88:  [2]int{2, 7},
		89:  [2]int{'A', 0},
		90:  [2]int{'A', 0},
		91:  [2]int{'A', 0},
		92:  [2]int{'A', 0},
		93:  [2]int{'A', 0},
		94:  [2]int{'A', 0},
		95:  [2]int{'A', 0},
		96:  [2]int{'A', 0},
		97:  [2]int{'A', 0},
		98:  [2]int{'A', 0},
		99:  [2]int{'A', 0},
		100: [2]int{'A', 0},
		101: [2]int{'A', 0},
		102: [2]int{'A', 0},
		103: [2]int{'A', 0},
		104: [2]int{4, 7},
		105: [2]int{5, 7},
		106: [2]int{6, 7},
		107: [2]int{7, 7},
		108: [2]int{8, 7},
		109: [2]int{9, 7},
		110: [2]int{10, 7},
		111: [2]int{11, 7},
		112: [2]int{12, 7},
		113: [2]int{13, 7},
		114: [2]int{14, 7},
		115: [2]int{15, 7},
		116: [2]int{16, 7},
		117: [2]int{17, 7},
		118: [2]int{18, 7},
	}

	if atomic < 1 || atomic >= len(lut) {
		return 0, 0
	}
	return lut[atomic][0], lut[atomic][1]
}
