/*

Your task is to write a function, smartSum, that returns the sum of an arbitrary number of arguments. But be careful, some of your arguments can be arrays of numbers or nested arrays.

smartSum(1,2,3,[4,5],6); // returns 21
smartSum(1,2,[[3,4],5],6); // returns 21

*/

package main

func main() {
	assert(smartsum([]any{1, 2, 3, []any{4, 5}, 6}) == 21)
	assert(smartsum([]any{1, 2, []any{[]any{3, 4}, 5}, 6}) == 21)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func smartsum(x any) int {
	r := 0
	for q := []any{x}; len(q) > 0; q = q[1:] {
		switch y := q[0].(type) {
		case []any:
			for _, z := range y {
				switch z := z.(type) {
				case []any:
					q = append(q, z)
				case int:
					r += z
				}
			}
		case int:
			r += y
		}
	}
	return r
}
