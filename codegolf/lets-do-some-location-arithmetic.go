/*

From the Wikipedia article:

Location arithmetic (Latin arithmeticæ localis) is the additive (non-positional) binary numeral systems, which John Napier explored as a computation technique in his treatise Rabdology (1617), both symbolically and on a chessboard-like grid.

What?
Location numerals is a way of writing numbers using letters of the alphabet.

Binary notation had not yet been standardized, so Napier used what he called location numerals to represent binary numbers. Napier's system uses sign-value notation to represent numbers; it uses successive letters from the English alphabet to represent successive powers of two: a = 2^0 = 1, b = 2^1 = 2, c = 2^2 = 4, d = 2^3 = 8, e = 2^4 = 16 and so on.

An example
ab = 1+2 = 3 in base 10

aabb = 1+1+2+2 = 6 in base 10

Note that aabb can be shortened to bc by replacing any 2 instances of a letter by a higher one.

Addition
You just concatenate the two numbers and simplify.

acd + bde = acdbde = abcdde = acebe = abcf = 39 in base 10

Subtraction
Just remove all digits appearing equally in both parts of the subtraction. Expanding (converting b to aa) may be necessary

abde - ad = be = 18 in base 10

Multiplication
This is a bit harder.

Lets say we want to multiply acd (13) by def (56). First you arrange acd vertically:

a
c
d

Then you add def after the first a:

a def
c
d

Now, c is 2 positions later in the alphabet than a, so we add 2 positions in the alphabet to def to make fgh. That is added to the second row.

a def
c fgh
d

Lastly, d is 1 position later in the alphabet than c, so we add 1 position in the alphabet to fgh to make ghi. That is added to the third row.

a def
c fgh
d ghi

Then you take the sum of the right: def + fgh + ghi = deffgghhi = deggghhi = deghhhi = deghii = deghj (728)

Another example of multiplication

Input:

bc * de
First:

b
c

Then

b ef
c

Then

b ef
c fg

Note that we wrote down ef on the first line. That's because bc starts with b, and b is the second letter in the alphabet, so we need to shift de by 1 letter, so it becomes ef.

Then

ef+fg

Output:

eh

Division
This is not part of this challenge, because it can get very complex.

Your actual challenge
Your program or function must take input as a string that looks like this:

a + b
And you must output:
ab

Of course, your program or function must support numbers of arbitrary length (up to the string or input limit of your language) with any of the operators +, -, or *. Some more examples:

Input:
ab + bd
Output:
acd

Input:
d - ab
Output:
ac

Input:
ab * cd
Output:
cf

Notes:
The order of letters in the output doesn't matter, but you can always assume that the order of letters in numbers in the input will be ascending (a before z).
You may take input with a trailing newline and output with a trailing newline.
You may not take input as a list of ab, * and bd for ab * bd.
The english alphabet is used (abcdefghijklmnopqrstuvwxyz)
Your output must be simplified (aa is not allowed, b is required)
The input will be simplified (b + c, not aa + bb or aa + aaaa)
You may require a space before and the operator (+, -, or *), or you may require there to be none.
There will only be one operator per input.
You may assume that the output and the input will never go over 2^27-1 (abcdefghijklmnopqrstuvwxyz)
This is code-golf, so the shortest answer in bytes wins!

*/

package main

import (
	"bytes"
	"go/ast"
	"go/parser"
	"go/token"
	"math/bits"
)

func main() {
	assert(eval("acd + bde") == "abcf")
	assert(eval("abde - ad") == "be")
	assert(eval("aabb") == "bc")
	assert(eval("a + b") == "ab")
	assert(eval("ab + bd") == "acd")
	assert(eval("d - ab") == "ac")
	assert(eval("ab * cd") == "cf")
	assert(eval("bc * de") == "eh")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eval(s string) (r string) {
	defer func() {
		if err := recover(); err != nil {
			r = "invalid expression"
		}
	}()

	e, err := parser.ParseExpr(s)
	if err != nil {
		panic(err)
	}

	return num2loc(walk(e))
}

func walk(e ast.Expr) int {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(e.X)
		y := walk(e.Y)
		r := 0
		switch e.Op {
		case token.ADD:
			r = x + y
		case token.SUB:
			r = x - y
		case token.MUL:
			r = x * y
		case token.QUO:
			r = x / y
		default:
			panic("invalid expression")
		}
		return r

	case *ast.Ident:
		return loc2num(e.Name)

	case *ast.BasicLit:
		return loc2num(e.Value)

	default:
		panic("invalid expression")
	}
}

func loc2num(s string) int {
	r := 0
	for _, c := range s {
		r += 1 << (c - 'a')
	}
	return r
}

func num2loc(n int) string {
	w := new(bytes.Buffer)

	s := ""
	if n < 0 {
		n = -n
		s = "-"
	}

	for i := 0; i < bits.UintSize; i++ {
		if n&(1<<i) != 0 {
			w.WriteByte('a' + byte(i))
		}
	}

	return s + w.String()
}
