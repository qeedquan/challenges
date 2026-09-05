/*

Problem
Starting from n=2 dice:

Roll n dice, with each number 1 to 6 equally likely on each die.
Check if their sum equals the most probable sum for n dice, that is 3.5*n.
If they're equal, terminate.
Otherwise, print n, and repeat from the start with n+2 dice
Your code doesn't have to do this procedure exactly, but should give random output probabilistically equivalent to it, based on our definition of randomness.

Your program should output all of the numbers on their own line; for example, if the program got up to 8 dice and rolled the most probable number with 8 dice, the output would be:

2
4
6

Example Run
On 2 dice, 7 is the most probable sum. Let's say the numbers rolled were 2 and 3. Then, you would print 2.

On 4 dice, 14 is the most probable sum. Let's say the numbers rolled were 3, 4, 2, and 5. Then, the sum is 14, so the program would terminate here.

The final output in this case is "2".

Rules
code-golf so shortest solution in bytes wins
Standard Loopholes Apply
The meta definition of randomness applies
You may use functions as well as programs

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	sim()
}

func sim() {
	for n := 2; ; n += 2 {
		s := 0
		for range n {
			s += rand.Intn(6) + 1
		}

		t := int(3.5 * float64(n))
		if s == t {
			break
		}

		fmt.Println(n)
	}
}
