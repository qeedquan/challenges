/*

Summary:
Given a number, num, return the shortest amount of steps it would take from 1, to land exactly on that number.

Description:
A step is defined as either:

Adding 1 to the number: num += 1
Doubling the number: num *= 2
You will always start from the number 1 and you will have to return the shortest count of steps it would take to land exactly on that number.

1 <= num <= 10000

Examples:

num == 3 would return 2 steps:

1 -- +1 --> 2:        1 step
2 -- +1 --> 3:        2 steps

2 steps
num == 12 would return 4 steps:

1 -- +1 --> 2:        1 step
2 -- +1 --> 3:        2 steps
3 -- x2 --> 6:        3 steps
6 -- x2 --> 12:       4 steps

4 steps
num == 16 would return 4 steps:

1 -- +1 --> 2:        1 step
2 -- x2 --> 4:        2 steps
4 -- x2 --> 8:        3 steps
8 -- x2 --> 16:       4 steps

4 steps

*/

package main

func main() {
	tab := []int{
		0, 1, 2, 2, 3, 3, 4, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 5,
		6, 6, 7, 6, 7, 7, 8, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9, 6,
		7, 7, 8, 7, 8, 8, 9, 7, 8, 8, 9, 8, 9, 9, 10, 6, 7, 7, 8, 7, 8, 8, 9,
		7, 8, 8, 9, 8, 9, 9, 10, 7, 8, 8, 9, 8, 9, 9,
	}

	for i := range tab {
		assert(steps(i+1) == tab[i])
	}

	assert(steps(3) == 2)
	assert(steps(12) == 4)
	assert(steps(16) == 4)
	assert(steps(71) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A014701
func steps(n int) int {
	c := 0
	for ; n > 1; c++ {
		if n%2 == 0 && n/2 >= 1 {
			n /= 2
		} else {
			n -= 1
		}
	}
	return c
}
