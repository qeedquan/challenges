/*

Your challenge, should you chose to accept it, is to code-golf a function that returns true or false (or some similar meaningful representation of yes and no) if a number meets the following criteria:

The integer itself is a prime number OR
Either of its neighbor integers are prime
For example:
An input of 7 would return True.
An input of 8 would also return True.
An input of 15 would return False. (Neither 14, 15, or 16 are prime)

The input must be able to return correctly for numbers between 2^0 and 2^20 inclusive, so there's no need to worry about sign issues or integer overflows.

*/

package main

import (
	"fmt"
	"math"
	"math/big"
	"reflect"
)

func main() {
	tab := []int64{1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 16, 17, 18, 19, 20, 22, 23, 24, 28, 29, 30, 31, 32, 36, 37, 38, 40, 41, 42, 43, 44, 46, 47, 48, 52, 53, 54, 58, 59, 60, 61, 62, 66, 67, 68, 70, 71, 72, 73, 74, 78, 79, 80, 82, 83, 84, 88, 89, 90, 96, 97, 98, 100}

	p := gen(len(tab))
	fmt.Println(p)
	assert(reflect.DeepEqual(p, tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int64 {
	r := []int64{}
	for i := int64(0); len(r) < n && i < math.MaxInt64; i++ {
		if notquiteprime(i) {
			r = append(r, i)
		}
	}
	return r
}

// https://oeis.org/A210940
func notquiteprime(n int64) bool {
	return isprime(n) || isprime(n-1) || isprime(n+1)
}

func isprime(n int64) bool {
	x := big.NewInt(n)
	return x.ProbablyPrime(2)
}
