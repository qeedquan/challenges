/*

You deal cards labeled 0 to 9 from a deck one a time, forming stacks that start at 0 and count up by 1.

When you deal a 0, you place it on the table to start a new stack.
When you deal any other card, you stack it atop a card that's exactly one lower in value, covering it. If there's no such card, the deck isn't stackable.
Given a deck, determine whether it can be stacked when dealt in the order given. Equivalently, given a list of digits, decide whether it can be partitioned into disjoint subsequences each of the form 0,1,..,k

Example

Take the deck 0012312425. The first two cards are 0, so they go on the table:

Stacks: 00

  Deck: 12312425
Next, we deal a 1, which goes on a 0, doesn't matter which:

        1
Stacks: 00

  Deck: 2312425
We then deal a 2 atop the just-placed 1, and the 3 on top of it.

        3
        2
        1
Stacks: 00

  Deck: 12425
Next, the 1, 2 and placed atop the first stack and 4 atop the second one.

        4
        3
        22
        11
Stacks: 00

  Deck: 25
Now, we need to place a 2, but there's no 1 atop either stack. So, this deck was not stackable.

Input: A nonempty list of digits 0-9, or a string of them. You can't assume that 0 will always be in the input.

Output: One of two distinct consistent values, one for stackable sequences and one for non-stackable ones

Test cases:

Stackable:

0
01
01234
00011122234567890
012031
0120304511627328390
Not stackable:

1
021
0001111
0012312425
012301210
000112223
For convenience, as lists:

[0]
[0, 1]
[0, 1, 2, 3, 4]
[0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 0]
[0, 1, 2, 0, 3, 1]
[0, 1, 2, 0, 3, 0, 4, 5, 1, 1, 6, 2, 7, 3, 2, 8, 3, 9, 0]

[1]
[0, 2, 1]
[0, 0, 0, 1, 1, 1, 1]
[0, 0, 1, 2, 3, 1, 2, 4, 2, 5]
[0, 1, 2, 3, 0, 1, 2, 1, 0]
[0, 0, 0, 1, 1, 2, 2, 2, 3]
Grouped:

[[0], [0, 1], [0, 1, 2, 3, 4], [0, 0, 0, 1, 1, 1, 2, 2, 2, 3], [0, 1, 2, 0, 3, 1], [0, 1, 2, 0, 3, 0, 4, 5, 1, 1, 6, 2, 7, 3, 2, 8, 3, 9, 0]]
[[1], [0, 2, 1], [0, 0, 0, 1, 1, 1, 1], [0, 0, 1, 2, 3, 1, 2, 4, 2, 5]]

*/

package main

func main() {
	assert(stackable([]int{0}) == true)
	assert(stackable([]int{0, 1}) == true)
	assert(stackable([]int{0, 1, 2, 3, 4}) == true)
	assert(stackable([]int{0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 0}) == true)
	assert(stackable([]int{0, 1, 2, 0, 3, 1}) == true)
	assert(stackable([]int{0, 1, 2, 0, 3, 0, 4, 5, 1, 1, 6, 2, 7, 3, 2, 8, 3, 9, 0}) == true)

	assert(stackable([]int{1}) == false)
	assert(stackable([]int{0, 2, 1}) == false)
	assert(stackable([]int{0, 0, 0, 1, 1, 1, 1}) == false)
	assert(stackable([]int{0, 0, 1, 2, 3, 1, 2, 4, 2, 5}) == false)
	assert(stackable([]int{0, 1, 2, 3, 0, 1, 2, 1, 0}) == false)
	assert(stackable([]int{0, 0, 0, 1, 1, 2, 2, 2, 3}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @ovs solution
func stackable(a []int) bool {
	p := []int{}
	for _, v := range a {
		var del bool

		p, del = remove(append(p, v, -1), v-1)
		if !del {
			return false
		}
	}
	return true
}

func remove(a []int, x int) ([]int, bool) {
	for i := range a {
		if a[i] == x {
			return append(a[:i], a[i+1:]...), true
		}
	}
	return a, false
}
