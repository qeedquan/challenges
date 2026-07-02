/*

Description

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...
shows the first 10 ugly numbers. By convention, 1 is included.
Given the integer n,write a program to find and print the n'th ugly number.

Input

Each line of the input contains a postisive integer n (n <= 1500).Input is terminated by a line with n=0.

Output

For each line, output the n’th ugly number .:Don’t deal with the line with n=0.
Sample Input

1
2
9
0

Sample Output

1
2
10

Source

New Zealand 1990 Division I,UVA 136

*/

package main

func main() {
	x := uglysieve(10)
	assert(x[0] == 1)
	assert(x[1] == 2)
	assert(x[8] == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A051037
func uglysieve(n int) []int {
	if n < 1 {
		return []int{}
	}

	i2, i3, i5 := 0, 0, 0
	n2, n3, n5 := 2, 3, 5

	u := make([]int, n)
	u[0] = 1
	for i := 1; i < n; i++ {
		u[i] = min(n2, n3, n5)
		if u[i] == n2 {
			n2, i2 = u[i2+1]*2, i2+1
		}
		if u[i] == n3 {
			n3, i3 = u[i3+1]*3, i3+1
		}
		if u[i] == n5 {
			n5, i5 = u[i5+1]*5, i5+1
		}
	}
	return u
}
