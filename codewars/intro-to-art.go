/*

Help prepare for the entrance exams to art school.

It is known in advance that this year, the school chose the symmetric letter “W” as the object for the image, and the only condition for its image is only the size that is not known in advance, so as training, you need to come up with a way that accurately depicts the object.

Write a function that takes an integer and returns a list of strings with a line-by-line image of the object.

Below is an example function:

get_w(3) # should return:
[
'*   *   *',
' * * * * ',
'  *   *  '
]

get_w(5) # should return:
[
'*       *       *',
' *     * *     * ',
'  *   *   *   *  ',
'   * *     * *   ',
'    *       *    '
]
Return an empty list for height < 2.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	for i := 2; i <= 11; i++ {
		draw(getw(i))
	}
}

func draw(s []string) {
	fmt.Printf("n=%d\n", len(s))
	for i := range s {
		fmt.Println(s[i])
	}
	fmt.Println()
}

func getw(n int) []string {
	r := []string{}
	if n < 2 {
		return r
	}

	r = append(r, outf("* * *", 2*n-3, 2*n-3))
	for i := 1; i < n-1; i++ {
		n0 := i
		n1 := 2*n - 3 - 2*i
		n2 := n + 3*(n-1) - (2*n1 + 4 + 2*i)
		r = append(r, outf(" * * * * ", n0, n1, n2, n1, n0))
	}
	r = append(r, outf(" * * ", n-1, 2*n-3, n-1))
	return r
}

func outf(f string, a ...int) string {
	w := new(bytes.Buffer)
	i := 0
	for _, r := range f {
		n := 1
		if r == ' ' {
			n, i = a[i], i+1
		}

		for range n {
			w.WriteRune(r)
		}
	}
	return w.String()
}
