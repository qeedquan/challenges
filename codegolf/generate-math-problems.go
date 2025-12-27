/*

Generate math problems (addition, subtraction, or multiplication) using numbers 0-10. Provide feedback on whether the user was right or wrong and show a score.

Specifics:

Must generate addition, subtraction, or multiplication problems
Numbers used must be 0-10
Each problem must be equally likely
If user is correct, must print "correct!" (with the exclamation point)
If user is wrong, must print "wrong!" (with the exclamation point)
After providing correct or wrong feedback, must show score with these specifications:

Starts with "Score:"
Shows number correct and then "correct"
Pipe (|) separation
Shows number wrong and then "wrong"
2 newlines for separation
Must repeat forever

For counting characters, the Text Mechanic counter will be used.

Sample session:

1-7=-6
correct!
Score: 1 correct | 0 wrong

9+3=12
correct!
Score: 2 correct | 0 wrong

4*5=20
correct!
Score: 3 correct | 0 wrong

7-8=3
wrong!
Score: 3 correct | 1 wrong

1*1=3
wrong!
Score: 3 correct | 2 wrong

7+6=

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	play()
}

func play() {
	const ops = "+-*"

	c, w := 0, 0
	for {
		i := rand.Intn(3)
		x := rand.Intn(11)
		y := rand.Intn(11)

		z0 := binop(ops[i], x, y)
		z1 := 0

		fmt.Printf("%d%c%d=", x, ops[i], y)
		n, err := fmt.Scan(&z1)
		if n != 1 || err != nil {
			break
		}

		if z0 == z1 {
			fmt.Println("correct!")
			c += 1
		} else {
			fmt.Println("wrong!")
			w += 1
		}
		fmt.Printf("Score: %d correct | %d wrong\n\n", c, w)
	}
	fmt.Println()
}

func binop(op byte, x, y int) int {
	switch op {
	case '+':
		return x + y
	case '-':
		return x - y
	case '*':
		return x * y
	}
	return 0
}
