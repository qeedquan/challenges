/*

Note that this challenge requires no handling or understanding of complex numbers.

Given a non-empty square matrix where every element is a two-element (Re,Im) integer list, determine (giving any truthy/falsy values or any two consistent values) whether this represents a Hermitian matrix.

Note that the input is a 3D array of integers; not a 2D array of complex numbers. If your language cannot take a 3D array directly, you may take a flat list (and the n×n or n×n×2 shape if that helps).

A matrix is Hermitian if it equals its own conjugate transpose. In other words, if you flip it across its top-left to bottom-right diagonal and negate the second element of all the two-element leaf-lists, it is identical to the input matrix. Note that the order of flipping and negating is irrelevant, so you may negate first, and flip afterwards.

Walk-though example
This example uses JSON with superfluous white-space to ease reading:

[[ [2, 0] , [2, 1] , [4, 0] ],
 [ [2,-1] , [3, 0] , [0, 1] ],
 [ [4, 0] , [0,-1] , [1, 0] ]]
Transpose (flip across NW—SE diagonal):

[[ [2, 0] , [2,-1] , [4, 0] ],
 [ [2, 1] , [3, 0] , [0,-1] ],
 [ [4, 0] , [0, 1] , [1, 0] ]]
Negate second elements of leaf-lists:

[[ [2, 0] , [2, 1] , [4, 0] ],
 [ [2,-1] , [3, 0] , [0, 1] ],
 [ [4, 0] , [0,-1] , [1, 0] ]]
As this is identical to the input, the matrix is Hermitian.

Test cases
Hermitian
[[[2,0],[2,1],[4,0]],[[2,-1],[3,0],[0,1]],[[4,0],[0,-1],[1,0]]]

[[[1,0],[2,0]],[[2,0],[1,0]]]

[[[1,0],[2,-3]],[[2,3],[1,0]]]

[[[42,0]]]

Non-Hermitian
[[[2,0],[2,1],[4,0]],[[2,-1],[3,0],[0,1]],[[4,0],[0,-1],[1,-1]]]

[[[0,1],[0,2]],[[0,2],[0,1]]]

[[[1,0],[2,3]],[[2,3],[1,0]]]

[[[3,2]]]

*/

package main

import "math/cmplx"

func main() {
	assert(hermitian([][]complex128{
		{2 + 0i, 2 + 1i, 4 + 0i},
		{2 - 1i, 3 + 0i, 0 + 1i},
		{4 + 0i, 0 - 1i, 1 + 0i},
	}) == true)

	assert(hermitian([][]complex128{
		{1 + 0i, 2 + 0i},
		{2 + 0i, 1 + 0i},
	}) == true)

	assert(hermitian([][]complex128{
		{1 + 0i, 2 - 3i},
		{2 + 3i, 1 + 0i},
	}) == true)

	assert(hermitian([][]complex128{
		{42 + 0i},
	}) == true)

	assert(hermitian([][]complex128{
		{2 + 0i, 2 + 1i, 4 + 0i},
		{2 - 1i, 3 + 0i, 0 + 1i},
		{4 + 0i, 0 - 1i, 1 - 1i},
	}) == false)

	assert(hermitian([][]complex128{
		{0 + 1i, 0 + 2i},
		{0 + 2i, 0 + 1i},
	}) == false)

	assert(hermitian([][]complex128{
		{1 + 0i, 2 + 3i},
		{2 + 3i, 1 + 0i},
	}) == false)

	assert(hermitian([][]complex128{
		{3 + 2i},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hermitian(m [][]complex128) bool {
	for i := range m {
		for j := range i + 1 {
			if m[i][j] != cmplx.Conj(m[j][i]) {
				return false
			}
		}
	}
	return true
}
