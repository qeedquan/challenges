/*

Given a single positive odd integer as input, return a converging zigzag as a list of strings, list of lists of characters, or newline-separated string, in this form:

#
 #
  #
   #
    #
   #
  #
 #
  #
   #
  #
You can replace # with any consistent non-whitespace character. Trailing whitespace on each line is allowed and a trailing newline is allowed.

The zig-zag starts at column 1 and for each row moves right one column, until it reaches column n (where n is the input). Then, it moves left to 2, then right to n-1, then left to 3, with the two bounds converging in until the zigzag ends in the middle column ((n+1)/2).

Test Cases
The example above is the test case for 5.

The following are individual test cases:

3
#
 #
  #
 #
7
#
 #
  #
   #
    #
     #
      #
     #
    #
   #
  #
 #
  #
   #
    #
     #
    #
   #
  #
   #
    #
   #
1

#

*/

package main

import "fmt"

func main() {
	for i := range 9 {
		zigzag(i)
	}
}

/*

@Doorknob

Works by analyzing the sequence of number of spaces as (for n=7):

          0
1 2 3 4 5 6 5 4 3 2 1
    2 3 4 5 4 3 2
        3 4 3
And for n=3:

  0
1 2 1

We can see that the middle number (a in the code) runs from [n-1, n/2). Then, the difference between the first number and the middle number is:

a  n  b  2a-n
-------------
6  7  5  5
5  7  3  3
4  7  1  1
2  3  1  1

So, if we have b going through [-(2a-n), 2a-n], a-abs(b) will give us the desired sequence. This is essentially what the code does.

*/

func zigzag(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}

	fmt.Println("#")
	for a := n - 1; a > n/2; a-- {
		for b := n - 2*a; b <= 2*a-n; b++ {
			fmt.Printf(" %*c\n", a-abs(b), '#')
		}
	}
	fmt.Println()
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
