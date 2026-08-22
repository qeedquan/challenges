/*

Introduction
Of course, we've got a lot of sequence challenges, so here is another one.

The Kimberling sequence (A007063) goes as following:

1, 3, 5, 4, 10, 7, 15, 8, 20, 9, 18, 24, 31, 14, 28, 22, ...
This is produced by shuffling the normal iteration:

[1] 2  3  4  5  6  7  8
The first term of the sequence is 1. After that, we reshuffle the sequence until all the terms on the left are used. The shuffling has the pattern right - left - right - left - .... Since there are no terms at the left of the 1, there is no shuffling. We get the following:

 2 [3] 4  5  6  7  8  9
On the ith iteration, we discard the ith item and put that in our sequence. This is the 2nd iteration, so we discard the 2nd item. The sequence becomes: 1, 3. For our next iteration, we are going to shuffle the current iteration with the pattern above. We take the first unused item at the right of the ith item. This happens to be 4. We will append this to our new iteration:

 4
Now we're going to take the first unused item at the left of the ith item. This is 2. We will append this to our new iteration:

 4  2
Since there are no items left at the left of the ith item, we'll just append the rest of the sequence to the new iteration:

 4  2 [5] 6  7  8  9  10  11  ...
This is our 3rd iteration, so we'll discard the 3rd item, which is 5. This is the third item in our sequence:

 1, 3, 5
To get the next iteration, just repeat the process. I've made a gif if it isn't clear:

https://i.stack.imgur.com/5HcEJ.gif

The gif took me longer than writing the actual post

Task
Given an non-negative integer n, output the first n terms of the sequence
You may provide a function or a program
This is code-golf, so the submission with the least amount of bytes wins!
Test cases:
Input: 4
Output: 1, 3, 5, 4

Input: 8
Output: 1, 3, 5, 4, 10, 7, 15, 8

Input: 15
Output: 1, 3, 5, 4, 10, 7, 15, 8, 20, 9, 18, 24, 31, 14, 28
Note: The commas in the output are not necessary. You may for example use newlines, or output a list, etc.

*/

package main

func main() {
	tab := []int{1, 3, 5, 4, 10, 7, 15, 8, 20, 9, 18, 24, 31, 14, 28, 22, 42, 35, 33, 46, 53, 6, 36, 23, 2, 55, 62, 59, 76, 65, 54, 11, 34, 48, 70, 79, 99, 95, 44, 97, 58, 84, 25, 13, 122, 83, 26, 115, 82, 91, 52, 138, 67, 90, 71, 119, 64, 37, 81, 39, 169, 88, 108, 141, 38, 16, 146, 41, 21}

	for i, v := range tab {
		assert(kimberling(i+1) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A007063
func kimberling(n int) int {
	if n < 1 {
		return 0
	}

	i, j := n, n
	for ; j < 2*i-3; i-- {
		k := j + 2
		if j%2 > 0 {
			k = 1 - j
		}
		j = i - k/2
	}
	return i + j - 1
}
