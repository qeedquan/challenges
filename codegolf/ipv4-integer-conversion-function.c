/*

Write the shortest function to convert an IP address into it's integer representation and output it as an integer.

To change an IPv4 address to it's integer representation, the following calculation is required:

Break the IP address into it's four octets.
(Octet1 * 16777216) + (Octet2 * 65536) + (Octet3 * 256) + (Octet4)
Sample Input

192.168.1.1           10.10.104.36           8.8.8.8
Sample Output

3232235777            168454180              134744072

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long ulong;

ulong
ipv4toint(const char *s)
{
	ulong p[4];

	if (sscanf(s, "%lu.%lu.%lu.%lu", p, p + 1, p + 2, p + 3) != 4)
		return 0;
	return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

int
main(void)
{
	assert(ipv4toint("192.168.1.1") == 3232235777);
	assert(ipv4toint("10.10.104.36") == 168454180);
	assert(ipv4toint("8.8.8.8") == 134744072);
	return 0;
}
