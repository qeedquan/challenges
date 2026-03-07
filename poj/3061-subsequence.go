/*

Description

A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.

Input

The first line is the number of test cases. For each test case the program has to read the numbers N and S, separated by an interval, from the first line. The numbers of the sequence are given in the second line of the test case, separated by intervals. The input will finish with the end of file.

Output

For each the case the program has to print the result on separate line of the output file.if no answer, print 0.

Sample Input

2
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5

Sample Output

2
3

Source

Southeastern Europe 2006

*/

package main

func main() {
	assert(subsequence([]int{5, 1, 3, 5, 10, 7, 4, 9, 2, 8}, 15) == 2)
	assert(subsequence([]int{1, 2, 3, 4, 5}, 11) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func subsequence(a []int, s int) int {
	n := len(a)
	i := 0
	j := 0
	v := 0
	r := n + 1
	for {
		for i < n && v < s {
			v += a[i]
			i += 1
		}
		if v < s {
			break
		}
		r = min(r, i-j)
		v -= a[j]
		j += 1
	}
	if r > n {
		r = 0
	}
	return r
}
