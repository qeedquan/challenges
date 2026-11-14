/*

Starting with /\ you can create a Sierpinski triangle like pattern by adding a line beneath such that...

Any loose branch / or \ splits again into two branches: /\.
Any collision of branches \/ dies with nothing (but spaces) under it.
Repeating these rules yields

     /\
    /\/\
   /\  /\
  /\/\/\/\
 /\      /\
/\/\    /\/\
etc...
(Inspiration by ViHart)

Write a program or function that takes in a positive integer N and prints the first N lines of this pattern to stdout, with no more leading or trailing spaces than necessary.

For example, if the input is 1 the output must be

/\

If the input is 2 the output must be

 /\
/\/\

If the input is 8 the output must be

       /\
      /\/\
     /\  /\
    /\/\/\/\
   /\      /\
  /\/\    /\/\
 /\  /\  /\  /\
/\/\/\/\/\/\/\/\
And so on.

The code with the fewest bytes wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := range 11 {
		sierpinski(i)
	}
}

// ported from @pbochniak solution
func sierpinski(n int) {
	fmt.Printf("n=%d\n", n)
	for x := 1; n > 0; x ^= (x << 1) {
		n -= 1
		s := strings.Repeat(" ", n)
		t := fmt.Sprintf("%b", x)
		t = strings.Replace(t, "0", `  `, -1)
		t = strings.Replace(t, "1", `/\`, -1)
		fmt.Printf("%s%s\n", s, t)
	}
	fmt.Println()
}
