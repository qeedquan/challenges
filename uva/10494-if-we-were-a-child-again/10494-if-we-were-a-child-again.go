package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"math/big"
)

func main() {
	fmt.Println(eval("110 / 100"))
	fmt.Println(eval("99 % 10"))
	fmt.Println(eval("2147483647 / 2147483647"))
	fmt.Println(eval("2147483646 % 2147483647"))
}

func eval(s string) *big.Int {
	e, err := parser.ParseExpr(s)
	if err != nil {
		return nil
	}
	return walk(e)
}

func walk(e ast.Expr) *big.Int {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(e.X)
		y := walk(e.Y)
		switch e.Op {
		case token.QUO:
			x.Quo(x, y)
		case token.REM:
			x.Mod(x, y)
		default:
			return nil
		}
		return x

	case *ast.BasicLit:
		x := new(big.Int)
		x.SetString(e.Value, 10)
		return x

	default:
		return nil
	}
}
