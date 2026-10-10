/*

Description

The fact that any positive integer has a representation as the sum of at most four positive squares (i.e. squares of positive integers) is known as Lagrange's Four-Square Theorem. The first published proof of the theorem was given by Joseph-Louis Lagrange in 1770. Your mission however is not to explain the original proof nor to discover a new proof but to show that the theorem holds for some specific numbers by counting how many such possible representations there are.
For a given positive integer n, you should report the number of all representations of n as the sum of at most four positive squares. The order of addition does not matter, e.g. you should consider 4^2 + 3^2 and 3^2 + 4^2 are the same representation.

For example, let's check the case of 25. This integer has just three representations 1^2+2^2+2^2+4^2, 3^2 + 4^2, and 5^2. Thus you should report 3 in this case. Be careful not to count 4^2 + 3^2 and 3^2 + 4^2 separately.

Input

The input is composed of at most 255 lines, each containing a single positive integer less than 2^15, followed by a line containing a single zero. The last line is not a part of the input data.

Output

The output should be composed of lines, each containing a single integer. No other characters should appear in the output.

The output integer corresponding to the input integer n is the number of all representations of n as the sum of at most four positive squares.

Sample Input

1
25
2003
211
20007
0

Sample Output

1
3
48
7
738

Source

Japan 2003,Aizu

*/

package main

func main() {
	x := gen(20100)
	assert(x[1] == 1)
	assert(x[25] == 3)
	assert(x[2003] == 48)
	assert(x[211] == 7)
	assert(x[20007] == 738)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002635
func gen(n int) []int {
	p := make([][4]int, n+1)
	for i := 1; i*i <= n; i++ {
		p[i*i][0]++
		for j := i; i*i+j*j <= n; j++ {
			p[i*i+j*j][1]++
			for k := j; i*i+j*j+k*k <= n; k++ {
				p[i*i+j*j+k*k][2]++
				for l := k; i*i+j*j+k*k+l*l <= n; l++ {
					p[i*i+j*j+k*k+l*l][3]++
				}
			}
		}
	}

	r := make([]int, n+1)
	for i := range r {
		r[i] = p[i][0] + p[i][1] + p[i][2] + p[i][3]
	}
	r[0] = 1
	return r
}
