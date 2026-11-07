/*

Description
Imagine a given set of numbers wherein some are cannibals. We define a cannibal as a larger number can eat a smaller number and increase its value by 1. There are no restrictions on how many numbers any given number can consume. A number which has been consumed is no longer available.

Your task is to determine the number of numbers which can have a value equal to or greater than a specified value.

Input Description
You'll be given two integers, i and j, on the first line. i indicates how many values you'll be given, and j indicates the number of queries.

Example:

 7 2
 21 9 5 8 10 1 3
 10 15
Based on the above description, 7 is number of values that you will be given. 2 is the number of queries.

That means -

Query 1 - How many numbers can have the value of at least 10

Query 2 - How many numbers can have the value of at least 15

Output Description
Your program should calculate and show the number of numbers which are equal to or greater than the desired number. For the sample input given, this will be -

 4 2
Explanation
For Query 1 -

The number 9 can consume the numbers 5 to raise its value to 10

The number 8 can consume the numbers 1 and 3 to raise its value to 10.

So including 21 and 10, we can get four numbers which have a value of at least 10.

For Query 2 -

The number 10 can consume the numbers 9,8,5,3, and 1 to raise its value to 15.

So including 21, we can get two numbers which have a value of at least 15.

Credit
This challenge was suggested by user u/Lemvig42, many thanks! If you have a challenge idea, please share it in r/dailyprogrammer_ideas and there's a good chance we'll use it

*/

package main

import "sort"

func main() {
	assert(count([]int{21, 9, 5, 8, 10, 1, 3}, 10) == 4)
	assert(count([]int{21, 9, 5, 8, 10, 1, 3}, 15) == 2)
	assert(count([]int{3, 3, 3, 2, 2, 2, 1, 1, 1}, 4) == 4)
	assert(count([]int{1, 2, 3, 4, 5}, 5) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(numbers []int, query int) int {
	cannibals := 0
	available := len(numbers)
	sort.Ints(numbers)
	for i := len(numbers) - 1; i >= 0; i-- {
		available -= max(query-numbers[i], 0)
		if available < 1 {
			break
		}
		cannibals += 1
		available -= 1
	}
	return cannibals
}
