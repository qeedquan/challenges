/*

In most programming languages, arithmetic is written with infix notation -- i.e. the operator is put in between the operands -- e.g. 1+2. In contrast, with Polish notation (a.k.a prefix notation), the operator comes before the operands -- e.g. +1 2. As long as the number of operands for each operator is fixed, this means that parentheses are never necessary, unlike with infix notation.

The Challenge
Given a string consisting of nonnegative integers (digits 0 through 9), spaces, +, -, *, and / representing a single expression in Polish notation, add parentheses around each sub-expression, maintaining the whitespace. The parentheses should start right before the operator and end right after the last operands. You can assume each function has arity 2 (i.e. it takes in exactly 2 operands). You can also assume there will be no extra preceding zeros (e.g. 000 or 09).

Test Cases
Input	Output
+1 2	(+1 2)
++ 1 2 3	(+(+ 1 2) 3)
    +1    +2 3	    (+1    (+2 3))
* *1 2 /3 0  	(* (*1 2) (/3 0))
//30 300/18 205	(/(/30 300)(/18 205))
/ -20/ 30 30  999	(/ (-20(/ 30 30))  999)
/////1 2 3 4 5 6	(/(/(/(/(/1 2) 3) 4) 5) 6)
/1/2/3/4/5/6/7/8 9	(/1(/2(/3(/4(/5(/6(/7(/8 9))))))))

Standard loopholes are forbidden. As this is code-golf, the shortest program wins.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	test("+1 2", "(+1 2)")
	test("++ 1 2 3", "(+(+ 1 2) 3)")
	test("    +1    +2 3", "    (+1    (+2 3))")
	test("* *1 2 /3 0  ", "(* (*1 2) (/3 0))  ")
	test("//30 300/18 205", "(/(/30 300)(/18 205))")
	test("/ -20/ 30 30  999", "(/ (-20(/ 30 30))  999)")
	test("/////1 2 3 4 5 6", "(/(/(/(/(/1 2) 3) 4) 5) 6)")
	test("/1/2/3/4/5/6/7/8 9", "(/1(/2(/3(/4(/5(/6(/7(/8 9))))))))")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r string) {
	p := parens(s)
	fmt.Printf("%q\n", p)
	assert(p == r)
}

/*

@DLosc

Explanation
Loop through the input string.

If the first character is a space, pop and output it.
If the first character is an operator:
Output an open paren.
Pop and output the operator.
Push 1 (representing a close-paren) and 0 (representing the space between an operator's first and second operands) to a stack.
Else (this is a number):
Output the first run of digits in the string.
Remove the first run of digits from the string.
Pop the stack; while the result is 1, output a close-paren and repeat.

*/

func parens(s string) string {
	w := new(bytes.Buffer)
	n := len(s)
	p := []byte{}
	for i := 0; i < n; i++ {
		switch {
		case s[i] == ' ':
			w.WriteByte(s[i])

		case strings.IndexByte("+-*/", s[i]) >= 0:
			w.WriteByte('(')
			w.WriteByte(s[i])
			p = append(p, 1)
			p = append(p, 0)

		case isdigit(s[i]):
			w.WriteByte(s[i])
			for ; i+1 < n && isdigit(s[i+1]); i++ {
				w.WriteByte(s[i+1])
			}

			for {
				sp := len(p) - 1
				if sp < 0 {
					break
				}

				op := p[sp]
				p = p[:sp]
				if op != 1 {
					break
				}
				w.WriteByte(')')
			}

		default:
			return s
		}
	}
	return w.String()
}

func isdigit(c byte) bool {
	return '0' <= c && c <= '9'
}
