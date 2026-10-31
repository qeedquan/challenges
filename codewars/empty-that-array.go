/*

Today's task is to write a function empty(), which take an array as argument. This function should return the same array, but empty.

To make it even more fun, you are not allowed to use any kind of loop (nor recursion)

Good luck!

*/

package main

import "fmt"

func main() {
	a := []int{1, 2, 3}
	b := empty(a)
	fmt.Println(a, b)
}

func empty(a []int) []int {
	return a[:0]
}
