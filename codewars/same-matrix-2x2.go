/*

You have some 2*2 matrices, each matrix is represented by an array of length 4.

such as [a, b, c, d] is matrix

a b
c d
Matrix can be rotated:

a b   90 degrees  c a  180 degrees  d c  270 degrees  b d
c d  -----------> d b  -----------> b a  -----------> a c
If matrix A can be obtained by rotating matrix B clockwise by 0, 90, 180 or 270 degrees, we think that A and B are the same matrix.

For example, the following matrices are considered the same.

1 2
3 4

3 1
4 2

4 3
2 1

2 4
1 3
The task of this kata is to count how many different matrices you have.

Samples

// Same as the above example.
count_different_matrices([[1, 2, 3, 4],
                          [3, 1, 4, 2],
                          [4, 3, 2, 1],
                          [2, 4, 1, 3]]);

//should return '1'
Notes

All the matrices' elements are integers between 1 and 9, and the number of matrices will not exceed 1000.

*/

package main

func main() {
	assert(count([][4]int{
		{1, 2, 3, 4},
		{3, 1, 4, 2},
		{4, 3, 2, 1},
		{2, 4, 1, 3},
	}) == 1)

	assert(count([][4]int{
		{1, 0, 0, 0},
		{2, 0, 0, 0},
		{3, 0, 0, 0},
	}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(m [][4]int) int {
	s := make(map[[4]int]bool)
	c := 0
	for _, p := range m {
		if s[p] {
			continue
		}
		k0 := [4]int{p[0], p[1], p[2], p[3]}
		k1 := [4]int{p[2], p[0], p[3], p[1]}
		k2 := [4]int{p[3], p[2], p[1], p[0]}
		k3 := [4]int{p[1], p[3], p[0], p[2]}
		s[k0] = true
		s[k1] = true
		s[k2] = true
		s[k3] = true
		c += 1
	}
	return c
}
