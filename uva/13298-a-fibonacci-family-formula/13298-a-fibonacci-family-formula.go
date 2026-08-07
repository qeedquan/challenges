package main

type Matrix [][]int

func main() {
	T := [][]int{
		{1, 1, 1, 1, 1, 1},
		{1, 1, 2, 3, 5, 8},
		{1, 1, 2, 4, 7, 13},
		{1, 1, 2, 4, 8, 15},
		{1, 1, 2, 4, 8, 16, 31, 61, 120, 236, 464, 912, 1793, 3525, 6930, 13624},
		{1, 1, 2, 4, 8, 16, 32, 63, 125, 248, 492, 976, 1936, 3840, 7617, 15109},
		{1, 1, 2, 4, 8, 16, 32, 64, 127, 253, 504, 1004, 2000, 3984, 7936, 15808},
		{1, 1, 2, 4, 8, 16, 32, 64, 128, 255, 509, 1016, 2028, 4048, 8080, 16128},
		{1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 511, 1021, 2040, 4076, 8144, 16272},
	}

	assert(kbonacci(5, 5) == 16)
	assert(kbonacci(3, 4) == 7)
	assert(kbonacci(2, 3) == 3)
	assert(kbonacci(7, 0) == 1)

	for k := range T {
		for n := range T[k] {
			assert(kbonacci(k+1, n) == T[k][n])
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://sahasatvik.github.io/kbonacci/
https://en.wikipedia.org/wiki/Generalizations_of_Fibonacci_numbers

k-bonacci sequences can be represented as a KxK matrix of the following form:

M[k] = 1 1 1 ... 1 1
       1 0 0 ... 0 0
	   0 1 0 ... 0 0
	   . . 1     . .
	   . .   .   . .
	   . .    .  . .
	   0 0 0 ... 1 0

Fibonacci  : 2x2 matrix
Tribonacci : 3x3 matrix
Tetranacci : 4x4 matrix
and so on

The matrix can be exponentiated to quickly find the nth term

*/

func kbonacci(k, n int) int {
	const mod = 1000000009

	if n < 0 || k < 1 {
		return 0
	}

	if n == 1 {
		return 1
	}

	A := make(Matrix, k)
	for i := range A {
		A[i] = make([]int, k)
	}
	for i := range k {
		A[0][i] = 1
	}
	for i := range k - 1 {
		A[i+1][i] = 1
	}
	A = pow(A, n, mod)

	return A[0][0]
}

func zero(n int) Matrix {
	Z := make(Matrix, n)
	for i := range Z {
		Z[i] = make([]int, n)
	}
	return Z
}

func eye(n int) Matrix {
	I := make(Matrix, n)
	for i := range I {
		I[i] = make([]int, n)
	}
	for i := range n {
		I[i][i] = 1
	}
	return I
}

func pow(A Matrix, n, mod int) Matrix {
	X := eye(len(A))
	Y := A
	for ; n > 0; n >>= 1 {
		if n&1 != 0 {
			X = mul(X, Y, mod)
		}
		Y = mul(Y, Y, mod)
	}
	return X
}

func mul(X, Y Matrix, mod int) Matrix {
	n := len(X)
	R := zero(n)
	for i := range n {
		for j := range n {
			for k := range n {
				R[i][j] += X[i][k] * Y[k][j]
				R[i][j] %= mod
			}
		}
	}
	return R
}
