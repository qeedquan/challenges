/*

Your task is to write a program that calculates the amount of different ways to display any given whole positive number using the following rules:

Meet the 'advanced binary system':

Any whole positive number can be displayed in binary form, but each bit can have every number from 0 to 9. This means, a valid number might look like this: 480 and would be calculated to 4 * 2^2 + 8 * 2^1 + 0 * 2^0 = 32. You see, every 'bit' is multiplied with 2 to the power of the significance of the bit, just like in binary but with 10 (0 to 9) different possible bits instead of 2 (0 and 1).

It is given a whole positive decimal number in any kind of form. This can be text input, a variable value, an array element, etc. Then your program calculates in how many ways (using the number format explained above. Leading zeroes obviously do not count) the inputted decimal number can be displayed. The result should then be returned, printed or drawn in any readable way as a decimal number.

Examples:

Input: 3 -> Output: 2 > Reason: the decimal number 3 can be displayed as 11 (1 * 2^1 + 1 * 2^0) and as 3 (3 * 2^0), thus 2 different possibilities

Input: 1 -> Output: 1 > Reason: the only possibility is 1 (1 * 2^0)

Input: 2 -> Output: 2 > Reason: possibilities are 10 and 2

And so on.

This is code golf: program with least amount of bytes wins!

Test cases

The first 30 values are:

1, 2, 2, 4, 4, 6, 6, 10, 10, 13, 13, 18, 18, 22, 22, 30, 30, 36, 36, 45, 45, 52, 52, 64, 64, 72, 72, 84, 84, 93

*/

package main

func main() {
	tab := []int{1, 2, 2, 4, 4, 6, 6, 10, 10, 13, 13, 18, 18, 22, 22, 30, 30, 36, 36, 45, 45, 52, 52, 64, 64, 72, 72, 84, 84, 93}
	for i, v := range tab {
		assert(ways(i) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ways(n int) int {
	return decibins((n + 3) / 2)
}

// https://oeis.org/A309616
func decibins(n int) int {
	a := 1
	s := []int{a}
	for i := 1; i < n; i++ {
		a += s[i/2]
		if i >= 5 {
			a -= s[(i-5)/2]
		}
		s = append(s, a)
	}
	return s[len(s)-1]
}
