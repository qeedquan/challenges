/*

A peer of mine approached me with this challenge and I wasn't able to come up with an elegant solution. After discussing my approach, we began to wonder what the people at Code Golf would come up with.

Given
A processor that implements only two instructions:

STO <register>, <address> (store from this register to this address)
SUB <register>, <address> (subtract the value at this address from this register)

It also only contains 2, 32-bit registers: A and B
As well as 2, 32-bit RAM address: 0x00 and 0x01

The values of A and B are unknown

Challenge
Write a program to copy RAM address 0x00 into 0x01 optimised to use the fewest number of instructions possible.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	uint32_t pc;
	uint32_t reg[2];
	uint32_t ram[2];
	uint32_t code[0x100];
} Mach;

enum {
	HLT = 0,
	STO = 1,
	SUB = 2,

	A = 0,
	B = 1,
};

void
run(Mach *m)
{
	uint32_t op, reg, addr;

	for (;;) {
		if (m->pc + 3 >= nelem(m->code))
			break;

		op = m->code[m->pc++];
		reg = m->code[m->pc++] % nelem(m->reg);
		addr = m->code[m->pc++] % nelem(m->ram);

		switch (op) {
		case STO:
			m->ram[addr] = m->reg[reg];
			break;
		case SUB:
			m->reg[reg] -= m->ram[addr];
			break;
		default:
			return;
		}
	}
}

void
test(uint32_t *code, size_t size, uint32_t ram0, uint32_t ram1)
{
	Mach m[1];

	memset(m, 0, sizeof(m));
	memcpy(m->code, code, size * sizeof(*code));
	m->reg[0] = rand();
	m->reg[1] = rand();
	m->ram[0] = ram0;
	m->ram[1] = ram1;

	run(m);
	assert(m->ram[0] == m->ram[1]);
}

int
main(void)
{
	// code from @SuperJedi224
	uint32_t code[] = {
	    STO, A, 0x01,
	    SUB, A, 0x01,
	    SUB, A, 0x00,
	    STO, A, 0x01,
	    SUB, A, 0x01,
	    SUB, A, 0x01,
	    STO, A, 0x01,
	    HLT,
	};

	uint32_t ram0, ram1, rammax;

	srand(time(NULL));
	rammax = 1000;
	for (ram0 = 0; ram0 <= rammax; ram0++) {
		for (ram1 = 0; ram1 <= rammax; ram1++) {
			test(code, nelem(code), ram0, ram1);
		}
	}

	return 0;
}
