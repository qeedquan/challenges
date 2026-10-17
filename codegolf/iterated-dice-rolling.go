/*

Given an input n where 3 <= n <= 25, perform the following steps, starting with a single n-sided die (faces in the range [1, n], inclusive):

Print the result of rolling the current n-sided dice in play, in the form kdn: X (where X is the result and k is the number of dice in play).
If X is greater than or equal to n/2 times the number of dice in play, add a die. Else, remove a die.
If the number of dice in play is equal to 0 or n, stop. Else, go to step 1.
Example runs (note that the output in parentheses is for explanation and is not required):

6-sided:

1d6: 4 (avg: 3.0, add)
2d6: 6 (avg: 6.0, add)
3d6: 9 (avg: 9.0, add)
4d6: 16 (avg: 12.0, add)
5d6: 13 (avg: 15.0, remove)
4d6: 9 (avg: 12.0, remove)
3d6: 5 (avg: 9.0, remove)
2d6: 7 (avg: 6.0, add)
3d6: 11 (avg: 9.0, add)
4d6: 14 (avg: 12.0, add)
5d6: 17 (avg: 15.0, add)

9-sided:

1d9: 7 (avg: 4.5, add)
2d9: 14 (avg: 9.0, add)
3d9: 18 (avg: 13.5, add)
4d9: 18 (avg: 18.0, add)
5d9: 28 (avg: 22.5, add)
6d9: 26 (avg: 27.0, remove)
5d9: 28 (avg: 22.5, add)
6d9: 34 (avg: 27.0, add)
7d9: 33 (avg: 31.5, add)
8d9: 30 (avg: 36.0, remove)
7d9: 29 (avg: 31.5, remove)
6d9: 35 (avg: 27.0, add)
7d9: 32 (avg: 31.5, add)
8d9: 42 (avg: 36.0, add)

Rules
Outputs must be exactly in the format kdn: X, with newlines separating each roll
You must actually simulate rolling multiple dice; simply returning a random integer in the range [1, n] (inclusive) multiplied by the number of dice currently in play is not allowed, as that does not accurately simulate rolling multiple dice.

Standard loopholes are forbidden
This is code-golf, so the shortest answer in bytes wins

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	sim(6)
	sim(9)
	sim(100)
}

func sim(n int) {
	if n < 1 {
		return
	}

	k := 1
	for {
		x := 0
		for range k {
			x += 1 + rand.Intn(n)
		}
		fmt.Printf("%dd%d: %d\n", k, n, x)

		if x >= k*n/2 {
			k++
		} else {
			k--
		}

		if k <= 0 || k >= n {
			break
		}
	}
	fmt.Println()
}
