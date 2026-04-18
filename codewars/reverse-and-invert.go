/*

Reverse and invert all integer values in a given list.

reverse_invert([1,12,'a',3.4,87,99.9,-42,50,5.6]) = [-1,-21,-78,24,-5]

Remove all types other than integer.

*/

package main

import "fmt"

func main() {
	fmt.Println(revinv([]any{1, 12, 'a', 3.4, 87, 99.9, -42, 50, 5.6}))
}

func revinv(a []any) []int {
	r := []int{}
	for _, v := range a {
		x, ok := v.(int)
		if ok {
			r = append(r, flip(x))
		}
	}
	return r
}

func flip(x int) int {
	r, s := 0, -1
	if x < 0 {
		x, s = -x, -s
	}
	for ; x > 0; x /= 10 {
		r = r*10 + x%10
	}
	return r * s
}
