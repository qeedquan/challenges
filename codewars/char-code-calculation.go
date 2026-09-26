/*

Given a string, turn each character into its ASCII character code and join them together to create a number - let's call this number total1:

'ABC' --> 'A' = 65, 'B' = 66, 'C' = 67 --> 656667
Then replace any incidence of the number 7 with the number 1, and call this number 'total2':

total1 = 656667
              ^
total2 = 656661
              ^
Then return the difference between the sum of the digits in total1 and total2:

  (6 + 5 + 6 + 6 + 6 + 7)
- (6 + 5 + 6 + 6 + 6 + 1)
-------------------------
                       6

*/

package main

func main() {
	assert(calc("ABC") == 6)
	assert(calc("AFHJD") == 18)
	assert(calc("FVJFVDF") == 24)
	assert(calc("AOUCUAOF") == 24)
	assert(calc("abcdef") == 6)
	assert(calc("ifkhchlhfd") == 6)
	assert(calc("aaaaaddddr") == 30)
	assert(calc("jfmgklf8hglbe") == 6)
	assert(calc("jaam") == 12)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func calc(s string) int {
	r := 0
	for i := range s {
		r += value(s[i])
	}
	return r
}

func value(n byte) int {
	r := 0
	for ; n > 0; n /= 10 {
		if n%10 == 7 {
			r += 6
		}
	}
	return r
}
