/*

Write a program or function that takes in a nonempty single-line string. You may assume it only contains printable ASCII excluding space.

Print or return an ASCII art lozenge shape similar to a lemon or lime made from the prefixes of the string.

Suppose the input string is n letters long. Then, such a shape consists of 2n - 1 columns of ASCII art stitched together, each consisting of 2n - 1 lines.
Counting from 1, the k-th column is f(k) = min(k, 2n - k) characters wide, and contains f(k) copies of the first f(k) characters of input, centered vertically, with single blank lines separating the copies.

For example, if the input is Lemon, the output should be:

          Lemon
      Lemo     Lemo
   Lem    Lemon    Lem
 Le   Lemo     Lemo   Le
L  Lem    Lemon    Lem  L
 Le   Lemo     Lemo   Le
   Lem    Lemon    Lem
      Lemo     Lemo
          Lemon
If the input is lime the output should be:

      lime
   lim    lim
 li   lime   li
l  lim    lim  l
 li   lime   li
   lim    lim
      lime

And the same pattern is followed for other inputs:

a

a

Be

 Be
B  B
 Be

/\

 /\
/  /
 /\

cat

   cat
 ca   ca
c  cat  c
 ca   ca
   cat

|||

   |||
 ||   ||
|  |||  |
 ||   ||
   |||

.__.

      .__.
   .__    .__
 ._   .__.   ._
.  .__    .__  .
 ._   .__.   ._
   .__    .__
      .__.

$tring

               $tring
          $trin      $trin
      $tri     $tring     $tri
   $tr    $trin      $trin    $tr
 $t   $tri     $tring     $tri   $t
$  $tr    $trin      $trin    $tr  $
 $t   $tri     $tring     $tri   $t
   $tr    $trin      $trin    $tr
      $tri     $tring     $tri
          $trin      $trin
               $tring
Lines in the output may have trailing spaces and there may be one optional trailing newline.

The shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	lemon("a")
	lemon("Be")
	lemon("/\\")
	lemon("cat")
	lemon("|||")
	lemon(".__.")
	lemon("$tring")
	lemon("linenoise")
	lemon("tohka")
	lemon("samidare")
}

/*

ported from @Sp3000 solution

The program essentially does a mask based on L1-norm/Manhattan distance from the centre, as well as the parity of this distance compared to the parity of the input length.

*/

func lemon(s string) {
	fmt.Printf("%q\n", s)
	n := len(s)
	for i := -n + 1; i <= n-1; i++ {
		y := n - abs(i)
		for j := -n + 1; j <= n-1; j++ {
			x := n - abs(j)
			z := (x + y - n) & truth(x+y > n)
			z = min(z*x, n)
			if z == 0 {
				fmt.Print(strings.Repeat(" ", x))
			} else {
				fmt.Print(s[:z])
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
