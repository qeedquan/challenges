/*

You are writing a function that takes two sets of arguments of arbitrary length. The return value will be the sum of the values of all of the arguments.

The function should contain at least 1 argument per set.

calculate(1)(1) // should return 2
calculate(1,1)(1) // should return 3
calculate(1,1)(1,-1) // should return 2
calculate(2,4)(3,7,1) // should return 17

*/

package main

func main() {
	assert(calculate(1)(1) == 2)
	assert(calculate(1, 1)(1) == 3)
	assert(calculate(1, 1)(1, -1) == 2)
	assert(calculate(2, 4)(3, 7, 1) == 17)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func calculate(x ...int) func(...int) int {
	return func(y ...int) int {
		return sum(x...) + sum(y...)
	}
}

func sum(x ...int) int {
	r := 0
	for _, v := range x {
		r += v
	}
	return r
}
