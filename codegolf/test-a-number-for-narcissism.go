/*

A number is narcissistic when the sum of its digits, with each digit raised to the power of digits quantity, is equal to the number itself.

153 ➞ 3 digits ➞ 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ➞ Narcissistic
84 ➞ 2 digits ➞ 8² + 4² = 64 + 16 = 80 ➞ Not narcissistic

Given a positive integer n, implement a function that returns true if the number is narcissistic, and false if it's not.
Examples

isNarcissistic(8208) ➞ true
// 8⁴ + 2⁴ + 0⁴ + 8⁴ = 8208

isNarcissistic(22) ➞ false
// 2² + 2² = 8

isNarcissistic(9) ➞ true
// 9¹ = 9

Notes

    Trivially, any number in the 1-9 range is narcissistic and any two-digit number is not.
    Curious fact: Only 88 numbers are narcissistic.

*/

package main

import "math"

func main() {
	tab := []uint64{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634,
		8208, 9474, 54748, 92727, 93084, 548834, 1741725,
		4210818, 9800817, 9926315, 24678050, 24678051, 88593477,
		146511208, 472335975, 534494836, 912985153, 4679307774,
		32164049650, 32164049651,
	}

	for i := range tab {
		assert(narcissistic(tab[i]) == true)
	}

	assert(narcissistic(153) == true)
	assert(narcissistic(84) == false)
	assert(narcissistic(8208) == true)
	assert(narcissistic(22) == false)
	assert(narcissistic(9) == true)
	assert(narcissistic(6) == true)
	assert(narcissistic(1741725) == true)
	assert(narcissistic(66) == false)
	assert(narcissistic(65239) == false)
	assert(narcissistic(886243) == false)
	assert(narcissistic(92727) == true)
	assert(narcissistic(472335975) == true)
	assert(narcissistic(42300981) == false)
	assert(narcissistic(548834) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A005188
func narcissistic(x uint64) bool {
	d := []uint64{}
	for v := x; v != 0; v /= 10 {
		d = append(d, v%10)
	}

	v := uint64(0)
	for i := range d {
		v += uint64(math.Pow(float64(d[i]), float64(len(d))))
		if v > x {
			return false
		}
	}
	return v == x
}
