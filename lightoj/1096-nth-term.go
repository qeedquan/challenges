/*

You have to find the nth term of the following function:

f(n) = a*f(n-1) + b*f(n-3) + c   if n > 2
       0                         if n <= 2

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case contains four integers n (0 ≤ n ≤ 108), a b c (1 ≤ a, b, c ≤ 10000).

Output
For each case, print the case number and f(n) modulo 10007.

Sample
Input	Output
2
10 1 2 3
5 1 3 9

Case 1: 162
Case 2: 27

*/

package main

type Matrix [4][4]int64
type Vector [4]int64

func main() {
	assert(nth(10, 1, 2, 3) == 162)
	assert(nth(5, 1, 3, 9) == 27)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nth(n, a, b, c int64) int64 {
	const mod = 10007

	if n < 3 {
		return 0
	}

	A := Matrix{{a, 0, b, c}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}}
	V := Vector{c, 0, 0, 1}
	A = pow(A, n-3, mod)
	R := xfm(A, V)
	return R[0] % mod
}

func pow(A Matrix, n, mod int64) Matrix {
	X := Matrix{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}
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
	for i := range 4 {
		for j := range 4 {
			for k := range 4 {
				R[i][j] += X[i][k] * Y[k][j]
				R[i][j] %= mod
			}
		}
	}
	return R
}

func xfm(M Matrix, V Vector) Vector {
	R := Vector{}
	for i := range 4 {
		R[i] = 0
		for j := range 4 {
			R[i] += M[i][j] * V[j]
		}
	}
	return R
}
