/*

Given a boolean expression with the following symbols.

Symbols
    'T' ---> true
    'F' ---> false

And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
Let the input be in form of two arrays one contains the symbols (T and F) in order and the other contains operators (&, | and ^}

Examples:

Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

Input: symbol[]    = {T, F, F}
       operator[]  = {^, |}
Output: 2
The given expression is "T ^ F | F", it evaluates true
in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )".

Input: symbol[]    = {T, T, F, T}
       operator[]  = {|, &, ^}
Output: 4
The given expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)).

*/

package main

func main() {
	assert(count("TFF", "^|") == 2)
	assert(count("TFT", "^&") == 2)
	assert(count("TTFT", "|&^") == 4)
	assert(count("TFTFTFTF", "|&^||&&^") == 216)
	assert(count("", "") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}

// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
func count(syms, ops string) int {
	n := len(syms)
	if n == 0 {
		return 0
	}

	F := alloc(n)
	T := alloc(n)
	for i := 0; i < n; i++ {
		if syms[i] == 'F' {
			F[i][i] = 1
		} else if syms[i] == 'T' {
			T[i][i] = 1
		}
	}

	for gap := 1; gap < n; gap++ {
		for i, j := 0, gap; j < n; i, j = i+1, j+1 {
			T[i][j], F[i][j] = 0, 0
			for g := 0; g < gap; g++ {
				k := i + g
				tik := T[i][k] + F[i][k]
				tkj := T[k+1][j] + F[k+1][j]
				switch ops[k] {
				case '&':
					T[i][j] += T[i][k] * T[k+1][j]
					F[i][j] += (tik*tkj - T[i][k]*T[k+1][j])
				case '|':
					F[i][j] += F[i][k] * F[k+1][j]
					T[i][j] += (tik*tkj - F[i][k]*F[k+1][j])
				case '^':
					T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]
				}
			}
		}
	}
	return T[0][n-1]
}
