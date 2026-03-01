/*

100 Prisoners and a light bulb
You may have seen this puzzle over on the puzzles exchange or perhaps heard it somewhere else. If you are unfamiliar with this puzzle check out:

100 Prisoners and a Light bulb

The gist of this puzzle is that there are 100 prisoners, each one is separated from one another and must go into a room one at a time.
The prisoner selected to go into the room is selected uniformly at random each time.
In this room there is a light bulb and a switch, the prisoner must either turn the light on, turn the light off, or do nothing.
At any given time one of the prisoners may say that all 100 prisoners have been in the room at least once.
If he is correct they are all freed, if they are incorrect they are all killed. Prior to being separated the group of prisoners may discuss a strategy and they may never communicate again.

One working strategy:
The prisoners select one prisoner as the leader. When anyone else enters the room they do nothing unless it's the first time they enter the room and the light is off; in that case, they turn the light on.
When the leader enters the room and the light is on then he turns the light off and maintains a counter, adding one to it.
Once he counts 99 (the light has been turned on once for every other prisoner) he knows that all 100 (including himself) have been in the room, and he claims their freedom.

The code challenge:
Take no input into your program.

Simulate the strategy and output the number of times a prisoner entered the room before the leader claimed their freedom.

n represents the number of times a prisoner enters the room for the first time.
k represents the leader of the prisoners.
d represents a data structure holding boolean values for each prisoner.
l represents a boolean value to hold the state of the light bulb.
i represents the number of iterations of the puzzle before it ends.

Examples:
Randomly pick an element from d. if l is false and k[rand] is false then l is now true and d[rand] is true. i = i + 1

Randomly pick an element from d. if l is true and d[rand] is false then do nothing. i = i + 1

Randomly pick an element from d. if l is false and d[rand] is true then do nothing. i = i + 1

Randomly pick an element from d. if d[rand] = k and if l is false then do nothing. i = i + 1

Randomly pick an element from d. if d[rand] = k and if l is true, set l to false, add 1 to n. i = i + 1

Randomly pick an element from d. if d[rand] = k and if l is true and n = 99 then end puzzle. i = i + 1 and output i.

this is code-golf so the shortest code wins. Have Fun!

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(sim(100))
}

func sim(n int) int {
	L := make([]int, n)
	for i := range L {
		L[i] = 1
	}

	b, l, c := 0, 0, 0
	for l < n-1 {
		i := rand.Intn(n)
		if b != 0 && i == n-1 {
			b, l = 0, l+1
		} else if b < 1 && L[i] != 0 {
			b, L[i] = 1, 0
		}
		c += 1
	}
	return c
}
