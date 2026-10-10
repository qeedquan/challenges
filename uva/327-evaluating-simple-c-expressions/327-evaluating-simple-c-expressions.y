%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	const char *input;
	int value[256];
	int use[256];
	int result;
	int error;
} Line;

typedef struct {
	int symbol;
	int value;
} Node;

%}

%define api.pure full
%locations
%param { Line *line };

%code
{
	int yylex(YYSTYPE *, YYLTYPE *, Line *);
	void yyerror(YYLTYPE *, Line *, const char *);
}

%union
{
	Node node;
}

%left '+' '-'
%left LINC LDEC

%type <node> expr primary postfix unexpr binexpr
%token <node> LIDENT LINC LDEC

%%

top:
	expr
	{
		line->result = $1.value;
	}

expr:
	binexpr

binexpr:
	unexpr
|
	binexpr '+' binexpr
	{
		$$.value = $1.value + $3.value;
	}
|
	binexpr '-' binexpr
	{
		$$.value = $1.value - $3.value;
	}

unexpr:
	postfix
|
	LINC unexpr
	{
		line->value[$2.symbol] += 1;
		$$.symbol = $2.symbol;
		$$.value = line->value[$$.symbol];
	}
|
	LDEC unexpr
	{
		line->value[$2.symbol] -= 1;
		$$.symbol = $2.symbol;
		$$.value = line->value[$$.symbol];
	}

postfix:
	primary
|
	postfix LINC
	{
		$$.symbol = $1.symbol;
		$$.value = line->value[$$.symbol];
		line->value[$$.symbol] += 1;
	}
|
	postfix LDEC
	{
		$$.symbol = $1.symbol;
		$$.value = line->value[$$.symbol];
		line->value[$$.symbol] -= 1;
	}

primary:
	LIDENT
	{
		line->use[$1.symbol] = 1;
	}

%%

int
yylex(YYSTYPE *stype, YYLTYPE *ltype, Line *line)
{
	int symbol;
	int type;

	while (isspace(line->input[0]))
		line->input++;
	symbol = line->input[0] & 0xff;

	stype->node.symbol = symbol;
	stype->node.value = line->value[symbol];

	type = 0;
	switch (symbol) {
	case '\0':
	case '+':
	case '-':
		type = symbol;
		if (symbol && symbol == line->input[1]) {
			type = (symbol == '+') ? LINC : LDEC;
			line->input++;
		}
		break;

	case 'a' ... 'z':
		type = LIDENT;
		break;

	default:
		yyerror(ltype, line, "invalid input");
		break;
	}
	line->input++;

	return type;
}

void
yyerror(YYLTYPE *, Line *line, const char *)
{
	line->error = 1;
}

void
init(Line *line, const char *input)
{
	int symbol;

	memset(line, 0, sizeof(*line));
	line->input = input;
	for (symbol = 'a'; symbol <= 'z'; symbol++)
		line->value[symbol] = symbol - 'a' + 1;
}

void
solve(const char *input)
{
	Line line;
	int symbol;

	init(&line, input);

	printf("Expression: %s\n", input);
	if (yyparse(&line) || line.error) {
		puts("Invalid!");
		puts("");
		return;
	}

	printf("    value = %d\n", line.result);
	for (symbol = 'a'; symbol <= 'z'; symbol++) {
		if (line.use[symbol])
			printf("    %c = %d\n", symbol, line.value[symbol]);
	}
}

int
main()
{
	solve("a + b");
	solve("b - z");
	solve("a+b--+c++");
	solve("c+f--+--a");
	solve("    f-- + c-- + d-++e");

	return 0;
}
