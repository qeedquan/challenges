/*

It can be easily proven using Hall's marriage theorem that given fixed n and k<n/2, there is an injective (one-to-one) function from all n-bit strings with k ones to n-bit strings
with k+1 ones such that an input and its corresponding output differ by exactly one bit.

For example, with n=5,k=2:

00011 -> 00111
00110 -> 01110
01100 -> 11100
11000 -> 11001
10001 -> 10011

00101 -> 01101
01010 -> 11010
10100 -> 10101
01001 -> 01011
10010 -> 10110

However, the proof is non-constructive. It would be nice to have an explicit construction.

Task

Given a nonempty n-bit string with k<n/2 ones, output an n-bit string with k+1 ones formed only by changing one zero in the input to one, such that the binomial(n, k) distinct inputs map to binomial(n, k) distinct outputs.
You must prove that your program has this property.

The bit strings may be represented in any reasonable format, including as decimal numbers and as subsets of a specified n-element set. You may also simply output the index of the changed bit rather than the full string.

The output must be deterministic — it is not allowed to simply change the first zero in the input each time for example; there must be exactly one mapping implemented for each valid (n,k) pair.
The program or function must also work for all valid (n,k) pairs in theory, and have at most polynomial time complexity in n.

Otherwise this is code-golf; fewest bytes wins.

This question was based on this MathsSE post, which at the time of posting this question had no answers. There is now an answer by Mike Earnest giving an injection that satisfies this challenge's constraints:

https://math.stackexchange.com/questions/4641994/injection-from-binary-strings-with-i-bits-to-i1-bits/4642385#4642385

Repeatedly delete occurrences of 10 in the bitstring. This leaves a string of the form 0...01...1 with at least one zero.
Change the rightmost remaining zero (at its original location) to a one.
100011010001011
XX   XXXX  XX
  001    00  11
    X    X
  00      0  11
          ^ change this to 1

*/

package main

func main() {
	assert(saturate("00011") == "00111")
	assert(saturate("00110") == "01110")
	assert(saturate("01100") == "11100")
	assert(saturate("11000") == "11001")
	assert(saturate("10001") == "10011")
	assert(saturate("00101") == "01101")
	assert(saturate("01010") == "11010")
	assert(saturate("10100") == "10101")
	assert(saturate("01001") == "01011")
	assert(saturate("10010") == "10110")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func saturate(s string) string {
	p, ok := positions(s)
	if !ok {
		return "invalid"
	}
	p = trim(s, p)
	i := trailingzero(s, p)
	return s[:i] + "1" + s[i+1:]
}

func positions(s string) ([]int, bool) {
	p := []int{}
	n := len(s)
	k := 0
	for i := 0; i < n; i++ {
		switch s[i] {
		case '0':
		case '1':
			k++
		default:
			return nil, false
		}
		p = append(p, i)
	}
	if k >= (n/2)+(n%2) {
		return nil, false
	}
	return p, true
}

func trim(s string, p []int) []int {
loop:
	for {
		for i, n := 0, len(p); i < n-1; i++ {
			a, b := p[i], p[i+1]
			if s[a] == '1' && s[b] == '0' {
				copy(p[i:], p[i+2:])
				p = p[:n-2]
				continue loop
			}
		}
		return p
	}
}

func trailingzero(s string, p []int) int {
	for i := len(p) - 1; i >= 0; i-- {
		if j := p[i]; s[j] == '0' {
			return j
		}
	}
	return 0
}
