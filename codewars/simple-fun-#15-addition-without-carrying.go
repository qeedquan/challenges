/*

Task
A little boy is studying arithmetics. He has just learned how to add two integers, written one below another, column by column. But he always forgets about the important part - carrying.

Given two integers, find the result which the little boy will get.

Example
For param1 = 456 and param2 = 1734, the output should be 1180

    456
   1734
+ ____
   1180
The little boy goes from right to left:

6 + 4 = 10 but the little boy forgets about 1 and just writes down 0 in the last column

5 + 3 = 8

4 + 7 = 11 but the little boy forgets about the leading 1 and just writes down 1 under 4 and 7.

There is no digit in the first number corresponding to the leading digit of the second one, so the little boy imagines that 0 is written before 456. Thus, he gets 0 + 1 = 1.

Input/Output
[input] integer a

A non-negative integer.

Constraints: 0 ≤ a ≤ 99999.

[input] integer b

A non-negative integer.

Constraints: 0 ≤ b ≤ 59999.

[output] an integer

The result that the little boy will get.

*/

package main

func main() {
	assert(addwc(456, 1734) == 1180)
	assert(addwc(99999, 0) == 99999)
	assert(addwc(999, 999) == 888)
	assert(addwc(0, 0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func addwc(a, b uint) uint {
	r := uint(0)
	for p := uint(1); a > 0 || b > 0; p *= 10 {
		r += p * ((a + b) % 10)
		a /= 10
		b /= 10
	}
	return r
}
