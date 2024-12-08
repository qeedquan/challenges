/*

Objective
Simulate an edge-triggered D Flip-Flop.

What is D Flip-Flop?
A D flip-flop is an electronic digital device that outputs an inputted data (abbr. D) with synchronization to a clock (abbr. CLK). Usually CLK is a uniform pulse, but in this challenge, CLK may be not uniform.

Input
A bitstring with length n
 will be given as CLK and another bitstring with length n−1
 will be given as D. A bit represents the state of an input during a unit time (tick). CLK leads D by half a tick.

Output
The output (abbr. Q) is a bitstring with same length and starting timepoint as D. If CLK doesn't start with 01, the starting bit of Q is implementation-defined. Q is updated upon a rising moment of CLK to the bit of D at the time. On the other times, Q retains its state.

Examples
The red line indicates a rising moment of CLK.

Example 1
https://i.stack.imgur.com/kMHal.png

Example 2
https://i.stack.imgur.com/572TD.png

Rules
If CLK isn't a tick longer than D, the entire challenge falls into don't care situation.
Though defined as bitstrings, the actual elements of CLK, D, and Q doesn't matter. In this case, if a string is not binary (that is, contains a third character), the entire challenge falls into don't care situation.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
simulate(const char *clock, const char *data, char *output)
{
	size_t i;
	int c;

	c = '0';
	for (i = 0; data[i]; i++) {
		if (clock[i] < clock[i + 1])
			c = data[i];

		output[i] = c;
	}
	output[i] = '\0';
}

void
test(const char *clock, const char *data, const char *expected)
{
	char output[128];

	simulate(clock, data, output);
	printf("%s\n", output);
	assert(!strcmp(output, expected));
}

int
main(void)
{
	test("000010000111110111100010101000000011", "10101011110011100001110010100111011", "00000000111111111111111000000000011");
	test("110101000101001010101010001011101100", "11111101011110011111110110101111110", "00111111001110011111111110000001111");

	return 0;
}
