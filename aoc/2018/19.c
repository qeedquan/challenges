/*

--- Day 19: Go With The Flow ---
With the Elves well on their way constructing the North Pole base, you turn your attention back to understanding the inner workings of programming the device.

You can't help but notice that the device's opcodes don't contain any flow control like jump instructions. The device's manual goes on to explain:

"In programs where flow control is required, the instruction pointer can be bound to a register so that it can be manipulated directly. This way, setr/seti can function as absolute jumps, addr/addi can function as relative jumps, and other opcodes can cause truly fascinating effects."

This mechanism is achieved through a declaration like #ip 1, which would modify register 1 so that accesses to it let the program indirectly access the instruction pointer itself. To compensate for this kind of binding, there are now six registers (numbered 0 through 5); the five not bound to the instruction pointer behave as normal. Otherwise, the same rules apply as the last time you worked with this device.

When the instruction pointer is bound to a register, its value is written to that register just before each instruction is executed, and the value of that register is written back to the instruction pointer immediately after each instruction finishes execution. Afterward, move to the next instruction by adding one to the instruction pointer, even if the value in the instruction pointer was just updated by an instruction. (Because of this, instructions must effectively set the instruction pointer to the instruction before the one they want executed next.)

The instruction pointer is 0 during the first instruction, 1 during the second, and so on. If the instruction pointer ever causes the device to attempt to load an instruction outside the instructions defined in the program, the program instead immediately halts. The instruction pointer starts at 0.

It turns out that this new information is already proving useful: the CPU in the device is not very powerful, and a background process is occupying most of its time. You dump the background process' declarations and instructions to a file (your puzzle input), making sure to use the names of the opcodes rather than the numbers.

For example, suppose you have the following program:

#ip 0
seti 5 0 1
seti 6 0 2
addi 0 1 0
addr 1 2 3
setr 1 0 0
seti 8 0 4
seti 9 0 5
When executed, the following instructions are executed. Each line contains the value of the instruction pointer at the time the instruction started, the values of the six registers before executing the instructions (in square brackets), the instruction itself, and the values of the six registers after executing the instruction (also in square brackets).

ip=0 [0, 0, 0, 0, 0, 0] seti 5 0 1 [0, 5, 0, 0, 0, 0]
ip=1 [1, 5, 0, 0, 0, 0] seti 6 0 2 [1, 5, 6, 0, 0, 0]
ip=2 [2, 5, 6, 0, 0, 0] addi 0 1 0 [3, 5, 6, 0, 0, 0]
ip=4 [4, 5, 6, 0, 0, 0] setr 1 0 0 [5, 5, 6, 0, 0, 0]
ip=6 [6, 5, 6, 0, 0, 0] seti 9 0 5 [6, 5, 6, 0, 0, 9]
In detail, when running this program, the following events occur:

The first line (#ip 0) indicates that the instruction pointer should be bound to register 0 in this program. This is not an instruction, and so the value of the instruction pointer does not change during the processing of this line.
The instruction pointer contains 0, and so the first instruction is executed (seti 5 0 1). It updates register 0 to the current instruction pointer value (0), sets register 1 to 5, sets the instruction pointer to the value of register 0 (which has no effect, as the instruction did not modify register 0), and then adds one to the instruction pointer.
The instruction pointer contains 1, and so the second instruction, seti 6 0 2, is executed. This is very similar to the instruction before it: 6 is stored in register 2, and the instruction pointer is left with the value 2.
The instruction pointer is 2, which points at the instruction addi 0 1 0. This is like a relative jump: the value of the instruction pointer, 2, is loaded into register 0. Then, addi finds the result of adding the value in register 0 and the value 1, storing the result, 3, back in register 0. Register 0 is then copied back to the instruction pointer, which will cause it to end up 1 larger than it would have otherwise and skip the next instruction (addr 1 2 3) entirely. Finally, 1 is added to the instruction pointer.
The instruction pointer is 4, so the instruction setr 1 0 0 is run. This is like an absolute jump: it copies the value contained in register 1, 5, into register 0, which causes it to end up in the instruction pointer. The instruction pointer is then incremented, leaving it at 6.
The instruction pointer is 6, so the instruction seti 9 0 5 stores 9 into register 5. The instruction pointer is incremented, causing it to point outside the program, and so the program ends.
What value is left in register 0 when the background process halts?

--- Part Two ---
A new background process immediately spins up in its place. It appears identical, but on closer inspection, you notice that this time, register 0 started with the value 1.

What value is left in register 0 when this new background process halts?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

enum {
	NCODE = 64,
	NREG = 6,
};

typedef struct {
	int op;
	int a;
	int b;
	int c;
} Inst;

typedef struct {
	int reg[NREG];
	int ip;

	Inst code[NCODE];
	int ncode;
} Mach;

typedef struct {
	char name[8];
	int op;
	int use;
} Optab;

enum {
	UA = 0x1,
	UB = 0x2,
};

enum {
	ADDR = 0,
	ADDI,
	MULR,
	MULI,
	BANR,
	BANI,
	BORR,
	BORI,
	SETR,
	SETI,
	GTIR,
	GTRI,
	GTRR,
	EQIR,
	EQRI,
	EQRR,
};

const Optab optab[] = {
	{ "addr", ADDR, UA | UB },
	{ "addi", ADDI, UA },
	{ "mulr", MULR, UA | UB },
	{ "muli", MULI, UA },
	{ "banr", BANR, UA | UB },
	{ "bani", BANI, UA },
	{ "borr", BORR, UA | UB },
	{ "bori", BORI, UA },
	{ "setr", SETR, UA },
	{ "seti", SETI, 0 },
	{ "gtir", GTIR, UB },
	{ "gtri", GTRI, UA },
	{ "gtrr", GTRR, UA | UB },
	{ "eqir", EQIR, UB },
	{ "eqri", EQRI, UA },
	{ "eqrr", EQRR, UA | UB },
};

// https://en.wikipedia.org/wiki/Divisor_summatory_function
vlong
divsum(vlong n)
{
	vlong f, g, s;

	f = 2;
	s = 1;
	while (f * f <= n) {
		g = s;
		while (!(n % f)) {
			n /= f;
			g *= f;
			s += g;
		}
		f += 1;
	}

	if (n == 1)
		return s;
	return s * (n + 1);
}

void
decode(const char *buf, Mach *m)
{
	const Optab *t;
	Inst *i;
	char op[8];
	size_t n;

	if (m->ncode >= NCODE)
		return;

	if (sscanf(buf, "#ip %d", &m->ip) == 1)
		return;

	i = m->code + m->ncode;
	if (sscanf(buf, "%4s %d %d %d", op, &i->a, &i->b, &i->c) != 4)
		return;

	for (n = 0; n < nelem(optab); n++) {
		t = optab + n;
		if (!strcmp(op, t->name)) {
			if (i->c < 0 || i->c >= NREG)
				return;
			if ((t->use & UA) && (i->a < 0 || i->a >= NREG))
				return;
			if ((t->use & UB) && (i->b < 0 || i->b >= NREG))
				return;

			i->op = t->op;
			m->ncode += 1;
			break;
		}
	}
}

void
load(const char *fn, Mach *m)
{
	FILE *fp;
	char buf[32];

	fp = fopen(fn, "rb");
	if (!fp) {
		printf("Failed to open file: %s\n", strerror(errno));
		exit(1);
	}

	memset(m, 0, sizeof(*m));
	while (fgets(buf, sizeof(buf), fp))
		decode(buf, m);

	fclose(fp);
}

void
xec(int *r, int op, int a, int b, int c)
{
	switch (op) {
	case ADDR:
		r[c] = r[a] + r[b];
		break;
	case ADDI:
		r[c] = r[a] + b;
		break;
	case MULR:
		r[c] = r[a] * r[b];
		break;
	case MULI:
		r[c] = r[a] * b;
		break;
	case BANR:
		r[c] = r[a] & r[b];
		break;
	case BANI:
		r[c] = r[a] & b;
		break;
	case BORR:
		r[c] = r[a] | r[b];
		break;
	case BORI:
		r[c] = r[a] | b;
		break;
	case SETR:
		r[c] = r[a];
		break;
	case SETI:
		r[c] = a;
		break;
	case GTIR:
		r[c] = (a > r[b]);
		break;
	case GTRI:
		r[c] = (r[a] > b);
		break;
	case GTRR:
		r[c] = (r[a] > r[b]);
		break;
	case EQIR:
		r[c] = (a == r[b]);
		break;
	case EQRI:
		r[c] = (r[a] == b);
		break;
	case EQRR:
		r[c] = (r[a] == r[b]);
		break;
	}
}

vlong
part1(Mach *m)
{
	Inst *i;
	int *pc;

	if (m->ip < 0 || m->ip >= NREG)
		return -1;

	memset(m->reg, 0, sizeof(*m->reg));

	pc = m->reg + m->ip;
	for (;;) {
		if (*pc < 0 || *pc >= m->ncode)
			break;

		i = m->code + *pc;
		xec(m->reg, i->op, i->a, i->b, i->c);
		*pc += 1;
	}
	return m->reg[0];
}

vlong
part2(Mach *m)
{
	Inst *i1, *i2;
	vlong n;

	if (m->ncode < 24)
		return -1;

	i1 = m->code + 21;
	i2 = m->code + 23;
	n = (22 * i1->b) + i2->b;
	n += 10551236;
	return divsum(n);
}

int
main()
{
	Mach m;

	load("19.txt", &m);
	printf("%lld\n", part1(&m));
	printf("%lld\n", part2(&m));
	return 0;
}
