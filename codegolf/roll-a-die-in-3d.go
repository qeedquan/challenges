/*

Simulate a roll of a fair die, and output the result in this ascii-art form:

    .-----------.
   / o       o /|
  /           /o|
 / o       o /  |
:-----------:o o|
| o       o |   |
|           |o o:
|     o     |  /
|           |o/
| o       o |/
'-----------'
Details
The outline of the die (i.e. the non-o characters) should be exactly as shown (with this orientation). The three faces should show the pip-patterns resulting from a random roll, in the manner shown.

You must simulate one fixed physical die. It must have faces 1...6 with opposite faces summing to 7.

You can choose whether the arrangement is left or right handed (i.e. whether 1-2-3 go clockwise or anticlockwise around their corner), and you can choose the orientations of the 2, 3 and 6 pip-patterns on their faces. For example, you might choose that the 6 face has its two lines of three pips next to the 3 and 4 faces. However, once these choices are made they must be used consistently, in the sense that the physical die cannot change its makeup. It just rotates randomly.

Thus, once the above choices are made, there should be exactly 24 possible outputs (8 choices for the sticking out corner * 3 rotations), and the program should output one of them chosen uniformly at random (as approximated by any reasonable PRNG).

The pip-patterns are as follows (with - for spaces for clarity). Each should be transformed by the appropriate affine map to fit on the face as in the example above.

---  ---  o--  o-o  o-o  ooo
-o-  o-o  -o-  ---  -o-  ---
---  ---  --o  o-o  o-o  ooo
Note: As has been pointed out, this choice of 2-pip pattern might be less common in real dice, but in the interests of fairness I'll insist on sticking to these patterns.

To make it completely explicit, each number's pips are a subset of

ooo
ooo
ooo
and here is what the die would look like with all 9 pips on every face:

    .-----------.
   / o   o   o /|
  / o   o   o /o|
 / o   o   o /o |
:-----------:o o|
| o   o   o | o |
|           |o o:
| o   o   o | o/
|           |o/
| o   o   o |/
'-----------'
The output can be printed, or output as a string with newlines or a sequence of lines. Trailing spaces and up to one trailing blank line are allowed.

This is code-golf so shortest program in each language wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"strings"
)

func main() {
	for range 50 {
		roll()
	}
}

func roll() {
	draw(rand.Intn(24))
}

func draw(n int) {
	if !(0 <= n && n < 24) {
		return
	}

	p := strings.Split(ART, "\n")
	fmt.Printf("n=%d\n", n)
	for i := 0; i < 11; i++ {
		fmt.Println(p[(11*n)+i+1])
	}
	fmt.Println()
}

const ART = `
    .-----------.
   /           /|
  /     o     /o|
 /           /  |
:-----------:   |
|           | o |
|           |   :
| o       o |  /
|           |o/
|           |/
'-----------'
    .-----------.
   /           /|
  /     o     /o|
 /           /  |
:-----------:o  |
|         o | o |
|           |  o:
|     o     |  /
|           |o/
| o         |/
'-----------'
    .-----------.
   /           /|
  /     o     /o|
 /           /  |
:-----------:o  |
| o       o |   |
|           |  o:
|     o     |  /
|           |o/
| o       o |/
'-----------'
    .-----------.
   /           /|
  /     o     / |
 /           /  |
:-----------:  o|
| o       o |   |
|           |o  :
|           |  /
|           | /
| o       o |/
'-----------'
    .-----------.
   /           /|
  / o       o / |
 /           /  |
:-----------:o  |
| o   o   o | o |
|           |  o:
|           |  /
|           | /
| o   o   o |/
'-----------'
    .-----------.
   /     o     /|
  /           / |
 /     o     /  |
:-----------:   |
| o         | o |
|           |   :
|     o     |  /
|           | /
|         o |/
'-----------'
    .-----------.
   /           /|
  / o       o /o|
 /           /  |
:-----------:o  |
|           |   |
|           |  o:
|     o     |  /
|           |o/
|           |/
'-----------'
    .-----------.
   /     o     /|
  /           /o|
 /     o     /o |
:-----------:o  |
| o       o |   |
|           |  o:
|           | o/
|           |o/
| o       o |/
'-----------'
    .-----------.
   / o         /|
  /     o     / |
 /         o /  |
:-----------:   |
| o       o | o |
|           |   :
|     o     |  /
|           | /
| o       o |/
'-----------'
    .-----------.
   /         o /|
  /     o     / |
 / o         /o |
:-----------:   |
|           |   |
|           |   :
|     o     | o/
|           | /
|           |/
'-----------'
    .-----------.
   / o         /|
  /     o     /o|
 /         o /  |
:-----------:o o|
|     o     |   |
|           |o o:
|           |  /
|           |o/
|     o     |/
'-----------'
    .-----------.
   /         o /|
  /     o     /o|
 / o         /  |
:-----------:o  |
| o       o | o |
|           |  o:
| o       o |  /
|           |o/
| o       o |/
'-----------'
    .-----------.
   / o       o /|
  /           /o|
 / o       o /  |
:-----------:o o|
| o       o |   |
|           |o o:
|     o     |  /
|           |o/
| o       o |/
'-----------'
    .-----------.
   / o       o /|
  /           / |
 / o       o /o |
:-----------:   |
| o       o |   |
|           |   :
| o       o | o/
|           | /
| o       o |/
'-----------'
    .-----------.
   / o       o /|
  /           / |
 / o       o /  |
:-----------:   |
|     o     | o |
|           |   :
|           |  /
|           | /
|     o     |/
'-----------'
    .-----------.
   / o       o /|
  /           /o|
 / o       o /  |
:-----------:o  |
|           | o |
|           |  o:
|     o     |  /
|           |o/
|           |/
'-----------'
    .-----------.
   / o       o /|
  /     o     / |
 / o       o /  |
:-----------:o  |
|           | o |
|           |  o:
|     o     |  /
|           | /
|           |/
'-----------'
    .-----------.
   / o       o /|
  /     o     /o|
 / o       o /o |
:-----------:o  |
| o         |   |
|           |  o:
|     o     | o/
|           |o/
|         o |/
'-----------'
    .-----------.
   / o       o /|
  /     o     /o|
 / o       o /  |
:-----------:o  |
| o   o   o |   |
|           |  o:
|           |  /
|           |o/
| o   o   o |/
'-----------'
    .-----------.
   / o       o /|
  /     o     / |
 / o       o /  |
:-----------:   |
| o       o | o |
|           |   :
|           |  /
|           | /
| o       o |/
'-----------'
    .-----------.
   / o   o   o /|
  /           /o|
 / o   o   o /  |
:-----------:   |
| o       o | o |
|           |   :
|     o     |  /
|           |o/
| o       o |/
'-----------'
    .-----------.
   / o       o /|
  / o       o / |
 / o       o /  |
:-----------:  o|
|         o |   |
|           |o  :
|     o     |  /
|           | /
| o         |/
'-----------'
    .-----------.
   / o   o   o /|
  /           /o|
 / o   o   o /  |
:-----------:o  |
|           |   |
|           |  o:
| o       o |  /
|           |o/
|           |/
'-----------'
    .-----------.
   / o       o /|
  / o       o /o|
 / o       o /  |
:-----------:o  |
| o       o | o |
|           |  o:
|           |  /
|           |o/
| o       o |/
'-----------'
`
