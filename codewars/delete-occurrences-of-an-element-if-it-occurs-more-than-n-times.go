/*

Alice and Bob were on a holiday. Both of them took many pictures of the places they've been, and now they want to show Charlie their entire collection. However, Charlie doesn't like these sessions, since the motive usually repeats. He isn't fond of seeing the Eiffel tower 40 times. He tells them that he will only sit during the session if they show the same motive at most N times. Luckily, Alice and Bob are able to encode the motive as a number. Can you help them to remove numbers such that their list contains each number only up to N times, without changing the order?

## Task

Given a list lst and a number N, create a new list that contains each number of lst at most N times without reordering. For example if N = 2, and the input is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3].

## Example

EnoughIsEnough.deleteNth(new int[] {20,37,20,21}, 1) // return [20,37,21]
EnoughIsEnough.deleteNth(new int[] {1,1,3,3,7,2,2,2,2}, 3) // return [1, 1, 3, 3, 7, 2, 2, 2]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{}, 5, []int{})
	test([]int{20, 37, 20, 21}, 1, []int{20, 37, 21})
	test([]int{1, 1, 1, 1, 1}, 5, []int{1, 1, 1, 1, 1})
	test([]int{1, 1, 3, 3, 7, 2, 2, 2, 2}, 3, []int{1, 1, 3, 3, 7, 2, 2, 2})
	test([]int{1, 2, 3, 1, 1, 2, 1, 2, 3, 3, 2, 4, 5, 3, 1}, 3, []int{1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, n int, r []int) {
	p := deletenth(a, n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func deletenth(a []int, n int) []int {
	r := []int{}
	m := make(map[int]int)
	for _, v := range a {
		if m[v]++; m[v] <= n {
			r = append(r, v)
		}
	}
	return r
}
