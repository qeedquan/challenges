/*

The inspiration for this code golf puzzle is the Bridge and Torch problem, in which d people at the start of a bridge must all cross it in the least amount of time.

The catch is that at most two people can cross at once, otherwise the bridge will crush under their weight, and the group only has access to one torch, which must be carried to cross the bridge.

Each person in the whole puzzle has a specified time that they take to walk across the bridge. If two people cross together, the pair goes as slow as the slowest person.

There is no set number of people that must cross the bridge; your solution MUST work for any value of d.

You needn't use standard input for this problem, but for the sake of explaining the problem, I will be using the following input and output format for the explanation. The first number, d, is the number of people at the start of the bridge. Then, the code will scan for d numbers, each representing the speed of a person.

The code output will be the LEAST amount of time required to cross everyone from the start of the bridge to the end of the bridge, while meeting the criteria explained earlier.

Here are some input cases and output cases and the explanation for the first input case. It is up to you to derive an algorithm from this information to solve the problem in the fewest bytes of code possible.

input

4
1 2 5 8
output

15

To reach this output, the people must cross in the following way.

A and B cross forward (2 minutes)
A returns (1 minute)
C and D cross forward (8 minutes)
B returns (2 minutes)
A and B cross forward (2 minutes)
Here's another test case to guide you along your way.

input

5
3 1 6 8 12

output

29
Rules:

Assume that the input will not be sorted, and you must do so on your own (if you need to)
The number of people in the puzzle is not fixed at 4 (N >= 1)
Every group and individual crossing must have a torch. There is only one torch.
Each group must consist of a maximum of only 2 people!
No, you may not jump off the bridge and swim to the other side. No other tricks like this ;).

*/
package main

import (
	"sort"
)

func main() {
	assert(crosstime([]int{3, 1, 6, 8, 12}) == 29)
	assert(crosstime([]int{1, 2, 5, 8}) == 15)
	assert(crosstime([]int{5}) == 5)
	assert(crosstime([]int{1}) == 1)
	assert(crosstime([]int{1, 3, 4, 5}) == 14)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@xnor

https://page.mi.fu-berlin.de/rote/Papers/pdf/Crossing+the+bridge+at+night.pdf

*/

func crosstime(a []int) int {
	sort.Ints(a)
	n := len(a)
	r := sum(a)
	if n > 1 {
		r += (n - 3) * a[0]
	}
	for i := range n / 2 {
		r += min(0, 2*a[1]-a[0]-a[n-2*i-2])
	}
	return r
}

func sum(a []int) int {
	r := 0
	for _, v := range a {
		r += v
	}
	return r
}
