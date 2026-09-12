/*

Description

FJ has purchased N (1 <= N <= 2000) yummy treats for the cows who get money for giving vast amounts of milk. FJ sells one treat per day and wants to maximize the money he receives over a given period time.

The treats are interesting for many reasons:
The treats are numbered 1..N and stored sequentially in single file in a long box that is open at both ends. On any day, FJ can retrieve one treat from either end of his stash of treats.
Like fine wines and delicious cheeses, the treats improve with age and command greater prices.
The treats are not uniform: some are better and have higher intrinsic value. Treat i has value v(i) (1 <= v(i) <= 1000).
Cows pay more for treats that have aged longer: a cow will pay v(i)*a for a treat of age a.
Given the values v(i) of each of the treats lined up in order of the index i in their box, what is the greatest value FJ can receive for them if he orders their sale optimally?

The first treat is sold on day 1 and has age a=1. Each subsequent day increases the age by 1.

Input

Line 1: A single integer, N

Lines 2..N+1: Line i+1 contains the value of treat v(i)

Output

Line 1: The maximum revenue FJ can achieve by selling the treats

Sample Input

5
1
3
1
5
2

Sample Output

43
Hint

Explanation of the sample:

Five treats. On the first day FJ can sell either treat #1 (value 1) or treat #5 (value 2).

FJ sells the treats (values 1, 3, 1, 5, 2) in the following order of indices: 1, 5, 2, 3, 4, making 1x1 + 2x2 + 3x3 + 4x1 + 5x5 = 43.

Source

USACO 2006 February Gold & Silver

*/

package main

func main() {
	assert(revenue([]int{1, 3, 1, 5, 2}) == 43)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func revenue(a []int) int {
	n := len(a)
	p := alloc(n + 1)
	for i := 1; i <= n; i++ {
		p[i][i] = n * a[i-1]
	}
	for i := 1; i <= n-1; i++ {
		for j := 1; i+j <= n; j++ {
			p[j][j+i] = max(p[j][j+i-1]+a[j+i-1]*(n-i), a[j-1]*(n-i)+p[j+1][j+i])
		}
	}
	return p[1][n]
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}
