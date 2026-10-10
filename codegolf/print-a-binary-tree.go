/*

Inspired by a recent question on SO...

Write a function to print a binary tree in the following format:

   3
 /   \
1     5
 \   / \
  2 4   6
The output should consist of a line of nodes, followed by a line of / and \ characters indicating relationships, followed by a line of nodes, etc.
You can assume all nodes are representable as a single character.
Adjacent nodes on the lowest level should be separated by at least one space, nodes further up should be separated as appropriate.
Nodes with two children should be placed precisely in the middle of their direct children.
Relationship slashes should be halfway between the parent and the appropriate child (round whichever way you want).
Input:

The input will be provided as an argument to your function. I won't specify the exact structure of the tree, however it must be usable as an actual binary tree. No "trees are represented in my program as strings coincidentally looking like the expected output".

You may print to an output stream or return a string containing the output, your choice.

Points for shortest code, but I'd much prefer a fully working long solution than a 90%-working short one.

Update for the bounty:

For the bounty, I (Optimizer) am making slight changes:

Input can be from STDIN,ARGV or function argument.
Output needs to be on STDOUT (or console.log for JS)
You can assume that input is in a form of array, for ex. [1,2,3] or [1 2 3]
Update 2 - The binary tree should actually be a binary search tree. Since I did not mention this initially, I will allow users to treat the converting a normal array into a binary search tree array as a separate program and the final byte count will only be for the program to take in the array as argument and print it like a binary tree.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	tree([]int{3, 1, 5, -1, 2, 4, 7})
}

/*

Ported from @dmckee solution

Input is a binary tree in array format:
https://en.wikipedia.org/wiki/Binary_tree#Arrays

The array contains only non-negative values, and empty nodes are represented with -1
The printed representation uses three characters for every node,
and places the (back) slash equally between the two node-centers.

The array needs to be a full binary tree (size=2^n for some n)

*/

func tree(values []int) {
	// maximum depth of the tree
	depth := int(math.Ceil(math.Log2(float64(len(values)))))

	// width needed for printing the whole tree
	width := 1<<(depth+1) - 1

	for level := 1; level <= depth; level++ {
		// l = level
		// m = depth

		// number of nodes on this level:
		// 2^(l-1)

		// internode spacing
		// 2^(m-l+2)-3
		spacing := 1<<(depth-level+2) - 3

		// width needed for printing this row
		// optimized from 3*2^l + k*((2^l)-1) at the bottom level
		rowwidth := (3+spacing)*1<<(level-1) - spacing

		// padding for this row
		padding := 1 + (width-rowwidth)/2

		// print connecting lines associated with the previous level
		if level != 1 {
			fmt.Printf("%*c", padding, ' ')
			for i := 1 << (level - 1); i <= (1<<level)-1; i++ {
				if values[i/2-1] < 0 || values[i-1] < 0 {
					fmt.Printf("   %*c", spacing, ' ')
				} else if i%2 == 0 {
					fmt.Printf("  /%*c", spacing, ' ')
				} else {
					fmt.Printf(" \\ %*c", spacing, ' ')
				}
			}
			fmt.Println()
		}

		// print the nodes on this level
		fmt.Printf("%*c", padding, ' ')
		for i := 1 << (level - 1); i <= (1<<level)-1; i++ {
			if values[i-1] > 0 {
				fmt.Printf("%3d%*c", values[i-1], spacing, ' ')
			} else {
				fmt.Printf("%*c", spacing+3, ' ')
			}
		}
		fmt.Println()
	}
}
