/*

aka. implement an easier version of 05ab1e's canvas element.

Description
The canvas element is used to draw ASCII lines on the screen.
The (easier version of the) canvas element takes a list of integers and returns a multi-line string (or a list of strings). The integers map to the following directions:

7   0   1
  ↖ ↑ ↗
6 ← X → 2
  ↙ ↓ ↘
5   4   3

0: upwards
1: top-right
2: right
3: bottom-right
4: downwards
5: bottom-left
6: left
7: top-left
If given eg. [6, 4, 2], it outputs this:

###
#
###

Explanation Image
https://i.stack.imgur.com/78ZyB.png

Start with one hash already drawn (X)
Draw two hashes towards the left (direction 6)
Draw two hashes downwards (direction 4)
Draw two hashes towards the right (direction 2)

Rules
Default Loopholes apply
Multiple integers or a list of integers will be given as the input
Output must be a string, a list of strings, or a matrix of characters (like a binary matrix)
You will not receive directions with intersecting lines
You can replace # with any other constant character, but you'll always have to draw 2 hashes per direction and start with a hash
Excess whitespace is allowed
The shortest code, as this is code-golf, wins

Examples
In: [1, 5, 3, 7, 5, 1, 7, 3]
Out:
#   #
 # #
  #
 # #
#   #

In: [2, 2, 2, 2, 4, 4, 7, 7]
Out:
#########
     #  #
      # #
       ##
        #

In: [1, 2, 3, 6, 6, 2, 4, 2, 2, 4, 2, 6, 4, 2, 1, 3, 2, 6, 7, 5, 6, 6, 4, 0, 6, 4, 0, 6, 0, 6, 2, 0, 2]
Out:
  ###
 #   #
# #####
    #
  #######
  #     #
###     ### #
  #     #  # #
  #########   ###
    # #
    # #

```

*/

package main

import (
	"bytes"
	"fmt"
	"math"
)

func main() {
	fmt.Println(scribble([]int{6, 4, 2}))
	fmt.Println(scribble([]int{1, 5, 3, 7, 5, 1, 7, 3}))
	fmt.Println(scribble([]int{2, 2, 2, 2, 4, 4, 7, 7}))
	fmt.Println(scribble([]int{1, 2, 3, 6, 6, 2, 4, 2, 2, 4, 2, 6, 4, 2, 1, 3, 2, 6, 7, 5, 6, 6, 4, 0, 6, 4, 0, 6, 0, 6, 2, 0, 2}))
}

func scribble(a []int) string {
	dirs := [][2]int{
		{0, -1},
		{1, -1},
		{1, 0},
		{1, 1},
		{0, 1},
		{-1, 1},
		{-1, 0},
		{-1, -1},
	}

	if len(a) == 0 {
		return ""
	}

	x, y, m := 0, 0, map[[2]int]bool{{0, 0}: true}
	for _, d := range a {
		if 0 <= d && d < len(dirs) {
			for i := 0; i < 2; i++ {
				x += dirs[d][0]
				y += dirs[d][1]
				k := [2]int{x, y}
				m[k] = true
			}
		}
	}

	x0, y0 := math.MaxInt, math.MaxInt
	x1, y1 := math.MinInt, math.MinInt
	for p := range m {
		x0 = min(x0, p[0])
		y0 = min(y0, p[1])
		x1 = max(x1, p[0])
		y1 = max(y1, p[1])
	}

	w := new(bytes.Buffer)
	for y := y0; y <= y1; y++ {
		for x := x0; x <= x1; x++ {
			k := [2]int{x, y}
			if m[k] {
				fmt.Fprint(w, "#")
			} else {
				fmt.Fprint(w, " ")
			}
		}
		fmt.Fprintln(w)
	}
	return w.String()
}
