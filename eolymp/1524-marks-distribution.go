/*

In an examination period, a student took n subjects and received a total of t marks.
The minimum passing mark for each subject is p.
Your task is to calculate the number of ways the student could have obtained the marks in the exams.
For example, if n=3, t=34, and p=10, then the marks in the three subjects could be distributed as follows:

So, the student can pass in 15 different ways.

Input
The first line contains the number of test cases. Each test case consists of one line containing three integers n, t, and p, each not exceeding 70.

Output
For each test case, print the number of ways the student could have obtained the marks in the exams on a separate line.
The answer will always fit in a signed 32-bit integer.

Examples
Input #1
2
3 34 10
3 34 10

Answer #1
15
15

*/

package main

func main() {
	assert(solve(3, 34, 10) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, t, p int) int {
	x := n - 1
	y := t - n*p
	m := x + y

	r := 1
	s := max(x, y)
	e := min(x, y)
	for i := s + 1; i <= m; i++ {
		r *= i
	}
	for i := 2; i <= e; i++ {
		r /= i
	}
	return r
}
