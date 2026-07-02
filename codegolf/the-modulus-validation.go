/*

Given a list of math expressions that all hold true and consist of modulo remainder calculations with two numbers and a result, your task is to yield the first n numbers that hold true for all the statements in the list.

For example:

[m % 3 = 0, m % 4 = 1, m % 5 = 3], where % is the modulo operator.

For n = 3, the first 3 numbers (counting from 0) that fit the sequence are 33, 93, 153, thus your result would be that (format up to you).

Rules / IO
You take a positive number n and a list of truths. Of course, the things you need take are only the RHS of the modulo operation and the result.
n and the numbers in the list of truths will always be in the range 1 -> 2^31-1, and so are the results.
You take input in any convenient form and output in any convenient form. For example, input: 3 [3 0, 4 1, 5 3] and output: 33 93 153.
It's guaranteed that the solution is mathematically possible.
The source of input can be from a file, function parameters, stdin, etc... Same goes for the output.
No loopholes.
This is code-golf, so the lowest byte count wins.
Testcases
# Input in the form <n>, <(d r), (d2 r2), ...>
# where <d> = RHS of the modulo expression and <r> the result of the expression. Output in the next line.

5, (3 2), (4 1), (5 3)
53 113 173 233 293

3, (8, 0), (13, 3), (14, 8)
120 848 1576

Reference implementation in pseudo-code
n = (an integer from stdin)
truths = (value pairs from stdin)
counter = 0

while n != 0 {
    if matches_criterias(counter, truths) {
        print counter
        n -= 1
    }

    counter += 1
}

*/

package main

import (
	"fmt"
	"math"
	"slices"
)

func main() {
	test(5, [][2]int{{3, 2}, {4, 1}, {5, 3}}, []int{53, 113, 173, 233, 293})
	test(3, [][2]int{{8, 0}, {13, 3}, {14, 8}}, []int{120, 848, 1576})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, a [][2]int, r []int) {
	p := solve(n, a)
	fmt.Println(p)
	assert(slices.Equal(p, r))
}

func solve(n int, a [][2]int) []int {
	r := []int{}
loop:
	for i := 0; len(r) < n && i < math.MaxInt; i++ {
		for _, v := range a {
			if i%v[0] != v[1] {
				continue loop
			}
		}
		r = append(r, i)
	}
	return r
}
