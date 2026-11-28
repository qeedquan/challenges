/*

It is a simple problem, you just need to get acquainted with Backus-Naur form if you never heard of it before.

Subroutine declarations in some programming language are described by the following syntactic rules:

<subroutine declaration>  ::=  <procedure declaration> | <function declaration>

<procedure declaration>   ::=  procedure <identifier> <formal arguments> ;

<function declaration>    ::=  function <identifier> <formal arguments> : <type> ;

<formal arguments>        ::=  ( <argument list> | )

<argument list>           ::=  <argument section> { ; <argument section> }

<argument section>        ::=  <identifier> { , <identifier> } : <type>

<identifier>              ::=  <letter|_>{<letter>|<digit>|_}

<type>                    ::=  integer | real | boolean
We do not include definitions for letter and digit as they seem obvious (e.g. A..Z | a..z and 0..9 respectively, but in BNF it is more verbose). The character _ is an underscore. Note that spaces (and tabs) can be inserted anywhere except inside identifiers.

You are to write simple syntax analyzer which checks whether given string satisfies the given rules (i.e. is correct subroutine declaration).

Input: The first line gives N - number of strings to follow.
Next lines contain one declaration each.

Output: Print numbers of lines which contain correct declarations, space-separated, counting from 1.

Example:

input:

4
function hypot(a, b: real): real;
procedure setxy(x integer, y integer);
procedure stop();
function is_round(x: real; y: integer);

output:

1 3

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *p;
	long r;
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

%token LPROC LFUNC LINT LREAL LBOOL LCHAR LDIGIT

%%
top:
	subroutine_declaration

subroutine_declaration:
	procedure_declaration
|
	function_declaration

procedure_declaration:
	LPROC identifier formal_arguments ';'

function_declaration:
	LFUNC identifier formal_arguments ':' type ';'

formal_arguments:
	'(' argument_list ')'

argument_list:
|
	argument_section
|
	';' argument_section

argument_section:
	identifier_list ':' type

identifier_list:
	identifier
|
	identifier ',' identifier_list

identifier:
	LCHAR
|
	LCHAR letters

letters:
	letter
|
	letters letter

type:
	LINT | LREAL | LBOOL

letter:
	LCHAR | LDIGIT 

%%

int
yylex(YYSTYPE *, YYLTYPE *ll, Line *ln)
{
	static const char *kw[] = { "procedure", "function", "integer", "real", "boolean" };
	static const size_t kwlen[] = { 9, 8, 7, 4, 7 };
	static const int kwsym[] = { LPROC, LFUNC, LINT, LREAL, LBOOL };

	int t;
	size_t i;

	while (isspace(ln->p[0]))
		ln->p++;

	for (i = 0; i < nelem(kw); i++) {
		if (!strncmp(ln->p, kw[i], kwlen[i])) {
			ln->p += kwlen[i];
			return kwsym[i];
		}
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case ':':
	case ';':
	case ',':
	case '(':
	case ')':
		t = ln->p[0];
		break;
	
	case 'A' ... 'Z':
	case 'a' ... 'z':
		t = LCHAR;
		break;
	
	case '0' ... '9':
		t = LDIGIT;
		break;

	default:
		yyerror(ll, ln, "invalid input");
		break;
	}
	ln->p++;

	return t;
}

void
yyerror(YYLTYPE *, Line *ln, const char *)
{
	ln->e = 1;
}

int
valid(const char *s)
{
	Line ln = { s, 0, 0 };
	if (yyparse(&ln) || ln.e)
		return 0;
	return 1;
}

int
main()
{
	assert(valid("function hypot(a, b: real): real;") == 1);
	assert(valid("procedure setxy(x integer, y integer);") == 0);
	assert(valid("procedure stop();") == 1);
	assert(valid("function is_round(x: real; y: integer);") == 0);

	return 0;
}
