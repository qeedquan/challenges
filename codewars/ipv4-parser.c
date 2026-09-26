/*

Problem Statement
Write a function that takes two string parameters, an IP (v4) address and a subnet mask, and returns two strings: the network block, and the host identifier.

The function does not need to support CIDR notation.

Description
A single IP address with subnet mask actually specifies several addresses: a network block, and a host identifier, and a broadcast address. These addresses can be calculated using a bitwise AND operation on each bit.

(The broadcast address is not used in this kata.)

Example
A computer on a simple home network might have the following IP and subnet mask:

IP: 192.168.2.1
Subnet: 255.255.255.0
(CIDR Notation: 192.168.2.1 /24)
In this example, the network block is: 192.168.2.0. And the host identifier is: 0.0.0.1.

bitwise AND
To calculate the network block and host identifier the bits in each octet are ANDed together. When the result of the AND operation is '1', the bit specifies a network address (instead of a host address).

To compare the first octet in our example above, convert both the numbers to binary and perform an AND operation on each bit:

11000000 (192 in binary)
11111111 (255 in binary)
--------------------------- (AND each bit)
11000000 (192 in binary)
So in the first octet, '192' is part of the network address. The host identifier is simply '0'.

For more information see the Subnetwork article on Wikipedia.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

vlong
ipstoi(const char *ip)
{
	vlong addr[4];

	if (sscanf(ip, "%lld.%lld.%lld.%lld", addr, addr + 1, addr + 2, addr + 3) != 4)
		return -1;
	return (addr[0] << 24) | (addr[1] << 16) | (addr[2] << 8) | addr[3];
}

void
ipitoa(vlong ip, char *buf)
{
	sprintf(buf, "%lld.%lld.%lld.%lld", (ip >> 24) & 0xff, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
}

int
parsenet(const char *ip, const char *mask, char *net, char *host)
{
	vlong ipaddr, maskaddr;

	ipaddr = ipstoi(ip);
	maskaddr = ipstoi(mask);
	if (ipaddr < 0 || maskaddr < 0)
		return -1;

	ipitoa(ipaddr & maskaddr, net);
	ipitoa(ipaddr - (ipaddr & maskaddr), host);
	return 0;
}

void
test(const char *ip, const char *mask, const char *rnet, const char *rhost)
{
	char net[32];
	char host[32];

	assert(parsenet(ip, mask, net, host) >= 0);
	printf("(%s, %s)\n", net, host);
	assert(!strcmp(net, rnet));
	assert(!strcmp(host, rhost));
}

int
main()
{
	test("192.168.2.1", "255.255.255.0", "192.168.2.0", "0.0.0.1");
	test("192.168.50.1", "255.255.255.0", "192.168.50.0", "0.0.0.1");
	test("192.168.50.129", "255.255.255.192", "192.168.50.128", "0.0.0.1");
	test("192.168.50.153", "255.255.255.225", "192.168.50.129", "0.0.0.24");
	test("65.196.188.53", "255.255.240.0", "65.196.176.0", "0.0.12.53");
	test("65.196.188.53", "0.0.0.0", "0.0.0.0", "65.196.188.53");

	return 0;
}
