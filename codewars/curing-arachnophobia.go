/*

There is no single treatment that works for every phobia, but some people cure it by being gradually exposed to the phobic situation or object. In this kata we will try curing arachnophobia by drawing primitive spiders.

Our spiders will have legs, body, eyes and a mouth. Here are some examples:

/\((OOwOO))/\

/╲(((0000w0000)))╱\

^(oWo)^

You will be given four values:

    leg size where each value stands for its own leg type: 1 for "^ ^", 2 for "/\ /\", 3 for "/╲ ╱\", 4 for "╱╲ ╱╲"
    body size where each value stands for its own body type: 1 for "( )", 2 for "(( ))", 3 for "((( )))"
    mouth representing the spider's mouth
    eye representing the spider's eye

Note: the eyes are symmetric, and their total amount is 2 to the power of body size.

You will also be given only valid data. That's it for the instructions, you can start coding!

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(drawspider(1, 1, 'W', 'o') == "^(oWo)^")
	assert(drawspider(2, 2, 'w', 'O') == "/\\((OOwOO))/\\")
	assert(drawspider(3, 3, 'w', '0') == "/╲(((0000w0000)))╱\\")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func drawspider(legs, body int, mouth, eyes rune) string {
	buf := new(bytes.Buffer)
	drawlegs(buf, legs, 'l')
	draweyes(buf, body, eyes, 'l')
	fmt.Fprintf(buf, "%c", mouth)
	draweyes(buf, body, eyes, 'r')
	drawlegs(buf, legs, 'r')
	return buf.String()
}

func drawlegs(buf *bytes.Buffer, legs, side int) {
	switch legs {
	case 1:
		fmt.Fprint(buf, `^`)
	case 2:
		fmt.Fprintf(buf, `/\`)
	case 3:
		if side == 'l' {
			fmt.Fprintf(buf, `/╲`)
		} else {
			fmt.Fprintf(buf, `╱\`)
		}
	default:
		fmt.Fprintf(buf, `╱╲`)
	}
}

func draweyes(buf *bytes.Buffer, body int, eye rune, side int) {
	length0 := body
	length1 := (1 << body) >> 1
	char0, char1 := '(', eye
	if side == 'r' {
		char0, char1 = eye, ')'
		length0, length1 = length1, length0
	}

	for range length0 {
		fmt.Fprintf(buf, "%c", char0)
	}
	for range length1 {
		fmt.Fprintf(buf, "%c", char1)
	}
}
