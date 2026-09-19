/*

Recursion is actually quite powerful, sometimes its doesn't look like that child problem of itself exist, but recursion is just helpful.

One case per answer.

*/

package main

func main() {
	for x := 0; x <= 1000; x++ {
		for y := 0; y <= x; y++ {
			assert(x-y == SUB101(x, y))
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@l4m2

In Infinite Turtle, all numbers are between 0 and 100, inclusive. There's only saturated increment and decrement by one operation, and isZero condition. Requires to subtract modulo 101.

My solution:

SUB101(x,y) := y==0?x:SUB101(x==0?GEN100(x):x-1,y-1)
GEN100(x) := SUB101(x+1,x)==0?x:GEN100(x+1)
Here, SUB101(x+1,x) returns 1 if x!=100, or 0 if x==100. GEN100 is never called inside due to input limit. By reusing SUB101, I needn't another SUB or ISEQUAL.

*/

func SUB101(x, y int) int {
	if y < 1 {
		return x
	}
	if x < 1 {
		return SUB101(GEN100(x), y-1)
	}
	return SUB101(x-1, y-1)
}

func GEN100(x int) int {
	if SUB101(x+1, x) == 0 {
		return x
	}
	return GEN100(x + 1)
}
