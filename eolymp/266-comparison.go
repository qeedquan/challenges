/*

Compare two numbers A and B.

Input
The input contains two nonnegative integers A and B (0≤A,B≤10^10000), each given on a separate line.

Output
Output < if A<B, = if A=B, or > if A>B.

Examples

Input #1
2
1

Answer #1
>

*/

package main

func main() {
	assert(solve("2", "1") == '>')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b string) rune {
	switch {
	case len(a) > len(b):
		return '>'
	case len(a) < len(b):
		return '<'
	case a > b:
		return '>'
	case a < b:
		return '<'
	}
	return '='
}
