/*

Introduction
I stumbled across this (useless) pattern the other day while I was watching TV. I named it "the 9 pattern" because the first number to use it was 9. The gist of it is, you enter a number (let's say x), and then you get back:

x
x + (x / 3) [let's call this y]
two-thirds of y [let's call this z]
z + 1
So, if I put inside this pattern the number 9 as x, this is what would come out:

9 (9)
12 (9 + 9 / 3) [9 over 3 is 3, and 9 + 3 is 12]
8 (12 times two-thirds) [a third of 12 is 4, and 4 * 2 is 8]
9 (8 + 1 is 9)
Challenge
Write me a function (in any programming language) that takes in a number, and outputs an integer array using the pattern.
Somewhat like this psuedo-code:

function ninePattern(int myInt) returns IntegerArray {
    int iterationA = myInt + (myInt / 3);
    int iterationB = iterationA * (2 / 3);
    int iterationC = iterationB + 1;
    IntegerArray x = [myInt, iterationA, iterationB, iterationC];
    return x;
}
Clarifications
Discussions have been arousing in comments regarding the specifications of the question. This section is meant to clarify some of those.

"better to count in bytes than characters"
I picked characters because (for me, at least) it would be easier to judge. Of course, I can't change that now. (lots of answers are already posted)

"rounding"
Rounding follows this rhyme:

If it's 5 or more, raise the score
If it's 4 or less, let it rest

Simply, put, if it is something like 4.7 or 3.85, round them to 5 and 4 respectively.

Examples
Input => Result
9 => [9, 12, 8, 9]
8 => [8, 11, 7, 8]
6 => [6, 8, 5, 6]
23 => [23, 31, 21, 22]
159 => [159, 212, 141, 142]
If, however, the numbers are something like 2.3 or 10.435446, round them to 2 and 10 respectively.

"language support"
You are free to not use functions and/or arrays IF AND ONLY IF the language of your choice does not support them. If it does (even if it will increase your characters count), you must use them.

*/

package main

import (
	"math"
)

func main() {
	assert(ninepattern(9) == [4]int{9, 12, 8, 9})
	assert(ninepattern(8) == [4]int{8, 11, 7, 8})
	assert(ninepattern(6) == [4]int{6, 8, 5, 6})
	assert(ninepattern(23) == [4]int{23, 31, 21, 22})
	assert(ninepattern(159) == [4]int{159, 212, 141, 142})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ninepattern(x int) [4]int {
	y := math.Round(float64(x) + (float64(x) / 3))
	z := math.Round((y * 2) / 3)
	w := math.Round(z + 1)
	return [4]int{x, int(y), int(z), int(w)}
}
