/*

Using a language of your choice write a program that takes a string as an input, and returns the string encrypted.

Algorithm:
You should assume that each character is always encoded in a byte and is ASCII-based. The extended ASCII codes are mapped to whatever is the default code page in use by the system.

You should encrypt the code in the following way: code of first character +1, code of second character +2, code of third character +3 .....

Extended ASCII codes are based on this table: http://www.asciitable.com/

Shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// https://naml.us/post/inverse-of-a-hash-function/
uint64_t
wanghash(uint64_t key)
{
	key = (~key) + (key << 21); // key = (key << 21) - key - 1;
	key = key ^ (key >> 24);
	key = (key + (key << 3)) + (key << 8); // key * 265
	key = key ^ (key >> 14);
	key = (key + (key << 2)) + (key << 4); // key * 21
	key = key ^ (key >> 28);
	key = key + (key << 31);
	return key;
}

uint64_t
wangunhash(uint64_t key)
{
	uint64_t tmp;

	// Invert key = key + (key << 31)
	tmp = key - (key << 31);
	key = key - (tmp << 31);

	// Invert key = key ^ (key >> 28)
	tmp = key ^ key >> 28;
	key = key ^ tmp >> 28;

	// Invert key *= 21
	key *= 14933078535860113213u;

	// Invert key = key ^ (key >> 14)
	tmp = key ^ key >> 14;
	tmp = key ^ tmp >> 14;
	tmp = key ^ tmp >> 14;
	key = key ^ tmp >> 14;

	// Invert key *= 265
	key *= 15244667743933553977u;

	// Invert key = key ^ (key >> 24)
	tmp = key ^ key >> 24;
	key = key ^ tmp >> 24;

	// Invert key = (~key) + (key << 21)
	tmp = ~key;
	tmp = ~(key - (tmp << 21));
	tmp = ~(key - (tmp << 21));
	key = ~(key - (tmp << 21));

	return key;
}

size_t
encrypt(const char *src, uint64_t *dst)
{
	size_t i;

	for (i = 0; src[i]; i++)
		dst[i] = wanghash(src[i]);
	return i;
}

size_t
decrypt(uint64_t *src, char *dst, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++)
		dst[i] = wangunhash(src[i]);
	dst[i] = '\0';
	return i;
}

void
test(const char *src)
{
	uint64_t tmp[128];
	char dst[128];
	size_t len;

	len = encrypt(src, tmp);
	decrypt(tmp, dst, len);
	printf("%s\n", dst);
	assert(!strcmp(src, dst));
}

int
main(void)
{
	test("Hello, World!");
	test("XYZWABCD");

	return 0;
}
