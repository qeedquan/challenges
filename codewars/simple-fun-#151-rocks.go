/*

Task
Vanya gets bored one day and decides to enumerate a large pile of rocks. He first counts the rocks and finds out that he has n rocks in the pile, then he goes to the store to buy labels for enumeration.

Each of the labels is a digit from 0 to 9 and each of the n rocks should be assigned a unique number from 1 to n.

If each label costs $1, how much money will Vanya spend on this project?

Input/Output
[input] integer n
The number of rocks in the pile.

1  ≤  n  ≤  10^9

[output] an integer
the cost of the enumeration.

Example
For n = 13, the result should be 17.

the numbers from 1 to n are:
1 2 3 4 5 6 7 8 9 10 11 12 13
we need 17 single digit labels:
1 2 3 4 5 6 7 8 9 1 0 1 1 1 2 1 3
each label cost $1, so the output should be 17.

*/

package main

import "math"

func main() {
	tab := []int{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13, 15, 17, 19, 21, 23,
		25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51,
		53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79,
		81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101, 103, 105,
		107, 109, 111, 113, 115, 117, 119, 121, 123, 125,
	}

	for i := range tab {
		assert(rocks(i+1) == tab[i])
	}
	assert(rocks(36123011) == 277872985)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A058183
func rocks(n int) int {
	if n < 1 {
		return 0
	}

	p := int(math.Log10(float64(10 * n)))
	return (n+1)*p - (int(math.Pow10(p))-1)/9
}
