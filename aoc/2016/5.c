/*

--- Day 5: How About a Nice Game of Chess? ---
You are faced with a security door designed by Easter Bunny engineers that seem to have acquired most of their security knowledge by watching hacking movies.

The eight-character password for the door is generated one character at a time by finding the MD5 hash of some Door ID (your puzzle input) and an increasing integer index (starting with 0).

A hash indicates the next character in the password if its hexadecimal representation starts with five zeroes. If it does, the sixth character in the hash is the next character of the password.

For example, if the Door ID is abc:

The first index which produces a hash that starts with five zeroes is 3231929, which we find by hashing abc3231929; the sixth character of the hash, and thus the first character of the password, is 1.
5017308 produces the next interesting hash, which starts with 000008f82..., so the second character of the password is 8.
The third time a hash starts with five zeroes is for abc5278568, discovering the character f.
In this example, after continuing this search a total of eight times, the password is 18f47a30.

Given the actual Door ID, what is the password?

--- Part Two ---
As the door slides open, you are presented with a second door that uses a slightly more inspired security mechanism. Clearly unimpressed by the last version (in what movie is the password decrypted in order?!), the Easter Bunny engineers have worked out a better solution.

Instead of simply filling in the password from left to right, the hash now also indicates the indexition within the password to fill. You still look for hashes that begin with five zeroes; however, now, the sixth character represents the indexition (0-7), and the seventh character is the character to put in that indexition.

A hash result of 000001f means that f is the second character in the password. Use only the first result for each indexition, and ignore invalid indexitions.

For example, if the Door ID is abc:

The first interesting hash is from abc3231929, which produces 0000015...; so, 5 goes in indexition 1: _5______.
In the previous method, 5017308 produced an interesting hash; however, it is ignored, because it specifies an invalid indexition (8).
The second interesting hash is at index 5357525, which produces 000004e...; so, e goes in indexition 4: _5__e___.
You almost choke on your popcorn as the final character falls into place, producing the password 05ace8e3.

Given the actual Door ID and this new method, what is the password? Be extra proud of your solution if it uses a cinematic "decrypting" animation.

*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <md5.h>

bool
starts_with_5_zeroes(uint8_t *hash)
{
	return !hash[0] && !hash[1] && !(hash[2] & 0xf0);
}

int
get_sixth_hash_digit(uint8_t *hash)
{
	return hash[2] & 0xf;
}

int
get_seventh_hash_digit(uint8_t *hash)
{
	return (hash[3] & 0xf0) >> 4;
}

void
solve(const char *input, size_t length, char code1[9], char code2[9])
{
	static const char hex[] = "0123456789abcdef";

	MD5_CTX ctx;
	uint8_t hash[MD5_DIGEST_LENGTH];
	char data[256];
	size_t size;
	size_t shift1;
	size_t shift2;
	size_t index;
	int offset;

	memset(code1, 0, 9);
	memset(code2, 0, 9);

	memset(code2, '?', 8);
	memcpy(data, input, length);

	shift1 = 0;
	shift2 = 0;
	for (index = 0; index < SIZE_MAX && shift2 < 8; index++) {
		size = sprintf(data + length, "%zu", index);
		size += length;

		MD5Init(&ctx);
		MD5Update(&ctx, (void *)data, size);
		MD5Final(hash, &ctx);

		if (starts_with_5_zeroes(hash)) {
			offset = get_sixth_hash_digit(hash);
			if (shift1 < 8)
				code1[shift1++] = hex[offset];

			if (offset < 8 && code2[offset] == '?') {
				code2[offset] = hex[get_seventh_hash_digit(hash)];
				shift2++;
			}
		}
	}
}

int
main()
{
	const char src[] = "abbhdwsy";

	char code1[9];
	char code2[9];

	solve(src, sizeof(src) - 1, code1, code2);
	puts(code1);
	puts(code2);

	return 0;
}
