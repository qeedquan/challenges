/*

In math, one way to figure out what the type of a given relation (linear, quadratic, etc) is to calculate the differences. To do so you take a list of y values for which the gap between the correspondent x values is the same, and subtract each one from the number above it, creating a list of numbers one shorter then the previous list. If the resultant list is completely composed of identical numbers, then the relation has a difference of 1 (it is linear). If they are not identical, then you repeat the process on the new list. If they are now identical, the relation has a difference of 2 (it is quadratic). If they are not identical, you simply continue this process until they are. For example, if you have the list of y values [1,6,15,28,45,66] for incrementally increasing x values:

First Differences:

1
6   1-6  =-5
15  6-15 =-9
28  15-28=-13
45  28-45=-17
66  45-66=-21

Second differences:

-5
-9  -5+9  =4
-13 -9+13 =4
-17 -13+17=4
-21 -17+21=4

As these results are identical, this relation has a difference of 2
Your Task
Write a program or function that, when given an array of integers as input, returns the difference of the relation described by the array, as explained above.

Input
An array of integers, which may be of any length>1.

Output
An integer representing the difference of the relation described by the input.

Test Cases
Input                            => Output
[1,2,3,4,5,6,7,8,9,10]           => 1
[1,4,9,16,25,36]                 => 2
[1,2,1]                          => 2 (when there is only one value left, all values are automatically identical, so the largest difference an array can have is equal to the length of the array-1)
"Hello World"                    => undefined behavior (invalid input)
[1,1,1,1,1,1,1,1,1]              => 0 (all elements are already identical)
[1, 3, 9, 26, 66, 150, 313, 610] => 6
Scoring
This is code-golf, lowest score in bytes in each language wins for that language. Lowest score overall gets the green checkmark.

*/

package main

func main() {
	assert(ndiff([]int{1, 6, 15, 28, 45, 66}) == 2)
	assert(ndiff([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 1)
	assert(ndiff([]int{1, 2, 1}) == 2)
	assert(ndiff([]int{1, 1, 1, 1, 1, 1, 1, 1, 1}) == 0)
	assert(ndiff([]int{1, 3, 9, 26, 66, 150, 313, 610}) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ndiff(x []int) int {
	c := 0
	for ; len(x) > 0 && distinct(x) >= 1; c++ {
		for i := 0; i < len(x)-1; i++ {
			x[i] -= x[i+1]
		}
		x = x[:len(x)-1]
	}
	return c
}

func distinct(x []int) int {
	c := 0
	for i := 1; i < len(x); i++ {
		if x[i] != x[i-1] {
			c++
		}
	}
	return c
}
