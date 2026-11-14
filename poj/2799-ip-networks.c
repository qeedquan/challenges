/*

Description

Alex is administrator of IP networks. His clients have a bunch of individual IP addresses and he decidedto group all those IP addresses into the smallest possible IP network.

Each IP address is a 4-byte number that is written byte-by-byte in a decimal dot-separated notation "byte0.byte1.byte2.byte3" (quotes are added for clarity). Each byte is written as a decimal number from0 to 255 (inclusive) without extra leading zeroes.

IP network is described by two 4-byte numbers - network address and network mask. Both networkaddress and network mask are written in the same notation as IP addresses.

In order to understand the meaning of network address and network mask you have to consider their binary representation. Binary representation of IP address, network address, and network mask consists of 32 bits: 8 bits for byte0 (most significant to least significant), followed by 8 bits for byte1, followed by 8 bits for byte2, and followed by 8 bits for byte3.

IP network contains a range of 2n IP addresses where 0 <= n <= 32. Network mask always has 32-n first bits set to one, and n last bits set to zero in its binary representation. Network address has arbitrary 32 - n first bits, and n last bits set to zero in its binary representation. IP network contains all IP addresses whose 32-n first bits are equal to 32-n first bits of network address with arbitrary n lastbits. We say that one IP network is smaller than the other IP network if it contains fewer IP addresses.

For example, IP network with network address 194.85.160.176 and network mask 255.255.255.248 contains 8 IP addresses from 194.85.160.176 to 194.85.160.183 (inclusive).
Input

The first line of the input contains a single integer number m (1 <= m <= 1000). The following m lines contain IP addresses, one address on a line. Each IP address may appear more than once in a case.
Output

Write to the output two lines that describe the smallest possible IP network that contains all IP addresses from this case. Write network address on the first line and network mask on the secondline.
Sample Input

3
194.85.160.177
194.85.160.183
194.85.160.178
Sample Output

194.85.160.176
255.255.255.248
Source

Northeastern Europe 2005

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uint32_t
ipv4(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
	return (a << 24) | (b << 16) | (c << 8) | d;
}

char *
ipv4s(uint32_t x, char *b)
{
	sprintf(b, "%" PRIu32 ".%" PRIu32 ".%" PRIu32 ".%" PRIu32,
	        (x >> 24) & 0xff,
	        (x >> 16) & 0xff,
	        (x >> 8) & 0xff,
	        x & 0xff);
	return b;
}

void
subnet(uint32_t *ip, size_t numip, uint32_t *addr, uint32_t *mask)
{
	uint32_t bits, lower, upper;
	size_t i;

	lower = 0xFFFFFFFFUL;
	upper = 0x00000000UL;
	for (i = 0; i < numip; i++) {
		if (ip[i] < lower)
			lower = ip[i];
		if (ip[i] > upper)
			upper = ip[i];
	}

	bits = 0x80000000UL;
	*mask = 0x00000000UL;
	while (bits && ((bits & (lower ^ upper)) == 0)) {
		*mask |= bits;
		bits >>= 1;
	}
	*addr = lower & *mask;
}

void
test(uint32_t *ip, size_t numip, uint32_t raddr, uint32_t rmask)
{
	uint32_t addr, mask;
	char str[32];

	subnet(ip, numip, &addr, &mask);

	printf("%s\n", ipv4s(addr, str));
	printf("%s\n", ipv4s(mask, str));
	printf("\n");

	assert(addr == raddr);
	assert(mask == rmask);
}

int
main(void)
{
	uint32_t ip[] = {
	    ipv4(194, 85, 160, 177),
	    ipv4(194, 85, 160, 183),
	    ipv4(194, 85, 160, 178),
	};

	test(ip, nelem(ip), ipv4(194, 85, 160, 176), ipv4(255, 255, 255, 248));

	return 0;
}
