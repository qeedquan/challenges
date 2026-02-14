/*

This expression actually has an omitted pair of parentheses.

1 + 2 * 3
To make things clear, it should be,

1 + (2 * 3)
Even this has its parentheses missing.

1 + 2 + 3
It actually means,

(1 + 2) + 3
People often assume left-to-right evaluation to such an arithmetic expression, but I want to make everything very clear.

Given an arithmetic expression, add parentheses until the order of evaluation is clear without any assumption, and don't remove any pre-existing parentheses.

Here are some examples of possible inputs and their expected output.

IN
OUT

IN  1
OUT 1

IN  (((1)))
OUT (((1)))

IN  1+2+3+4+5
OUT (((1+2)+3)+4)+5

IN  1/2/3/4/5
OUT (((1/2)/3)/4)/5

IN  1/2/((3/4))/5
OUT ((1/2)/((3/4)))/5

IN  1+2-3*4/5+6-7*8/9
OUT (((1+2)-((3*4)/5))+6)-((7*8)/9)

IN  1+(2-3*4/5+6-7)*8/9
OUT 1+(((((2-((3*4)/5))+6)-7)*8)/9)
The expression will be composed of single-digit numbers, operators (+, -, *, /), and parentheses. The typical rules of evaluation apply; left-to-right, parentheses first, multiplication first.

The input may have whitespaces, which has no effect, but your program should be able to handle them. The output must have no whitespace and have the same format as given in the examples. The input should be read either as a command line argument or from stdin, and the code should be runnable with no additional code.

This is a code-golf challenge.

Here's a rather formal definition of an arithmetic expression.

primary-expression
  [0-9]
  (arithmetic-expression)

multiplicative-expression
  primary-expression
  multiplicative-expression (* | /) primary-expression

additive-expression
  multiplicative-expression
  additive-expression (+ | -) multiplicative-expression

arithmetic-expression
  additive-expression
This is a python script that you can use to validate your output (in a very manual way..).

I had fun writing Lisp in Python.

def addop(op):
    return op == '+' or op == '-'

def match(l):
    if l[1:] == []:
        return [1, l]
    elif addop(l[1]):
        if l[3:] == [] or addop(l[3]):
            return [3, l[0:3]]
        else:
            m = match(l[2:])
            return [m[0] + 2, l[0:2] + [m[1]]]
    else:
        if l[3:] == [] or addop(l[3]):
            return [3, l[0:3]]
        else:
            m = match([l[0:3]] + l[3:])
            return [m[0] + 2, m[1]]

def tree__(l):
    m = match(l)
    if l[m[0]:] == []:
        return m[1]
    else:
        return tree__([m[1]] + l[m[0]:])

def tree_(l):
    if l == []:
        return []
    elif isinstance(l[0], list):
        return [tree_(tree__(l[0]))] + tree_(l[1:])
    else:
        return [l[0]] + tree_(l[1:])

def tree(l):
    return tree_(tree__(l))

def afterParen(s, n):
    if s == '':
        return '';
    if s[0] == '(':
        return afterParen(s[1:], n + 1)
    if s[0] == ')':
        if n == 0:
            return s[1:]
        else:
            return afterParen(s[1:], n - 1)
    else:
        return afterParen(s[1:], n)

def toList(s):
    if s == '' or s[0] == ')':
        return []
    elif s[0] == '(':
        return [toList(s[1:])] + toList(afterParen(s[1:], 0))
    elif s[0].isspace():
        return toList(s[1:])
    elif s[0].isdigit():
        return [int(s[0])] + toList(s[1:])
    else:
        return [s[0]] + toList(s[1:])

def toString(l):
    if l == []:
        return ''
    elif isinstance(l[0], list):
        return '(' + toString(l[0]) + ')' + toString(l[1:])
    elif isinstance(l[0], int):
        return str(l[0]) + toString(l[1:])
    else:
        return l[0] + toString(l[1:])

def addParen(s):
    return toString(tree(toList(s)))

exp = "1+2*3+4+2+2-3*4/2*4/2"
print(exp)
print(addParen(exp))
exp = "((1+2*(3+4)+(((((2))+(2-3*4/2)*4)))/2))"
print(exp)
print(addParen(exp))

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
)

func main() {
	assert(parens("1+2*3") == "1+(2*3)")
	assert(parens("1+2+3") == "(1+2)+3")
	assert(parens("") == "")
	assert(parens("1") == "1")
	assert(parens("(((1)))") == "(((1)))")
	assert(parens("1+2+3+4+5") == "(((1+2)+3)+4)+5")
	assert(parens("1/2/3/4/5") == "(((1/2)/3)/4)/5")
	assert(parens("1/2/((3/4))/5") == "((1/2)/((3/4)))/5")
	assert(parens("1+2-3*4/5+6-7*8/9") == "(((1+2)-((3*4)/5))+6)-((7*8)/9)")
	assert(parens("1+(2-3*4/5+6-7)*8/9") == "1+(((((2-((3*4)/5))+6)-7)*8)/9)")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func parens(s string) string {
	e, err := parser.ParseExpr(s)
	if err != nil {
		return s
	}
	return walk(e, nil)
}

func walk(e, p ast.Expr) string {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(e.X, e)
		y := walk(e.Y, e)
		r := fmt.Sprintf("%v%v%v", x, e.Op, y)
		_, ok := p.(*ast.ParenExpr)
		if p != nil && !ok {
			r = "(" + r + ")"
		}
		return r

	case *ast.ParenExpr:
		return fmt.Sprintf("(%v)", walk(e.X, e))

	case *ast.UnaryExpr:
		return fmt.Sprintf("%v%v", e.Op, walk(e.X, e))

	case *ast.Ident:
		return e.Name

	case *ast.BasicLit:
		return e.Value

	default:
		panic(fmt.Sprintf("unsupported type: %T", e))
	}
}
