package main

import (
	"bufio"
	"bytes"
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"strings"
	"text/scanner"
	"unicode"
)

func main() {
	parseFlags()

	name := flag.Arg(0)
	src, err := os.ReadFile(name)
	check(err)

	var (
		lex   Lexer
		tilde int
		done  bool
	)

	lex.Init(name, bytes.NewReader(src), func(scanner.Position, error) {
		done = true
	})

	units := 0
	for !done {
		_, tok, _ := lex.Next()
		if tok == EOF {
			break
		}

		if tok == TILDE {
			if tilde++; tilde >= 2 {
				break
			}
		} else {
			tilde = 0
		}

		if isUnit(tok) {
			units += 1
		}
	}

	author := "N/A"
	end := bytes.LastIndexByte(src, '~')
	if end >= 0 {
		author = string(bytes.TrimSpace(src[end+1:]))
	}
	fmt.Printf("Program by %s contains %d units.\n", author, units)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "[options] file.pas")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseFlags() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}
}

func isUnit(tok Token) bool {
	if tok.Reserved() {
		return true
	}
	switch tok {
	case SYMBOL, LITERAL, NUMBER, LPAREN, LBRACK,
		ADD, SUB, MUL, DIVX, EQ, LT, GT, LE, GE, NEQ,
		AT, DEREF, ASSIGN:
		return true
	}
	return false
}

type Token int

const (
	EOF Token = iota
	UNK

	COMMENT
	SYMBOL
	NUMBER
	LITERAL

	ADD
	ADDROF
	ASSIGN
	AT
	COLON
	COMMA
	DEREF
	DIVX
	DOT
	EQ
	GE
	GT
	LBRACK
	LE
	LPAREN
	LT
	MODX
	MUL
	NEQ
	RBRACK
	RPAREN
	SEMI
	SUB
	SYMDIFF
	TILDE

	AND
	ARRAY
	ASM
	BEGIN
	BREAK
	CASE
	CONST
	CONSTRUCTOR
	CONTINUE
	DESTRUCTOR
	DIV
	DO
	DOWNTO
	ELSE
	END
	FALSE
	FILE
	FOR
	FUNCTION
	GOTO
	IF
	IMPLEMENTATION
	IN
	INLINE
	INTERFACE
	LABEL
	MOD
	NIL
	NOT
	OBJECT
	OF
	ON
	OPERATOR
	OR
	PACKED
	PROCEDURE
	PROGRAM
	RECORD
	REPEAT
	SET
	SHL
	SHR
	STRING
	THEN
	TO
	TRUE
	TYPE
	UNIT
	UNTIL
	USES
	VAR
	WHILE
	WITH
	XOR
)

func (t Token) Reserved() bool {
	switch t {
	case AND, ARRAY, ASM, BEGIN, BREAK,
		CASE, CONST, CONSTRUCTOR, CONTINUE,
		DESTRUCTOR, DIV, DO, DOWNTO,
		ELSE, END, FALSE, FILE,
		FOR, FUNCTION, GOTO, IF,
		IMPLEMENTATION, IN, INLINE, INTERFACE,
		LABEL, MOD, NIL, NOT,
		OBJECT, OF, ON, OPERATOR,
		OR, PACKED, PROCEDURE, PROGRAM,
		RECORD, REPEAT, SET, SHL,
		SHR, STRING, THEN, TO,
		TRUE, TYPE, UNIT, UNTIL,
		USES, VAR, WHILE, WITH, XOR:
		return true
	}
	return false
}

type Lexer struct {
	pos0      scanner.Position
	pos       scanner.Position
	b         *bufio.Reader
	errh      func(scanner.Position, error)
	NumErrors int
}

func (l *Lexer) Init(name string, r io.Reader, errh func(scanner.Position, error)) {
	l.pos = scanner.Position{
		Filename: name,
		Line:     1,
		Column:   1,
	}
	l.pos0 = l.pos
	l.b = bufio.NewReader(r)
	l.errh = errh
	l.NumErrors = 0
}

func (l *Lexer) errf(pos scanner.Position, format string, args ...interface{}) {
	l.NumErrors++
	if l.errh != nil {
		l.errh(pos, fmt.Errorf(format, args...))
	}
}

func (l *Lexer) ungetr() {
	l.b.UnreadRune()
	l.pos = l.pos0
}

func (l *Lexer) getr() rune {
	l.pos0 = l.pos

	r, w, err := l.b.ReadRune()
	if err != nil {
		if err != io.EOF {
			l.errf(l.pos0, "I/O error: %v", err)
		}
		return -1
	}

	l.pos.Offset += w
	l.pos.Column += w
	if r == '\n' {
		l.pos.Line++
		l.pos.Column = 1
	}
	return r
}

func (l *Lexer) whitespace() rune {
	var r rune
	for {
		r = l.getr()
		if !unicode.IsSpace(r) {
			break
		}
	}
	return r
}

func (l *Lexer) comment(r rune) (tok Token, lit string) {
	tok = COMMENT
	for {
		r = l.getr()
		if r == '}' || r == '\n' {
			break
		}
		lit += string(r)
	}
	return
}

func (l *Lexer) number(r rune) (tok Token, lit string, err error) {
	tok = NUMBER
	lit = string(r)

	hex := false
	if r == '$' {
		r = l.getr()

		hex = true
		lit += string(r)
		r = l.getr()
		if !isDigit(r, hex) {
			l.ungetr()
			err = fmt.Errorf("missing digits after %v", lit)
			return
		}
		l.ungetr()
	}

	p := r
	for {
		r = l.getr()
		if !isDigit(r, hex) && !(r == '-' && (p == 'e' || p == 'E')) {
			break
		}
		lit += string(r)
		p = r
	}
	l.ungetr()

	return
}

func isDigit(r rune, hex bool) bool {
	switch {
	case '0' <= r && r <= '9':
		return true
	case r == '.' || r == 'E' || r == 'e':
		return true
	case hex && (('a' <= r && r <= 'f') || ('A' <= r && r <= 'F')):
		return true
	}
	return false
}

func isSymbol(r rune) bool {
	return unicode.IsLetter(r) || unicode.IsDigit(r) || r == '_'
}

func (l *Lexer) symbol(r rune) (tok Token, lit string) {
	tok = SYMBOL
	for isSymbol(r) {
		lit += string(r)
		r = l.getr()
	}
	l.ungetr()

	switch strings.ToLower(lit) {
	case "and":
		tok = AND
	case "array":
		tok = ARRAY
	case "asm":
		tok = ASM
	case "begin":
		tok = BEGIN
	case "break":
		tok = BREAK
	case "case":
		tok = CASE
	case "const":
		tok = CONST
	case "constructor":
		tok = CONSTRUCTOR
	case "continue":
		tok = CONTINUE
	case "destructor":
		tok = DESTRUCTOR
	case "div":
		tok = DIV
	case "do":
		tok = DO
	case "downto":
		tok = DOWNTO
	case "else":
		tok = ELSE
	case "end":
		tok = END
	case "false":
		tok = FALSE
	case "file":
		tok = FILE
	case "for":
		tok = FOR
	case "function":
		tok = FUNCTION
	case "goto":
		tok = GOTO
	case "if":
		tok = IF
	case "implementation":
		tok = IMPLEMENTATION
	case "in":
		tok = IN
	case "inline":
		tok = INLINE
	case "interface":
		tok = INTERFACE
	case "label":
		tok = LABEL
	case "mod":
		tok = MOD
	case "nil":
		tok = NIL
	case "not":
		tok = NOT
	case "object":
		tok = OBJECT
	case "of":
		tok = OF
	case "on":
		tok = ON
	case "operator":
		tok = OPERATOR
	case "or":
		tok = OR
	case "packed":
		tok = PACKED
	case "procedure":
		tok = PROCEDURE
	case "program":
		tok = PROGRAM
	case "record":
		tok = RECORD
	case "repeat":
		tok = REPEAT
	case "set":
		tok = SET
	case "shl":
		tok = SHL
	case "shr":
		tok = SHR
	case "string":
		tok = STRING
	case "then":
		tok = THEN
	case "to":
		tok = TO
	case "true":
		tok = TRUE
	case "type":
		tok = TYPE
	case "unit":
		tok = UNIT
	case "until":
		tok = UNTIL
	case "uses":
		tok = USES
	case "var":
		tok = VAR
	case "while":
		tok = WHILE
	case "with":
		tok = WITH
	case "xor":
		tok = XOR
	}
	return
}

func (l *Lexer) readec() rune {
	r := l.getr()
	if r != '\\' {
		return r
	}
	r = l.getr()
	switch r {
	case 'a':
		r = '\a'
	case 'b':
		r = '\b'
	case 'e':
		r = '\033'
	case 'f':
		r = '\f'
	case 'n':
		r = '\n'
	case 'q':
		r = '"' | 0x100
	case 'r':
		r = '\r'
	case 's':
		r = ' '
	case 't':
		r = '\t'
	case 'v':
		r = '\v'
	}
	return r
}

func (l *Lexer) literal(r rune) (tok Token, lit string, err error) {
	tok = LITERAL
	lit = string(r)
	for {
		r := l.readec()
		lit += string(r)
		if r == '\'' {
			break
		}
		if r == -1 {
			err = fmt.Errorf("unterminated string")
			break
		}
	}
	return
}

func (l *Lexer) sym3(r1 rune, tok1 Token, r2 rune, tok2 Token, r3 rune, tok3 Token) (tok Token, lit string) {
	tok = tok1
	lit = string(r1)
	switch l.getr() {
	case r2:
		tok = tok2
		lit += string(r2)
	case r3:
		tok = tok3
		lit += string(r3)
	default:
		l.ungetr()
	}
	return
}

func (l *Lexer) Next() (pos scanner.Position, tok Token, lit string) {
	var err error

redo:
	if err != nil {
		l.errf(pos, "%v", err)
		err = nil
	}
	r := l.whitespace()
	pos = l.pos0

	if r == '{' {
		tok, lit = l.comment(r)
		return
	}
	if unicode.IsDigit(r) || r == '$' {
		tok, lit, err = l.number(r)
		if err != nil {
			goto redo
		}
		return
	}
	if isSymbol(r) {
		tok, lit = l.symbol(r)
		return
	}

	if r == '\'' {
		tok, lit, err = l.literal(r)
		if err != nil {
			goto redo
		}
		return
	}

	lit = string(r)
	switch r {
	case -1:
		tok = EOF
	case '+':
		tok = ADD
	case '-':
		tok = SUB
	case '*':
		tok = MUL
	case '/':
		tok = DIVX
	case '%':
		tok = MODX
	case '(':
		tok = LPAREN
	case ')':
		tok = RPAREN
	case '[':
		tok = LBRACK
	case ']':
		tok = RBRACK
	case ';':
		tok = SEMI
	case ',':
		tok = COMMA
	case '=':
		tok = EQ
	case '~':
		tok = TILDE
	case '.':
		tok = DOT
	case '@':
		tok = AT
	case '<':
		tok, lit = l.sym3(r, LT, '>', NEQ, '=', LE)
	case '>':
		tok, lit = l.sym3(r, GT, '<', SYMDIFF, '=', GE)
	case ':':
		tok, lit = l.sym3(r, COLON, '=', ASSIGN, '=', ASSIGN)
	case '^':
		tok = DEREF
	default:
		tok = UNK
	}
	return
}
