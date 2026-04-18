/*

I have some (say, n) marbles (small glass balls) and I am going to buy some boxes to store them. The
boxes are of two types:
T ype 1: each box costs c1 Taka and can hold exactly n1 marbles
T ype 2: each box costs c2 Taka and can hold exactly n2 marbles
I want each of the used boxes to be filled to its capacity and also to minimize the total cost of buying
them. Since I find it difficult for me to figure out how to distribute my marbles among the boxes, I
seek your help. I want your program to be efficient also.

Input
The input file may contain multiple test cases. Each test case begins with a line containing the integer
n (1 ≤ n ≤ 2, 000, 000, 000). The second line contains c1 and n1, and the third line contains c2 and n2.
Here, c1, c2, n1 and n2 are all positive integers having values smaller than 2,000,000,000.
A test case containing a zero for n in the first line terminates the input.

Output
For each test case in the input print a line containing the minimum cost solution (two nonnegative
integers m1 and m2, where mi = number of T ypei boxes required) if one exists, print ‘failed’ otherwise.
If a solution exists, you may assume that it is unique.

Sample Input
43
1 3
2 4
40
5 9
5 12
0

Sample Output
13 1
failed

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(43, 1, 3, 2, 4))
	fmt.Println(solve(40, 5, 9, 5, 12))
}

func solve(v, c1, n1, c2, n2 int64) (int64, int64) {
	x, y, d := exgcd(n1, n2)
	if v%d != 0 {
		return -1, -1
	}

	x *= v / d
	y *= v / d
	n2 /= d
	n1 /= d
	l := int64(math.Ceil(float64(-x) / float64(n2)))
	u := int64(math.Floor(float64(y) / float64(n1)))
	if l <= u {
		r1 := c1*(x+n2*l) + c2*(y-n1*l)
		r2 := c1*(x+n2*u) + c2*(y-n1*u)
		if r1 < r2 {
			return x + n2*l, y - n1*l
		}
		return x + n2*u, y - n1*u
	}

	return -1, -1
}

func exgcd(a, b int64) (int64, int64, int64) {
	if b == 0 {
		return 1, 0, a
	}

	x, y, d := exgcd(b, a%b)
	return y, x - (a/b)*y, d
}
