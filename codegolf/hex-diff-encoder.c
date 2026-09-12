/*

Write a codec that

encodes list of bytes by calculating the difference between the values (0-255) of consecutive bytes, converting those differences to their hexadecimal representation, and outputting them as fixed 2-character hex values.
If a byte has a smaller value than the previous one, the difference should be treated as though the values "wrap around" using an overflow mechanism, as if subtracting within a circular range from 0 to 255.
decodes an encoded hexadecimal string back to its original form by reversing the encoding process
In both encoding and decoding, the first value is directly converted, while the following values are calculated as currentValue - previousValue

Encoding Example
Input: Hi!

Output: 4821B8

Explanation:

H has an ASCII value of 72 → 0x48.
The difference between i (ASCII 105) and H (ASCII 72) is 105 - 72 = 33 → 0x21.
The difference between ! (ASCII 33) and i (ASCII 105) is 33 - 105 = -72 + 256 = 184 → 0xB8.
Decoding Example
Input: 4821B8

Output: Hi!

Explanation:

The first 2 bytes 0x48 convert to decimal 72 → H.
The next 2 bytes 0x21 are 33 in decimal. Adding this to 72 gives 105 → i.
The last 2 bytes 0xB8 are 184 in decimal. Adding this to the previous value 105, accounting for the overflow, gives 105 + 184 = 289 mod 256 = 33 → !.

More examples
Hi! -> 4821B8
Hello World! -> 481D070003B1371803FAF8BD
aaaaaaaaaa -> 61000000000000000000
9876543210 -> 39FFFFFFFFFFFFFFFFFF
abcdefghijklmnopqrstuvwxyz -> 6101010101010101010101010101010101010101010101010101
ZYXWVUTSRQPONMLKJIHGFEDCBA -> 5AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

Rules
The encoding input can be a string, a list/array of bytes, or any type in the language that can represent text. The output must be a string
The decoding input must be a string. The output can be a string, a list/array of bytes, or any type in the language that can represent text
You can chose to implement the codec as two separate programs or as a single one, as long as both encoding and decoding are present
This is a code-golf challenge, shortest answer in bytes wins. If encoding and decoding are separated, the sum of the two will be added to calculate the score

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void
encode(const char *src, uint8_t *dst)
{
	char prev;

	for (prev = 0; *src; src++) {
		*dst++ = (*src - prev) & 0xff;
		prev = *src;
	}
}

void
decode(uint8_t *src, char *dst, size_t size)
{
	int prev;
	size_t i;

	prev = 0;
	for (i = 0; i < size; i++) {
		dst[i] = (src[i] + prev) & 0xff;
		prev = dst[i];
	}
	dst[i] = '\0';
}

void
test(const char *asc, void *hex, size_t size)
{
	uint8_t enc[32];
	char dec[32];

	encode(asc, enc);
	decode(enc, dec, size);
	assert(!memcmp(enc, hex, size));
	assert(!strcmp(asc, dec));
}

int
main()
{
	uint8_t hex1[] = {0x48, 0x21, 0xb8};
	uint8_t hex2[] = {0x48, 0x1D, 0x07, 0x00, 0x03, 0xB1, 0x37, 0x18, 0x03, 0xFA, 0xF8, 0xBD};
	uint8_t hex3[] = {0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	uint8_t hex4[] = {0x39, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	uint8_t hex5[] = {0x61, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01};
	uint8_t hex6[] = {0x5A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

	test("Hi!", hex1, sizeof(hex1));
	test("Hello World!", hex2, sizeof(hex2));
	test("aaaaaaaaaa", hex3, sizeof(hex3));
	test("9876543210", hex4, sizeof(hex4));
	test("abcdefghijklmnopqrstuvwxyz", hex5, sizeof(hex5));
	test("ZYXWVUTSRQPONMLKJIHGFEDCBA", hex6, sizeof(hex6));

	return 0;
}
