/*

Given some positive integer n that is not a square, find the fundamental solution (x,y) of the associated Pell equation

x^2 - n*y^2=1

Details
The fundamental (x,y) is a pair of integers x,y satisfying the equation where x is minimal, and positive.
(There is always the trivial solution (x,y)=(1,0) which is not counted.)
You can assume that n is not a square.

Examples
 n           x    y
 1           -    -
 2           3    2
 3           2    1
 4           -    -
 5           9    4
 6           5    2
 7           8    3
 8           3    1
 9           -    -
10          19    6
11          10    3
12           7    2
13         649    180
14          15    4
15           4    1
16           -    -
17          33    8
18          17    4
19         170    39
20           9    2
21          55    12
22         197    42
23          24    5
24           5    1
25           -    -
26          51    10
27          26    5
28         127    24
29        9801    1820
30          11    2
31        1520    273
32          17    3
33          23    4
34          35    6
35           6    1
36           -    -
37          73    12
38          37    6
39          25    4
40          19    3
41        2049    320
42          13    2
43        3482    531
44         199    30
45         161    24
46       24335    3588
47          48    7
48           7    1
49           -    -
50          99    14
51          50    7
52         649    90
53       66249    9100
54         485    66
55          89    12
56          15    2
57         151    20
58       19603    2574
59         530    69
60          31    4
61  1766319049    226153980
62          63    8
63           8    1
64           -    -
65         129    16
66          65    8
67       48842    5967
68          33    4
69        7775    936
70         251    30
71        3480    413
72          17    2
73     2281249    267000
74        3699    430
75          26    3
76       57799    6630
77         351    40
78          53    6
79          80    9
80           9    1
81           -    -
82         163    18
83          82    9
84          55    6
85      285769    30996
86       10405    1122
87          28    3
88         197    21
89      500001    53000
90          19    2
91        1574    165
92        1151    120
93       12151    1260
94     2143295    221064
95          39    4
96          49    5
97    62809633    6377352
98          99    10
99          10    1
Relevant OEIS sequences: A002350 A002349 A033313 A033317

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef long long vlong;

int
solve(vlong n, vlong *rx, vlong *ry)
{
	vlong r, x, y;
	double m;

	*rx = *ry = -1;
	m = sqrt(n);
	for (x = 2; x < LLONG_MAX; x++) {
		y = floor(x / m);
		r = (x * x) - (n * y * y);
		if (r == 1) {
			*rx = x;
			*ry = y;
			return 0;
		}

		if (fmod(x, m) * x <= 1)
			break;
	}
	return -1;
}

void
test(vlong n, vlong rx, vlong ry)
{
	vlong x, y;

	solve(n, &x, &y);
	printf("%lld %lld %lld\n", n, x, y);
	assert(x == rx);
	assert(y == ry);
}

int
main()
{
	test(1, -1, -1);
	test(2, 3, 2);
	test(3, 2, 1);
	test(4, -1, -1);
	test(5, 9, 4);
	test(6, 5, 2);
	test(7, 8, 3);
	test(8, 3, 1);
	test(9, -1, -1);
	test(10, 19, 6);
	test(11, 10, 3);
	test(12, 7, 2);
	test(13, 649, 180);
	test(14, 15, 4);
	test(15, 4, 1);
	test(16, -1, -1);
	test(17, 33, 8);
	test(18, 17, 4);
	test(19, 170, 39);
	test(20, 9, 2);
	test(21, 55, 12);
	test(22, 197, 42);
	test(23, 24, 5);
	test(24, 5, 1);
	test(25, -1, -1);
	test(26, 51, 10);
	test(27, 26, 5);
	test(28, 127, 24);
	test(29, 9801, 1820);
	test(30, 11, 2);
	test(31, 1520, 273);
	test(32, 17, 3);
	test(33, 23, 4);
	test(34, 35, 6);
	test(35, 6, 1);
	test(36, -1, -1);
	test(37, 73, 12);
	test(38, 37, 6);
	test(39, 25, 4);
	test(40, 19, 3);
	test(41, 2049, 320);
	test(42, 13, 2);
	test(43, 3482, 531);
	test(44, 199, 30);
	test(45, 161, 24);
	test(46, 24335, 3588);
	test(47, 48, 7);
	test(48, 7, 1);
	test(49, -1, -1);
	test(50, 99, 14);
	test(51, 50, 7);
	test(52, 649, 90);
	test(53, 66249, 9100);
	test(54, 485, 66);
	test(55, 89, 12);
	test(56, 15, 2);
	test(57, 151, 20);
	test(58, 19603, 2574);
	test(59, 530, 69);
	test(60, 31, 4);
	test(61, 1766319049, 226153980);
	test(62, 63, 8);
	test(63, 8, 1);
	test(64, -1, -1);
	test(65, 129, 16);
	test(66, 65, 8);
	test(67, 48842, 5967);
	test(68, 33, 4);
	test(69, 7775, 936);
	test(70, 251, 30);
	test(71, 3480, 413);
	test(72, 17, 2);
	test(73, 2281249, 267000);
	test(74, 3699, 430);
	test(75, 26, 3);
	test(76, 57799, 6630);
	test(77, 351, 40);
	test(78, 53, 6);
	test(79, 80, 9);
	test(80, 9, 1);
	test(81, -1, -1);
	test(82, 163, 18);
	test(83, 82, 9);
	test(84, 55, 6);
	test(85, 285769, 30996);
	test(86, 10405, 1122);
	test(87, 28, 3);
	test(88, 197, 21);
	test(89, 500001, 53000);
	test(90, 19, 2);
	test(91, 1574, 165);
	test(92, 1151, 120);
	test(93, 12151, 1260);
	test(94, 2143295, 221064);
	test(95, 39, 4);
	test(96, 49, 5);
	test(97, 62809633, 6377352);
	test(98, 99, 10);
	test(99, 10, 1);

	return 0;
}
