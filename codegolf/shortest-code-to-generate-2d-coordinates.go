/*

I'm looking for the shortest code to generate the following sequences:

Sequence A
i | y x
0 | 0 0
1 | 0 1
2 | 1 0
3 | 1 1
The best I have is x = i % 2, y = i / 2, there is probably no beating that. Those are coordinates of corners of a box in 2D, but they are not in a good order for drawing. To draw a box as line loop, one needs those coordinates:

Sequence B
i | y x
0 | 0 0
1 | 0 1
2 | 1 1
3 | 1 0
So far, I have x = (i ^ i / 2) % 2, y = i / 2. There is likely space for improvement there. Finally, how to generate directions towards the box edges (where the order does not matter, but i still must be 0 to 3):

Sequence C
i |  y  x
? |  0 -1
? |  0  1
? | -1  0
? |  1  0
So far I have rather ugly x = (1 | -(i % 2)) * (i / 2), y = (1 | -(i % 2)) * (1 - i / 2).

Shortest code in any programming language wins (I actually plan to use these). The best solution will be used in a closed-source project, no attribution can be paid other than source code comment, so post only if you're ok with it. Submit solutions to any of the above sequences. Don't bother writing code that generates all of them, think of it like competition with three categories (and tree possible winners).

*/

package main

import "fmt"

func main() {
	output()
}

func output() {
	for i := range 4 {
		x := (1 | -(i % 2)) * (i / 2)
		y := (1 | -(i % 2)) * (1 - i/2)
		fmt.Printf("%d | % d % d\n", i, x, y)
	}
}
