/*

A briefcase has a 4-digit rolling-lock. Each digit is a number from 0-9 that can be rolled either forwards or backwards.

Create a function that returns the smallest number of turns it takes to transform the lock from the current combination to the target combination. One turn is equivalent to rolling a number forwards or backwards by one.

To illustrate:

current-lock: 4089
target-lock: 5672
What is the minimum number of turns it takes to transform 4089 to 5672?

4 ➞ 5
4 ➞ 5  // Forward Turns: 1 <- Min
4 ➞ 3 ➞ 2 ➞ 1 ➞ 0 ➞ 9 ➞ 8 ➞ 7 ➞ 6 ➞ 5  // Backward Turns: 9

0 ➞ 6
0 ➞ 1 ➞ 2 ➞ 3 ➞ 4 ➞ 5 ➞ 6  // Forward Turns: 6
0 ➞ 9 ➞ 8 ➞ 7 ➞ 6  // Backward Turns: 4  <- Min

8 ➞ 7
8 ➞ 9 ➞ 0 ➞ 1 ➞ 2 ➞ 3 ➞ 4 ➞ 5 ➞ 6 ➞ 7  // Forward Turns: 9
8 ➞ 7  // Backward Turns: 1  <- Min

9 ➞ 2
9 ➞ 0 ➞ 1 ➞ 2  // Forward Turns: 3  <- Min
9 ➞ 8 ➞ 7 ➞ 6 ➞ 5 ➞ 4 ➞ 3 ➞ 2  // Backward Turns: 7
It takes 1 + 4 + 1 + 3 = 9 minimum turns to change the lock from 4089 to 5672.

Notes
Both locks are in string format.
A 9 rolls forward to 0, and a 0 rolls backwards to a 9.

*/

package main

func main() {
	assert(minturns("4089", "5672") == 9)
	assert(minturns("1732", "4444") == 9)
	assert(minturns("7109", "2332") == 13)
	assert(minturns("2391", "4984") == 10)
	assert(minturns("1234", "3456") == 8)
	assert(minturns("1111", "1100") == 2)
	assert(minturns("1111", "0000") == 4)
	assert(minturns("0000", "9999") == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minturns(current, target string) int {
	total := 0
	for index := range 4 {
		diff := abs(int(current[index]-'0') - int(target[index]-'0'))
		if diff > 5 {
			diff = 10 - diff
		}
		total += diff
	}
	return total
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
