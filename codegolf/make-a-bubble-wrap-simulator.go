/*

Bubble-wraps are maximum-level entertainment. Everyone can agree to that.

Now, you will make even computers enjoy bubble-wraps.

Specs
You will be given two integers, w, and h.(each are responsively width and height)

Your program should output all w*h phases waiting 1 second between each one and terminate.

Every bubble-wrap starts with all cells full.

For example, a 4*6 bubble-wrap starts like:

O_O_
_O_O
O_O_
_O_O
O_O_
_O_O
And each phase, a random non-popped cell is popped.For example,

O_O_
_O_O
O_X_
_O_O
O_O_
_O_O
The program should terminate when all the cells are popped. aka.

X_X_
_X_X
X_X_
_X_X
X_X_
_X_X
Examples
(4,6)
(5,5)
(6,2)
(10,10)
(7,9)

*/

package main

import (
	"fmt"
	"math/rand/v2"
)

func main() {
	bubblewrap(4, 6)
	bubblewrap(5, 5)
	bubblewrap(6, 2)
	bubblewrap(10, 10)
	bubblewrap(7, 9)
}

func bubblewrap(w, h int) {
	fmt.Printf("w=%d h=%d\n", w, h)
	if w < 1 || h < 1 {
		return
	}

	m, p := alloc(w, h)
	for {
		show(m)
		if len(p) == 0 {
			break
		}
		y := p[0] / w
		x := p[0] % w
		m[y][x] = 'X'
		p = p[1:]
	}
}

func alloc(w, h int) ([][]byte, []int) {
	const sym = "O_"

	m := make([][]byte, h)
	p := []int{}
	i := 0
	for y := range m {
		m[y] = make([]byte, w)
		for x := range m[y] {
			m[y][x] = sym[i]
			if i == 0 {
				p = append(p, y*w+x)
			}
			i ^= 1
		}
		i ^= 1
	}
	rand.Shuffle(len(p), func(i, j int) {
		p[i], p[j] = p[j], p[i]
	})
	return m, p
}

func show(m [][]byte) {
	for y := range m {
		fmt.Printf("%s\n", m[y])
	}
	fmt.Println()
}
