/*

Given an integer n≥2, print a triangle of height n of (triangles of height n of asterisks), as in this SO question.

For n=2, print:

    *
   ***
 *  *  *
*********

For n=3, print:

            *
           ***
          *****
       *    *    *
      ***  ***  ***
     ***************
  *    *    *    *    *
 ***  ***  ***  ***  ***
*************************

For n=4, print:

                        *
                       ***
                      *****
                     *******
                 *      *      *
                ***    ***    ***
               *****  *****  *****
              *********************
          *      *      *      *      *
         ***    ***    ***    ***    ***
        *****  *****  *****  *****  *****
       ***********************************
   *      *      *      *      *      *      *
  ***    ***    ***    ***    ***    ***    ***
 *****  *****  *****  *****  *****  *****  *****
*************************************************
And so on. Some rules:

I write "print", but a function returning a string or list of lines is fine too.
Trailing whitespace on each line is allowed, but not leading whitespace.
Trailing blank lines are allowed.
This is code-golf: write the shortest program you can, measured in bytes.

*/

package main

import "fmt"

func main() {
	for i := 2; i <= 4; i++ {
		tree(i)
	}
}

func tree(n int) {
	fmt.Printf("n=%d\n", n)
	for y := n*n - 1; y >= 0; y-- {
		m := 2*n - 1
		for x := m*m - 1; x >= 0; x-- {
			if abs(x%m-n+1)+y%n < n && abs(x/m-n+1)+y/n < n {
				fmt.Print("*")
			} else if x != 0 {
				fmt.Print(" ")
			} else {
				fmt.Println()
			}
		}
	}
	fmt.Println()
	fmt.Println()
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
