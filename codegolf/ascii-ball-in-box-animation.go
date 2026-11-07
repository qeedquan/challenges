/*

Write a program that displays a moving ASCII ball * inside a rectangle (20 by 10 chars including border). The ball must not cross the rectangle, e.g. bump off when it hits the wall. The scene must be cleared and redrawn every 0.1 seconds and the ball must move 1 char in x and y direction every frame. The shortest program written in any language wins.

Example output (frame 1)

+------------------+
|*                 |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
+------------------+
Example output (frame 2)

+------------------+
|                  |
| *                |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
+------------------+
Example output (frame 8)

+------------------+
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|       *          |
+------------------+
Example output (frame 9)

+------------------+
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|        *         |
|                  |
+------------------+

*/

package main

import (
	"fmt"
	"strings"
	"time"
)

const (
	W = 18
	H = 8
)

func main() {
	animate()
}

func animate() {
	x, y := 0, 0
	dx, dy := 1, 1
	for {
		draw(x, y)
		x, y, dx, dy = update(x, y, dx, dy)
		fmt.Printf("[%d, %d]\n", x, y)
		time.Sleep(100 * time.Millisecond)
	}
}

func update(x, y, dx, dy int) (int, int, int, int) {
	x += dx
	y += dy
	if x < 0 || x >= W {
		x = clamp(x, 0, W-1)
		dx = -dx
	}
	if y < 0 || y >= H {
		y = clamp(y, 0, H-1)
		dy = -dy
	}

	return x, y, dx, dy
}

func draw(x, y int) {
	fmt.Printf("\033c")
	fmt.Printf("+%s+\n", strings.Repeat("-", W))
	for h := 0; h < H; h++ {
		fmt.Printf("|")
		for w := 0; w < W; w++ {
			if x == w && y == h {
				fmt.Printf("*")
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Printf("|\n")
	}
	fmt.Printf("+%s+\n", strings.Repeat("-", W))
}

func clamp(x, a, b int) int {
	if x < a {
		x = a
	} else if x > b {
		x = b
	}
	return x
}
