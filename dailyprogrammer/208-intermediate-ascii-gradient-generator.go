/*

A linear colour gradient is where an image transitions through a range of colours, like this. A gradient doesn't need to be directly horizontal or vertical - it can be diagonal too, or only be longer or shorter than usual. It can also cycle through as many colours as you like.

A radial colour gradient is a similar concept, except the colours move radially outwards like this, rather than linearly across. Radial gradients can also be in different positions or with different colours.

To describe a gradient, you need two things - the colours in it, and its location. Describing the location of a radial gradient is easy: for a radial gradient like this, you only need to know the center of the gradient (the red dot), and the radius from the center at which the gradient finishes (r). To locate a linear gradient like this, you need to know two points - the start (red) and end (green) location. The gradient colours run perpendicular to the line joining the start and end points.

Today, we won't be dealing with colours. Instead, we'll be dealing with characters on the screen. You'll accept the parameters of a gradient, and you'll output the displayed gradient.

Formal Inputs and Outputs
Input Description
You will first accept the size of the output display, as a width and height in characters, like this:

40 30
This corresponds to a grid 40 across and 30 down, like this:

........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
........................................
The grid follows screen space, so the top-left corner is position (0, 0).

Next, you will accept the characters that make up the gradient 'colours', from start to finish (or from inside to outside, for a radial gradient), like this: (note the space at the start)

 .,:;xX&@
Any points outside the gradient will have the first/last character, depending on which side of the gradient they're on.

After this, you will accept the parameters of the gradient. This may take one of two forms:

For a radial gradient, the next line will look like this:
radial x y r
Where (x, y) is the center of the gradient, and r is the radius of the gradient, both in pixels.

For a linear gradient, the next line will look like this:
linear x1 y1 x2 y2
Where (x1, y1) is the start point of the gradient, and (x2, y2) is the end point of the gradient, both in pixel measure.

Output Description
You are to display the given gradient on a grid with the given size, like this:

@@@@@@@@@@@&&&&&XXXXXXXXX&&&&&@@@@@@@@@@
@@@@@@@@@@&&&&XXXXXXXXXXXXX&&&&@@@@@@@@@
@@@@@@@@&&&&XXXXXXxxxxxXXXXXX&&&&@@@@@@@
@@@@@@@&&&&XXXXxxxxxxxxxxxXXXX&&&&@@@@@@
@@@@@@@&&&XXXxxxxxx;;;xxxxxxXXX&&&@@@@@@
@@@@@@&&&XXXxxxx;;;;;;;;;xxxxXXX&&&@@@@@
@@@@@&&&XXXxxx;;;;;;;;;;;;;xxxXXX&&&@@@@
@@@@@&&XXXxxx;;;;:::::::;;;;xxxXXX&&@@@@
@@@@&&&XXxxx;;;:::::::::::;;;xxxXX&&&@@@
@@@@&&XXXxx;;;::::,,,,,::::;;;xxXXX&&@@@
@@@&&&XXxxx;;:::,,,,,,,,,:::;;xxxXX&&&@@
@@@&&XXXxx;;;::,,,,...,,,,::;;;xxXXX&&@@
@@@&&XXXxx;;:::,,.......,,:::;;xxXXX&&@@
@@@&&XXxxx;;::,,,... ...,,,::;;xxxXX&&@@
@@@&&XXxx;;;::,,...   ...,,::;;;xxXX&&@@
@@@&&XXxx;;;::,,..     ..,,::;;;xxXX&&@@
@@@&&XXxx;;;::,,...   ...,,::;;;xxXX&&@@
@@@&&XXxxx;;::,,,... ...,,,::;;xxxXX&&@@
@@@&&XXXxx;;:::,,.......,,:::;;xxXXX&&@@
@@@&&XXXxx;;;::,,,,...,,,,::;;;xxXXX&&@@
@@@&&&XXxxx;;:::,,,,,,,,,:::;;xxxXX&&&@@
@@@@&&XXXxx;;;::::,,,,,::::;;;xxXXX&&@@@
@@@@&&&XXxxx;;;:::::::::::;;;xxxXX&&&@@@
@@@@@&&XXXxxx;;;;:::::::;;;;xxxXXX&&@@@@
@@@@@&&&XXXxxx;;;;;;;;;;;;;xxxXXX&&&@@@@
@@@@@@&&&XXXxxxx;;;;;;;;;xxxxXXX&&&@@@@@
@@@@@@@&&&XXXxxxxxx;;;xxxxxxXXX&&&@@@@@@
@@@@@@@&&&&XXXXxxxxxxxxxxxXXXX&&&&@@@@@@
@@@@@@@@&&&&XXXXXXxxxxxXXXXXX&&&&@@@@@@@
@@@@@@@@@@&&&&XXXXXXXXXXXXX&&&&@@@@@@@@@
Sample Inputs and Outputs
Gradient 1
Input
40 30
 .,:;xX&@
radial 20 15 20
Output
(shown above, in Output Description)

Gradient 2
Notice how the colours appear in the reverse order, as the end point is to the left of the start point.

Input
60 30
 '"^+$
linear 30 30 0 0
Output
$$$$$$$$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$$$$$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$$$$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$$$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$$++++++++++^^^^^^^^^^""""""""""'''''''''
$$++++++++++^^^^^^^^^^""""""""""'''''''''
$++++++++++^^^^^^^^^^""""""""""'''''''''
++++++++++^^^^^^^^^^""""""""""'''''''''
+++++++++^^^^^^^^^^""""""""""'''''''''
++++++++^^^^^^^^^^""""""""""'''''''''
+++++++^^^^^^^^^^""""""""""'''''''''
++++++^^^^^^^^^^""""""""""'''''''''
+++++^^^^^^^^^^""""""""""'''''''''
++++^^^^^^^^^^""""""""""'''''''''
+++^^^^^^^^^^""""""""""'''''''''
++^^^^^^^^^^""""""""""'''''''''
+^^^^^^^^^^""""""""""'''''''''
^^^^^^^^^^""""""""""'''''''''
^^^^^^^^^""""""""""'''''''''
^^^^^^^^""""""""""'''''''''
^^^^^^^""""""""""'''''''''
^^^^^^""""""""""'''''''''
^^^^^""""""""""'''''''''
^^^^""""""""""'''''''''
^^^""""""""""'''''''''
^^""""""""""'''''''''
Gradient 3
The gradient start/end/centre points don't have to be inside the grid!

Input
40 40
aaabcccdeeefggg
radial -10 20 60
Output
ccccccccccdddddeeeeeeeeeeeeeeeffffgggggg
cccccccccccdddddeeeeeeeeeeeeeefffffggggg
ccccccccccccdddddeeeeeeeeeeeeeeffffggggg
cccccccccccccdddddeeeeeeeeeeeeeffffggggg
cccccccccccccdddddeeeeeeeeeeeeefffffgggg
ccccccccccccccdddddeeeeeeeeeeeeeffffgggg
cccccccccccccccddddeeeeeeeeeeeeeffffgggg
cccccccccccccccdddddeeeeeeeeeeeeeffffggg
bcccccccccccccccddddeeeeeeeeeeeeeffffggg
bbccccccccccccccdddddeeeeeeeeeeeeffffggg
bbbccccccccccccccddddeeeeeeeeeeeeffffggg
bbbbcccccccccccccddddeeeeeeeeeeeeeffffgg
bbbbcccccccccccccddddeeeeeeeeeeeeeffffgg
bbbbbcccccccccccccddddeeeeeeeeeeeeffffgg
abbbbcccccccccccccddddeeeeeeeeeeeeffffgg
abbbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
aabbbbccccccccccccddddeeeeeeeeeeeeffffgg
abbbbbccccccccccccddddeeeeeeeeeeeeffffgg
abbbbcccccccccccccddddeeeeeeeeeeeeffffgg
bbbbbcccccccccccccddddeeeeeeeeeeeeffffgg
bbbbcccccccccccccddddeeeeeeeeeeeeeffffgg
bbbbcccccccccccccddddeeeeeeeeeeeeeffffgg
bbbccccccccccccccddddeeeeeeeeeeeeffffggg
bbccccccccccccccdddddeeeeeeeeeeeeffffggg
bcccccccccccccccddddeeeeeeeeeeeeeffffggg
cccccccccccccccdddddeeeeeeeeeeeeeffffggg
cccccccccccccccddddeeeeeeeeeeeeeffffgggg
ccccccccccccccdddddeeeeeeeeeeeeeffffgggg
cccccccccccccdddddeeeeeeeeeeeeefffffgggg
cccccccccccccdddddeeeeeeeeeeeeeffffggggg
ccccccccccccdddddeeeeeeeeeeeeeeffffggggg
cccccccccccdddddeeeeeeeeeeeeeefffffggggg
Notes
Got any cool challenge ideas? Submit them to r/DailyProgrammer_Ideas!

*/

package main

import (
	"fmt"
	"math"
)

type samplerfn func([]rune, int, int, []int) rune

func main() {
	gen(40, 30, []rune(" .,:;xX&@"), radial, []int{20, 15, 20})
	gen(60, 30, []rune(` '"^+$`), linear, []int{30, 30, 0, 0})
	gen(40, 40, []rune("aaabcccdeeefggg"), radial, []int{-10, 20, 60})
}

func gen(width, height int, colors []rune, sample samplerfn, args []int) {
	for y := range height {
		for x := range width {
			fmt.Printf("%c", sample(colors, x, y, args))
		}
		fmt.Println()
	}
	fmt.Println()
}

func radial(colors []rune, x, y int, args []int) rune {
	dx := float64(x - args[0])
	dy := float64(y - args[1])
	dist := math.Hypot(dx, dy)
	if dist > float64(args[2]) {
		return colors[len(colors)-1]
	}

	d0 := dist * float64(len(colors)-1)
	d1 := float64(args[2])
	return colors[int(d0/d1)]
}

func linear(colors []rune, x, y int, args []int) rune {
	ax := float64(args[0] - x)
	ay := float64(args[1] - y)
	bx := float64(args[0] - args[2])
	by := float64(args[1] - args[3])
	normb := math.Hypot(bx, by)
	ubx := bx / normb
	uby := by / normb
	dist := ax*ubx + ay*uby
	if dist < 0 {
		return colors[0]
	}
	if dist > normb {
		return colors[len(colors)-1]
	}

	index := dist * float64(len(colors)-1)
	index = math.Ceil(index / normb)
	return colors[int(index)]
}
