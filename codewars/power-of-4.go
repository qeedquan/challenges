/*

Write a method that returns true if a given parameter is a power of 4, and false if it's not. If parameter is not an Integer (eg String, Array) method should return false as well.

(In C# Integer means all integer Types like Int16,Int32,.....)

Examples
powerOf4(1024) // returns true
powerOf4(44) // returns false
powerOf4("not a positive integer") // returns false

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	for i := uint64(0); i <= math.MaxUint32; i++ {
		if ispow4(i) {
			fmt.Println(i)
		}
	}
}

// https://oeis.org/A000302
func ispow4(n uint64) bool {
	return n != 0 && n&(n-1) == 0 && n&0xAAAAAAAAAAAAAAAA == 0
}
