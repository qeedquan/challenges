/*

Challenge
We define a Minsky machine as a program made of the following two instructions:

+X which increments the register X and continues to the next instruction
-Xn which simply continues if X is zero, otherwise decrements X and jumps to the n'th instruction
For this code challenge, one must find a Minsky machine that:

Has three registers that are initialized to 0 (not all need to be used)
Uses ONLY the aforementioned instructions.
Has 32 or less instructions.
HALTS! (by reaching the end of the program); This MUST be proven to halt, not modeling some unsolved problem, like the Collatz conjecture.
Note that labels can be used, in which case they don't count towards the instruction count.

Example of Correct Program
+B
+B
-A06
+C
+A
-B04
+B
-A00
-C06
Example of Incorrect Program
+D
+D
-C01
-D00
A = B * 2 + X
The longest running program wins!

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

enum {
	NCODE = 32,
	NREG = 3,
};

vlong
sim(const char **code, int ncode)
{
	vlong steps;
	int reg[NREG];
	int pc, nextpc;
	int ri;

	if (ncode < 1 || ncode > NCODE)
		return -1;

	memset(reg, 0, sizeof(reg));
	steps = 0;
	for (pc = 0; pc < ncode; pc++) {
		if (pc < 0 || !code[pc][0] || !code[pc][1])
			return -1;

		ri = code[pc][1] - 'A';
		nextpc = atoi(&code[pc][2]);
		if (ri < 0 || ri >= NREG || nextpc < 0 || nextpc >= ncode)
			return -1;

		switch (code[pc][0]) {
		case '+':
			reg[ri] = (reg[ri] + 1) % INT_MAX;
			break;

		case '-':
			if (reg[ri]) {
				reg[ri] -= 1;
				pc = nextpc - 1;
			}
			break;

		default:
			return -1;
		}

		steps++;
		if (steps == LLONG_MAX)
			return -1;
	}

	return steps;
}

/*

@InI4

Hmm, it feels more like a math problem, than like a coding challenge. Yet ironically I didn't tackle the math part,
but wrote me an interpreter (yea, old-fashioned Java objects, with labels for jumps) for the code and did some trial and error approach.
I can prove this to terminate, it mixes some exponential with some quadratic and takes 11813164 steps to finish.
Even after these iterations, I am still confident, this can be beaten.

*/

vlong
solve()
{
	static const char *code[] = {
		"+A",
		"+A",
		"+C",
		"+C",
		"+C",
		"-A2",
		"+A",
		"+A",
		"+A",
		"+A",
		"-C6",
		"+C",
		"+C",
		"+C",
		"+C",
		"-A11",
		"+A",
		"+A",
		"+A",
		"+A",
		"-C16",
		"+C",
		"-B25",
		"+C",
		"+C",
		"-A21",
		"+A",
		"+B",
		"-C26",
		"-A30",
		"-A31",
		"-A21",
	};

	return sim(code, nelem(code));
}

int
main()
{
	printf("%lld\n", solve());
	return 0;
}
