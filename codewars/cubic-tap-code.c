/*

Cubic Tap Code
This works similarly to Tap Code except instead of being mapped onto a 5x5 square, letters are mapped onto a 3x3x3 cube, left to right, top to bottom, front to back with space being the 27th "letter". Letters are represented by a series of taps (represented as dots .) and pauses (represented by spaces  ), for example A is represented as . . . (first column, first row, first layer) and   is represented as ... ... ... (third column, third row, third layer).

For reference the three layers of the cube are as follows (underscore represents space):

1  1  2  3
1  A  B  C
2  D  E  F
3  G  H  I

2  1  2  3
1  J  K  L
2  M  N  O
3  P  Q  R

3  1  2  3
1  S  T  U
2  V  W  X
3  Y  Z  _

Your task (should you choose to accept it)
Create two functions encode() and decode(), to encode and decode strings to and from cubic tap code.

Input
encode() takes a string of uppercase letters and spaces and outputs a string of dots and spaces. decode() takes a string of dots and spaces and outputs a string of uppercase letters and spaces. All inputs will be valid.

Examples
encode("N") => ".. .. .."
encode("TEST") => ".. . ... .. .. . . . ... .. . ..."
encode("HELLO WORLD") => ".. ... . .. .. . ... . .. ... . .. ... .. .. ... ... ... .. .. ... ... .. .. ... ... .. ... . .. . .. ."

decode(".. .. ..") => "N"
decode(".. . ... .. .. . . . ... .. . ...") => "TEST"
decode(".. ... . .. .. . ... . .. ... . .. ... .. .. ... ... ... .. .. ... ... .. .. ... ... .. ... . .. . .. .") => "HELLO WORLD"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static const int CUBEP[256][3] = {
	[' '] = { 3, 3, 3 },
	['A'] = { 1, 1, 1 },
	['B'] = { 2, 1, 1 },
	['C'] = { 3, 1, 1 },
	['D'] = { 1, 2, 1 },
	['E'] = { 2, 2, 1 },
	['F'] = { 3, 2, 1 },
	['G'] = { 1, 3, 1 },
	['H'] = { 2, 3, 1 },
	['I'] = { 3, 3, 1 },
	['J'] = { 1, 1, 2 },
	['K'] = { 2, 1, 2 },
	['L'] = { 3, 1, 2 },
	['M'] = { 1, 2, 2 },
	['N'] = { 2, 2, 2 },
	['O'] = { 3, 2, 2 },
	['P'] = { 1, 3, 2 },
	['Q'] = { 2, 3, 2 },
	['R'] = { 3, 3, 2 },
	['S'] = { 1, 1, 3 },
	['T'] = { 2, 1, 3 },
	['U'] = { 3, 1, 3 },
	['V'] = { 1, 2, 3 },
	['W'] = { 2, 2, 3 },
	['X'] = { 3, 2, 3 },
	['Y'] = { 1, 3, 3 },
	['Z'] = { 2, 3, 3 },
};

static const char CUBES[3][3][4] = {
	{ "ABC", "DEF", "GHI" },
	{ "JKL", "MNO", "PQR" },
	{ "STU", "VWX", "YZ " },
};

void
encode(const char *src, char *dst)
{
	const int *pos;
	char *dst0;
	int idx0, idx1;

	for (dst0 = dst; *src; src++) {
		pos = CUBEP[*src & 0xff];
		if (!pos[0])
			continue;

		for (idx0 = 0; idx0 < 3; idx0++) {
			for (idx1 = 0; idx1 < pos[idx0]; idx1++)
				*dst++ = '.';
			*dst++ = ' ';
		}
	}

	if (dst0 != dst)
		dst--;
	*dst = '\0';
}

int
decode(const char *src, char *dst)
{
	size_t pos[3];
	size_t npos;
	size_t idx;

	memset(pos, 0, sizeof(pos));
	npos = 0;
	do {
		if (*src && !isspace(*src)) {
			pos[npos] += 1;
		} else if (++npos >= 3) {
			for (idx = 0; idx < 3; idx++) {
				if (!pos[idx] || pos[idx] > 4)
					return -1;
				if (idx > 0 && pos[idx] > 3)
					return -1;

				pos[idx] -= 1;
			}

			*dst++ = CUBES[pos[2]][pos[1]][pos[0]];

			memset(pos, 0, sizeof(pos));
			npos = 0;
		}
	} while (*src++);

	*dst = '\0';
	return 0;
}

void
test(int op, const char *src, const char *res)
{
	char dst[128];

	if (op == 'E')
		encode(src, dst);
	else
		decode(src, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test('E', "N", ".. .. ..");
	test('E', "TEST", ".. . ... .. .. . . . ... .. . ...");
	test('E', "HELLO WORLD", ".. ... . .. .. . ... . .. ... . .. ... .. .. ... ... ... .. .. ... ... .. .. ... ... .. ... . .. . .. .");

	test('D', ".. .. ..", "N");
	test('D', ".. . ... .. .. . . . ... .. . ...", "TEST");
	test('D', ".. ... . .. .. . ... . .. ... . .. ... .. .. ... ... ... .. .. ... ... .. .. ... ... .. ... . .. . .. .", "HELLO WORLD");

	return 0;
}
