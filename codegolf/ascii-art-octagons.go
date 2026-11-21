/*

Given an input integer n > 1, output an ASCII-art octagon with side lengths composed of n characters. See examples below:

n=2
 ##
#  #
#  #
 ##

n=3
  ###
 #   #
#     #
#     #
#     #
 #   #
  ###

n=4
   ####
  #    #
 #      #
#        #
#        #
#        #
#        #
 #      #
  #    #
   ####

n=5
    #####
   #     #
  #       #
 #         #
#           #
#           #
#           #
#           #
#           #
 #         #
  #       #
   #     #
    #####

and so on.
You can print it to STDOUT or return it as a function result.

Any amount of extraneous whitespace is acceptable, so long as the characters line up appropriately.

Rules and I/O
Input and output can be given by any convenient method.
You can use any printable ASCII character instead of the # (except space), but the "background" character must be space (ASCII 32).
Either a full program or a function are acceptable.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 10; i++ {
		octagon(i)
	}
}

/*

@Arnauld

How?
This builds the output character by character.

Given the input n, we compute:

n' = n-1
w  = 3n'

For each character at (x,y), we compute (h,v):

h=w/2 - |x-w/2|
v=w/2 - |y-w/2|

The cells belonging to the octagon satisfy one of the following conditions:

((h=0 OR v=0) AND h+v≥n') OR h+v=n':

*/

func octagon(n int) {
	m := n - 1
	w := 3*m + (n & 1)
	fmt.Printf("n=%d\n", n)
	for y := 0; y < w; y++ {
		for x := 0; x < w; x++ {
			h := w/2 - abs(x-w/2)
			v := w/2 - abs(y-w/2)
			if ((h == 0 || v == 0) && h+v >= m) || (h+v == m) {
				fmt.Printf("#")
			} else {
				fmt.Printf(" ")
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
