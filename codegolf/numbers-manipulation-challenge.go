/*

Use any programming language to generate two random digits between 1 and 9 (including both). Then your program should display:

in the first line: the first random digit,
in the second line: the second random digit,
in the third line: a number whose tens and units digits are the first and second random digits respectively,
in the fourth line: the number from the third line raised to the power of 2.
For example, if digits "9" and "2" were generated, your program should display exactly:

9
2
92
8464

*/

package main

import (
	"fmt"
	"math/rand/v2"
)

func main() {
	output()
}

func output() {
	x := 1 + rand.IntN(9)
	y := 1 + rand.IntN(9)
	z := 10*x + y
	w := z * z
	fmt.Println(x)
	fmt.Println(y)
	fmt.Println(z)
	fmt.Println(w)
}
