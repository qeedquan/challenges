/*

While doodling around with numbers, I found an interesting permutation you can generate from a list of numbers. If you repeat this same permutation enough times, you will always end up back at the original array. Let's use the following list:

[1, 2, 3, 4, 5]
as an example

Reverse the array. Now our array is

[5, 4, 3, 2, 1]
Reorder (swap) each pair. Our list has 2 pairs: [5, 4], and [3, 2]. Unfortunately, we can't group the 1 into a pair, so we'll just leave it on it's own. After swapping each pair, the new array is:

[4, 5, 2, 3, 1]
Repeat steps 1 and 2 until we return to the original array. Here are the next 4 steps:

Step 2:
Start:          [4, 5, 2, 3, 1]
Reversed:       [1, 3, 2, 5, 4]
Pairs Swapped:  [3, 1, 5, 2, 4]

Step 3:
Start:          [3, 1, 5, 2, 4]
Reversed:       [4, 2, 5, 1, 3]
Pairs Swapped:  [2, 4, 1, 5, 3]

Step 4:
Start:          [2, 4, 1, 5, 3]
Reversed:       [3, 5, 1, 4, 2]
Pairs Swapped:  [5, 3, 4, 1, 2]

Step 5:
Start:          [5, 3, 4, 1, 2]
Reversed:       [2, 1, 4, 3, 5]
Pairs Swapped:  [1, 2, 3, 4, 5]

# No more steps needed because we are back to the original array
If the length of the list, n is odd, it will always take exactly n steps to return to the original array. If n is even, it will always take 2 steps to return to the original array, unless n is 2, in which case it will take 1 step (because reversing and swapping is the same thing).

Your task for today (should you choose to accept it) is to visualize this set of steps for lists of arbitrary lengths. You must write a program or function that takes a single positive integer n as input, and does this set of steps for the list [1, n]. You must output each intermediate step along the way, whether that means printing each step, or returning them all as a list of steps. I'm not very picky about the output format, as long as it's clear that you are generating every step. This means (for example) any of these:

Outputting every step as a list to STDOUT

Returning a list of lists

Returning a list of string representations of each step

Returning/outputting a matrix

would be acceptable.

You must also output the original array, whether that comes at the end or at the beginning is up to you. (technically, both are correct)

You will have to handle the edge case of 2 taking 1 step instead of 2, so please make sure your solution works with an input of 2 (and 1 is another potential edge case).

As usual, this is code-golf, so standard loopholes apply, and try to make your solution shorter than any other in the language of your choice (or even try to beat another language that is typically shorter than yours if you're feeling up for a challenge).

Test IO
1:
[1]


2:
[1, 2]


3:
[2, 3, 1]
[3, 1, 2]
[1, 2, 3]


4:
[3, 4, 1, 2]
[1, 2, 3, 4]


5:
[4, 5, 2, 3, 1]
[3, 1, 5, 2, 4]
[2, 4, 1, 5, 3]
[5, 3, 4, 1, 2]
[1, 2, 3, 4, 5]


7:
[6, 7, 4, 5, 2, 3, 1]
[3, 1, 5, 2, 7, 4, 6]
[4, 6, 2, 7, 1, 5, 3]
[5, 3, 7, 1, 6, 2, 4]
[2, 4, 1, 6, 3, 7, 5]
[7, 5, 6, 3, 4, 1, 2]
[1, 2, 3, 4, 5, 6, 7]


9:
[8, 9, 6, 7, 4, 5, 2, 3, 1]
[3, 1, 5, 2, 7, 4, 9, 6, 8]
[6, 8, 4, 9, 2, 7, 1, 5, 3]
[5, 3, 7, 1, 9, 2, 8, 4, 6]
[4, 6, 2, 8, 1, 9, 3, 7, 5]
[7, 5, 9, 3, 8, 1, 6, 2, 4]
[2, 4, 1, 6, 3, 8, 5, 9, 7]
[9, 7, 8, 5, 6, 3, 4, 1, 2]
[1, 2, 3, 4, 5, 6, 7, 8, 9]
And for good measure, here's one giant test case:

27:
[26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17, 14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 1]
[3, 1, 5, 2, 7, 4, 9, 6, 11, 8, 13, 10, 15, 12, 17, 14, 19, 16, 21, 18, 23, 20, 25, 22, 27, 24, 26]
[24, 26, 22, 27, 20, 25, 18, 23, 16, 21, 14, 19, 12, 17, 10, 15, 8, 13, 6, 11, 4, 9, 2, 7, 1, 5, 3]
[5, 3, 7, 1, 9, 2, 11, 4, 13, 6, 15, 8, 17, 10, 19, 12, 21, 14, 23, 16, 25, 18, 27, 20, 26, 22, 24]
[22, 24, 20, 26, 18, 27, 16, 25, 14, 23, 12, 21, 10, 19, 8, 17, 6, 15, 4, 13, 2, 11, 1, 9, 3, 7, 5]
[7, 5, 9, 3, 11, 1, 13, 2, 15, 4, 17, 6, 19, 8, 21, 10, 23, 12, 25, 14, 27, 16, 26, 18, 24, 20, 22]
[20, 22, 18, 24, 16, 26, 14, 27, 12, 25, 10, 23, 8, 21, 6, 19, 4, 17, 2, 15, 1, 13, 3, 11, 5, 9, 7]
[9, 7, 11, 5, 13, 3, 15, 1, 17, 2, 19, 4, 21, 6, 23, 8, 25, 10, 27, 12, 26, 14, 24, 16, 22, 18, 20]
[18, 20, 16, 22, 14, 24, 12, 26, 10, 27, 8, 25, 6, 23, 4, 21, 2, 19, 1, 17, 3, 15, 5, 13, 7, 11, 9]
[11, 9, 13, 7, 15, 5, 17, 3, 19, 1, 21, 2, 23, 4, 25, 6, 27, 8, 26, 10, 24, 12, 22, 14, 20, 16, 18]
[16, 18, 14, 20, 12, 22, 10, 24, 8, 26, 6, 27, 4, 25, 2, 23, 1, 21, 3, 19, 5, 17, 7, 15, 9, 13, 11]
[13, 11, 15, 9, 17, 7, 19, 5, 21, 3, 23, 1, 25, 2, 27, 4, 26, 6, 24, 8, 22, 10, 20, 12, 18, 14, 16]
[14, 16, 12, 18, 10, 20, 8, 22, 6, 24, 4, 26, 2, 27, 1, 25, 3, 23, 5, 21, 7, 19, 9, 17, 11, 15, 13]
[15, 13, 17, 11, 19, 9, 21, 7, 23, 5, 25, 3, 27, 1, 26, 2, 24, 4, 22, 6, 20, 8, 18, 10, 16, 12, 14]
[12, 14, 10, 16, 8, 18, 6, 20, 4, 22, 2, 24, 1, 26, 3, 27, 5, 25, 7, 23, 9, 21, 11, 19, 13, 17, 15]
[17, 15, 19, 13, 21, 11, 23, 9, 25, 7, 27, 5, 26, 3, 24, 1, 22, 2, 20, 4, 18, 6, 16, 8, 14, 10, 12]
[10, 12, 8, 14, 6, 16, 4, 18, 2, 20, 1, 22, 3, 24, 5, 26, 7, 27, 9, 25, 11, 23, 13, 21, 15, 19, 17]
[19, 17, 21, 15, 23, 13, 25, 11, 27, 9, 26, 7, 24, 5, 22, 3, 20, 1, 18, 2, 16, 4, 14, 6, 12, 8, 10]
[8, 10, 6, 12, 4, 14, 2, 16, 1, 18, 3, 20, 5, 22, 7, 24, 9, 26, 11, 27, 13, 25, 15, 23, 17, 21, 19]
[21, 19, 23, 17, 25, 15, 27, 13, 26, 11, 24, 9, 22, 7, 20, 5, 18, 3, 16, 1, 14, 2, 12, 4, 10, 6, 8]
[6, 8, 4, 10, 2, 12, 1, 14, 3, 16, 5, 18, 7, 20, 9, 22, 11, 24, 13, 26, 15, 27, 17, 25, 19, 23, 21]
[23, 21, 25, 19, 27, 17, 26, 15, 24, 13, 22, 11, 20, 9, 18, 7, 16, 5, 14, 3, 12, 1, 10, 2, 8, 4, 6]
[4, 6, 2, 8, 1, 10, 3, 12, 5, 14, 7, 16, 9, 18, 11, 20, 13, 22, 15, 24, 17, 26, 19, 27, 21, 25, 23]
[25, 23, 27, 21, 26, 19, 24, 17, 22, 15, 20, 13, 18, 11, 16, 9, 14, 7, 12, 5, 10, 3, 8, 1, 6, 2, 4]
[2, 4, 1, 6, 3, 8, 5, 10, 7, 12, 9, 14, 11, 16, 13, 18, 15, 20, 17, 22, 19, 24, 21, 26, 23, 27, 25]
[27, 25, 26, 23, 24, 21, 22, 19, 20, 17, 18, 15, 16, 13, 14, 11, 12, 9, 10, 7, 8, 5, 6, 3, 4, 1, 2]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27]

Have fun golfing!

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	for i := 1; i < 10; i++ {
		rs3(i)
	}
	rs3(27)
}

func rs3(n int) {
	a := make([]int, n)
	for i := range a {
		a[i] = i + 1
	}
	b := append([]int{}, a...)

	fmt.Printf("%d:\n", n)
	for {
		reverse(b)
		swap(b)
		fmt.Println(b)
		if slices.Equal(a, b) {
			break
		}
	}
	fmt.Println()
}

func reverse(a []int) {
	n := len(a)
	for i := 0; i < n/2; i++ {
		a[i], a[n-i-1] = a[n-i-1], a[i]
	}
}

func swap(a []int) {
	for i := 0; i+1 < len(a); i += 2 {
		a[i], a[i+1] = a[i+1], a[i]
	}
}
