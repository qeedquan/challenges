/*

Given is any integer x > 0 and any base y > 3.

1. Sum all digits of x (if written in the set base).
2. Multiply this by the highest possible digit (is always base -1).
3. Repeat until this value is (y - 1) ^ 2

Searched is the count of iterations and the steps.

Example 1:

x= 739
y= 7
searched: (7 - 1) ^ 2 = 36

based: (b7)2104
sum: (dec)7
mul: (dec)42

based: (b7)60
sum: (dec)6
mul: (dec)36

2 steps needed -> answer is [2, 739, 42, 36] or [739, 42, 36, 2]
Example 2:

x = 1712
y = 19
s: 324

step1: 1712 -> 360
step2:  360 -> 648
step3:  648 -> 324

3 steps needed -> answer is [3, 1712, 360, 648, 324] or [1712, 360, 648, 324, 3]
Special:
In some cases (some combinations with a base of 3) you will not be able to get to (y - 1) ^ 2 like for x = 53 and y = 3. For this reason y needs to be bigger than 3 and you can ignore this.

The count of iterations need to be the first or the last value

This is code-golf lowest byte-count wins.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(739, 7, []int{739, 42, 36, 2})
	test(1712, 19, []int{1712, 360, 648, 324, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y int, r []int) {
	v := sdts(x, y)
	fmt.Println(v)
	assert(reflect.DeepEqual(v, r))
}

func sdts(x, y int) []int {
	if x < 1 || y < 4 {
		return nil
	}

	r := []int{}
	i := 1
	for s := y - 1; x-s*s != 0; i++ {
		r = append(r, x)
		t := 0
		for ; x != 0; x /= y {
			t += x % y
		}
		x = t*y - t
	}
	r = append(r, x, i-1)
	return r
}
