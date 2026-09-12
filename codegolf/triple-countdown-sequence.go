/*

Let's start with the natural numbers

[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100...
Now we will make a new list, replacing each natural number n with a countdown from n to 1.

[1,2,1,3,2,1,4,3,2,1,5,4,3,2,1,6,5,4,3,2,1,7,6,5,4,3,2,1,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,10,9,8,7,6,5,4,3,2,1,11,10,9,8,7,6,5,4,3,2,1,12,11,10,9,8,7,6,5,4,3,2,1,13,12,11,10,9,8,7,6,5,4,3,2,1,14,13,12,11,10,9,8,7,6..
Now we will repeat the process.

[1,2,1,1,3,2,1,2,1,1,4,3,2,1,3,2,1,2,1,1,5,4,3,2,1,4,3,2,1,3,2,1,2,1,1,6,5,4,3,2,1,5,4,3,2,1,4,3,2,1,3,2,1,2,1,1,7,6,5,4,3,2,1,6,5,4,3,2,1,5,4,3,2,1,4,3,2,1,3,2,1,2,1,1,8,7,6,5,4,3,2,1,7,6,5,4,3,2,1,6..
And now we will do it a third time:

[1,2,1,1,1,3,2,1,2,1,1,2,1,1,1,4,3,2,1,3,2,1,2,1,1,3,2,1,2,1,1,2,1,1,1,5,4,3,2,1,4,3,2,1,3,2,1,2,1,1,4,3,2,1,3,2,1,2,1,1,3,2,1,2,1,1,2,1,1,1,6,5,4,3,2,1,5,4,3,2,1,4,3,2,1,3,2,1,2,1,1,5,4,3,2,1,4,3,2,1...
This is the triple countdown sequence.

Your task is to implement the triple countdown sequence. You may either take input and give the value of the sequence at that index, or you may simply output the terms starting from the beginning without stop.1

This is code-golf so answers will be scored in bytes with fewer bytes being the goal.

1: Both zero and one indexing are permitted. Outputting the terms without halt includes lazy structures which can produce an infinite number of terms.

*/

package main

import "reflect"

func main() {
	tab := []int{1, 2, 1, 1, 1, 3, 2, 1, 2, 1, 1, 2, 1, 1, 1, 4, 3, 2, 1, 3, 2, 1, 2, 1, 1, 3, 2, 1, 2, 1, 1, 2, 1, 1, 1, 5, 4, 3, 2, 1, 4, 3, 2, 1, 3, 2, 1, 2, 1, 1, 4, 3, 2, 1, 3, 2, 1, 2, 1, 1, 3, 2, 1, 2, 1, 1, 2, 1, 1, 1, 6, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 4, 3, 2, 1, 3, 2, 1, 2, 1, 1, 5, 4, 3, 2, 1, 4, 3, 2, 1}

	n := len(tab)
	x := countdown(n)
	assert(reflect.DeepEqual(x[:n], tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func countdown(n int) []int {
	r := natural(n)
	for i := 0; i < 3; i++ {
		r = expand(r)
	}
	return r
}

func natural(n int) []int {
	r := make([]int, n)
	for i := range r {
		r[i] = i + 1
	}
	return r
}

func expand(a []int) []int {
	r := []int{}
	for i := range a {
		for j := a[i]; j >= 1; j-- {
			r = append(r, j)
		}
	}
	return r
}
