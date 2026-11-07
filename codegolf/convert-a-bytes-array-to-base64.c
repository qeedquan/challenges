/*

Your mission is to write a function/program that converts an array of bytes (i.e: an array of integers from 0 to 255), to base64.

Using built-in base64 encoders is not allowed.

The required base64 implementation is RFC 2045. (using "+", "/", and mandatory padding with "=")

Shortest code (in bytes) wins!

Example:
Input (int array): [99, 97, 102, 195, 169]

Output (string): Y2Fmw6k=

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

size_t
b64enc(uint8_t *dst, const uint8_t *src, size_t srclen)
{
	return EVP_EncodeBlock(dst, src, srclen);
}

void
test(const uint8_t *src, size_t srclen, const char *expected)
{
	uint8_t buf[32];
	size_t len;

	len = b64enc(buf, src, srclen);
	printf("%s\n", buf);
	assert(len == strlen(expected));
	assert(!memcmp(buf, expected, len + 1));
}

int
main()
{
	const uint8_t src[] = {99, 97, 102, 195, 169};

	test(src, sizeof(src), "Y2Fmw6k=");

	return 0;
}
