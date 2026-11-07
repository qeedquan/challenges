/*

Calculate the Liouville number to n decimal places.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	fmt.Println(liouville(7))
}

/*

https://en.wikipedia.org/wiki/Liouville_number
https://oeis.org/A012245

*/
func liouville(n int) string {
	w := new(bytes.Buffer)
	fmt.Fprint(w, "0.")
	for i := 0; i < n; i++ {
		fmt.Fprint(w, trunc(i))
	}
	return w.String()
}

func facts(n int) string {
	if n < 1 {
		return "0"
	}
	return strings.Repeat(facts(n-1), n)
}

func trunc(n int) string {
	if n < 1 {
		return ""
	}

	s := strings.Repeat(facts(n-1), n-1)
	if i := len(s); i >= 1 {
		s = s[:i-1]
	}
	s += "1"

	return s
}
