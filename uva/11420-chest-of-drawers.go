/*

A chest of drawers means a wardrobe which has many drawers aligned vertically as shown in the figure on the left. Although this is useful furniture,
some problems arise when all the drawers need have provisions of locking -
that is sometimes a drawer is not secured even if it is locked. For example
assume that the third drawer from the top is locked but the drawer immediately above it is not locked. Then the drawer that is locked is also not secured
because one can access it by pulling out the drawer immediately above it.
In a chest of n drawers, there are a number of ways to ensure that exactly
s drawers are secure. For example for the chest of drawers shown on the left,
exactly four drawers can be secured in six ways. These six ways are shown in

Figure 2.
Given the value of n and s, your job is to find out in how many ways they
can be secured.

Figure 2: In this figure L means that the drawer is locked and U means that the corresponding drawer
is unlocked. And here all six locking combinations are shown which ensures that exactly four drawers
are secured. Letters corresponding the secured drawers are boldfaced.

Input
The input file contains at most 5000 lines of inputs.
Each line contains two integers n and s (1 ≤ n ≤ 65 and 0 ≤ s ≤ 65). Here n is the total number
of drawers and s is the number of drawers that needs to be secured.
Input is terminated by a line containing two negative numbers. This input should not be processed.

Output
For each line of input produce one line of output. This line contains an integer which denotes in how
many, s drawers out of the n drawers can be secured.

Sample Input
6 2
6 3
6 4
-1 -1

Sample Output
16
9
6

*/

package main

func main() {
	assert(solve(6, 2) == 16)
	assert(solve(6, 3) == 9)
	assert(solve(6, 4) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, s int) int {
	p := make([][][2]int, n+1)
	for i := range p {
		p[i] = make([][2]int, n+1)
	}

	p[1][1][1] = 1
	p[1][0][0] = 1
	for i := 2; i <= n; i++ {
		for j := 0; j <= i; j++ {
			p[i][j][0] = p[i-1][j][0] + p[i-1][j][1]
			p[i][j][1] = p[i-1][j][0]
			if j > 0 {
				p[i][j][1] += p[i-1][j-1][1]
			}
		}
	}
	return p[n][s][0] + p[n][s][1]
}
