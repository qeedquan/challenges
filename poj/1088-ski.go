/*

Description

Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

Input

输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

Output

输出最长区域的长度。

Sample Input

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

Sample Output

25

Source

SHTSC 2002

*/

package main

func main() {
	assert(region([][]int{
		{1, 2, 3, 4, 5},
		{16, 17, 18, 19, 6},
		{15, 24, 25, 20, 7},
		{14, 23, 22, 21, 8},
		{13, 12, 11, 10, 9},
	}) == 25)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func region(a [][]int) int {
	if len(a) == 0 || len(a[0]) == 0 {
		return 0
	}

	r := len(a)
	c := len(a[0])
	p := alloc(r, c)
	for i := range p {
		for j := range p[i] {
			p[i][j] = 1
		}
	}

	m := 0
	for i := range p {
		for j := range p[i] {
			p[i][j] = find(a, p, r, c, i, j)
			m = max(m, p[i][j])
		}
	}
	return m
}

func find(a, p [][]int, r, c, i, j int) int {
	if p[i][j] > 1 {
		return p[i][j]
	}

	m := 1
	if j-1 >= 0 && a[i][j] > a[i][j-1] {
		m = max(m, find(a, p, r, c, i, j-1)+1)
	}
	if j+1 < c && a[i][j] > a[i][j+1] {
		m = max(m, find(a, p, r, c, i, j+1)+1)
	}
	if i-1 >= 0 && a[i][j] > a[i-1][j] {
		m = max(m, find(a, p, r, c, i-1, j)+1)
	}
	if i+1 < r && a[i][j] > a[i+1][j] {
		m = max(m, find(a, p, r, c, i+1, j)+1)
	}
	return m
}

func alloc(r, c int) [][]int {
	m := make([][]int, r)
	t := make([]int, r*c)
	for i := range m {
		m[i] = t[i*c : (i+1)*c]
	}
	return m
}
