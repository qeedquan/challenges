/*

A binary eye is an odd set of digits, with all of its digits except the center one set to 1 or 0, and the center one set to the opposite of the others. Thus, there are two binary eyes for a given odd number of digits:

x	eyes
1	1,0
3	101,010
5	11011,00100
7	1110111,0001000
9	111101111,000010000

Make the smallest program possible, in any language, that prints out x number of binary eyes. For example, with an input of two, the program would output
1,0 and 101,010.
With 3 it should output that and the next, and with 4 the next as well, and so on. with 5 it should output the complete table above. You can also have it just continue giving outputs, as long as it outputs only correct outputs, and at least the number of outputs asked for.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(eyes(1) == "1,0")
	assert(eyes(3) == "101,010")
	assert(eyes(5) == "11011,00100")
	assert(eyes(7) == "1110111,0001000")
	assert(eyes(9) == "111101111,000010000")
	for i := 0; i <= 10; i++ {
		fmt.Println(i, eyes(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eyes(n int) string {
	if n < 1 {
		return ""
	}
	if n == 1 {
		return "1,0"
	}

	if n&1 == 0 {
		return fmt.Sprint(eyes(n-1), " ", eyes(n+1))
	}

	w := new(bytes.Buffer)
	squiggle(w, n/2, '1', '0')
	w.WriteRune(',')
	squiggle(w, n/2, '0', '1')
	return w.String()
}

func squiggle(w *bytes.Buffer, n int, a, b rune) {
	for i := 0; i < n; i++ {
		w.WriteRune(a)
	}
	w.WriteRune(b)
	for i := 0; i < n; i++ {
		w.WriteRune(a)
	}
}
