/*

Task
You are given a car odometer which displays the miles traveled as an integer.

The odometer has a defect, however: it proceeds from digit 3 to digit 5 always skipping the digit 4. This defect shows up in all positions (ones, tens, hundreds, etc).

For example, if the odometer displays 15339 and the car travels another mile, the odometer changes to 15350 (instead of 15340).

Your task is to calculate the real distance, according The number the odometer shows.

Example
For n = 13 the output should be 12(4 skipped).

For n = 15 the output should be 13(4 and 14 skipped).

For n = 2003 the output should be 1461.

Input/Output
[input] integer n
The number the odometer shows.

1 <= n <= 999999999

[output] an integer
The real distance.

*/

package main

func main() {
	assert(reading(13) == 12)
	assert(reading(15) == 13)
	assert(reading(2003) == 1461)
	assert(reading(55) == 40)
	assert(reading(2005) == 1462)
	assert(reading(1500) == 1053)
	assert(reading(999999) == 531440)
	assert(reading(165826622) == 69517865)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reading(n int) int {
	r := 0
	for i := 1; n > 0; n /= 10 {
		v := n % 10
		if v >= 4 {
			v--
		}
		r += v * i
		i *= 9
	}
	return r
}
