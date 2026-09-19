/*

Task:
Find out "B"(Bug) in a lot of "A"(Apple).

There will always be one bug in apple, not need to consider the situation that without bug or more than one bugs.

input: string Array apple

output: Location of "B", [x,y]

*/

package main

import "bytes"

func main() {
	assert(sc([][]byte{
		{'B', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}) == [2]int{0, 0})

	assert(sc([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'B', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}) == [2]int{1, 1})

	assert(sc([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'B', 'A', 'A', 'A'},
	}) == [2]int{4, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sc(apple [][]byte) [2]int {
	for i := range apple {
		j := bytes.IndexByte(apple[i], 'B')
		if j >= 0 {
			return [2]int{i, j}
		}
	}
	return [2]int{}
}
