/*

https://imgur.com/J0BpTXO

Have you heard how history of Microsoft started? Some hardware company produced Altair 8800 "minicomputer" (bulky device without keyboard or display, with just few kilobytes of memory and tumblers to set memory values manually). Bill Gates and Paul Allen read of it in some magazine, and decided to write BASIC language interpreter for it. They called the company representatives, and said they already have such an interpreter, and after confirming interest in it, set to work.

They did it in few weeks, despite not even having the Altair itself (really Allen was creating emulator of it while Gates was creating Basic).

This programming language - BASIC was extremely popular when computers were large and their resources were small.

We do not propose you to repeat the achievement of Gates and Allen, but let's try to code single step of interpreting process - tokenization of the source text. While Altair BASIC not necessarily used this step, it is quite convenient to perform it when developing interpreter / parser of almost any programming language.

Problem Statement
Basic sources are parsed and even executed line-per-line. So you'll get a number of source lines as input and the goal is for every line to tell of which token types it consists.

Only 5 token types need to be recognized:

"word" (w) - anything which starts with letter and then continues with letters or digits; also it may end with dollar sign (examples LET, X13, A5);
"number" (n) - for simplicity, regard only integers - i.e. sequence of digits (e.g. 0, 12357);
"quotes" (q) - string literal, starting and ending with double quotes, no provision is made for escaping double quote itself as a part of string (for example "Hi Peoplezzz!!!");
"operators" (o) - any of >=, <=, <>, >, <, =, +, -, *, /, ^
"punctuation" (p) - any of ,, ;, :, (, ) (comma, semicolon, colon, parentheses)
Token types are identified by single letters (w, n, q, o, p). So the line like this:

PRINT "Meaning of the life is", 40+2
Should give as an answer wqpnon.

Spaces between tokens are skipped. If you detect some state of error while trying to parse the next token, add letter e to the answer and don't parse this line further.

Note 1: in real interpreter we keep token content of course, not only their type - but for our exercise it is not important.

Note 2: some language errors are on higher level than tokenization. For example PRINT +-* 40 40 has illogical chain of tokens - but tokens themselves parse correctly, there is no error on tokenization step, that's all right.

Input data give the total number (N) of lines first. Then N source lines follow.
Answer should give chains of token types for every of these lines, separated with spaces.

Example

input:

10 INPUT "What is your name: "; U$
20 PRINT "Hello "; U$
30 INPUT "How many stars do you want: "; N
40 S$ = ""
50 FOR I = 1 TO N
60 S$ = S$ + "*"
70 NEXT I
80 PRINT S$
90 INPUT "Do you want more stars? "; A$
100 IF LEN(A$) = 0 THEN GOTO 90
110 A$ = LEFT$(A$, 1)
120 IF A$ = "Y" OR A$ = "y" THEN GOTO 30
130 PRINT "Goodbye "; U$
140 END

answer:

nwqpw nwqpw nwqpw nwoq nwwonww nwowoq nww nww nwqpw nwwpwponwwn nwowpwpnp nwwoqwwoqwwn nwqpw nw

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isop(int c)
{
	return c && strchr("><=+-*/^", c) != NULL;
}

int
ispunc(int c)
{
	return c && strchr(",;:()", c) != NULL;
}

int
isletter(int c)
{
	c = tolower(c);
	return isalpha(c) || isdigit(c);
}

int
isnotquote(int c)
{
	return c != '"';
}

void
skip(const char **in, int (*is)(int))
{
	const char *p;

	p = *in;
	while (*p && is(*p))
		p += 1;
	*in = p;
}

int
scan(const char **in)
{
	const char *p;
	int t;

	t = 0;
	p = *in;
	skip(&p, isspace);
	if (isalpha(tolower(*p))) {
		skip(&p, isletter);
		if (*p == '$')
			p += 1;
		t = 'w';
	} else if (isdigit(*p)) {
		skip(&p, isdigit);
		t = 'n';
	} else if (*p == '"') {
		p += 1;
		skip(&p, isnotquote);
		p += (*p == '"');
		t = 'q';
	} else if (isop(*p)) {
		p += 1;
		if ((p[0] == '>' || p[0] == '<') && p[1] == '=')
			p += 1;
		t = 'o';
	} else if (ispunc(*p)) {
		p += 1;
		t = 'p';
	}
	*in = p;
	return t;
}

void
tokenize(const char *in, char *out)
{
	for (;;) {
		*out = scan(&in);
		if (!*out)
			break;
		out++;
	}
}

void
test(const char *in, const char *res)
{
	char out[128];

	tokenize(in, out);
	puts(out);
	assert(!strcmp(out, res));
}

int
main()
{
	test("PRINT \"Meaning of the life is\", 40+2", "wqpnon");
	test("10 INPUT \"What is your name: \"; U$", "nwqpw");
	test("20 PRINT \"Hello \"; U$", "nwqpw");
	test("30 INPUT \"How many stars do you want: \"; N", "nwqpw");
	test("40 S$ = \"\"", "nwoq");
	test("50 FOR I = 1 TO N", "nwwonww");
	test("60 S$ = S$ + \"*\"", "nwowoq");
	test("70 NEXT I", "nww");
	test("80 PRINT S$", "nww");
	test("90 INPUT \"Do you want more stars? \"; A$", "nwqpw");
	test("100 IF LEN(A$) = 0 THEN GOTO 90", "nwwpwponwwn");
	test("110 A$ = LEFT$(A$, 1)", "nwowpwpnp");
	test("120 IF A$ = \"Y\" OR A$ = \"y\" THEN GOTO 30", "nwwoqwwoqwwn");
	test("130 PRINT \"Goodbye \"; U$", "nwqpw");
	test("140 END", "nw");

	return 0;
}
