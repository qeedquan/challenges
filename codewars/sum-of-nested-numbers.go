/*

Build a function sumNestedNumbers/sum_nested_numbers that finds the sum of all numbers in a series of nested arrays raised to the power of their respective nesting levels. Numbers in the outer most array should be raised to the power of 1.

For example,

sumNestedNumbers([1, [2], 3, [4, [5]]])
should return 1 + 2*2 + 3 + 4*4 + 5*5*5 === 149

*/

package main

func main() {
	assert(nestedsum([]any{0}) == 0)
	assert(nestedsum([]any{1, 2, 3, 4, 5}) == 15)
	assert(nestedsum([]any{1, []any{2}, 3, []any{4, []any{5}}}) == 149)
	assert(nestedsum([]any{6, []any{5}, []any{[]any{4}}, []any{[]any{[]any{3}}}, []any{[]any{[]any{[]any{2}}}}, []any{[]any{[]any{[]any{1}}}}}) == 209)
	assert(nestedsum([]any{1, []any{-1}, []any{[]any{1}}, []any{[]any{[]any{-1}}}, []any{[]any{[]any{[]any{1}}}}}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nestedsum(x any) int {
	return recurse(x, 0)
}

func recurse(x any, p int) int {
	switch x := x.(type) {
	case int:
		return ipow(x, p)
	case []any:
		s := 0
		for i := range x {
			s += recurse(x[i], p+1)
		}
		return s
	default:
		panic("unsupported type")
	}
}

func ipow(x, p int) int {
	r := 1
	for i := 0; i < p; i++ {
		r *= x
	}
	return r
}
