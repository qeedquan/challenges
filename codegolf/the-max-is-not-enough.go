/*

Intro
A friend posed this question today in a slightly different way - "Can a single [Python] command determine the largest of some integers AND that they aren't equal?".

While we didn't find a way to do this within reasonable definitions of "a single command", I thought it might be a fun problem to golf.

 Challenge
"Return the largest of a list of integers if-and-only-if they are not all equal."

More specifically:

Given a string containing only a comma-separated list of integers:

If they are all equal, return/output nothing
Else, return/output the largest
Rules
The input must be a string containing only a comma-separated list of integers
The output must be either nothing (no output of any kind), or else the largest element from the input, represented as it is in the input
Entries may be a full program or just a function, provided you provide some way to test them!

Assumptions
Assume input list elements may be more than one digit but no larger than ( 232 − 1 )
Assume the input list has no more than a million elements
Assume the input will not include negative values
Assume the input will never be empty
For the avoidance of doubt, the explanation of the challenge given just after "More specifically" shall supersede the statement of the challenge above it ("Return the largest...").

 Examples
(1) All equal:

Input: 1,1
Output:
(2) Dissimilar:

Input: 1,2
Output: 2
(3) Zero!:

Input: 0,0,0,0,0,0,0,1,0,0
Output: 1
(4) Random:

Input: 7,3,8,4,8,3,9,4,6,1,3,7,5
Output: 9
(5) Larger numbers, larger list:

Input: 627,3894,863,5195,7789,5269,8887,3262,1448,3192
Output: 8887
Additional examples:
(6) All equal, larger list:

Input: 7,7,7,7,7,7,7,7,7
Output:
(7) All equal, larger list, larger numbers:

Input: 61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976,61976
Output:
(8) Not equal, larger list, larger numbers:

Input: 96185,482754,96185,96185,96185,96185,96185,96185,7,96185,96185,96185,96185,96185,96185,96185,96185,96185,96185,96185,96185,96185,96185,96185,96185,961185,96185,96185,96185
Output: 961185

Scoring
This is code-golf, so the code with the shortest number of bytes wins!

*/

package main

import "fmt"

func main() {
	test([]int{1, 1}, false)
	test([]int{1, 2}, 2)
	test([]int{0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 1)
	test([]int{7, 3, 8, 4, 8, 3, 9, 4, 6, 1, 3, 7, 5}, 9)
	test([]int{627, 3894, 863, 5195, 7789, 5269, 8887, 3262, 1448, 3192}, 8887)
	test([]int{7, 7, 7, 7, 7, 7, 7, 7, 7}, false)
	test([]int{61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976, 61976}, false)
	test([]int{96185, 482754, 96185, 96185, 96185, 96185, 96185, 96185, 7, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 96185, 961185, 96185, 96185, 96185}, 961185)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, r any) {
	v, ok := maxne(a)
	fmt.Println(v, ok)
	switch r := r.(type) {
	case bool:
		assert(ok == r)
	case int:
		assert(v == r)
	}
}

func maxne(a []int) (int, bool) {
	if len(a) == 0 {
		return 0, false
	}

	m, c := a[0], 0
	for _, v := range a[1:] {
		if m < v {
			m, c = v, 0
		} else if m == v {
			c++
		}
	}
	return m, c == 0
}
