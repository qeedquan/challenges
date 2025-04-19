/*

Douglas Adams was born on March 11, 1952, and died when he was just 49. In honor of this wonderful writer, I challenge you to display 42 in the most creative way possible.

You could print it in the log, via some convoluted method, or display it as ASCII art, or anything! Just come up with a creative method of displaying 42.

Because this a popularity-contest, whichever answer has the most upvotes by March 11, will be declared the winner.

Note: this is not a duplicate. The question it was marked as duplicating was a code-trolling question whose goal was to write code to output 42, not find the most creative way to display it.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

typedef struct BF BF;

typedef uint8_t (*getcfn)(BF *);
typedef void (*putcfn)(BF *, uint8_t);

struct BF {
	uint64_t fl;
	uint64_t pc;
	uint64_t ip;

	uint64_t memsz;
	uint64_t codesz;
	uint8_t *mem;
	uint8_t *code;

	getcfn getc;
	putcfn putc;
	void *aux;
};

enum {
	BF_MEMSZ = 30000,
};

enum {
	BF_FEOF = 1 << 0,
	BF_FMEM = 1 << 1,
	BF_FPAR = 1 << 2,
};

void
bfreset(BF *bf)
{
	bf->fl = 0;
	bf->pc = 0;
	bf->ip = 0;
}

int
bfinit(BF *bf, uint64_t memsz, const uint8_t *code, size_t codesz, getcfn getc, putcfn putc, void *aux)
{
	memset(bf, 0, sizeof(*bf));

	if (memsz == 0 || codesz == 0) {
		errno = EINVAL;
		goto error;
	}

	bf->mem = calloc(memsz, sizeof(*bf->mem));
	bf->code = calloc(codesz, sizeof(*bf->code));
	if (!bf->mem || !bf->code)
		goto error;

	memcpy(bf->code, code, codesz);
	bf->memsz = memsz;
	bf->codesz = codesz;

	bf->getc = getc;
	bf->putc = putc;
	bf->aux = aux;

	bfreset(bf);
	return 0;

error:
	free(bf->mem);
	free(bf->code);
	return -errno;
}

void
bffree(BF *bf)
{
	free(bf->mem);
	free(bf->code);
}

uint8_t
bfgetc(BF *)
{
	return getc(stdin);
}

void
bfputc(BF *, uint8_t ch)
{
	printf("%c", ch);
}

int
bfbranch(BF *bf, int cond, int fwd, int c0, int c1)
{
	int p;

	if (!cond)
		return 0;

	for (p = 1; p > 0;) {
		if ((fwd && bf->pc + 1 >= bf->codesz) || bf->pc == 0) {
			bf->fl |= BF_FPAR;
			return 1;
		}

		if (fwd)
			bf->pc++;
		else
			bf->pc--;

		if (bf->code[bf->pc] == c0)
			p++;
		else if (bf->code[bf->pc] == c1)
			p--;
	}
	return 0;
}

int
bfstep(BF *bf)
{
	if (bf->pc >= bf->codesz)
		bf->fl |= BF_FEOF;

	if (bf->fl)
		return 1;

	switch (bf->code[bf->pc]) {
	case '>':
		if (++bf->ip >= bf->memsz)
			bf->fl |= BF_FMEM;
		break;

	case '<':
		if (bf->ip == 0)
			bf->fl |= BF_FMEM;
		else
			bf->ip--;
		break;

	case '.':
		bf->putc(bf, bf->mem[bf->ip]);
		break;

	case ',':
		bf->mem[bf->ip] = bf->getc(bf);
		break;

	case '+':
		bf->mem[bf->ip]++;
		break;

	case '-':
		bf->mem[bf->ip]--;
		break;

	case '[':
		if (bfbranch(bf, bf->mem[bf->ip] == 0, 1, '[', ']'))
			return 1;
		break;

	case ']':
		if (bfbranch(bf, bf->mem[bf->ip] != 0, 0, ']', '['))
			return 1;
		break;
	}
	bf->pc++;

	return 0;
}

void
bfrun(BF *bf)
{
	while (bfstep(bf) == 0)
		;
	printf("\n");
}

// code from @grovesNL
static const uint8_t fourtytwo[] = {
    "           +++++[>++[>+>+        ++>++++>++++>++++>++++++    "
    "          >++++++>+++++++        ++>+++++++++<<<<<<<<<-]>>   "
    "         >+>+>+> >>>+[<]<        -]>>       >++>-->>+>>++>+  "
    "        >--<<<<  <<<.....         .>            ....<......  "
    "       ...>...   <<.>....                       >.>>>>>.<.   "
    "       <<<<..     ..<....                      >..>>>>>.<    "
    "      .<<<<.      >>>.<<.                     >>>>>.<.<      "
    "      <<<<<       <.>...>                    >>>.>>>.        "
    "     <<<.<        <<<..>>                  .>>>>>.<          "
    "    <.<<<         <<...>>                 >>>.<<<            "
    "   <..<.          ...>...               <<.>..>.             "
    "   >>.<.<<...>>...<<...>>...<         <....>>..              "
    "  .<<<.>.>>..>.<<.......<....        .....>...               "
    "                 <<.>...            .....>...                "
    "                 <......           .>>>.<<..                 "
    "                 <<.>...          .....>...<......>.>>.<.<<< "
    "                 .>......        ..>>...<<....>>.....>.<..>. ",
};

int
main(void)
{
	BF bf[1];

	if (bfinit(bf, BF_MEMSZ, fourtytwo, sizeof(fourtytwo), bfgetc, bfputc, NULL) < 0)
		return 1;
	bfrun(bf);
	bffree(bf);
	return 0;
}
