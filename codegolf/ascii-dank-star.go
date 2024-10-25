/*

Input description
A string (for best results, all characters should be printable and be the same width).

Output description
A character star following the pattern:

0  0  0
 1 1 1
  222
0123210
  222
 1 1 1
0  0  0

where 0, 1 ... are subsequent characters of the string. The output does not necessarily have to be one string - printing the star char by char into the console is fine.

Example
>> star('overflow')
>>

o      o      o
 v     v     v
  e    e    e
   r   r   r
    f  f  f
     l l l
      ooo
overflowolfrevo
      ooo
     l l l
    f  f  f
   r   r   r
  e    e    e
 v     v     v
o      o      o


*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	dankstar("")
	dankstar("a")
	dankstar("ab")
	dankstar("abc")
	dankstar("0123")
	dankstar("overflow")
}

func dankstar(s string) {
	n := len(s)
	for i := 0; i < n-1; i++ {
		print1(s[i], i, n)
	}
	print2(s)
	for i := n - 2; i >= 0; i-- {
		print1(s[i], i, n)
	}
	fmt.Println()
}

func print1(c byte, m, n int) {
	fmt.Print(spaces(m))
	for i := 0; i < 3; i++ {
		fmt.Printf("%c%s", c, spaces(n-m-2))
	}
	fmt.Println(spaces(m))
}

func print2(s string) {
	fmt.Print(s)
	for i := len(s) - 2; i >= 0; i-- {
		fmt.Printf("%c", s[i])
	}
	fmt.Println()
}

func spaces(n int) string {
	if n < 0 {
		return ""
	}
	return strings.Repeat(" ", n)
}
