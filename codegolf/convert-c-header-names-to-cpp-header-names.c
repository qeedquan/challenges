/*

In the C standard library, header names end with a .h suffix:

stdio.h
In C++, those header names are available in an alternative form, with a c prefix instead:

cstdio
Write a function that converts the first form into the second. You can do the conversion in-place, or leave the original string intact and return a new string. Whatever feelds natural in your language of choice.

The code must be compiled/interpreted without errors. Compiler warnings are acceptable.

Here is your baseline C solution. It has 70 characters and generates a warning about strlen:

void f(char*h){int i=strlen(h);h[--i]=0;while(--i)h[i]=h[i-1];*h='c';}
The shortest solution (measured in number of characters) wins.

Update: If your language of choice does not support functions, whole programs are also acceptable.

Update: As suggested by FUZxxl, here is a complete list of the header files in the C standard library:

assert.h
ctype.h
errno.h
float.h
limits.h
locale.h
math.h
setjmp.h
signal.h
stdarg.h
stddef.h
stdio.h
stdlib.h
string.h
time.h
Specifically, there are no header names with multiple dots in them.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
conv(const char *s, char *b)
{
	size_t n;

	n = sprintf(b, "c%s", s);
	if (n > 2 && !strcmp(b + n - 2, ".h"))
		b[n - 2] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	conv(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("assert.h", "cassert");
	test("ctype.h", "cctype");
	test("errno.h", "cerrno");
	test("float.h", "cfloat");
	test("limits.h", "climits");
	test("locale.h", "clocale");
	test("math.h", "cmath");
	test("setjmp.h", "csetjmp");
	test("signal.h", "csignal");
	test("stdarg.h", "cstdarg");
	test("stddef.h", "cstddef");
	test("stdio.h", "cstdio");
	test("stdlib.h", "cstdlib");
	test("string.h", "cstring");
	test("time.h", "ctime");

	return 0;
}
