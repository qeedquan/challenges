/*

Your task is to create a program or function that generates a zipper with a length of 10 lines. Each line of the zipper is represented by two dashes --:

--
--
--
--
--
--
--
--
--
--
The program/function will take a percentage (divisible by 10) as input, and the output will be the zipper "unzipped" (dashes separated) from the top by the percentage, revealing the 1-indexed, lowest level repeated 2 times, with all prior levels repeated 4, 6, 8, ...etc. times, while keeping the bottom of the zipper centered.

Examples
>>10%
-11-
 --
 --
 --
 --
 --
 --
 --
 --
 --

>>50%
-1111111111-
 -22222222-
  -333333-
   -4444-
    -55-
     --
     --
     --
     --
     --

>>100%
-11111111111111111111-
 -222222222222222222-
  -3333333333333333-
   -44444444444444-
    -555555555555-
     -6666666666-
      -77777777-
       -888888-
        -9999-
         -10-

The input (percentage) can be formatted however you like (50%, .5, 50, 5 [zero implied], etc), and it will always be in the range of 0 to 100 and divisible by 10. The spacing in the examples must be preserved in your output.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := range 11 {
		unzip(i * 10)
	}
}

// ported from @Jeremy solution
func unzip(n int) {
	fmt.Printf("%d%%\n", n)
	n /= 10
	p := ""
	for i := 1; i <= 10; i++ {
		switch {
		case n < 0:
			fmt.Printf("%s--", p)
		case i > 9:
			if n&1 != 0 {
				fmt.Printf(" ")
			}
			fmt.Printf("%s-10-", p)
		default:
			p = strings.Repeat(" ", i-1)
			q := strings.Repeat(fmt.Sprint(i), 2*n)
			fmt.Printf("%s-%s-", p, q)
			n -= 1
		}
		fmt.Println()
	}
	fmt.Println()
}
