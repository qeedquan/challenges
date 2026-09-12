/*

Description
As the title already told you, you have to parse a IPv6 hex string in a weird way. For each block in the string you have to parse its characters as if they were separate hexadecimal values, add them up, and join the results into a string.

Here's an example of an IPv6 string: 1B1D:AF01:3847:F8C4:20E9:0111:DFEA:AAAA. And here's how you'd convert its first block to an integer: "1B1D" => 0x1 + 0xB + 0x1 + 0xD = 26. After all the blocks have been processed in the same way, the results should be joined together: "26" + "26" + "22" + "39" + "25" + "3" + "52" + "40" -> "262622392535240"

Note: some character other than colon (:) may be used in the input string, but it is guaranteed that hexadecimal digits will never be used as separators.

Examples
"1111:1111:1111:1111:1111:1111:1111:1111" => "4" + "4" + "4" + "4" + "4" + "4" + "4" + "4" => "44444444"
"1111-1111-1111-1111-1111-1111-1111-1111" => "4" + "4" + "4" + "4" + "4" + "4" + "4" + "4" => "44444444"
"ABCD_1111_ABCD_1111_ABCD_1111_ABCD_1111" => "46" + "4" + "46" + "4" + "46" + "4" + "46" + "4" => 464464464464
Happy coding!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
parse(const char *s, char *b)
{
	size_t i, j;
	int v;
	char *p;

	*b = '\0';
	p = b;
	v = 0;
	for (i = j = 0; s[i]; i++) {
		if ('0' <= s[i] && s[i] <= '9')
			v += s[i] - '0';
		else if ('a' <= s[i] && s[i] <= 'f')
			v += s[i] - 'a' + 10;
		else if ('A' <= s[i] && s[i] <= 'F')
			v += s[i] - 'A' + 10;
		else {
			p += sprintf(p, "%d", v);
			v = 0;
			j = i + 1;
		}
	}
	if (j != i)
		sprintf(p, "%d", v);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	parse(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("1B1D:AF01:3847:F8C4:20E9:0111:DFEA:AAAA", "262622392535240");
	test("1111:1111:1111:1111:1111:1111:1111:1111", "44444444");
	test("1111-1111-1111-1111-1111-1111-1111-1111", "44444444");
	test("ABCD_1111_ABCD_1111_ABCD_1111_ABCD_1111", "464464464464");

	return 0;
}
