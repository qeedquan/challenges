/*

Description

The Lab Cup Table Tennis Competition is going to take place soon among laboratories in PKU. Students from the AI Lab are all extreme enthusiasts in table tennis and hold strong will to represent the lab in the competition. Limited by the quota, however, only one of them can be selected to play in the competition.

To make the selection fair, they agreed on a single round robin tournament, in which every pair of students played a match decided by best of 5 games. The one winning the most matches would become representative of the lab. Now Ava, head of the lab, has in hand a form containing the scores of all matches. Who should she decide on for the competition?

Input

The input contains exactly one test case. The test case starts with a line containing n (2 ≤ n ≤ 100), the number of students in the lab. Then follows an n × n matrix A. Each element in the matrix will be one of 0, 1, 2 and 3. The element at row i and column j, aij, is the number of games won by the ith student in his/her match with the jth student. Exactly one of aij and aji (i ≠ j) is 3 and the other one will be less than 3. All diagonal elements of the matrix are 0’s.

Output

Output the number of the student who won the most matches. In the case of a tie, choose the one numbered the smallest.

Sample Input

4
0 0 3 2
3 0 3 1
2 2 0 2
3 3 3 0

Sample Output

4

Source

PKU Local 2007 (POJ Monthly--2007.04.28), ideas from ava, text and test cases by frkstyc

*/

package main

func main() {
	assert(student([][]int{
		{0, 0, 3, 2},
		{3, 0, 3, 1},
		{2, 2, 0, 2},
		{3, 3, 3, 0},
	}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func student(a [][]int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	p := make([]int, n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if a[i][j] == 3 {
				p[i]++
			}
		}
	}

	r := 0
	m := p[0]
	for i := 1; i < n; i++ {
		if m < p[i] {
			r, m = i, p[i]
		}
	}
	return r + 1
}
