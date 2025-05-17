/*

For a while now, I've been running into a problem when counting on my fingers, specifically, that I can only count to ten. My solution to that problem has been to count in binary on my fingers, putting up my thumb for one, my forefinger for two, both thumb and forefinger for three, etc. However, we run into a bit of a problem when we get to the number four. Specifically, it requires us to put up our middle finger, which results in a rather unfortunate gesture, which is not typically accepted in society. This type of number is a rude number. We come to the next rude number at 36, when we raise the thumb on our second hand and the middle finger of our first hand. The definition of a rude number is any number that, under this system of counting, results in us putting up only the middle finger of any hand. Once we pass 1023 (the maximum number reachable on one person, with two hands of five fingers each), assume we continue with a third hand, with additional hands added as required.

Your Task:
Write a program or function that receives an input and outputs a truthy/falsy value based on whether the input is a rude number.

Input:
An integer between 0 and 109 (inclusive).

Output:
A truthy/falsy value that indicates whether the input is a rude number.

Test Cases:
Input:    Output:
0   --->  falsy
3   --->  falsy
4   --->  truthy
25  --->  falsy
36  --->  truthy
127 --->  falsy
131 --->  truthy

Scoring:
This is code-golf, so the lowest score in bytes wins.

*/

package main

import (
	"strconv"
	"strings"
)

func main() {
	assert(rude(0) == false)
	assert(rude(3) == false)
	assert(rude(4) == true)
	assert(rude(25) == false)
	assert(rude(36) == true)
	assert(rude(127) == false)
	assert(rude(131) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rude(n int64) bool {
	s := strconv.FormatInt(n, 32)
	return strings.IndexByte(s, '4') >= 0
}
