/*

Bailey–Borwein–Plouffe Iterations
We've seen a few pi challenges on PPCG, but none that specifically dictate the algorithm you should be using.
I'd like to see implementations of the Bailey–Borwein–Plouffe algorithm in any language up to iteration n. The formula is as follows:

https://i.sstatic.net/Emi5u.png

Your algorithm should output each iteration up to n, showing intermediate sums as well as the final result to form a "piangle".
You may also use the reduced polynomial form of the algorithm shown on the wikipedia page. An example run for n=50 is shown below:

3
3.1
3.14
3.141
3.1415
3.14159
3.141592
3.1415926
3.14159265
3.141592653
3.1415926535
3.14159265358
3.141592653589
3.1415926535897
3.14159265358979
3.141592653589793
3.1415926535897932
3.14159265358979323
3.141592653589793238
3.1415926535897932384
3.14159265358979323846
3.141592653589793238462
3.1415926535897932384626
3.14159265358979323846264
3.141592653589793238462643
3.1415926535897932384626433
3.14159265358979323846264338
3.141592653589793238462643383
3.1415926535897932384626433832
3.14159265358979323846264338327
3.141592653589793238462643383279
3.1415926535897932384626433832795
3.14159265358979323846264338327950
3.141592653589793238462643383279502
3.1415926535897932384626433832795028
3.14159265358979323846264338327950288
3.141592653589793238462643383279502884
3.1415926535897932384626433832795028841
3.14159265358979323846264338327950288419
3.141592653589793238462643383279502884197
3.1415926535897932384626433832795028841971
3.14159265358979323846264338327950288419716
3.141592653589793238462643383279502884197169
3.1415926535897932384626433832795028841971693
3.14159265358979323846264338327950288419716939
3.141592653589793238462643383279502884197169399
3.1415926535897932384626433832795028841971693993
3.14159265358979323846264338327950288419716939937
3.141592653589793238462643383279502884197169399375
3.1415926535897932384626433832795028841971693993751
3.14159265358979323846264338327950288419716939937510
The precision of each iteration should equal the n that is passed to the algorithm, that is to say that each iteration should calculate pi up to the passed n for all k.

Rules:
Built-ins are not allowed, nor is pi, you must use the formula.
You must support n up to a maximum that your language allows in terms of the calculation of 16^n. If the input is causing an arithmetic overflow during calculation after x<n executions because your language only supports decimals up to 2^32-1, this is fine. Any other assumptions on n are not fine.
You MUST provide an explanation of how you got the output if it is not obvious. For instance, if you're posting in a Golfing language a break-down is 100% required. This is to ensure you're using the algorithm that is specified.
Standard loop-holes are disallowed.
This is code-golf, lowest byte count wins here.
Reference Code (Code used to Generate Example):

public static void main(String[] args) {
    (0..50).each {
        n->
        def x=(0..n).collect {
            j->
            def k=new BigDecimal(j)
            def s={it.setScale(n)}
            def a=s(1.0g).divide(s(16.0g)**s(k))
            def b=s(4.0g)/(s(8.0g)*s(k)+s(1.0g))
            def c=s(2.0g)/(s(8.0g)*s(k)+s(4.0g))
            def d=s(1.0g)/(s(8.0g)*s(k)+s(5.0g))
            def e=s(1.0g)/(s(8.0g)*s(k)+s(6.0g))
            def f=a*(b-c-d-e)
        }.sum()
        println(n + "\t" + x.setScale(n, BigDecimal.ROUND_DOWN))
    }
}
This implementation caps out at n=255, you may cap out at less or more.
This implementation was done in Groovy.

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"math/big"
)

func main() {
	bbp(50)
}

// https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
func bbp(n int) {
	z := new(big.Rat)
	for k := range n + 1 {
		z.Add(z, term(k))
		fmt.Println(decs(z, k))
	}
}

func decs(z *big.Rat, k int) string {
	if k >= 1 {
		k += 1
	}
	s := z.FloatString(2*k + 1)
	return s[:k+1]
}

func term(k int) *big.Rat {
	s := fmt.Sprintf("1/(16^%d) * (4/(8*%d + 1) - 2/(8*%d + 4) - 1/(8*%d + 5) - 1/(8*%d + 6))", k, k, k, k, k)
	e, err := parser.ParseExpr(s)
	if err != nil {
		panic(err)
	}
	return walk(e)
}

func walk(e ast.Expr) *big.Rat {
	var r *big.Rat
	switch e := e.(type) {
	case *ast.ParenExpr:
		r = walk(e.X)

	case *ast.BinaryExpr:
		x := walk(e.X)
		y := walk(e.Y)
		switch e.Op {
		case token.ADD:
			x.Add(x, y)
		case token.SUB:
			x.Sub(x, y)
		case token.MUL:
			x.Mul(x, y)
		case token.QUO:
			x.Quo(x, y)
		case token.XOR:
			n := x.Num()
			p := y.Num()
			n.Exp(n, p, nil)
			x.SetInt(n)
		default:
			panic("unreachable")
		}
		r = x

	case *ast.BasicLit:
		r = new(big.Rat)
		r.SetString(e.Value)

	default:
		panic("unreachable")
	}
	return r
}
