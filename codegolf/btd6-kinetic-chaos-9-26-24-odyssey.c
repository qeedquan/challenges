/*

This week's odyssey in Bloons Tower Defense 6 has a neat gimmick, but it's slightly confusing at first. Each custom round is actually two consecutive regular rounds at once, but this means the round number no longer helps you know what is coming! The rounds are as follows:

1  1,2
2  3,4
3  5,6
4  7,8
5  9,10
6  11,12
7  13,14
8  15,16
9  17,18
10 19,20
11 21,22
12 23,24
13 25,26
14 27,28
15 29,30
16 31,32
17 33,34
18 35,36
19 37,38
20 39,40
21 41,42
22 43,44
23 45,46
24 47,48
25 49,50
26 51,52
27 53,54
28 55,56
29 57,58
30 59,60
31 61,62
32 63,64
33 65,66
34 67,68
35 69,70
36 71,72
37 73,74
38 75,76
39 77,78
40 79,80
41 81,82
42 83,84
43 85,86
44 87,88
45 89,90
46 91,92
47 93,94
48 95,96
49 97,98
50 99,100
51 101,102
52 103,104
53 105,106
54 107,108
55 109,110
56 111,112
57 113,114
58 115,116
59 117,118
60 119,120
61 121,122
62 123,124
63 125,126
64 127,128
65 129,130
66 131,132
67 133,134
68 135,136
69 137,138
70 139,140
Where each round is (2n-1, 2n). Since rounds only go up to 140, the table only needs 70 lines.

A lookup table would be nice... Since I play on speedup, code should be as short as possible so I can type it before the next custom round starts. You can use any delimiters provided each round is on its own line, and the round number delimiter is different from the paired round delimiter. trailing whitespace on each line is fine, as is a trailing newline at the end. You can use a leading zero instead of padding with spaces for rounds 1-9, padding can be done on either side.

*/

#include <stdio.h>

void
output(int n)
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%-2d %d,%d\n", i, (2 * i) - 1, 2 * i);
}

int
main()
{
	output(70);
	return 0;
}
