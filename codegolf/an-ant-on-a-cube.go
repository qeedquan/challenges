/*

An ant walks along the edges (not faces) of a wireframe cube. Each vertex it encounters presents it with a fork from which two new edges branch off. The ant chooses which way to turn -- left or right. These direction are relative to the ant, who is facing the vertex and is outside the cube. Your goal is to determine, from the sequence of left/right choices the ant took, whether it ends at the same position that it started.

For example, if the ant turns left four times (left left left left), it will have traversed a square counterclockwise and ended at the same place it started. But, if it goes left left left left right, it will end on a different spot on the cube. Also, if it goes left right right right left, it ends on its starting edge but facing the opposite vertex, which does not count as the same position.

The ant's path might repeat edges, including the edge it started at, but what matters is where it ends after the whole sequence.

Write a named function that takes in the ant's sequence of turns and outputs whether the ant is back at its start position after the sequence. Assigning an unnamed function to a variable is enough to make it a named function.

(Edit: If your language can't make a named function, it can instead implement the function with inputs and outputs through STDIN/printing or the stack. If that's not possible, make it a snippet in which the input and output are saved in variables.)

Input

A sequence of left/right decisions of length 0 to 31 inclusive, represented in a format of your choice. This might be a string of letters R/L, a list of numbers 1/-1, or an array of Booleans. Nothing cheesy like having them be method names or strings useful for your code.

Please post the test cases in your format if it's different from the test cases below.

Output

True/False, 0/1, or the analogues in your language.

Winning criteria

Fewest bytes wins. Remember, you need to give a named function. You can have code outside the function, but those bytes count too. Your function should behave correctly if called multiple times.

Test cases

True cases (one per line, second one is empty list):

1 1 1 1

-1 -1 -1 -1
1 -1 1 -1 1 -1
1 1 -1 -1 1 1 -1 -1
-1 1 1 -1 -1 1 1 -1
1 1 1 -1 -1 -1 -1 1
1 -1 -1 1 -1 -1
1 1 1 1 -1 -1 -1 -1 1 -1 -1 1 -1 -1
-1 -1 -1 1 -1 -1 1 1 -1 1 -1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
False cases (one per line):

1
1 1
1 1 1
-1 1
1 -1 -1 -1 1
1 -1 -1 1 1
-1 1 -1 1
1 1 1 1 -1
-1 -1 1 -1 1 -1 -1 1
1 -1 1 1 1 1 -1 -1 -1 1 1 -1 -1 -1
Here's the same test cases with L's and R's.

True cases:

RRRR

LLLL
RLRLRL
RRLLRRLL
LRRLLRRL
RRRLLLLR
RLLRLL
RRRRLLLLRLLRLL
LLLRLLRRLRLRRRRRRRRRRRRRRRRR
False cases:

R
RR
RRR
LR
RLLLR
RLLRR
LRLR
RRRRL
LLRLRLLR
RLRRRRLLLRRLLL
Extra credit challenge

Same thing, but with a dodecahedron rather than a cube. See Hunt the Wumpus for ideas.

*/

package main

func main() {
	assert(cycle([]int{1, 1, 1, 1}) == true)
	assert(cycle([]int{-1, -1, -1, -1}) == true)
	assert(cycle([]int{1, -1, 1, -1, 1, -1}) == true)
	assert(cycle([]int{1, 1, -1, -1, 1, 1, -1, -1}) == true)
	assert(cycle([]int{-1, 1, 1, -1, -1, 1, 1, -1}) == true)
	assert(cycle([]int{1, 1, 1, -1, -1, -1, -1, 1}) == true)
	assert(cycle([]int{1, -1, -1, 1, -1, -1}) == true)
	assert(cycle([]int{1, 1, 1, 1, -1, -1, -1, -1, 1, -1, -1, 1, -1, -1}) == true)
	assert(cycle([]int{-1, -1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) == true)
	assert(cycle([]int{1}) == false)
	assert(cycle([]int{1, 1}) == false)
	assert(cycle([]int{1, 1, 1}) == false)
	assert(cycle([]int{-1, 1}) == false)
	assert(cycle([]int{1, -1, -1, -1, 1}) == false)
	assert(cycle([]int{1, -1, -1, 1, 1}) == false)
	assert(cycle([]int{-1, 1, -1, 1}) == false)
	assert(cycle([]int{1, 1, 1, 1, -1}) == false)
	assert(cycle([]int{-1, -1, 1, -1, 1, -1, -1, 1}) == false)
	assert(cycle([]int{1, -1, 1, 1, 1, 1, -1, -1, -1, 1, 1, -1, -1, -1}) == false)

}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Armin Rigo

Takes a list of 1 and -1. Based on 3D rotations: checks if the point (3,2,1) ends up at the same position after applying a series of rotations.
There are two possible rotations, corresponding to 1 and -1.
Each one is done by permuting two coordinates and changing the sign of one of them.
The exact coordinates to change and which sign to permute is not important.

*/

func cycle(a []int) bool {
	p := [3]int{3, 2, 1}
	for _, d := range a {
		if d < 0 {
			d = 2
		}
		p[d], p[0] = -p[0], p[d]
	}
	return p == [3]int{3, 2, 1}
}
