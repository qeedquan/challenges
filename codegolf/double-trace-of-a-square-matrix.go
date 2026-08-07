/*

Inspired by a question (now closed) at Stack Overflow.

Given a square matrix, let its double trace be defined as the sum of the entries from its main diagonal and its anti-diagonal. These are marked with X in the following examples:

X · · X
· X X ·
· X X ·
X · · X
X · · · X
· X · X ·
· · X · ·
· X · X ·
X · · · X
Note that for odd n, the central entry, which belongs to both diagonals, is counted only once.

Rules
The matrix size can be any positive integer.
The matrix will only contain non-negative integers.
Any reasonable input format can be used. If the matrix is taken as an array (even a flat one) its size cannot be taken as a separate input.
Input and output means are flexible as usual. Programs or functions are allowed. Standard loopholes are forbidden.
Shortest wins.
Test cases
5
   ->  5
3 5
4 0
     ->  12
 7  6 10
20 13 44
 5  0  1
          ->  36
4 4 4 4
4 4 4 4
4 4 4 4
4 4 4 4
          ->  32
23  4 21  5
24  7  0  7
14 22 24 16
 4  7  9 12
             ->  97
22 12 10 11  1
 8  9  0  5 17
 5  7 15  4  3
 5  3  7  0 25
 9 15 19  3 21
                -> 85
Inputs in other formats:

[[5]]
[[3,5],[4,0]]
[[7,6,10],[20,13,44],[5,0,1]]
[[4,4,4,4],[4,4,4,4],[4,4,4,4],[4,4,4,4]]
[[23,4,21,5],[24,7,0,7],[14,22,24,16],[4,7,9,12]]
[[22,12,10,11,1],[8,9,0,5,17],[5,7,15,4,3],[5,3,7,0,25],[9,15,19,3,21]]
[5]
[3 5; 4 0]
[7 6 10; 20 13 44; 5 0 1]
[4 4 4 4; 4 4 4 4; 4 4 4 4; 4 4 4 4]
[23 4 21 5; 24 7 0 7; 14 22 24 16; 4 7 9 12]
[22 12 10 11 1; 8 9 0 5 17; 5 7 15 4 3; 5 3 7 0 25; 9 15 19 3 21]
[5]
[3,5,4,0]
[7,6,10,20,13,44,5,0,1]
[4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4]
[23,4,21,5,24,7,0,7,14,22,24,16,4,7,9,12]
[22,12,10,11,1,8,9,0,5,17,5,7,15,4,3,5,3,7,0,25,9,15,19,3,21]

*/

package main

func main() {
	assert(doubletrace([][]int{
		{5},
	}) == 5)

	assert(doubletrace([][]int{
		{3, 5},
		{4, 0},
	}) == 12)

	assert(doubletrace([][]int{
		{7, 6, 10},
		{20, 13, 44},
		{5, 0, 1},
	}) == 36)

	assert(doubletrace([][]int{
		{4, 4, 4, 4},
		{4, 4, 4, 4},
		{4, 4, 4, 4},
		{4, 4, 4, 4},
	}) == 32)

	assert(doubletrace([][]int{
		{23, 4, 21, 5},
		{24, 7, 0, 7},
		{14, 22, 24, 16},
		{4, 7, 9, 12},
	}) == 97)

	assert(doubletrace([][]int{
		{22, 12, 10, 11, 1},
		{8, 9, 0, 5, 17},
		{5, 7, 15, 4, 3},
		{5, 3, 7, 0, 25},
		{9, 15, 19, 3, 21},
	}) == 85)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func doubletrace(m [][]int) int {
	n := len(m)
	r := 0
	for i := 0; i < n; i++ {
		r += m[i][i] + m[i][n-i-1]
	}
	if n&1 != 0 {
		r -= m[n/2][n/2]
	}
	return r
}
