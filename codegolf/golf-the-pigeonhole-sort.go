/*

Implement the Pigeonhole sort. This is a variant of the Bucket sort, and its logic is very simple: index your items (by a given function) and then return all non-empty indexes' items.

Your program/function should get an array of items in the most comfortable way for your language of choice, (i.e. a parameter, stdin, etc.), and in any format you like (for example: JSON). It should return/output a sorted array.

Do not modify the given array.

The second parameter that will be given to your program/function will be the "sort-by function". For exmaple, in JavaScript it will be something like function(item){return item.id;}.

For simplicity, you can assume this function returns a unique positive Integer for each item in the given array.

Shortest code wins. Only ASCII is allowed.

*/

package main

import "fmt"

func main() {
	fmt.Println(pigeonholesort([]int{4, 10, 3, 1, 20}))
}

func pigeonholesort(a []int) []int {
	m := make(map[int]int)
	n := 0
	for _, v := range a {
		n, m[v] = max(n, v), m[v]+1
	}

	r := make([]int, len(a))
	for i, j := 0, 0; i <= n; i++ {
		for range m[i] {
			r[j], j = i, j+1
		}
	}

	return r
}
