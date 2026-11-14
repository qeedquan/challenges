%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	const char *p;
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

%token LAND LAT LAVERAGE LCAS LCHANGE LDIGIT LFIRST
%token LGO LKEEP LKMH LLEFT LLETTER LQUOTE LRECORD
%token LRIGHT LSECOND LSPEED LTHEN LTHIRD LTIME LTO

%%
top:
	instruction

instruction:
	navigational | timekeeping | navigational LAND timekeeping

navigational:
	directional | navigational LAND LTHEN directional

directional:
	how direction | how direction where

how:
	LGO | LGO when | LKEEP

direction:
	LRIGHT | LLEFT

when:
	LFIRST | LSECOND | LTHIRD

where:
	LAT sign

sign:
	LQUOTE signwords LQUOTE

signwords:
	sword | signwords sword

sword:
	letter | sword letter

letter:
	LLETTER

timekeeping:
	record | change

record:
	LRECORD LTIME

change:
	cas LTO nnn LKMH

cas:
	LCHANGE LAVERAGE LSPEED | LCAS

nnn:
	digit | nnn digit

digit:
	LDIGIT

%%

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define DEF(t, s) { t, s, sizeof(s) - 1 }

int
yylex(YYSTYPE *, YYLTYPE *ll, Line *ln)
{
	static const struct {
		int type;
		const char *str;
		size_t len;
	} *kw, kws[] = {
		DEF(LAND, "AND"),
		DEF(LAT, "AT"),
		DEF(LAVERAGE, "AVERAGE"),
		DEF(LCAS, "CAS"),
		DEF(LCHANGE, "CHANGE"),
		DEF(LFIRST, "FIRST"),
		DEF(LGO, "GO"),
		DEF(LKEEP, "KEEP"),
		DEF(LKMH, "KMH"),
		DEF(LLEFT, "LEFT"),
		DEF(LRECORD, "RECORD"),
		DEF(LRIGHT, "RIGHT"),
		DEF(LSECOND, "SECOND"),
		DEF(LSPEED, "SPEED"),
		DEF(LTHEN, "THEN"),
		DEF(LTHIRD, "THIRD"),
		DEF(LTIME, "TIME"),
		DEF(LTO, "TO"),
	};

	const char *p;
	size_t i, n;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	p = ln->p;
	n = 0;
	while (p[n] && p[n] != '.' && !isspace(p[n]))
		n += 1;

	for (i = 0; i < nelem(kws); i++) {
		kw = kws + i;
		if (n != kw->len)
			continue;
		if (strncmp(p, kw->str, kw->len) != 0)
			continue;
		ln->p += kw->len;
		return kw->type;
	}

	t = 0;
	switch (ln->p[0]) {
	case '\0':
		break;

	case '"':
		t = LQUOTE;
		break;

	case 'A' ... 'Z':
	case '.':
		t = LLETTER;
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

const char *
check(const char *s)
{
	Line ln = { s, 0 };
	if (yyparse(&ln) || ln.e)
		return "Trap!";
	return s;
}

void
test(const char *s)
{
	puts(check(s));
}

int
main()
{
	test("KEEP LEFT AND THEN GO RIGHT");
	test("CAS TO 20 KMH");
	test("GO FIRST RIGHT AT \"SMITH ST.\" AND CAS TO 20 KMH");
	test("GO 2nd RIGHT");
	test("GO LEFT AT \"SMITH STREET AND RECORD TIME\"");
	test("KEEP RIGHT AND THEN RECORD TIME");

	return 0;
}
