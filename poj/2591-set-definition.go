/*

Description

Set S is defined as follows:
(1) 1 is in S;
(2) If x is in S, then 2x + 1 and 3x + 1 are also in S;
(3) No other element belongs to S.

Find the N-th element of set S, if we sort the elements in S by increasing order.

Input

Input will contain several test cases; each contains a single positive integer N (1 <= N <= 10000000), which has been described above.

Output

For each test case, output the corresponding element in S.

Sample Input

100
254

Sample Output

418
1461

Source

POJ Monthly--2005.08.28,Static

*/

package main

func main() {
	tab := []int{
		1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, 28, 31, 39, 40, 43, 45, 46,
		55, 57, 58, 63, 64, 67, 79, 81, 82, 85, 87, 91, 93, 94, 111, 115, 117,
		118, 121, 127, 129, 130, 135, 136, 139, 159, 163, 165, 166, 171, 172,
		175, 183, 187, 189, 190, 193, 202, 223, 231, 235, 237,
	}

	x := gen(256)
	assert(x[100] == 418)
	assert(x[254] == 1461)
	for i := range tab {
		assert(x[i+1] == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002977
func gen(n int) []int {
	i2 := 1
	i3 := 1

	r := make([]int, 3*n+1)
	r[1] = 1
	for i := 2; i <= n; i++ {
		x2 := 2*r[i2] + 1
		x3 := 3*r[i3] + 1
		r[i] = min(x2, x3)
		if r[i] == x2 {
			i2++
		}
		if r[i] == x3 {
			i3++
		}
	}
	return r[:n]
}
