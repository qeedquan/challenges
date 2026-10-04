/*

Introduction
Cacti come in various different sizes, shapes and colors. However, the most iconic cactus and must-have in every Western has to be the saguaro. Important features are its size and arms, which have defined the stereotypical cactus appearance.

Your task is to bring the saguaro in the ASCII world. However, -- as in the real world -- no saguaro is like another, so your program has to be able to generate saguaros with varying arm configurations.

An example saguaro
Input: [0b10, 0b11] ([2, 3] in decimal, input length of 2)
     _
    / \
 _  | |
/ \ | |
| | | |
\ \_| |
 \__  |
    \ |
 _  | |  _
/ \ | | / \
| | | | | |
\ \_| |_/ /
 \__   __/
    \ /
    | |
    | |
Specifications
A saguaro always has a base and a top, with variable amounts of stem in between. The stem parts can have no arms, an arm on the right, one on the left or two arms.

Saguaro growth patterns are given as an input list containing two-bit values. 00 means no arms, 01 an arm on the right, 10 an arm on the left and 11 two arms (all in binary). The input list's length determines the saguaro's height.

Saguaro sections look like the following. Cactus parts are surrounded by octothorps, #, for clarity which shall not be printed.
A saguaro's height is always equal to 4+6*k characters for nonnegative integers k.

#############
#     _     # Saguaro top
#    / \    #
#############
# _  | |  _ # Stem, both arms
#/ \ | | / \# Stem id: 11
#| | | | | |#
#\ \_| |_/ /#
# \__   __/ #
#    \ /    #
#############
# _  | |    # Stem, left arm
#/ \ | |    # Stem id: 10
#| | | |    #
#\ \_| |    #
# \__  |    #
#    \ |    #
#############
#    | |  _ # Stem, right arm
#    | | / \# Stem id: 01
#    | | | |#
#    | |_/ /#
#    |  __/ #
#    | /    #
#############
#    | |    # Stem, no arms
#    | |    # Stem id: 00
#    | |    #
#    | |    #
#    | |    #
#    | |    #
#############
#    | |    # Saguaro base
#    | |    #
#############
Input
As previously said, the input consists of a list of two-bit values (0, 1, 2, 3 in decimal). It can be given in any reasonable format. The list's first element corresponds to the saguaro's highest stem part, the second element to its second highest stem part, etc.
If you want, you can require the input list's length as an additional input. Please specify it in your answer if you do so.

Output
Your output ASCII saguaro should be built using the exact stem parts as described above. Trailing spaces on a line and trailing new lines are ignored; you may print more, fewer or as many as specified above.

Rules
Standard loopholes apply
This being code-golf, a program's byte count should be minimal
Test cases
An outlier. Input: [0b01, 0b00, 0b01, 0b11]
     _
    / \
    | |  _
    | | / \
    | | | |
    | |_/ /
    |  __/
    | /
    | |
    | |
    | |
    | |
    | |
    | |
    | |  _
    | | / \
    | | | |
    | |_/ /
    |  __/
    | /
 _  | |  _
/ \ | | / \
| | | | | |
\ \_| |_/ /
 \__   __/
    \ /
    | |
    | |
Alternating arms. Input: [0b10, 0b01, 0b10]
     _
    / \
 _  | |
/ \ | |
| | | |
\ \_| |
 \__  |
    \ |
    | |  _
    | | / \
    | | | |
    | |_/ /
    |  __/
    | /
 _  | |
/ \ | |
| | | |
\ \_| |
 \__  |
    \ |
    | |
    | |
An abundance of arms. Input: [0b11, 0b11]
     _
    / \
 _  | |  _
/ \ | | / \
| | | | | |
\ \_| |_/ /
 \__   __/
    \ /
 _  | |  _
/ \ | | / \
| | | | | |
\ \_| |_/ /
 \__   __/
    \ /
    | |
    | |
No arms, also known as a spear. Input: [0b00]
     _
    / \
    | |
    | |
    | |
    | |
    | |
    | |
    | |
    | |
No body, some call it a young cactus. Input: []
     _
    / \
    | |
    | |

*/

package main

import "fmt"

func main() {
	cactus([]int{0b01, 0b00, 0b01, 0b11})
	cactus([]int{0b10, 0b01, 0b10})
	cactus([]int{0b11, 0b11})
	cactus([]int{0b00})
	cactus([]int{})
}

func cactus(bits []int) {
	output(TOP)
	for _, index := range bits {
		output(LIMBS[index&3])
	}
	output(BASE)
}

func output(lines []string) {
	for _, line := range lines {
		fmt.Println(line)
	}
}

var TOP = []string{
	`     _     `,
	`    / \    `,
}

var BOTH = []string{
	` _  | |  _ `,
	`/ \ | | / \`,
	`| | | | | |`,
	`\ \_| |_/ /`,
	` \__   __/ `,
	`    \ /    `,
}

var LEFT = []string{
	` _  | |    `,
	`/ \ | |    `,
	`| | | |    `,
	`\ \_| |    `,
	` \__  |    `,
	`    \ |    `,
}

var RIGHT = []string{
	`    | |  _ `,
	`    | | / \`,
	`    | | | |`,
	`    | |_/ /`,
	`    |  __/ `,
	`    | /    `,
}

var NONE = []string{
	`    | |    `,
	`    | |    `,
	`    | |    `,
	`    | |    `,
	`    | |    `,
	`    | |    `,
	`    | |    `,
	`    | |    `,
}

var BASE = []string{
	`    | |    `,
	`    | |    `,
}

var LIMBS = [][]string{
	NONE, RIGHT, LEFT, BOTH,
}
