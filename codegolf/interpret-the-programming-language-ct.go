/*

The programming language CT is a Turing-complete programming language based on cyclic tag systems. Bitwise Cyclic Tag can be substituted into this.

0 in CT <- 10 in BCT
1 in CT <- 11 in BCT
; in CT <- 0 in BCT
It has 3 commands:

; Delete the leftmost data-bit.
0 If leftmost data-bit = 1: Append 0 to the data-string.
1 If leftmost data-bit = 1: Append 1 to the data-string.
You will be given two strings as input: the first being the program and the second being the data-string. Leading spaces are mandatory (they are inserted in place of the leftmost data-bit during the ; command). Example:

Program: 1;;
Data-string: 1111
11111
 1111
  111
  1111
   111
    11
    111
     11
      1
      11
       1
It stops when the data-string is empty. This is code-golf, so the shortest answer in bytes wins!

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	interpret([]byte("1;;"), []byte("1111"))
}

func interpret(code, mem []byte) {
	if len(code) == 0 {
		return
	}

	sp := 0
	pc := 0
	for len(mem) > 0 {
		op := code[pc]
		pc = (pc + 1) % len(code)
		switch op {
		case ';':
			sp += 1
			mem = mem[1:]
		case '0', '1':
			mem = append(mem, op)
		}
		fmt.Printf("%s%s\n", strings.Repeat(" ", sp), mem)
	}
}
