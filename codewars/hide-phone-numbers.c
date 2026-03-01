/*

You work in an office and your boss has asked you to download from the database the full list of subscribers of your newsletter. You need to hide subscribers' phone numbers and check their prefixes in order to send the encrypted file to a client.

Your tasks are:

to hide the last six digits of each phone number
to check validity of prefixes
Example 1
Original phone number	Encrypted
1-201-680-0202	1-201-6XX-XXXX
The valid formats for the Italian and US (the last one) numbers are the following:

CASE 1: +39 <separator> ### <separator> ### <separator> ####

CASE 2: 0039 <separator> ### <separator> ### <separator> ####

CASE 3: 1 <separator> ### <separator> ### <separator> ####

The list of separators is the following:

for Italian numbers: " ", ".", ""

for US numbers: " ", ".", "", "-"

Example 2:
Original phone number	Result
145-201-680-0202	false
If prefixes are different from the three indicated above (+39, 0039, 1) return false.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
match(const char *fmt, const char *str, char val[10], char sep[3][2])
{
	size_t nval;
	size_t nsep;

	memset(val, 0, 10);
	memset(sep, 0, 3 * 2);
	for (nval = nsep = 0; *fmt; fmt++) {
		switch (*fmt) {
		case ' ':
		case '-':
			if (strchr(" .", *str) || (*fmt == '-' && *str == '-'))
				sep[nsep++][0] = *str++;
			else if (isdigit(*str))
				nsep++;
			else
				return false;
			break;

		case 'd':
			if (!isdigit(*str))
				return false;
			val[nval++] = *str++;
			break;

		default:
			if (*fmt != *str++)
				return false;
			break;
		}
	}
	return *fmt == *str;
}

char *
encrypt(const char *str, char *buf)
{
	char val[10];
	char sep[3][2];
	char *ptr;

	ptr = buf;
	if (match("+39 ddd ddd dddd", str, val, sep))
		ptr += sprintf(ptr, "+39");
	else if (match("0039 ddd ddd dddd", str, val, sep))
		ptr += sprintf(ptr, "0039");
	else if (match("1-ddd-ddd-dddd", str, val, sep))
		ptr += sprintf(ptr, "1");
	else
		return NULL;

	ptr += sprintf(ptr, "%s%c%c%c", sep[0], val[0], val[1], val[2]);
	ptr += sprintf(ptr, "%s%cXX", sep[1], val[3]);
	ptr += sprintf(ptr, "%sXXXX", sep[2]);

	return buf;
}

void
test(const char *str, const char *res)
{
	char buf[128];
	char *ptr;

	ptr = encrypt(str, buf);
	if (!res)
		assert(ptr == res);
	else {
		assert(ptr);
		puts(ptr);
		assert(!strcmp(ptr, res));
	}
}

int
main()
{
	test("1-201-680-0202", "1-201-6XX-XXXX");
	test("0039 455 555 6433", "0039 455 5XX XXXX");
	test("145-201-680-0202", NULL);
	test("+39 328 6587120", "+39 328 6XXXXXX");
	test("1-212-420-0202", "1-212-4XX-XXXX");
	test("11-211-458-7851", NULL);

	return 0;
}
