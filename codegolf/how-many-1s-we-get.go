/*

Description
Count how many occurrences there are of the digit 1 between two given numbers [a,b], inclusive.

For example, from 1 to 100 it should be 21:

1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 31, 41, 51, 61, 71, 81, 91, 100

The number 1 is repeated 21 times.

Rules
Each number in the input list is guaranteed is an integer in the range 0≤a≤b<2^32.

The shortest answer in bytes wins.
Test cases
[1, 100] -> 21
[11, 200] -> 138
[123, 678] -> 182

Example
Here is my code using bash

eval echo {$1..$2}|grep -o 1|wc -l

*/

package main

func main() {
	assert(ones(1, 100) == 21)
	assert(ones(11, 200) == 138)
	assert(ones(123, 678) == 182)

	N := 1000
	for a := 0; a <= N; a++ {
		for b := 0; b <= N; b++ {
			assert(ones(a, b) == onesbf(a, b))
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func onesbf(a, b int) int {
	c := 0
	for i := a; i <= b; i++ {
		for x := i; x > 0; x /= 10 {
			if x%10 == 1 {
				c++
			}
		}
	}
	return c
}

func ones(a, b int) int {
	return max(count(b)-count(a-1), 0)
}

// https://oeis.org/A094798
func count(n int) int {
	s := 0
	for t := 1; t <= n; t *= 10 {
		s += min(max(0, (n%(10*t))-(t-1)), t) + t*(n/(10*t))
	}
	return s
}
