/*

Challenge:
Given the input number n. It should give me nested sublists of n layers with the power of two numbers for each level. Each power of two value will be in separate sublists.

Notes:
n will always be greater than 0

I am using the example output with Python Lists. You can use any type of sequence in your own language.

Your output must be one-indexed, add one to n if your output is zero-indexed.

Your output sequence must be nested.

Test cases:
n = 1: [1]
n = 2: [1, [2]]
n = 3: [1, [2, [4]]]
n = 4: [1, [2, [4, [8]]]]
n = 5: [1, [2, [4, [8, [16]]]]]
n = 6: [1, [2, [4, [8, [16, [32]]]]]]
n = 7: [1, [2, [4, [8, [16, [32, [64]]]]]]]
This is code-golf, so the shortest code in bytes wins!

The power of twos are these values 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048..., each values is double of the previous value.

*/

package main

import "fmt"

func main() {
	for i := 0; i < 8; i++ {
		fmt.Println(i, gen(i))
	}
}

func gen(n int) any {
	return recurse(0, n)
}

func recurse(i, n int) any {
	if n < 1 {
		return []any{}
	}

	r := []any{1 << i}
	if i+1 < n {
		r = append(r, recurse(i+1, n))
	}
	return r
}
