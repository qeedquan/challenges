/*

Your network scanning tool is annoyingly picky about input, and immediately crashes if you feed it an IPv4 address that contains improper characters or isn't properly formatted.

An IPv4 address is a 32-bit numeric address written as four numbers separated by periods. Each number can be zero to 255.

We need to write a tool to pre-validate the input to avoid those crashes, and our specific tool is picky: A valid format will look like a.b.c.d where a, b, c and d:

Can be a 0 or a natural number with no leading zeros.
Should be between 0 - 255 (inclusive).
Should not contain special symbols like +, -, ,, and others.
Should be decimal (base 10)

Input: A string

Output: Truthy or Falsey value (arbitrary values also accepted)

Test Cases:

Input            |  Output  |  Reason
                 |          |
- 1.160.10.240   |  true    |
- 192.001.32.47  |  false   |  (leading zeros present)
- 1.2.3.         |  false   |  (only three digits)
- 1.2.3          |  false   |  (only three digits)
- 0.00.10.255    |  false   |  (leading zeros present)
- 1.2.$.4        |  false   |  (only three digits and a special symbol present)
- 255.160.0.34   |  true    |
- .1.1.1         |  false   |  (only three digits)
- 1..1.1.1       |  false   |  (more than three periods)
- 1.1.1.-0       |  false   |  (special symbol present)
- .1.1.+1        |  false   |  (special symbol present)
- 1 1 1 1        |  false   |  (no periods)
- 1              |  false   |  (only one digit)
- 10.300.4.0     |  false   |  (value over 255)
- 10.4F.10.99    |  false   |  (invalid characters)
- fruit loops    |  false   |  (umm...)
- 1.2.3.4.5      |  false   |  (too many periods/numbers)
- 0.0.0.0        |  true    |
- 0.0 0.0.       |  false   |  (periods misplaced)
- 1.23..4        |  false   |  (a typo of 1.2.3.4)
- 1:1:1:1:1:1:1:1|  false   |  (an IPv6 address, not IPv4)

This is code-golf, so fewest bytes will win!

Note for the users - if anyone wants to add some test-cases, they're welcomed (by suggesting an edit).

*/

#include <assert.h>
#include <stdbool.h>
#include <arpa/inet.h>

bool
validip(const char *s)
{
	struct in_addr in4;
	return inet_pton(AF_INET, s, &in4) != 0;
}

int
main(void)
{
	assert(validip("1.160.10.240") == true);
	assert(validip("192.001.32.47") == false);
	assert(validip("1.2.3.") == false);
	assert(validip("1.2.3") == false);
	assert(validip("0.00.10.255") == false);
	assert(validip("1.2.$.4") == false);
	assert(validip("255.160.0.34") == true);
	assert(validip(".1.1.1") == false);
	assert(validip("1..1.1.1") == false);
	assert(validip("1.1.1.-0") == false);
	assert(validip(".1.1.+1") == false);
	assert(validip("1 1 1 1") == false);
	assert(validip("1") == false);
	assert(validip("10.300.4.0") == false);
	assert(validip("10.4F.10.99") == false);
	assert(validip("fruit loops") == false);
	assert(validip("1.2.3.4.5") == false);
	assert(validip("0.0.0.0") == true);
	assert(validip("0.0.0.0.") == false);
	assert(validip("1.23..4") == false);
	assert(validip("1:1:1:1:1:1:1:1") == false);

	return 0;
}
