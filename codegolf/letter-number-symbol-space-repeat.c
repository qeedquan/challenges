/*

There are 97 ASCII characters that people encounter on a regular basis. They fall into four categories:

Letters (52 total)

ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Numbers or Digits (10 total)

0123456789
Symbols & Punctuation (32 total)

!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
Whitespace (3 total)

Space  , tab \t, and newline \n. (We'll treat newline variants like \r\n as one character.)

For conciseness, we'll call these categories L, N, S, and W respectively.

Choose any of the 24 permutations of the letters LNSW you desire and repeat it indefinitely to form a programming template for yourself.

For example, you might choose the permutation NLWS, so your programming template would be:

NLWSNLWSNLWSNLWSNLWS...
You need to write a program or function based on this template, where:

Every L is replaced with any letter (ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz).

Every N is replaced with any number (0123456789).

Every S is replaced with any symbol (!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~).

Every W is replaced with any whitespace character ( \t\n).

Basically, your code must follow the pattern

<letter><number><symbol><whitespace><letter><number><symbol><whitespace>...
as the question title suggests, except you may choose a different ordering of the four character categories, if desired.

Note that:

Replacements for a category can be different characters. e.g. 9a ^8B\t~7c\n] validly conforms to the template NLWSNLWSNLWS (\t and \n would be their literal chars).

There are no code length restrictions. e.g. 1A +2B - and 1A +2B and 1A  and 1 all conform to the template NLWSNLWSNLWS....

What your template-conformed code must do is take in one unextended ASCII character and output a number from 0 to 4 based on what category it is a member of in the categorization above. That is, output 1 if the input is a letter, 2 if a number, 3 if a symbol, and 4 if whitespace. Output 0 if the input is none of these (a control character).

For input, you may alternatively take in a number 0 to 127 inclusive that represents the code of the input ASCII character.

The input (as char code) and output pairs your code must have are precisely as follows:

in out
0 0
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 4
10 4
11 0 or 4
12 0 or 4
13 0 or 4
14 0
15 0
16 0
17 0
18 0
19 0
20 0
21 0
22 0
23 0
24 0
25 0
26 0
27 0
28 0
29 0
30 0
31 0
32 4
33 3
34 3
35 3
36 3
37 3
38 3
39 3
40 3
41 3
42 3
43 3
44 3
45 3
46 3
47 3
48 2
49 2
50 2
51 2
52 2
53 2
54 2
55 2
56 2
57 2
58 3
59 3
60 3
61 3
62 3
63 3
64 3
65 1
66 1
67 1
68 1
69 1
70 1
71 1
72 1
73 1
74 1
75 1
76 1
77 1
78 1
79 1
80 1
81 1
82 1
83 1
84 1
85 1
86 1
87 1
88 1
89 1
90 1
91 3
92 3
93 3
94 3
95 3
96 3
97 1
98 1
99 1
100 1
101 1
102 1
103 1
104 1
105 1
106 1
107 1
108 1
109 1
110 1
111 1
112 1
113 1
114 1
115 1
116 1
117 1
118 1
119 1
120 1
121 1
122 1
123 3
124 3
125 3
126 3
127 0
Inputs 11, 12, and 13 correspond to characters that are sometimes considered whitespace, thus their outputs may be 0 or 4 as you desire.

The shortest code in bytes wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
gen(void)
{
	static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	static const char numbers[] = "0123456789";
	static const char symbols[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	static const char whitespace[] = " \t\n";

	static const struct String {
		const char *buf;
		size_t len;
	} lut[] = {
	    {letters, sizeof(letters) - 1},
	    {numbers, sizeof(numbers) - 1},
	    {symbols, sizeof(symbols) - 1},
	    {whitespace, sizeof(whitespace) - 1},
	};

	const struct String *s;
	size_t i;

	i = 0;
	for (;;) {
		s = lut + i;
		printf("%c", s->buf[rand() % s->len]);
		i = (i + 1) % nelem(lut);
	}
}

int
main(void)
{
	srand(time(NULL));
	gen();
	return 0;
}
