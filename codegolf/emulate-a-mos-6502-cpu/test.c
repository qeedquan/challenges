/*

This is kind of inspired by the Intel 8086 challenge that's also on here, but I thought a 6502 challenge would be interesting too.

The challenge
I thought this would be a fun one to see the results for. This one is obviously towards the more advanced side of the spectrum. The challenge is to write your own 6502 CPU emulator. This involves, of course, understanding its instruction set and its encoding format. Resources are linked at the bottom of this. The 6502 is one of the easiest real-world processors to emulate. For the purposes of this challenge, you won't need to worry about cycle timing if you don't want to — but that's always a plus to include!

DON'T COPY ANYBODY ELSE'S CODE!! Of course, you can certainly peek at other emulators to help you understand, but no copy and pasting! :)

Once your code works, you can always go the extra mile if you like and turn it into an Apple II emulator, or NES, C64, VIC-20 or any of the other billions of old 6502-based systems from back in the day.

Testing your emulator
I have compiled a 6502 test suite which I found the source code to here: AllSuiteA.asm from hcm-6502

My compiled version can be downloaded here.

Load the 48 KB binary into your emulator's memory space at $4000, which leaves 16 KB of read-write RAM below it. When the test has finished executing, the value in address $0210 should be $FF, if your CPU passed. You will know that the test is finished when the program counter (PC) has reached address $45C0.

Other tests are available here as well: 6502 Test programs (for emulators and re-implementations)

Doing something more interactive with it
Once your CPU works, you probably will want to do something more fun than staring at test output! I compiled a ROM image of Enhanced BASIC for the 6502. It is 16 KB, so you should load it into $C000 of your emulated memory space, reset your virtual 6502, and begin execution.

Download this ZIP, which contains ehbasic.bin.

The way that EhBASIC handles input/output is very simple. When it wants to write a character to the console, it writes the byte to memory location $F001. So, when your emulator sees the 6502 try to write to that location, simply print that character value to the console with a printf("%c", value); or however else you'd like. (This challenge isn't limited to C of course.)

When it polls for a character being inputted from the console, it's pretty similar. It keeps reading from memory location $F004, where you should have the next ASCII character value from the keyboard waiting to be read. If there is no more input to read, it should return a value of zero.

EhBASIC polls the value at that location until it's non-zero, which lets it know the byte is valid keyboard input. That's why if there's no more input to read, the emulator should return zero there. EhBASIC will spin on it until the next valid key when it's looking for input.

If you don't clear that value to zero after it reads the last key value, it will cause it to repeat as if you were holding the key down, so be careful to do that correctly!

If your emulator works correctly, this is what you will see printed out on your console when it executes the ROM image:

6502 EhBASIC [C]old/[W]arm ?
Press C, then press enter and you should see:

Memory size ?

31999 Bytes free

Enhanced BASIC 2.22

Ready
The bytes free may be different for you, but in my emulator I limited the writable memory area to a cap of 32 KB. You could really go all the way up to where the ROM begins, which is the 48 KB mark.

6502 CPU resource links
Here are some resources that should give you enough information to work with:

The Instruction Set
6502 Instruction Set
The 6502/65C02/65C816 Instruction Set Decoded <-- this one has some very interesting info
MOS Technology 6502
If you have questions or need more technical information, feel free to ask me. There is also a massive wealth of other 6502 info on the web. Google is your friend!

*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "fake6502.h"

#define FAIL "\x1b[1;31mFAIL!\x1b[0m"
#define PASS "\x1b[1;32mpass\x1b[0m"

uint8_t memory[65536];

uint8_t
read6502(uint16_t address)
{
	return memory[address];
}

void
write6502(uint16_t address, uint8_t value)
{
	memory[address] = value;
}

void
load_file(const char *filename)
{
	printf("%s -- ", filename);
	FILE *f = fopen(filename, "rb");
	if (!f) {
		fprintf(stderr, "cannot open test\n");
		return;
	}
	if (fread(memory, 1, sizeof(memory), f) != sizeof(memory)) {
		fprintf(stderr, "premature EOF\n");
		return;
	}
	fflush(stdout);
}

void
test(const char *filename, uint16_t success, bool trace)
{
	load_file(filename);
	reset6502();
	while (1) {
		uint16_t save = PC;
		step6502();
		if (trace) {
			printf("PC=%04X ", PC);
			printf("SP=01%02X ", SP);
			printf("A=%02X X=%02X Y=%02X ", A, X, Y);
			printf("P=%02X\n", getP());
		}
		if (save == PC) {
			printf("%s -- ", PC != success ? FAIL : PASS);
			printf("PC=%04x ", PC);
			printf("A=%02x X=%02x Y=%02x SP=%02x ", A, X, Y, SP);
			printf("P=%02x\n", getP());
			return;
		}
	}
}

int
main(void)
{
	test("AllSuiteA.bin", 0x45c0, false);
	return 0;
}
