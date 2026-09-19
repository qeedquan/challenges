/*

The xorspace of a set of integers is the set of all integers that can be obtained by combining the starting integers with the usual bitwise xor operator (^). For example, the xorspace of (8, 4) is (0, 4, 8, 12): 0 is 4^4, 12 is 4^8, and no other numbers can be reached. Note that the starting numbers are always included, by this definition (for example, 4 is 4^4^4).

Your goal is to write the shortest program that takes a list of non-negative integers as input, and outputs the number of elements in their xorspace.

Standard loopholes are forbidden.
Input and output can be in any of the usual formats. Input is guaranteed to be valid, non-empty, and without duplicates.
Your code should be able to process all test cases in less than a day.

Test cases
Input: 0
Output: 1

Input: 6
Output: 2

Input: 8 4
Ouput: 4

Input: 0 256
Output: 2

Input: 256 259 3
Output: 4

Input: 60 62 94 101 115
Output: 32

Input: 60 62 94 101 115 40 91
Output: 32

Input: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
Output: 64

Input: 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384
Output: 32768

*/

package main

func main() {
	assert(xorspace([]int{0}) == 1)
	assert(xorspace([]int{6}) == 2)
	assert(xorspace([]int{8, 4}) == 4)
	assert(xorspace([]int{0, 256}) == 2)
	assert(xorspace([]int{256, 259, 3}) == 4)
	assert(xorspace([]int{60, 62, 94, 101, 115}) == 32)
	assert(xorspace([]int{60, 62, 94, 101, 115, 40, 91}) == 32)
	assert(xorspace([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63}) == 64)
	assert(xorspace([]int{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384}) == 32768)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func xorspace(a []int) int {
	m := map[int]bool{0: true}
	for _, x := range a {
		p := []int{}
		for y := range m {
			p = append(p, x^y)
		}

		for _, v := range p {
			m[v] = true
		}
	}
	return len(m)
}
