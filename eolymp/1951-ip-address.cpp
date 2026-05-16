/*

In order to access the Internet, each computer is assigned an IP-address.
It consists of four integers in the range from 0 to 255 separated by dots.
The following three lines show three valid IP-addresses:

127.0.0.0

192.168.0.01

255.00.255.255

Write a program that determines whether the given string is a valid IP-address.

Input
The input consists of a string of no more than 15 characters, containing digits and exactly three dots.

Output
If the string is a valid IP-address, output 1; otherwise, output 0.

Examples
Input #1
127.0.0.1
Answer #1
1

*/

#include <cassert>
#include <cstdio>

typedef unsigned int uint;

int valid(const char *ip)
{
	uint a, b, c, d;
	if (sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d) != 4)
		return 0;
	if (a > 255 || b > 255 || c > 255 || d > 255)
		return 0;
	return 1;
}

int main()
{
	assert(valid("127.0.0.1") == 1);
	assert(valid("192.168.0.01") == 1);
	assert(valid("255.00.255.255") == 1);
	assert(valid("255.255.255.255") == 1);
	assert(valid("127.0.0.-41") == 0);
	assert(valid("-12.0.0.41") == 0);

	return 0;
}
