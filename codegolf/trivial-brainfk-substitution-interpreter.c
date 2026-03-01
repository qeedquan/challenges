/*

Brainf**k is the most famous esoteric programming language and is the inspiration for hundreds of other esoteric languages. In fact, there are quite a few languages that are so heavily based off of Brainf**k that the only difference is the characters used. Your challenge is to interpret one of these languages.

Brainf**k
Brainf**k uses these commands:

> Move pointer to the right
< Move pointer to the left
+ Increment the memory cell under the pointer
- Decrement the memory cell under the pointer
. Output the character signified by the cell at the pointer
, Input a character and store it in the cell at the pointer
[ Jump past the matching ] if the cell under the pointer is 0
] Jump back to the matching [ if the cell under the pointer is nonzero
Trivial Brainf**k Substitution
There are lots of esolangs that are identical to Brainf**k in that they use the same commands, just with different characters/strings signaling the commands. For example, take Ook!:

Brainf**k | Ook         | Command
-----------------------------------------------------
>         | Ook. Ook?   | Move the pointer to the right
<         | Ook? Ook.   | Move the pointer to the left
+         | Ook. Ook.   | Increment the memory cell under the pointer
-         | Ook! Ook!   | Decrement the memory cell under the pointer
.         | Ook! Ook.   | Output the character signified by the cell at the pointer
,         | Ook. Ook!   | Input a character and store it in the cell at the pointer
[         | Ook! Ook?   | Jump past the matching Ook? Ook! if the cell under the pointer is 0
]         | Ook? Ook!   | Jump back to the matching Ook! Ook? if the cell under the pointer is nonzero
Ook is exactly like Brainf**k, except for the syntax.

TrivialBrainfuckSubstitution is a function defined as:

TrivialBrainfuckSubstitution(string1, string2, string3, string4, string5, string6, string7, string8)
Each string provided substitutes the corresponding Brainf**k character - so string1 will be a substitution for >, string2 will be a substitution for <, so on and so forth.

For example, Ook! is equivalent to TrivialBrainfuckSubstitution("Ook. Ook?", "Ook? Ook.", "Ook. Ook.", "Ook! Ook!", "Ook! Ook.", "Ook. Ook!", "Ook! Ook?", "Ook? Ook!").

Alphuck is equivalent to TrivialBrainfuckSubstitution("a", "c", "e", "i", "j", "o", "p", "s").

The challenge
Implement TrivialBrainfuckSubstitution.

To elaborate: Given eight strings representing the eight substitutions and a ninth string representing a program, interpret the program as a trivial Brainf** substitution.

Rules
TrivialBrainfuckSubstitution may take function arguments or command line arguments. These are the only ways it may take the first eight arguments.
TrivialBrainfuckSubstitution can take the ninth argument from standard input, a file, or a literal ninth argument.
TrivialBrainfuckSubstitution must be able to take any ASCII characters as substitutions. It does not have to handle Unicode, and you can assume there are no duplicate elements provided.
Note that the actual function in your code need not be named TrivialBrainfuckSubstitution. This is just the title of the function; the actual name in the code can be f, or x, or a lambda, or whatever you like.
Your interpreter should not require any spaces between command substitutions. However, it should not break if they are present. To rephrase, it should ignore unrecognized commands, just like normal Brainf**k.
You may assume that all substitutions are the same length. I.e. you may assume that AB, A, and B are never in the same substitution set.
Challenge-specific Brainf**k semantics
In your newly-created Brainf**k language:

You do not need to be able to go left from the start of the tape. (You can choose to allow this.)
The tape should have a minimum length of 30000. (If you want it can be longer or allocated dynamically.)
The maximum value of the tape elements must be the maximum value for an integer in your (host) language.
Input can be read from standard input or a file.
An attempt to read EOF (End Of File) should not cause any undefined behavior. EOF must simply be stored as would any other character read.

Test cases
Test case 1
Test case 2

Winner
As with code-golf, the shortest submission wins. I won't ever accept an answer unless one is 50 bytes shorter than all others.

Also, as this challenge is somewhat more difficult than others (while certainly not the hardest), I kindly ask that you include an ungolfed version and explanation with your answer.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned char uchar;
typedef unsigned int uint;

typedef struct {
	const char *from;
	const char *to;
} Sub;

typedef struct {
	char *code;
	uchar *mem;

	uint ncode;
	uint nmem;

	uint ip;
	uint dp;
} BF;

void
bfreset(BF *bf)
{
	bf->ip = 0;
	bf->dp = 0;
}

void
bffree(BF *bf)
{
	free(bf->code);
	free(bf->mem);
}

int
bfnew(BF *bf, const char *code, uint ncode, uint nmem)
{
	if (ncode == 0 || nmem == 0)
		return -EINVAL;

	bf->code = calloc(ncode, sizeof(*bf->code));
	bf->mem = calloc(nmem, sizeof(*bf->mem));
	if (!bf->code || !bf->mem) {
		bffree(bf);
		return -errno;
	}

	memcpy(bf->code, code, ncode);

	bf->ncode = ncode;
	bf->nmem = nmem;

	bfreset(bf);
	return 0;
}

int
branch(BF *bf, int cond, int dir, int c0, int c1)
{
	uint p;

	if (!cond)
		return 0;

	for (p = 1; p > 0;) {
		if (bf->ip == 0 && dir < 0)
			return -2;

		bf->ip += dir;
		if (bf->ip >= bf->ncode)
			return -3;

		if (bf->code[bf->ip] == c0)
			p++;
		else if (bf->code[bf->ip] == c1)
			p--;
	}

	return 0;
}

int
bfstep(BF *bf)
{
	int r;

	if (bf->ip >= bf->ncode) {
		printf("\n");
		return -1;
	}

	r = 0;
	switch (bf->code[bf->ip]) {
	case '>':
		bf->dp = (bf->dp + 1) % bf->nmem;
		break;

	case '<':
		if (bf->dp > 0)
			bf->dp--;
		else
			bf->dp = bf->nmem - 1;
		break;

	case '.':
		printf("%c", bf->mem[bf->dp]);
		break;

	case '+':
		bf->mem[bf->dp]++;
		break;

	case '-':
		bf->mem[bf->dp]--;
		break;

	case ',':
		scanf("%c", &bf->mem[bf->dp]);
		break;

	case '[':
		r = branch(bf, !bf->mem[bf->dp], 1, '[', ']');
		break;

	case ']':
		r = branch(bf, bf->mem[bf->dp], -1, ']', '[');
		break;
	}
	bf->ip++;

	return r;
}

int
bfrun(BF *bf)
{
	int r;

	while ((r = bfstep(bf)) >= 0)
		;
	return r;
}

size_t
translate(Sub *sub, size_t nsub, const char *in, char *out)
{
	Sub *s;
	size_t i, l, n;

	l = 0;
	while (*in) {
		for (i = 0; i < nsub; i++) {
			s = sub + i;
			n = strlen(s->from);
			if (!strncmp(in, s->from, n)) {
				l += sprintf(out + l, "%s", s->to);
				in += n;
				break;
			}
		}
		if (i == nsub)
			in += 1;
	}
	return l;
}

void
test(Sub *sub, size_t nsub, const char *input)
{
	BF bf[1];
	char code[512];
	size_t ncode;

	ncode = translate(sub, nsub, input, code);
	assert(bfnew(bf, code, ncode, 50000) >= 0);
	bfrun(bf);
	bffree(bf);
}

int
main(void)
{
	Sub sub1[] = {
	    {"Ook. Ook?", ">"},
	    {"Ook? Ook.", "<"},
	    {"Ook. Ook.", "+"},
	    {"Ook! Ook!", "-"},
	    {"Ook! Ook.", "."},
	    {"Ook. Ook!", ","},
	    {"Ook! Ook?", "["},
	    {"Ook? Ook!", "]"},
	};
	Sub sub2[] = {
	    {"a", ">"},
	    {"c", "<"},
	    {"e", "+"},
	    {"i", "-"},
	    {"j", "."},
	    {"o", ","},
	    {"p", "["},
	    {"s", "]"},
	};

	const char input1[] = "Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook! Ook. Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook. Ook. Ook! Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook. Ook! Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook. Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook! Ook. Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook? Ook? Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook? Ook! Ook! Ook? Ook! Ook? Ook. Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook? Ook. Ook! Ook. Ook. Ook. Ook. Ook. Ook. Ook. Ook! Ook. Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook. Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook! Ook. Ook. Ook? Ook. Ook? Ook. Ook. Ook! Ook.";
	const char input2[] = "eeeee<<<<<<eeepaeeeepaeeaee>>>>>>eaeeeaecccc++++----isaeaeaiaaepcscisaajaiiijeeeeeeejjeeejaajcijcjeeejiiiiiijiiiiiiiijaaejaeej";

	test(sub1, nelem(sub1), input1);
	test(sub2, nelem(sub2), input2);

	return 0;
}
