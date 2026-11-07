/*

Given a positive integer n output an ASCII hexagon with diagonal side length n, as pictured (note there are 2n _ characters on the top edge)

Examples:
n=1

 __
/  \
\__/
n=2

  ____
 /    \
/      \
\      /
 \____/
n=5

     __________
    /          \
   /            \
  /              \
 /                \
/                  \
\                  /
 \                /
  \              /
   \            /
    \__________/
etc.

Shortest code in bytes wins. Usual input/output methods apply.

*/

package main

import "fmt"

func main() {
	for i := range 9 {
		hexagon(i)
	}
}

func hexagon(n int) {
	const sym = "/\\ _\n"

	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}

	repeat(' ', n)
	repeat('_', 2*n)
	fmt.Println()
	for i, j := 0, 0; i >= 0; {
		repeat(' ', n-i-1)
		fmt.Printf("%c", sym[j])
		repeat(sym[(j&not(i))|2], (n+i)<<1)
		fmt.Printf("%c", sym[not(j)])
		fmt.Println()

		if i += 1 - 2*j; i == n {
			i, j = i-1, 1
		}
	}
	fmt.Println()
}

func repeat(c byte, n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%c", c)
	}
}

func not(x int) int {
	if x != 0 {
		return 0
	}
	return 1
}
