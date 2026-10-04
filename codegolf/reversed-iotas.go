/*

I didn't invent this challenge, but I find it very interesting to solve.

For every input number, e.g.:

4
Generate a range from 1 to that number:

[1 2 3 4]
And then, for every item in that list, generate a list from 1 to that number:

[[1] [1 2] [1 2 3] [1 2 3 4]]
Then, reverse every item of that list.

[[1] [2 1] [3 2 1] [4 3 2 1]]
Notes:
1 being a loose item is allowed, since flattening will not matter with this anyway.
To preserve the spirit of the challenge, the range has to be 1-indexed.
You may flatten the list if your platform doesn't support the concept of nested lists.

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 4; i++ {
		fmt.Println(riota(i))
	}
}

func riota(n int) [][]int {
	var r [][]int
	for i := 0; i < n; i++ {
		p := make([]int, i+1)
		for j := 0; j <= i; j++ {
			p[j] = i - j + 1
		}
		r = append(r, p)
	}
	return r
}
