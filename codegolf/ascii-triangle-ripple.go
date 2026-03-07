/*

Ok, my first golf question. Please be gentle :) I know there's way too many ascii puzzles :P but here we go.

The task is simple, use your favorite programming language to print a triangle ripple. The input should be the size of the ripple.

Each triangle is evenly spaced out. Basically, you keep adding the triangles until there is not enough space for the smallest triangle.

You are allowed white spaces anywhere you want as long as the ripples are the same as the example with the correct size.

Example
q)g 1
__
\/
q)g 2
____
\  /
 \/
q)g 3
______
\    /
 \  /
  \/
q)g 4
________
\  __  /
 \ \/ /
  \  /
   \/
q)g 5
__________
\  ____  /
 \ \  / /
  \ \/ /
   \  /
    \/
q)g 6
____________
\  ______  /
 \ \    / /
  \ \  / /
   \ \/ /
    \  /
     \/
q)g 7
______________
\  ________  /
 \ \  __  / /
  \ \ \/ / /
   \ \  / /
    \ \/ /
     \  /
      \/
q)g 8
________________
\  __________  /
 \ \  ____  / /
  \ \ \  / / /
   \ \ \/ / /
    \ \  / /
     \ \/ /
      \  /
       \/

As usual, shortest code wins :)

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 10; i++ {
		ripple(i)
	}
}

// ported from @Reto Koradi solution
func ripple(n int) {
	fmt.Printf("n=%d\n", n)
	for y := 0; y <= n; y++ {
		for x := -n; x < n; x++ {
			b := 2*n - abs(2*x+1)
			c := b - 2*y + 2
			b -= 6 * y
			switch {
			case b > 0:
				fmt.Printf("_")
			case b < -4 && c > 0 && c%4 == 1:
				if x < 0 {
					fmt.Printf("\\")
				} else {
					fmt.Printf("/")
				}
			default:
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
