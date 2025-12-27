/*

One-time pads and stream ciphers add random noise or pseudo-random noise to plain-text producing a cipher-text that is either random or appears at least under close inspection to be random.

One weakness with both of these is the necessary synchronization required between the sender and receiver. To continue sending messages, both parties must know where they left off and where to continue.

An alternative to such techniques are block-encryption algorithms. Here, the plain-text is broken into equally sized blocks, and the key is used to jumble the information in each block so that it appears, at least at first glance, to be random. Performing this on each of the blocks of the plain-text produces the cipher-text. For this to work, however, the process of jumbling must be reversible by the receiver.

The first encryption algorithms were block encryption, where each "block" was one letter. The Atbash encryption algorithm was used to encrypt politically sensitive details in the book of Jeremiah whereby the first letter of the Hebrew alphabet was swapped with the last, the second with the second-last, and so on. As short vowels such as 'a' and 'e' in 'bat' and 'bet' are not written, the encrypted word could still be pronounced. Thus, 'BBL' ('Babel' or Babylon) is encrypted as 'ShShCh' which is pronounced as 'Sheshach'; and 'KShDiM' ('Kashedime' or Chaldeans) is encrypted as 'LVKMI', which is pronounced as 'Lev-Kamai'. This does not work so well in English, as all vowels are explicitly written, so "ALICE" and "BOB" are encrypted as the unpronounceable words "ZORXV" and "YLY".

Julius Caesar used a simpler single-letter encryption algorithm whereby each letter is replaced that letter three positions prior to it:

ABCDEFGHIKLMNOPQRSTVXYZ
XYZABCDEFGHIKLMNOPQRSTV

Thus, SENATVSPOPVLVSQVEROMANVS would be translated as PBKXQRPMLMRHRPNRBOLIZKRP.

While at first glance, this appears random, on closer inspection, you will see that R appears five times; P four times; and A, C, D, E, F, G, S, T, V and Y never appear. With 24 random letters from an alphabet of length 23, such a skewed distribution would be exceptionally unlikely. This lack of randomness can thus be used to determine the plain-text from the cipher-text.

In English, the letter 'e' is the most common character, so if you were to inspect the cipher-text of such substitution ciphers, whichever letter appears most often is likely encrypting the letter 'e'. Next, look at all pairs of letters preceding whichever letter is substituted for 'e' and find that pair 'AB' such that 'AB' appears quite frequently, but 'BA' is seldom if not non-existent. With almost 100% certainty, these letters represent 'th', respectively. In this manner, the lack of randomness can be used to deduce the encryption algorithm.

Thus, block encrypting one letter at a time is does not lead to very secure cipher-texts as the non-random nature of the language being spoken translates into non-randomness in the cipher-text.

The Vigenère encryption algorithm devised in the sixteenth century extended on the Caesar cipher by using a keyword to generate a larger block, where each block could be translated independent of the others; however, each letter was still then substituted in the a manner similar to that of the Caesar cipher.

In the mid nineteenth century, the Playfair encryption algorithm used a block size of two letters where the encryption where the encryption of each letter depended on what appeared in the second location. This, however, too was subject to cryptanalysis, as "TH" had a 50-50 chance of being encrypted as a pair, so whatever "TH" was encrypted to would still appear relatively often, but whatever "HT" would encrypt to would seldom appear.

All of these algorithms can be described as using look-up tables, as they can be implemented using a table where encryption of each letter can be deduced from the entry in a table.

Today, block encryption algorithms use blocks of binary numbers (often 64 bits in size, but more recently 128 bits) and use either look-up tables or invertible mathematical operations such as addition, xor and multiplication under certain circumstances. DES, triple-DES and IDEA are three 64-bit block encryption algorithms and AES is a 128-bit block encryption algorithm. By applying these algorithms to each group of 64 bits or 128 bits in the plain-text, this produces a cipher-text where each block appears to be essentially random, but where the inverse of each of the algorithms can be used to retrieve the plain text. The word essential here is critical, as the encrypted blocks are not truly random and aspects of the non-random nature can still, at least in some cases, be used to decrypt the messages.

One straight-forward block encryption algorithm is the patent-free Corrected Block Tiny Encryption Algorith (also known as XXTEA). Source code for these algorithms is available on the Wikipedia pages.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#define DELTA 0x9e3779b9
#define MX (((z >> 5 ^ y << 2) + (y >> 3 ^ z << 4)) ^ ((sum ^ y) + (key[(p & 3) ^ e] ^ z)))

/* https://en.wikipedia.org/wiki/XXTEA */
void
btea(uint32_t *v, int n, uint32_t const key[4])
{
	uint32_t y, z, sum;
	unsigned rounds, e;
	int p;

	if (n > 1) { /* Coding Part */
		rounds = 6 + (52 / n);
		sum = 0;
		z = v[n - 1];
		do {
			sum += DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p < n - 1; p++) {
				y = v[p + 1];
				v[p] += MX;
				z = v[p];
			}
			y = v[0];
			v[n - 1] += MX;
			z = v[n - 1];
		} while (--rounds);
	} else if (n < -1) { /* Decoding Part */
		n = -n;
		rounds = 6 + (52 / n);
		sum = rounds * DELTA;
		y = v[0];
		do {
			e = (sum >> 2) & 3;
			for (p = n - 1; p > 0; p--) {
				z = v[p - 1];
				v[p] -= MX;
				y = v[p];
			}
			z = v[n - 1];
			v[0] -= MX;
			y = v[0];
			sum -= DELTA;
		} while (--rounds);
	}
}

int
main(void)
{
	uint32_t in[128];
	uint32_t out[128];
	uint32_t key[4];
	int size;
	size_t i;

	srand(time(NULL));

	for (i = 0; i < nelem(in); i++)
		in[i] = rand();
	for (i = 0; i < nelem(key); i++)
		key[i] = rand();
	memcpy(out, in, sizeof(in));

	size = nelem(out);
	btea(out, size, key);
	btea(out, -size, key);

	assert(!memcmp(in, out, sizeof(out)));

	return 0;
}
