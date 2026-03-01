/*

Task
In the given code, a few identifiers are marked with / * Insert type here * /. Specify the correct types of such identifiers.

Also, inside the function pointer_monster, change each / * ? * / into exactly one digit, so that pointer_monster(d) returns the string "Pointer monster".

Notes
You can add characters to both side of each identifier to specify its correct type.

Restrictions
You can't remove any characters from the given initial code, except the comment sections. Changing whitespaces is acceptable.

You can't add the characters "#&'+,-/;.

*/

#include <stdio.h>

char a[4][7] = {"Common", "Point", "Boost", "Better"};
char (*b[4])[7] = {a + 3, a + 1, a, a + 2};

char (*(*c())[4])[7]
{
	return &b;
}

char (**d())[7]
{
	return c()[1] - 3;
}

char buf[256];

char *
pointer_monster(char (**(*f)())[7])
{
	int len;

	len = sprintf(buf, "%s", *f()[0]);
	len += sprintf(buf + len, "%s ", *((**f)() - 1)[0] + 4);
	len += sprintf(buf + len, "%s", (*f())[0] - 4);
	len += sprintf(buf + len, "%s", f()[1][2] + 3);
	len += sprintf(buf + len, "%s", *((**f)() - 1)[0] + 4);
	return buf;
}

int
main()
{
	printf("%s\n", pointer_monster(d));
	return 0;
}
