/*

The input is a string consisting of the characters _ / \ L V space and newline defining a simple polygon (which means no extra segments, no self-touch and no self-intersect).

The area of a single character cell is 2

_ splits the cell into sizes 0 and 2
\ splits the cell into sizes 1 and 1
/ splits the cell into sizes 1 and 1
L splits the cell into sizes 0 and 2
V splits the cell into sizes 1 and 1 (The two sides of the V will always be on the same side of the polygon so they are treated together in the listing.)
Every character connects the two corners of its character cell which you expect (e.g. top left and top right in case of V).

An example with area of 7 (1+2+1 in the second row and 1+1+1 in the third one):

 _
/ \
V\/
Input
Input will form a rectangle, i.e. there will be the same number of characters between newlines.
There can be extra whitespace on any side of the polygon.
Trailing newline is optional.
Output
A single positive integer, the area of the polygon.
Examples
Outputs are after the last row of their inputs.

  _
  V

1

/L
\/

3



    /VV\
    L  /
     L/
14

  ____/\
  \    /
/\/   /
\____/

32

   /V\
  /   \__
  \     /
/\/   /V
L____/

45

This is code-golf so the shortest entry wins.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	assert(area(ART1) == 7)
	assert(area(ART2) == 1)
	assert(area(ART3) == 3)
	assert(area(ART4) == 14)
	assert(area(ART5) == 32)
	assert(area(ART6) == 45)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// Ported from @Toby Speight solution
func area(s string) int {
	a := 0
	i := 0
	for _, r := range s {
		if strings.IndexRune("\nV_ ", r) < 0 {
			i ^= 1
		}

		n := i + i
		if strings.IndexRune("\\/V", r) >= 0 {
			n = 1
		}
		a += n
	}
	return a
}

func mkart(s string) string {
	w := new(bytes.Buffer)
	t := strings.Split(s, "\n")
	for _, t := range t {
		if strings.TrimSpace(t) == "" {
			continue
		}
		fmt.Fprintf(w, "%s\n", t)
	}

	r := w.String()
	n := len(r)
	if n > 0 {
		r = r[:n-1]
	}
	return r
}

var ART1 = mkart(`
 _
/ \
V\/
`)

var ART2 = mkart(`
  _
  V
`)

var ART3 = mkart(`
/L
\/
`)

var ART4 = mkart(`
    /VV\
    L  /
     L/
`)

var ART5 = mkart(`
  ____/\ 
  \    /
/\/   /
\____/
`)

var ART6 = mkart(`
   /V\
  /   \__
  \     /
/\/   /V
L____/
`)
