/*

Given a number n, generate the first n columns of this pattern:

                               #
               #               #
       #       #       #       #
   #   #   #   #   #   #   #   #
 # # # # # # # # # # # # # # # #
################################ ...
The height of the column at (1-indexed) n is the number of trailing 0 bits in n's binary representation, plus one. As a result, the bottom layer has every column filled in, the second layer every second column, the third layer every fourth column, etc.

Rules
You may input and output through any standard method.
You may assume the input is an integer between 1 and 999, inclusive.
The output may contain any amount of whitespace, as long as the pattern is intact.
The pattern must be 1-indexed, and in the same format as shown here.
You may use any single non-whitespace character in place of #, but you may not change the space character.

Test cases
1
#

2
 #
##

3
 #
###

4
   #
 # #
####

5
   #
 # #
#####

7
   #
 # # #
#######

32
                               #
               #               #
       #       #       #       #
   #   #   #   #   #   #   #   #
 # # # # # # # # # # # # # # # #
################################
A few larger test cases can be found here.

Scoring
This is code-golf, so the shortest code in bytes in each language wins.

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	tower(1)
	tower(2)
	tower(3)
	tower(4)
	tower(5)
	tower(7)
	tower(32)
	tower(64)
}

func tower(n uint) {
	fmt.Printf("%d\n", n)
	h := bits.UintSize - bits.LeadingZeros(n)
	for y := 0; y < h; y++ {
		for x := uint(1); x <= n; x++ {
			i := bits.TrailingZeros(x) + 1
			if h-y <= i {
				fmt.Printf("#")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
