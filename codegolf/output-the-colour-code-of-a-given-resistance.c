/*

Should be relatively easy to do, given an input of a resistance (in ohms) and a tolerance (%),
output the colour codes for a 4 band resistor, left to right.
Input will always be a valid ohm value and %.

The Codes

https://static.vecteezy.com/system/resources/previews/025/747/522/original/four-band-resistor-color-code-values-table-physics-and-electronics-vector.jpg

Examples

0 4 -> Black, Black, Black, Yellow (Technically in real life these would be a single black band for 0 ohm resistors, but this works)
84000 1 -> Grey, Yellow, Orange, Brown
0.63 0.05 -> Blue, Orange, Silver, Grey
80000000000 1 -> Grey Black White Brown

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
colorcode(double resistance, double tolerance, char *output)
{
	static const struct code {
		char color[8];
		double tolerance;
	} codes[] = {
		{ "Black", 0 },
		{ "Brown", 1 },
		{ "Red", 2 },
		{ "Orange", 3 },
		{ "Yellow", 4 },
		{ "Green", 0.5 },
		{ "Blue", 0.25 },
		{ "Violet", 0.10 },
		{ "Grey", 0.05 },
		{ "White", 0 },
		{ "Gold", 5 },
		{ "Silver", 10 },
		{ "None", 20 },
	};

	const struct code *code;
	int digit1, digit2;
	int multiplier;
	size_t index;

	sprintf(output, "%.1e", resistance);
	if (sscanf(output, "%d.%de%d", &digit1, &digit2, &multiplier) != 3)
		return -1;
	if (digit1 < 0 || digit1 > 9 || digit2 < 0 || digit2 > 9)
		return -1;

	if (-2 <= multiplier && multiplier < 0)
		multiplier = 10 - multiplier;
	else if (1 <= multiplier && multiplier <= 10)
		multiplier -= 1;
	else if (multiplier != 0)
		return -1;

	for (index = 0; index < nelem(codes); index++) {
		code = codes + index;
		if (fabs(code->tolerance - tolerance) < 1e-12)
			break;
	}
	index %= nelem(codes);

	sprintf(output, "%s %s %s %s",
	    codes[digit1].color, codes[digit2].color,
	    codes[multiplier].color, codes[index].color);

	return 0;
}

void
test(double resistance, double tolerance, const char *expected)
{
	char output[128];

	assert(colorcode(resistance, tolerance, output) >= 0);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test(0, 4, "Black Black Black Yellow");
	test(84000, 1, "Grey Yellow Orange Brown");
	test(0.63, 0.05, "Blue Orange Silver Grey");
	test(80000000000, 1, "Grey Black White Brown");

	return 0;
}
