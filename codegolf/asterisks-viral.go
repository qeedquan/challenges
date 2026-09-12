/*

Given a positive integer N ("virality"), your program should create an ASCII-art drawing of a tree with two branches of length N extending downwards and/or rightwards from the top-left corner.

The direction taken by each branch after the first asterisk can be either rightwards or downwards, and this choice should be made randomly1 at every next step.

For example, given an input of 5, the output might look like:

***
* ***
**
 **
The two branches are allowed to touch (be on adjacent cells), but not overlap (be on the same cell), so the following would not be allowed:

***
* *
*****
  *
  *
Examples
For input 1, the only possible output is:

**
*
(This will be present in all valid outputs, since having the two branches take the same path would cause them to overlap.)

Possible outputs for an input of 3 include:

***
* *
**
**
***
*
*
For input 7:

****
*  **
*   **
*
***
  *
For input 10:

****
*  *
*********
  *
  *****
This is code-golf, so the shortest valid answer (in bytes) wins.

1. This should uniformly random (i.e. a 50/50 chance of each direction), or as close to uniformly random as you can get on normal hardware.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	for i := range 21 {
		output(viral(i))
	}
}

func output(m [][]byte) {
	fmt.Printf("n=%d\n", len(m))
	for i := range m {
		fmt.Printf("%s\n", m[i])
	}
	fmt.Println()
}

// ported from @O.O.Balance solution
func viral(n int) [][]byte {
	m := alloc(n + 1)
	i, j := 0, 0
	k, l := 0, 0
	r, s := 0, 0
	t, u := 0, 0
	for ; n >= 0; n-- {
		i += r
		j += s
		k += t
		l += u
		m[i][j] = '*'
		m[k][u] = '*'
		for {
			r = rand.Intn(2)
			t = rand.Intn(2)
			s = r ^ 1
			u = t ^ 1
			if !(i+r == k+t && j+s == l+u) {
				break
			}
		}
	}
	return m
}

func alloc(n int) [][]byte {
	m := make([][]byte, n)
	for i := range m {
		m[i] = make([]byte, n)
		for j := range m {
			m[i][j] = ' '
		}
	}
	return m
}
