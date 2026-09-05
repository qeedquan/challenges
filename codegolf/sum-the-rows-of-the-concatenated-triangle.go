/*

Consider the following triangle.

1
23
456
7891
01112
131415
1617181
92021222
324252627
2829303132
33343536373
839404142434
4454647484950
51525354555657
585960616263646
5666768697071727
37475767778798081
As you probably noticed, the first row is of length 1, and each row thereafter is 1 digit longer than to the previous one and that it contains the digits of the positive integers concatenated.

You will be given an integer N. Your task is to find the sum of the digits that lie on Nth row of the above triangle.

Rules
You can choose either 0 or 1 indexing. Please specify that in your answer.

Default Loopholes apply.

You can take input and provide output by any standard mean, and in any reasonable format.

This is OEIS A066548, and this sequence is the triangle itself (except that we do not remove leading zeros).

This is code-golf, so the shortest code in bytes (in every language) wins. Have fun golfing!

Test Cases
Input  |  Output

0  |  1
1  |  5
2  |  15
3  |  25
4  |  5
5  |  15
6  |  25
7  |  20
8  |  33
9  |  33
10 |  43
11 |  46
12 |  64
Note that the above are 0-indexed. If you are looking for 1-indexed test cases, increment the input by 1.

On a quite unrelated note, I recently changed my profile picture and that inspired me to write this challenge.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	tab := []int{1, 5, 15, 25, 5, 15, 25, 20, 33, 33, 43, 46, 64, 63, 73, 90, 101, 117, 127, 27, 41, 55, 59, 61, 72, 89, 99, 109, 126, 137, 131, 70, 85, 100, 121, 141, 152, 170, 197, 135, 108, 145, 164, 189, 219, 240, 160, 167, 184, 227, 259, 282, 203, 207, 248, 275, 317, 297, 228}

	for i := range tab {
		assert(sct(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A066548
func sct(n int) int {
	w := new(bytes.Buffer)
	for i := 1; i <= n*n+1; i++ {
		fmt.Fprint(w, i)
	}

	s := w.String()
	j := triangular(n)
	r := 0
	for i := 0; i < n; i++ {
		r += int(s[i+j] - '0')
	}
	return r
}

func triangular(n int) int {
	return n * (n - 1) / 2
}
