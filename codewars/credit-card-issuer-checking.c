/*

Given a credit card number we can determine who the issuer/vendor is with a few basic knowns.

Complete the function getIssuer() that will use the values shown below to determine the card issuer for a given card number. If the number cannot be matched then the function should return the string Unknown.

Where Issuer is defined with the following enum type.

enum Issuer {
  VISA = 'VISA',
  AMEX = 'AMEX',
  Mastercard = 'Mastercard',
  Discover = 'Discover',
  Unknown = 'Unknown',
}

Examples
getIssuer(4111111111111111) == "VISA"
getIssuer(4111111111111) == "VISA"
getIssuer(4012888888881881) == "VISA"
getIssuer(378282246310005) == "AMEX"
getIssuer(6011111111111117) == "Discover"
getIssuer(5105105105105100) == "Mastercard"
getIssuer(5105105105105106) == "Mastercard"
getIssuer(9111111111111111) == "Unknown"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

const char *
issuer(uvlong x)
{
	char s[32];
	int n;

	n = snprintf(s, sizeof(s), "%llu", x);
	switch (n) {
	case 13:
		if (s[0] == '4')
			return "VISA";
		break;

	case 15:
		if (s[0] == '3' && strchr("47", s[1]))
			return "AMEX";
		break;

	case 16:
		if (!strncmp(s, "6011", 4))
			return "Discover";
		if (s[0] == '4')
			return "VISA";
		if (s[0] == '5' && strchr("12345", s[1]))
			return "Mastercard";
		break;
	}
	return "Unknown";
}

int
main()
{
	assert(!strcmp(issuer(4111111111111111), "VISA"));
	assert(!strcmp(issuer(4111111111111), "VISA"));
	assert(!strcmp(issuer(4012888888881881), "VISA"));
	assert(!strcmp(issuer(378282246310005), "AMEX"));
	assert(!strcmp(issuer(6011111111111117), "Discover"));
	assert(!strcmp(issuer(5105105105105100), "Mastercard"));
	assert(!strcmp(issuer(5105105105105106), "Mastercard"));
	assert(!strcmp(issuer(9111111111111111), "Unknown"));

	return 0;
}
