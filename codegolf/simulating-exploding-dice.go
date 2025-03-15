/*

Your task is to make a program that takes in an integer n > 1, and outputs the roll of a single n-sided die. However, this dice follows the rules for exploding dice.

When you roll the die, check what value you rolled.
If you got the maximum for that kind of die (on a standard d4 that would be 4, or 6 on a d6, etc.), roll again and add the new roll to that total.
Each roll continues adding to the total, until you don't roll the max number anymore.
That final number is still added though.

Your program should take in a single integer n, and roll the exploding n-sided die.
Here's an example distribution to show what it should look like for n=4.
Note that you should never output any multiples of n, since they will always explode.

You can assume the stack size for any recursion you do is infinite, and your random function must meet our standards for randomness (built-in random generator or time/date).
Your random function should also be as uniform as possible, vs. something like a geometric distribution, since these are dice we're talking about.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(roll(4))
	fmt.Println(roll(6))
}

func roll(n int) int {
	r := 0
	for {
		x := rand.Intn(n) + 1
		r += x
		if x != n {
			break
		}
	}
	return r
}
