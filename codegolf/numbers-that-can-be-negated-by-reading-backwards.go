/*

Balanced ternary is a modified version of ternary (base 3), using the three digits 1,0 and -1 (written as T) to represent numbers.

The balanced ternary representation of -n can be obtained by replacing 1 with T and T with 1 in the balanced ternary representation of n.

Examples:

1     // decimal: 1
T     // decimal: -1
1T    // decimal: 3-1 = 2
T1    // decimal: -3+1 = -2
1TTT0 // decimal: 3^4-3^3-3^2-3^1+0= 42
Your task is to write a function or program that outputs all positive integers n for which reversing the balanced ternary representation gives the balanced ternary representation of -n (OEIS 233571).

Example:

1100T0100TT (decimal 78080) reversed is TT0010T0011 (decimal -78080)

The first few numbers in the sequence:

1 -> 2  // balanced ternary: 1T
2 -> 8  // balanced ternary: 10T
3 -> 20 // balanced ternary: 1T1T
4 -> 26 // balanced ternary: 100T
5 -> 32 // balanced ternary: 11TT
6 -> 56 // balanced ternary: 1T01T
...
100 -> 14600 //  balanced ternary: 1T1T001T1T
...
9999 -> 132258878 // balanced ternary: 1001T00TT11001T00T
Rules
The standard sequence I/O rules apply
It is allowed to output numbers in balanced ternary:
(as a string using three distinguishable characters, or as a list of digits)
Your code should be able to handle at least the first 10000 elements of this sequence
This is code-golf so the shortest solution (in each language) measured in bytes wins

*/

package main

import (
	"math"
	"slices"
)

func main() {
	tab := []int{0, 2, 8, 20, 26, 32, 56, 80, 104, 146, 164, 182, 224, 242, 260, 302, 320, 338, 416, 488, 560, 656, 728, 800, 896, 968, 1040, 1172, 1226, 1280, 1406, 1460, 1514, 1640, 1694, 1748, 1898, 1952, 2006, 2132, 2186, 2240, 2366, 2420, 2474, 2624, 2678, 2732, 2858}

	assert(slices.Equal(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A233571
func isivt(x int) bool {
	t := 0
	for v := x; v > 0; v /= 3 {
		t = (v+1)%3 - 1 + t*3
		v += 1
	}
	return x == -t
}

func gen(n int) []int {
	r := []int{}
	for i := 0; i < math.MaxInt && len(r) < n; i++ {
		if isivt(i) {
			r = append(r, i)
		}
	}
	return r
}
