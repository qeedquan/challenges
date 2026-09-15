/*

SHA-1 is arguably the most widely used hash algorithm in the world at the moment. However, due to speculation that the hash algorithm will be broken soon, it will be eventually phased out (It has been broken; see https://www.theverge.com/2017/2/23/14712118/google-sha1-collision-broken-web-encryption-shattered). Nonetheless, it is definitely worth learning since it is extremely similar to its successor, SHA-2, which is still believed to be secure. If you would like to learn more about SHA-1, I'd recommend scanning the Wikipedia page but even better is this lecture on how SHA-1 works.

Here is a general outline of the algorithm:

Initial constants/variables:

H0 = [0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0], these will serve as the initial hash values, also called registers. They will also be reffered to individually as A, B, C, D, and E, respectively.

K = [0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6], these will serve as constants used in the compression phase

The Four Functions:

F1(B, C, D) = (B & C) | ((~B) & D)
F2(B, C, D) = B ^ C ^ D
F3(B, C, D) = (B & C) | (B & D) | (C & D)
F4(B, C, D) = B ^ C ^ D
Note: & is the bitwise AND operator, | is the bitwise OR operator, ^ is the bitwise XOR (exclusive OR) operator, and ~ is the bitwise NOT operator.

Pre-Processing:

Given an input M, determine its length in bits.
Break the input M into 512-bit chunks, maintaining the original order.
At the end of the last chunk, add a 1-bit (unless the chunk is already 512-bits, in which case start a new chunk with a 1 bit).
Pad this chunk with enough 0 bits so that the chunk has exactly 64 bits left at the end. In other words, fill the chunk until it is 448 bits long.
Complete the last chunk by appending a 64-bit representation of the original bit length measured at the beginning.
Compression: Repeat the following steps for each chunk in order:

Split the current chunk into 16 32-bit words. However, you will need a total of 80 words. Compute the following 64 words using the following formula where leftrotate is a function that rotates the bits of its first argument by an amount specified in its second: w[i] = leftrotate(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1)

Save the current values of H0 aka A, B, C, D, and E.

The compression function consists of 80 rounds, which is split into four equal 20-round stages. A, B, C, D, and E are fed into the compression function and are modified. Parts of the compression function depend on what stage it is.

At the end of 80 rounds, add the new A, B, C, D, and E values to their values from the start of the 80 rounds, applying modulo 2^32. The following is a depiction of a round in the compression function:

https://upload.wikimedia.org/wikipedia/commons/thumb/e/e2/SHA-1.svg/365px-SHA-1.svg.png

The F represents one of the F functions (F1 for stage 1, F2 for stage 2, etc.), the <<<n represents a left bit rotation by n bits, the red crossed squares represent addition modulo 2^32, Kt represents the K constant for the t'th stage, and Wt stands for the Wth word of the chunk.

Completion:

Once every chunk has been processed, concatenate the bits of A, B, C, D, and E together and the resulting value is the hash value. You can also convert the 5 registers into hex strings and concatenate those, since hash values are often given in hex string format.
Implement this without cheating! No using built-in hash libraries/modules! Assume that message input is always of type bytes, and return bytes too.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// ported from 9front
typedef struct DigestState DigestState;
typedef struct DigestState SHA1state;

struct DigestState {
	size_t len;
	union {
		uint32_t state[16];
		uint64_t bstate[8];
	};
	uint8_t buf[256];
	int blen;
	char malloced;
	char seeded;
};

enum {
	SHA1dlen = 20, /* SHA digest length */
};

void
encode(uint8_t *output, uint32_t *input, size_t len)
{
	uint32_t x;
	uint8_t *e;

	for (e = output + len; output < e;) {
		x = *input++;
		*output++ = x >> 24;
		*output++ = x >> 16;
		*output++ = x >> 8;
		*output++ = x;
	}
}

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define F0(x, y, z) (0x5a827999 + ((z) ^ ((x) & ((y) ^ (z)))))
#define F1(x, y, z) (0x6ed9eba1 + ((x) ^ (y) ^ (z)))
#define F2(x, y, z) (0x8f1bbcdc + (((x) & (y)) | (((x) | (y)) & (z))))
#define F3(x, y, z) (0xca62c1d6 + ((x) ^ (y) ^ (z)))

#define STEP(a, b, c, d, e, f, i)                                                                     \
	if (i < 16) {                                                                                 \
		w[i] = p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3];                                    \
		p += 4;                                                                               \
	} else {                                                                                      \
		uint32_t x = w[(i - 3) & 15] ^ w[(i - 8) & 15] ^ w[(i - 14) & 15] ^ w[(i - 16) & 15]; \
		w[i & 15] = ROTL(x, 1);                                                               \
	}                                                                                             \
	e += ROTL(a, 5) + w[i & 15] + f(b, c, d);                                                     \
	b = ROTL(b, 30);

void
_sha1block(uint8_t *p, size_t len, uint32_t *s)
{
	uint32_t w[16], a, b, c, d, e;
	uint8_t *end;

	/* at this point, we have a multiple of 64 bytes */
	for (end = p + len; p < end;) {
		a = s[0];
		b = s[1];
		c = s[2];
		d = s[3];
		e = s[4];

		STEP(a, b, c, d, e, F0, 0);
		STEP(e, a, b, c, d, F0, 1);
		STEP(d, e, a, b, c, F0, 2);
		STEP(c, d, e, a, b, F0, 3);
		STEP(b, c, d, e, a, F0, 4);

		STEP(a, b, c, d, e, F0, 5);
		STEP(e, a, b, c, d, F0, 6);
		STEP(d, e, a, b, c, F0, 7);
		STEP(c, d, e, a, b, F0, 8);
		STEP(b, c, d, e, a, F0, 9);

		STEP(a, b, c, d, e, F0, 10);
		STEP(e, a, b, c, d, F0, 11);
		STEP(d, e, a, b, c, F0, 12);
		STEP(c, d, e, a, b, F0, 13);
		STEP(b, c, d, e, a, F0, 14);

		STEP(a, b, c, d, e, F0, 15);
		STEP(e, a, b, c, d, F0, 16);
		STEP(d, e, a, b, c, F0, 17);
		STEP(c, d, e, a, b, F0, 18);
		STEP(b, c, d, e, a, F0, 19);

		STEP(a, b, c, d, e, F1, 20);
		STEP(e, a, b, c, d, F1, 21);
		STEP(d, e, a, b, c, F1, 22);
		STEP(c, d, e, a, b, F1, 23);
		STEP(b, c, d, e, a, F1, 24);

		STEP(a, b, c, d, e, F1, 25);
		STEP(e, a, b, c, d, F1, 26);
		STEP(d, e, a, b, c, F1, 27);
		STEP(c, d, e, a, b, F1, 28);
		STEP(b, c, d, e, a, F1, 29);

		STEP(a, b, c, d, e, F1, 30);
		STEP(e, a, b, c, d, F1, 31);
		STEP(d, e, a, b, c, F1, 32);
		STEP(c, d, e, a, b, F1, 33);
		STEP(b, c, d, e, a, F1, 34);

		STEP(a, b, c, d, e, F1, 35);
		STEP(e, a, b, c, d, F1, 36);
		STEP(d, e, a, b, c, F1, 37);
		STEP(c, d, e, a, b, F1, 38);
		STEP(b, c, d, e, a, F1, 39);

		STEP(a, b, c, d, e, F2, 40);
		STEP(e, a, b, c, d, F2, 41);
		STEP(d, e, a, b, c, F2, 42);
		STEP(c, d, e, a, b, F2, 43);
		STEP(b, c, d, e, a, F2, 44);

		STEP(a, b, c, d, e, F2, 45);
		STEP(e, a, b, c, d, F2, 46);
		STEP(d, e, a, b, c, F2, 47);
		STEP(c, d, e, a, b, F2, 48);
		STEP(b, c, d, e, a, F2, 49);

		STEP(a, b, c, d, e, F2, 50);
		STEP(e, a, b, c, d, F2, 51);
		STEP(d, e, a, b, c, F2, 52);
		STEP(c, d, e, a, b, F2, 53);
		STEP(b, c, d, e, a, F2, 54);

		STEP(a, b, c, d, e, F2, 55);
		STEP(e, a, b, c, d, F2, 56);
		STEP(d, e, a, b, c, F2, 57);
		STEP(c, d, e, a, b, F2, 58);
		STEP(b, c, d, e, a, F2, 59);

		STEP(a, b, c, d, e, F3, 60);
		STEP(e, a, b, c, d, F3, 61);
		STEP(d, e, a, b, c, F3, 62);
		STEP(c, d, e, a, b, F3, 63);
		STEP(b, c, d, e, a, F3, 64);

		STEP(a, b, c, d, e, F3, 65);
		STEP(e, a, b, c, d, F3, 66);
		STEP(d, e, a, b, c, F3, 67);
		STEP(c, d, e, a, b, F3, 68);
		STEP(b, c, d, e, a, F3, 69);

		STEP(a, b, c, d, e, F3, 70);
		STEP(e, a, b, c, d, F3, 71);
		STEP(d, e, a, b, c, F3, 72);
		STEP(c, d, e, a, b, F3, 73);
		STEP(b, c, d, e, a, F3, 74);

		STEP(a, b, c, d, e, F3, 75);
		STEP(e, a, b, c, d, F3, 76);
		STEP(d, e, a, b, c, F3, 77);
		STEP(c, d, e, a, b, F3, 78);
		STEP(b, c, d, e, a, F3, 79);

		s[0] += a;
		s[1] += b;
		s[2] += c;
		s[3] += d;
		s[4] += e;
	}
}

/*
 *  we require len to be a multiple of 64 for all but
 *  the last call.  There must be room in the input buffer
 *  to pad.
 */
SHA1state *
sha1(uint8_t *p, size_t len, uint8_t *digest, SHA1state *s)
{
	uint8_t buf[128];
	uint32_t x[16];
	uint8_t *e;
	size_t i;

	if (s == NULL) {
		s = malloc(sizeof(*s));
		if (s == NULL)
			return NULL;
		memset(s, 0, sizeof(*s));
		s->malloced = 1;
	}

	if (s->seeded == 0) {
		/* seed the state, these constants would look nicer big-endian */
		s->state[0] = 0x67452301;
		s->state[1] = 0xefcdab89;
		s->state[2] = 0x98badcfe;
		s->state[3] = 0x10325476;
		s->state[4] = 0xc3d2e1f0;
		s->seeded = 1;
	}

	/* fill out the partial 64 byte block from previous calls */
	if (s->blen) {
		i = 64 - s->blen;
		if (len < i)
			i = len;
		memmove(s->buf + s->blen, p, i);
		len -= i;
		s->blen += i;
		p += i;
		if (s->blen == 64) {
			_sha1block(s->buf, s->blen, s->state);
			s->len += s->blen;
			s->blen = 0;
		}
	}

	/* do 64 byte blocks */
	i = len & ~0x3f;
	if (i) {
		_sha1block(p, i, s->state);
		s->len += i;
		len -= i;
		p += i;
	}

	/* save the left overs if not last call */
	if (digest == 0) {
		if (len) {
			memmove(s->buf, p, len);
			s->blen += len;
		}
		return s;
	}

	/*
	 *  this is the last time through, pad what's left with 0x80,
	 *  0's, and the input count to create a multiple of 64 bytes
	 */
	if (s->blen) {
		p = s->buf;
		len = s->blen;
	} else {
		memmove(buf, p, len);
		p = buf;
	}
	s->len += len;
	e = p + len;
	if (len < 56)
		i = 56 - len;
	else
		i = 120 - len;
	memset(e, 0, i);
	*e = 0x80;
	len += i;

	/* append the count */
	x[0] = s->len >> 29;
	x[1] = s->len << 3;
	encode(p + len, x, 8);

	/* digest the last part */
	_sha1block(p, len + 8, s->state);
	s->len += len + 8;

	/* return result and free state */
	encode(digest, s->state, SHA1dlen);
	if (s->malloced == 1)
		free(s);
	return NULL;
}

void
sum(FILE *fp)
{
	DigestState *s;
	uint8_t buf[8192];
	uint8_t md[SHA1dlen];
	size_t len;
	size_t i;

	s = sha1(NULL, 0, NULL, NULL);
	while ((len = fread(buf, 1, sizeof(buf), fp)) > 0)
		sha1(buf, len, NULL, s);
	sha1(NULL, 0, md, s);

	for (i = 0; i < SHA1dlen; i++)
		printf("%02x", md[i]);
	puts("");
}

int
main()
{
	sum(stdin);
	return 0;
}
