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

%type sentence predclaim preds predname predstring statement verbpred
%token LA LMOD LBA LDA LLA LNAM LPREDA

%%
top:
	sentence '.'

sentence:
	statement
|
	predclaim

predclaim:
	predname LBA preds
|
	LDA preds

preds:
	predstring
|
	preds LA predstring

predname:
	LLA predstring
|
	LNAM

predstring:
	LPREDA
|
	predstring LPREDA

statement:
	predname verbpred predname
|
	predname verbpred

verbpred:
	LMOD predstring

%%

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define DEF(t, s) { t, s, sizeof(s) - 1 }

int
isvowel(int c)
{
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 1;
	}
	return 0;
}

int
yylex(YYSTYPE *, YYLTYPE *ll, Line *ln)
{
	static const struct {
		int type;
		const char *str;
		size_t len;
	} *kw, kws[] = {
		DEF(LA, "a"),
		DEF(LA, "e"),
		DEF(LA, "i"),
		DEF(LA, "o"),
		DEF(LA, "u"),
		DEF(LMOD, "ga"),
		DEF(LMOD, "ge"),
		DEF(LMOD, "gi"),
		DEF(LMOD, "go"),
		DEF(LMOD, "gu"),
		DEF(LBA, "ba"),
		DEF(LBA, "be"),
		DEF(LBA, "bi"),
		DEF(LBA, "bo"),
		DEF(LBA, "bu"),
		DEF(LDA, "da"),
		DEF(LDA, "de"),
		DEF(LDA, "di"),
		DEF(LDA, "do"),
		DEF(LDA, "du"),
		DEF(LLA, "la"),
		DEF(LLA, "le"),
		DEF(LLA, "li"),
		DEF(LLA, "lo"),
		DEF(LLA, "lu"),
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

	if (n > 0 && (!islower(p[n - 1]) || !isvowel(p[n - 1]))) {
		ln->p += n;
		return LNAM;
	}

	if (n == 5) {
		t = isvowel(p[4]);
		t |= isvowel(p[0]) << 4;
		t |= isvowel(p[1]) << 3;
		t |= isvowel(p[2]) << 2;
		t |= isvowel(p[3]) << 1;
		if (t == 0x5 || t == 0x9) {
			ln->p += n;
			return LPREDA;
		}
	}

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
	case '.':
		t = ln->p[0];
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
		return "Bad!";
	return "Good";
}

void
test(const char *s, const char *r)
{
	assert(!strcmp(check(s), r));
}

int
main()
{
	test("la mutce bunbo mrenu bi ditca.", "Good");
	test("la fumna bi le mrenu.", "Bad!");
	test("djan ga vedma le negro ketpi.", "Good");

	return 0;
}
