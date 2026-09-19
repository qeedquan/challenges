/*

Given any string, print it in the form of a triangle where the text runs up and down along each diagonal. For example, an input of "Hello World" should output:

                    d
                  l
                r   d
              o   l
            W   r   d
              o   l
        o   W   r   d
      l       o   l
    l   o   W   r   d
  e   l       o   l
H   l   o   W   r   d
  e   l       o   l
    l   o   W   r   d
      l       o   l
        o   W   r   d
              o   l
            W   r   d
              o   l
                r   d
                  l
                    d

The space between each character in a row must be at least 1, in order to maintain the proper format.

*/

package main

import "fmt"

func main() {
	detonate("Hello World")
	detonate("#")
	detonate("!$")
	detonate("ABC")
	detonate("XYZW")
}

func detonate(s string) {
	n := len(s)
	m := n - 1
	d := -1
	for i := 0; i < 2*n-1; i++ {
		for j := 0; j < n; j++ {
			c := s[j]
			switch {
			case j < m:
				fallthrough
			case j&1 == (n^i)&1:
				c = ' '
			}
			fmt.Printf("%c ", c)
		}
		fmt.Println()
		if m += d; m < 0 {
			m, d = 0, 1
		}
	}
	fmt.Println()
}
