/*

Consider the following sequence:

1, 0, 1, 2, 4, 1, 6, 8, 0, 1, 2, 4, 6, 8, 1, 0, 2, 4, 6, 8, 1, 0, 2, 4, 6, 8, 0, 1, ...
The even digits start from 0 and are grouped into runs of increasing length. They are arranged cyclically, meaning that they are sorted in ascending order until 8 is reached, and then cycled back from 0. 1 separates the runs of even digits, and it also starts the sequence. Let's visualize how this sequence is formed:

                 1, 0, 1, 2, 4, 1, 6, 8, 0, 1, 2, 4, 6, 8, 1, 0, 2, 4, 6, 8, 1,  ...

                    -     ----     -------     ----------     -------------
run length:         1      2          3            4                5            ...
position of 1:   X     X        X           X              X                 X   ...
even sequence:      0,    2, 4,    6, 8, 0,    2, 4, 6, 8,    0, 2, 4, 6, 8      ...
Acceptable Input and Output methods:

Receive an integer N as input and output the Nth term of this sequence.

Receive an integer N as input and output the first N terms of this sequence.

Print the sequence indefinitely.

You can choose either 0 or 1-indexing for the first two methods.

You can compete in any programming language, while using the standard input and output methods. Standard loopholes are forbidden. This is code-golf, so the shortest code in each language wins.

*/

#include <stdio.h>

void
output()
{
	int i, n, k;

	n = k = 0;
	for (;;) {
		printf("%d\n", 1);
		k += 1;
		for (i = 0; i < k; i++) {
			printf("%d\n", n % 10);
			n += 2;
		}
	}
}

int
main()
{
	output();
	return 0;
}
