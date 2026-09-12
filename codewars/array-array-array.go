/*

You are given an initial 2-value array (x). You will use this to calculate a score.

If both values in (x) are numbers, the score is the sum of the two. If only one is a number, the score is that number. If neither is a number, return 'Void!'.

Once you have your score, you must return an array of arrays. Each sub array will be the same as (x) and the number of sub arrays should be equal to the score.

For example:

if (x) == ['a', 3] you should return [['a', 3], ['a', 3], ['a', 3]].

*/

package main

import "fmt"

func main() {
	fmt.Println(explode([2]any{'a', 3}))
	fmt.Println(explode([2]any{5, 3}))
}

func explode(x [2]any) any {
	x0, i0 := x[0].(int)
	x1, i1 := x[1].(int)

	if !i0 && !i1 {
		return "Void!"
	}

	n := 0
	if i0 {
		n += x0
	}
	if i1 {
		n += x1
	}

	r := make([][2]any, n)
	for i := range r {
		r[i] = x
	}
	return r
}
