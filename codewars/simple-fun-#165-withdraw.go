/*

 An ATM ran out of 10 dollar bills and only has 100, 50 and 20 dollar bills.

 Given an amount between 40 and 10000 dollars (inclusive) and assuming that the ATM wants to use as few bills as possible, determinate the minimal number of 100, 50 and 20 dollar bills the ATM needs to dispense (in that order).

## Example

 For n = 250, the result should be [2, 1, 0].

 For n = 260, the result should be [2, 0, 3].

 For n = 370, the result should be [3, 1, 1].

## Input/Output

 - [input] integer n
  Amount of money to withdraw. Assume that n is always exchangeable with [100, 50, 20] bills.
 - [output] integer array
  An array of number of 100, 50 and 20 dollar bills needed to complete the withdraw (in that order).

*/

package main

func main() {
	assert(withdraw(0) == [3]int{0, 0, 0})
	assert(withdraw(40) == [3]int{0, 0, 2})
	assert(withdraw(50) == [3]int{0, 1, 0})
	assert(withdraw(60) == [3]int{0, 0, 3})
	assert(withdraw(230) == [3]int{1, 1, 4})
	assert(withdraw(250) == [3]int{2, 1, 0})
	assert(withdraw(260) == [3]int{2, 0, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func withdraw(n int) [3]int {
	f := 0
	for n%20 > 0 {
		f = 1
		n -= 50
	}
	return [3]int{n / 100, f, (n % 100) / 20}
}
