/*

Write a program or a function to print the following cube (if you allow me to call it so) in different sizes:

          ^L^L^L^L^L^L^L^L^L^L^L
         //^L^L^L^L^L^L^L^L^L^L^L
        ////^L^L^L^L^L^L^L^L^L^L^L
       //////^L^L^L^L^L^L^L^L^L^L^L
      ////////^L^L^L^L^L^L^L^L^L^L^L
     //////////^L^L^L^L^L^L^L^L^L^L^L
    ////////////^L^L^L^L^L^L^L^L^L^L^L
   //////////////^L^L^L^L^L^L^L^L^L^L^L
  ////////////////^L^L^L^L^L^L^L^L^L^L^L
 //////////////////^L^L^L^L^L^L^L^L^L^L^L
////////////////////^L^L^L^L^L^L^L^L^L^L^L
\\\\\\\\\\\\\\\\\\\\ " " " " " " " " " " "
 \\\\\\\\\\\\\\\\\\ " " " " " " " " " " "
  \\\\\\\\\\\\\\\\ " " " " " " " " " " "
   \\\\\\\\\\\\\\ " " " " " " " " " " "
    \\\\\\\\\\\\ " " " " " " " " " " "
     \\\\\\\\\\ " " " " " " " " " " "
      \\\\\\\\ " " " " " " " " " " "
       \\\\\\ " " " " " " " " " " "
        \\\\ " " " " " " " " " " "
         \\ " " " " " " " " " " "
           " " " " " " " " " " "
The shape is made of pairs of characters: ^L, ", \\, //

Input:
An integer greater than 1, representing the size of the shape.
The one showed above has a size of 11 because each side of each face is made of 11 pairs of characters.
Note that only two faces are fully displayed.

Output:
A cube of the given size.

Here's another example, with a size of 5:

    ^L^L^L^L^L
   //^L^L^L^L^L
  ////^L^L^L^L^L
 //////^L^L^L^L^L
////////^L^L^L^L^L
\\\\\\\\ " " " " "
 \\\\\\ " " " " "
  \\\\ " " " " "
   \\ " " " " "
     " " " " "
This is code-golf, the shortest in bytes wins.

Even though you are not required to do so, it would be nice if you could provide an easy way to check the output of your code

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(shape(5))
	fmt.Println(shape(10))
}

func shape(n int) string {
	r, p := "", ""
	for i := n - 1; i >= 0; i-- {
		x := p + strings.Repeat("//", i) + strings.Repeat("^L", n) + "\n"
		y := p + strings.Repeat("\\\\", i) + strings.Repeat(" \"", n) + "\n"
		r = x + r + y
		p += " "
	}
	return r
}
