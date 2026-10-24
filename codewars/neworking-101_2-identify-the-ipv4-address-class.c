/*

Introduction
An IPv4 address is made up of 32 bits. The bits are divided into four sections called octets (groups of eight). Each octet can have a number in the range 0 to 255 (unsigned 8-bit integers).

All IPv4 addresses belong to an Address Class. There are five different address classes (A, B, C, D and E). It's the first (left most) octet that tells us which class the address belongs to.

Class:  Identifier:  Ranges:
---------------------------------------
 A      0-------     00000000-01111111
 B      10------     10000000-10111111
 C      110-----     11000000-11011111
 D      1110----     11100000-11101111
 E      1111----     11110000-11111111
The bits in the Identifiers column above is used to determine the class of an address. So, if an address starts with the bits that are visible in the identifier column, it belongs to the class in the Class column on the same row.

If we look at the address 192.168.0.1 as an example:

The first octet is 192, which in binary is 11000000.
The first 3 bits of this octet is set to 110 which means that it is a Class C address.
The Assignment
Your task is to implement a function char ipv4_address_class(const char *ipv4_addr) which takes in an IPv4 address ipv4_addr and returns a character char (A, B, C, D, or E) representing the address class.

Testing
The tests will challenge your function with addresses in the full 32-bit range (0.0.0.0 - 255.255.255.255) and nothing else.

Links
Check out these links for more information:

https://en.wikipedia.org/wiki/Classful_network
https://en.wikipedia.org/wiki/Binary_number

*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
netclass(const char *addr)
{
	static const struct net {
		int ident;
		int range;
	} nets[] = {
		{ 'A', 127 },
		{ 'B', 191 },
		{ 'C', 223 },
		{ 'D', 239 },
		{ 'E', 255 },
	};

	const struct net *net;
	size_t i;
	int ip[4];

	if (sscanf(addr, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]) != 4)
		return -1;

	for (i = 0; i < 4; i++) {
		if (ip[i] < 0 || ip[i] > 255)
			return -1;
	}

	for (i = 0; i < nelem(nets); i++) {
		net = nets + i;
		if (ip[0] <= net->range)
			return net->ident;
	}
	return -1;
}

int
main()
{
	assert(netclass("1.1.1.1") == 'A');
	assert(netclass("172.66.43.71") == 'B');
	assert(netclass("192.168.0.1") == 'C');
	assert(netclass("224.0.0.227") == 'D');
	assert(netclass("242.0.0.227") == 'E');
	return 0;
}
