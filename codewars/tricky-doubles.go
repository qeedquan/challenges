/*

Create a function that returns twice the supplied value unless it is a tricky double.

The trick: if the number passed in is a double, simply return the value that was passed.

Examples of a double number include:

44
77
3333
8787
100100
In the example 8787, the number 87 is doubled (appears twice).

trickyDoubles(15)   // should return 30
trickyDoubles(100)  // should return 200
trickyDoubles(4343) // should return 4343

*/

package main

import "fmt"

func main() {
	assert(trickydoubles(44) == 44)
	assert(trickydoubles(77) == 77)
	assert(trickydoubles(8787) == 8787)
	assert(trickydoubles(100100) == 100100)
	assert(trickydoubles(15) == 30)
	assert(trickydoubles(100) == 200)
	assert(trickydoubles(4343) == 4343)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func trickydoubles(x uint) uint {
	s := fmt.Sprint(x)
	n := len(s)
	if s[:n/2] == s[n/2:] {
		return x
	}
	return x * 2
}
