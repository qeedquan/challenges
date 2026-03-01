/*

https://i.stack.imgur.com/yT2lY.png

Above is the picture of the flag of the country Nepal. Pretty cool.

What's cooler, is the aspect ratio, which is defined under the constitution as:

https://i.stack.imgur.com/eDvds.jpg

That formula in copyable form:

(6136891429688-306253616715*sqrt(2)-(934861968+20332617192*sqrt(2)) * sqrt(118-48*sqrt(2)))/4506606337686

Your task is to output at least the first 113 digits of the decimal expansion, in any format of your choosing. These digits are:

1.2190103378294521845700248699309885665950123333195645737170955981267389324534409006970256858120588676151695966441

These digits form can be found in sequence A230582.

This constant is algebraic, specifically quartic. In particular it is the least root of 243356742235044x⁴ - 1325568548812608x³ + 2700899847521244x² - 2439951444086880x + 824634725389225.

This is code-golf, so shortest answer wins.

Related: Let's draw the flag of Nepal

*/

package main

import (
	"go/ast"
	"go/parser"
	"go/token"
	"math/big"
)

func main() {
	assert(nepal(113) == "1.2190103378294521845700248699309885665950123333195645737170955981267389324534409006970256858120588676151695966441")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A230582
func nepal(p uint) string {
	if p == 0 {
		return ""
	}

	e, err := parser.ParseExpr("(6136891429688-306253616715*sqrt(2)-(934861968+20332617192*sqrt(2)) * sqrt(118-48*sqrt(2)))/4506606337686")
	if err != nil {
		panic(err)
	}

	f := walk(e, p*10)
	r := f.Text('f', int(p)-1)
	return r
}

func walk(e ast.Expr, p uint) *big.Float {
	switch e := e.(type) {
	case *ast.CallExpr:
		fn, ok := e.Fun.(*ast.Ident)
		if !ok || fn.Name != "sqrt" || len(e.Args) != 1 {
			panic(e)
		}
		x := walk(e.Args[0], p)
		x.Sqrt(x)
		return x
	case *ast.BinaryExpr:
		x := walk(e.X, p)
		y := walk(e.Y, p)
		switch e.Op {
		case token.ADD:
			x.Add(x, y)
		case token.SUB:
			x.Sub(x, y)
		case token.MUL:
			x.Mul(x, y)
		case token.QUO:
			x.Quo(x, y)
		default:
			panic(e.Op)
		}
		return x
	case *ast.BasicLit:
		x := new(big.Float)
		x.SetPrec(p)
		x.SetString(e.Value)
		return x
	case *ast.ParenExpr:
		return walk(e.X, p)
	default:
		panic(e)
	}
}
