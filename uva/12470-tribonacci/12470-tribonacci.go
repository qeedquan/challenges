package main

type Matrix [3][3]int64

func main() {
	assert(tribonacci(1) == 0)
	assert(tribonacci(2) == 1)
	assert(tribonacci(3) == 2)
	assert(tribonacci(4) == 3)
	assert(tribonacci(5) == 6)
	assert(tribonacci(6) == 11)
	assert(tribonacci(7) == 20)
	assert(tribonacci(8) == 37)
	assert(tribonacci(9) == 68)
	assert(tribonacci(10) == 125)
	assert(tribonacci(100) == 616688122)
	assert(tribonacci(10000) == 335363379)
	assert(tribonacci(10000000) == 272924536)
	assert(tribonacci(100000000000) == 48407255)
	assert(tribonacci(10000000000000000) == 163452242)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://math.stackexchange.com/questions/4062915/tribonacci-generating-matrix
https://oeis.org/A001590

*/

func tribonacci(n int64) int64 {
	const mod = 1000000009

	if n < 1 {
		return 0
	}

	A := Matrix{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}
	A = pow(A, n, mod)
	return A[1][1]
}

func pow(A Matrix, n, mod int64) Matrix {
	X := Matrix{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}
	Y := A
	for ; n > 0; n >>= 1 {
		if n&1 != 0 {
			X = mul(X, Y, mod)
		}
		Y = mul(Y, Y, mod)
	}
	return X
}

func mul(X, Y Matrix, mod int64) Matrix {
	R := Matrix{}
	for i := range 3 {
		for j := range 3 {
			for k := range 3 {
				R[i][j] += X[i][k] * Y[k][j]
				R[i][j] %= mod
			}
		}
	}
	return R
}
