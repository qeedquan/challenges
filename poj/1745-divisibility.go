/*

Description

Consider an arbitrary sequence of integers. One can place + or - operators between integers in the sequence, thus deriving different arithmetical expressions that evaluate to different values. Let us, for example, take the sequence: 17, 5, -21, 15. There are eight possible expressions: 17 + 5 + -21 + 15 = 16
17 + 5 + -21 - 15 = -14
17 + 5 - -21 + 15 = 58
17 + 5 - -21 - 15 = 28
17 - 5 + -21 + 15 = 6
17 - 5 + -21 - 15 = -24
17 - 5 - -21 + 15 = 48
17 - 5 - -21 - 15 = 18
We call the sequence of integers divisible by K if + or - operators can be placed between integers in the sequence in such way that resulting value is divisible by K. In the above example, the sequence is divisible by 7 (17+5+-21-15=-14) but is not divisible by 5.

You are to write a program that will determine divisibility of sequence of integers.

Input

The first line of the input file contains two integers, N and K (1 <= N <= 10000, 2 <= K <= 100) separated by a space.
The second line contains a sequence of N integers separated by spaces. Each integer is not greater than 10000 by it's absolute value.

Output

Write to the output file the word "Divisible" if given sequence of integers is divisible by K or "Not divisible" if it's not.

Sample Input

4 7
17 5 -21 15

Sample Output

Divisible

Source

Northeastern Europe 1999

*/

package main

func main() {
	assert(divisible([]int{17, 5, -21, 15}, 7) == "Divisible")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func divisible(a []int, k int) string {
	n := len(a)
	if n == 0 {
		return "Divisible"
	}

	p := alloc(max(n+1, k))
	p[n][abs(a[n-1])%k] = 1
	for i := n - 1; i >= 1; i-- {
		for j := 0; j < k; j++ {
			if p[i+1][j] != 0 {
				p[i][abs(j+a[i-1])%k] = 1
				p[i][abs(j-a[i-1])%k] = 1
			}
		}
	}
	if p[1][0] == 0 {
		return "Not Divisible"
	}
	return "Divisible"
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
