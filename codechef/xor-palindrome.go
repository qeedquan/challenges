/*

Xor Palindrome
You are given a binary string A of length N.

You can perform the following type of operation on the string A:
Choose two different indices i and j (1 <= i, j <= N)
Change A[i] and A[j] to A[i]^A[j]. Here ^ represents the bitwise XOR operation.

Find the minimum number of operations required to convert the given string into a palindrome.

Input Format
First line of the input contains T, the number of test cases. Then the test cases follow.
First line of each test case contains an integer N denoting the size of the string.
Second line of each test case contains a binary string A of length N containing 0s and 1s only.

Output Format
For each test case, print the minimum number of operations required to make the string a palindrome.

Constraints
1 ≤ T ≤ 1000
1 <= N <= 2*10^5
Sum of N over all test cases does not exceed 2*10^5

Sample 1:
Input
4
5
11011
7
0111010
1
1
4
1100

Output
0
1
0
1

More Info
Time limit 2.5 secs
Memory limit 1.5 GB
Source Limit 50000 Bytes

*/

package main

func main() {
	assert(xorpal("11011") == 0)
	assert(xorpal("0111010") == 1)
	assert(xorpal("1") == 0)
	assert(xorpal("1100") == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func xorpal(s string) int {
	n := len(s)
	c := 0
	for i := 0; i < n/2; i++ {
		if s[i] != s[n-i-1] {
			c += 1
		}
	}
	return (c + 1) / 2
}
