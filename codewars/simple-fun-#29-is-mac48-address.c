/*

Task

A media access control address (MAC address) is a unique identifier assigned to network interfaces for communications on the physical network segment.

The standard (IEEE 802) format for printing MAC-48 addresses in human-friendly form is six groups of two hexadecimal digits (0 to 9 or A to F), separated by hyphens (e.g. 01-23-45-67-89-AB).

Example

For inputString = "00-1B-63-84-45-E6", the output should be true;

For inputString = "Z1-1B-63-84-45-E6", the output should be false;

For inputString = "not a MAC-48 address", the output should be false.

Input/Output

[input] string inputString

[output] a boolean value

true if inputString corresponds to MAC-48 address naming rules, false otherwise.

*/

#include <assert.h>
#include <stdio.h>

bool
ishex(int c)
{
	if ('a' <= c && c <= 'f')
		return true;
	if ('A' <= c && c <= 'F')
		return true;
	return '0' <= c && c <= '9';
}

bool
mac48(const char *s)
{
	static const char fmt[] = "xx-xx-xx-xx-xx-xx";
	size_t i;

	for (i = 0; s[i] && fmt[i]; i++) {
		switch (fmt[i]) {
		case 'x':
			if (!ishex(s[i]))
				return false;
			break;

		default:
			if (s[i] != fmt[i])
				return false;
			break;
		}
	}
	return s[i] == '\0';
}

int
main()
{
	assert(mac48("00-1B-63-84-45-E6") == true);
	assert(mac48("Z1-1B-63-84-45-E6") == false);
	assert(mac48("not a MAC-48 address") == false);
	assert(mac48("FF-FF-FF-FF-FF-FF") == true);
	assert(mac48("00-00-00-00-00-00") == true);
	assert(mac48("G0-00-00-00-00-00") == false);
	assert(mac48("12-34-56-78-9A-BC") == true);
	assert(mac48("02-03-04-05-06-07-") == false);
	return 0;
}
