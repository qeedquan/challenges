/*

Task
Your task is to print or output all positive numbers in which every multi-digit substring in its decimal representation is also prime. If the number has at least 2 digits, this would imply that the number itself also needs to be prime.

Example
6197 is in the sequence because every multi-digit substring in 6197 is prime, namely: 61, 19, 97, 619, 197, 6197 (itself).
Note that 6 is not a prime but 6197 is still in the sequence because 6 is not a multi-digit substring of 6197.
8 is also in the sequence because every multi-digit substring in 8 is prime. There is no multi-digit substring in 8, so this is a case of vacuous truth.
Specs
Standard loopholes apply, except that you are allowed to hardcode the output or store information related to the output in your program.
The numbers in the output can be in any order.
The numbers in the output are allowed to have duplicates.
You may use any separator, if you choose to print instead of output.
You are allowed to prefix and/or postfix output if you choose to print instead of output.
The separator and the prefix and the postfix may not contain any digits (U+0030 to U+0039).
Full list (58 items)
1
2
3
4
5
6
7
8
9
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
113
131
137
173
179
197
311
313
317
373
379
419
431
479
613
617
619
673
719
797
971
1373
3137
3797
6131
6173
6197
9719
Reference
OEIS A131648 (incomplete list)
As always, please feel free to address in the comments anything I should clarify.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A131648 (related)
void
output()
{
	static const int tab[] = {
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		11,
		13,
		17,
		19,
		23,
		29,
		31,
		37,
		41,
		43,
		47,
		53,
		59,
		61,
		67,
		71,
		73,
		79,
		83,
		89,
		97,
		113,
		131,
		137,
		173,
		179,
		197,
		311,
		313,
		317,
		373,
		379,
		419,
		431,
		479,
		613,
		617,
		619,
		673,
		719,
		797,
		971,
		1373,
		3137,
		3797,
		6131,
		6173,
		6197,
		9719,
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("%d\n", tab[i]);
}

int
main()
{
	output();
	return 0;
}
