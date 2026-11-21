/*

In Russia, there is an army-purposed station named UVB-76 or "Buzzer" (see also https://en.wikipedia.org/wiki/UVB-76). Most of time specific "buzz" noise is being broadcasted, but on very rare occasions, the buzzer signal is interrupted and a voice transmission in Russian takes place. Transmitted messages have always the same format like this:

MDZHB 01 213 SKIF 38 87 23 95

or:

MDZHB 80 516 GANOMATIT 21 23 86 25

Message format consists of following parts:

Initial keyword "MDZHB";
Two groups of digits, 2 digits in first and 3 in second ones;
Some keyword of arbitrary length consisting only of uppercase letters;
Final 4 groups of digits with 2 digits in each group.

*/

#include <assert.h>
#include <stdio.h>

bool
uvb76(const char *s)
{
	static const char fmt[] = "MDZHB dd ddd s dd dd dd dd";

	const char *f;

	for (f = fmt; *s && *f; f++) {
		switch (*f) {
		case 'd':
			if (!('0' <= *s && *s <= '9'))
				return false;
			break;

		case 's':
			while ('A' <= *s && *s <= 'Z')
				s++;
			continue;

		default:
			if (*s != *f)
				return false;
			break;
		}
		s++;
	}
	return !*s && !*f;
}

int
main()
{
	assert(uvb76("Is this a right message?") == false);
	assert(uvb76("MDZHB 85 596 KLASA 81 00 02 91") == true);
	assert(uvb76("MDZHB 12 733 EDINENIE 67 79 66 32") == true);
	assert(uvb76("MDZHV 60 130 VATRUKH 58 89 54 54") == false);
	assert(uvb76("MDZHB 01 213 SKIF 38 87 23 95") == true);
	assert(uvb76("MDZHB 80 516 GANOMATIT 21 23 86 25") == true);

	return 0;
}
