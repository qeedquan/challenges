/*

--- Day 12: Leonardo's Monorail ---
You finally reach the top floor of this building: a garden with a slanted glass ceiling. Looks like there are no more stars to be had.

While sitting on a nearby bench amidst some tiger lilies, you manage to decrypt some of the files you extracted from the servers downstairs.

According to these documents, Easter Bunny HQ isn't just this building - it's a collection of buildings in the nearby area. They're all connected by a local monorail, and there's another building not far from here! Unfortunately, being night, the monorail is currently not operating.

You remotely connect to the monorail control systems and discover that the boot sequence expects a password. The password-checking logic (your puzzle input) is easy to extract, but the code it uses is strange: it's assembunny code designed for the new computer you just assembled. You'll have to execute the code and get the password.

The assembunny code you've extracted operates on four registers (a, b, c, and d) that start at 0 and can hold any integer. However, it seems to make use of only a few instructions:

cpy x y copies x (either an integer or the value of a register) into register y.
inc x increases the value of register x by one.
dec x decreases the value of register x by one.
jnz x y jumps to an instruction y away (positive means forward; negative means backward), but only if x is not zero.
The jnz instruction moves relative to itself: an offset of -1 would continue at the previous instruction, while an offset of 2 would skip over the next instruction.

For example:

cpy 41 a
inc a
inc a
dec a
jnz a 2
dec a
The above code would set register a to 41, increase its value by 2, decrease its value by 1, and then skip the last dec a (because a is not zero, so the jnz a 2 skips it), leaving register a at 42. When you move past the last instruction, the program halts.

After executing the assembunny code in your puzzle input, what value is left in register a?

--- Part Two ---
As you head down the fire escape to the monorail, you notice it didn't start; register c needs to be initialized to the position of the ignition key.

If you instead initialize register c to be 1, what value is now left in register a?

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

typedef struct {
	const char *p;
	int i;
	int e;
} Line;

%}

%define api.pure full
%locations
%param { Line *ln };

%code
{
	int yylex(YYSTYPE *, YYLTYPE *, Line *);
	void yyerror(YYLTYPE *, Line *, const char *);
}

%union
{
	int v;
}

%token CPY JNZ INC DEC
%token <v> NUM REG

%%
inst:
	CPY NUM REG
	{
		printf("%c = %d;\n", $3, $2);
	}
|
	CPY REG REG
	{
		printf("%c = %c;\n", $3, $2);
	}
|
	JNZ REG NUM
	{
		printf("if (%c) goto L%d;\n", $2, ln->i + $3);
	}
|
	JNZ NUM NUM
	{
		printf("if (%d) goto L%d;\n", $2, ln->i + $3);
	}
|
	INC REG
	{
		printf("%c += 1;\n", $2);
	}
|
	DEC REG
	{
		printf("%c -= 1;\n", $2);
	}
%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0]) || ln->p[0] == '-') {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return NUM;
	}

	if (!strncmp(ln->p, "cpy", 3)) {
		ln->p += 3;
		return CPY;
	} else if (!strncmp(ln->p, "jnz", 3)) {
		ln->p += 3;
		return JNZ;
	} else if (!strncmp(ln->p, "inc", 3)) {
		ln->p += 3;
		return INC;
	} else if (!strncmp(ln->p, "dec", 3)) {
		ln->p += 3;
		return DEC;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
		t = ln->p[0];
		break;
	
	case 'a':
	case 'b':
	case 'c':
	case 'd':
		lv->v = ln->p[0];
		t = REG;
		break;

	default:
		yyerror(ll, ln, "invalid input");
		break;
	}
	ln->p++;

	return t;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->e = 1;

	(void) ll;
	(void) msg;
}

int
solve(const char *name)
{
	FILE *fp;
	char buf[512];
	int ret;
	Line ln;

	ret = 0;
	fp = fopen(name, "rb");
	if (!fp) {
		printf("%s: %s\n", name, strerror(errno));
		return -errno;
	}

	ln.e = 0;
	ln.i = 1;

	puts("#include <stdio.h>");
	puts("long solve(long a, long b, long c, long d) {");
	while (fgets(buf, sizeof(buf), fp)) {
		ln.p = buf;

		printf("L%d: ", ln.i);
		if (yyparse(&ln) || ln.e)
			goto error;

		ln.i += 1;
	}
	puts("return a;");
	puts("}");
	
	puts("int main() {");
	puts("printf(\"%ld\\n\", solve(0, 0, 0, 0));");
	puts("printf(\"%ld\\n\", solve(0, 0, 1, 0));");
	puts("return 0;");
	puts("}");

	if (0) {
	error:
		printf("%s:%d: syntax error\n", name, ln.i);
		ret = -1;
	}

	fclose(fp);
	return ret;
}

int
main(void)
{
	solve("12.txt");
	return 0;
}
